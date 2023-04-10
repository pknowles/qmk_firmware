/*
Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>
          2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * This code was heavily inspired by the ergodox_ez keymap, and modernized
 * to take advantage of the quantum.h microcontroller agnostics gpio control
 * abstractions and use the macros defined in config.h for the wiring as opposed
 * to repeating that information all over the place.
 */

#include QMK_KEYBOARD_H
#include "i2c_master.h"

extern int mydebug;

extern i2c_status_t mcp23017_status;
#define I2C_TIMEOUT 1000

// For a better understanding of the i2c protocol, this is a good read:
// https://www.robot-electronics.co.uk/i2c-tutorial

// I2C address:
// See the datasheet, section 3.3.1 on addressing I2C devices and figure 3-6 for an
// illustration
// http://ww1.microchip.com/downloads/en/devicedoc/20001952c.pdf
// All address pins of the mcp23017 are connected to the ground on the ferris
// | 0  | 1  | 0  | 0  | A2 | A1 | A0 |
// | 0  | 1  | 0  | 0  | 0  | 0  | 0  |
#define I2C_ADDR 0b0100000
#define I2C_ADDR_WRITE ((I2C_ADDR << 1) | I2C_WRITE)
#define I2C_ADDR_READ ((I2C_ADDR << 1) | I2C_READ)

// Register addresses
// See https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library/blob/master/Adafruit_MCP23017.h
#define IODIRA 0x00  // i/o direction register
#define IODIRB 0x01
#define GPPUA 0x0C  // GPIO pull-up resistor register
#define GPPUB 0x0D
#define GPIOA 0x12  // general purpose i/o port register (write modifies OLAT)
#define GPIOB 0x13
#define OLATA 0x14  // output latch register
#define OLATB 0x15

bool         i2c_initialized = 0;
i2c_status_t mcp23017_status = I2C_ADDR;

uint8_t init_mcp23017(void) {
    print("starting init");
    mcp23017_status = I2C_ADDR;

    // I2C subsystem
    if (i2c_initialized == 0) {
        i2c_init();  // on pins D(1,0)
        i2c_initialized = true;
        wait_ms(I2C_TIMEOUT);
    }

    // set pin direction
    // - unused  : input  : 1
    // - input   : input  : 1
    // - driving : output : 0
    // This means: we will read all the bits on GPIOA
    // This means: we will write to the pins 0-4 on GPIOB (in select_rows)
    uint8_t buf[]   = {IODIRA, 0b00000000, 0b11111111};
    mcp23017_status = i2c_transmit(I2C_ADDR_WRITE, buf, sizeof(buf), I2C_TIMEOUT);
    if (!mcp23017_status) {
        // set pull-up
        // - unused  : on  : 1
        // - input   : on  : 1
        // - driving : off : 0
        // This means: we will read all the bits on GPIOA
        // This means: we will write to the pins 0-4 on GPIOB (in select_rows)
        uint8_t pullup_buf[] = {GPPUA, 0b00000000, 0b11111111};
        mcp23017_status      = i2c_transmit(I2C_ADDR_WRITE, pullup_buf, sizeof(pullup_buf), I2C_TIMEOUT);
    }
    return mcp23017_status;
}

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];  // debounced values

static void         init_cols(void);
static void         unselect_rows(void);

static uint8_t mcp23017_reset_loop;

void matrix_init_custom(void) {
    // initialize row and col
    mcp23017_status = init_mcp23017();

    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
    }
}

void matrix_power_up(void) {
    matrix_init_custom();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    if (mcp23017_status) {  // if there was an error
        if (++mcp23017_reset_loop == 0) {
            // if (++mcp23017_reset_loop >= 1300) {
            // since mcp23017_reset_loop is 8 bit - we'll try to reset once in 255 matrix scans
            // this will be approx bit more frequent than once per second
            dprint("trying to reset mcp23017\n");
            mcp23017_status = init_mcp23017();
            if (mcp23017_status) {
                dprint("right side not responding\n");
            } else {
                dprint("right side attached\n");
            }
        }
    }

    bool changed = false;

    // Right hand side with the GPIO expander. Sadly this is column major
    // because the mcp23017 only has internal pull-up resistors (so diodes must
    // go the other way) and neo-key PCB diodes are row-to-column.
    for (uint8_t col = 0; col < MATRIX_COLS_RIGHT; col++) {
        // select on mcp23017
        if (mcp23017_status) {  // if there was an error
                                // do nothing
        } else {
            // Select the desired row by writing a byte for the entire GPIOB bus where only the bit representing the row we want to select is a zero (write instruction) and every other bit is a one.
            // Note that the row - MATRIX_ROWS_PER_SIDE reflects the fact that being on the right hand, the columns are numbered from MATRIX_ROWS_PER_SIDE to MATRIX_ROWS, but the pins we want to write to are indexed from zero up on the GPIOB bus.
            uint8_t buf[]   = {GPIOA, 0xFF & ~(1 << col)};
            mcp23017_status = i2c_transmit(I2C_ADDR_WRITE, buf, sizeof(buf), I2C_TIMEOUT);
        }

        if (mcp23017_status) {  // if there was an error
            return 0;
        } else {
            uint8_t buf[]   = {GPIOB};
            mcp23017_status = i2c_transmit(I2C_ADDR_WRITE, buf, sizeof(buf), I2C_TIMEOUT);
            // We read all the pins on GPIOA.
            // The initial state was all ones and any depressed key at a given column for the currently selected row will have its bit flipped to zero.
            // The return value is a row as represented in the generic matrix code were the rightmost bits represent the lower columns and zeroes represent non-depressed keys while ones represent depressed keys.
            // Since the pins connected to eact columns are sequential, and counting from zero up (col 5 -> GPIOA0, col 6 -> GPIOA1 and so on), the only transformation needed is a bitwise not to swap all zeroes and ones.
            uint8_t data = 0;
            if (!mcp23017_status) {
                mcp23017_status = i2c_receive(I2C_ADDR_READ, &data, sizeof(data), I2C_TIMEOUT);
                data            = ~data;
            }

            if(col == 0)
              mydebug = data;

            for (uint8_t row = 0; row < MATRIX_ROWS_RIGHT; row++) {
                bool tmp = (current_matrix[MATRIX_ROWS_LEFT + row] & (MATRIX_ROW_SHIFTER << col)) > 0;
                bool down = (data & (1 << row)) > 0;
                changed |= tmp != down;
                current_matrix[MATRIX_ROWS_LEFT + row] = current_matrix[MATRIX_ROWS_LEFT + row] & (~(MATRIX_ROW_SHIFTER << col));
                current_matrix[MATRIX_ROWS_LEFT + row] |= down ? (MATRIX_ROW_SHIFTER << col) : 0;
            }
        }
    }

    // Left hand side
    pin_t matrix_col_pins_mcu[MATRIX_COLS_LEFT] = MATRIX_COL_PINS_MCU;
    pin_t matrix_row_pins_mcu[MATRIX_ROWS_LEFT] = MATRIX_ROW_PINS_MCU;
    for (uint8_t col = 0; col < MATRIX_COLS_LEFT; col++) {
        // Select column
        setPinOutput(matrix_col_pins_mcu[col]);
        writePinLow(matrix_col_pins_mcu[col]);

        wait_us(30);

        // Read rows from the column
        uint8_t col_value_prev = 0;
        uint8_t col_value = 0;
        for (uint8_t row = 0; row < MATRIX_ROWS_LEFT; row++) {
            // Select the col pin to read (active low)
            bool down = !readPin(matrix_row_pins_mcu[row]);

            // Populate the matrix row with the state of the col pin
            col_value |= down ? (1U << row) : 0;

            // Compare with the original
            col_value_prev |= (current_matrix[row] & (MATRIX_ROW_SHIFTER << col));
            current_matrix[row] = current_matrix[row] & (~(MATRIX_ROW_SHIFTER << col));
            current_matrix[row] |= down ? (MATRIX_ROW_SHIFTER << col) : 0;
        }

        changed |= (col_value != col_value_prev);

        // Un-select column
        setPinInput(matrix_col_pins_mcu[col]);
        writePinLow(matrix_col_pins_mcu[col]);
    }

    return changed;
}

static void init_cols(void) {
    // init on mcp23017
    // not needed, already done as part of init_mcp23017()

    // init on mcu
    pin_t matrix_row_pins_mcu[MATRIX_ROWS_LEFT] = MATRIX_ROW_PINS_MCU;
    for (int pin_index = 0; pin_index < MATRIX_ROWS_LEFT; pin_index++) {
        pin_t pin = matrix_row_pins_mcu[pin_index];
        setPinInput(pin);
        writePinHigh(pin);
    }
}

static void unselect_rows(void) {
    // unselect rows on microcontroller
    pin_t matrix_col_pins_mcu[MATRIX_COLS_LEFT] = MATRIX_COL_PINS_MCU;
    for (int pin_index = 0; pin_index < MATRIX_COLS_LEFT; pin_index++) {
        pin_t pin = matrix_col_pins_mcu[pin_index];
        setPinInput(pin);
        writePinLow(pin);
    }
}
