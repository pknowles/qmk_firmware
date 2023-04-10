// Copyright 2022 Pyarelal Knowles (@pknowles)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define AUDIO_PIN C6
#define AUDIO_INIT_DELAY
#define STARTUP_SONG SONG(STARTUP_SOUND)

//#define RGBLIGHT_EFFECT_RGB_TEST
//#define RGBLIGHT_EFFECT_RAINBOW_SWIRL

#define RGB_DISABLE_WHEN_USB_SUSPENDED true

#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 32

#define NO_ACTION_ONESHOT

// keyboards/sowbug/68keys/config.h
// https://www.reddit.com/r/olkb/comments/sbvefp/has_anyone_gotten_qmk_rgb_matrix_effects_working/
// Seems very important but not mentioned in the docs!!
#define RGBLED_NUM 72
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
//#define RGB_MATRIX_KEYPRESSES
//#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_DI_PIN D7
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 64
//#define ENABLE_RGB_MATRIX_RAINDROPS
//#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
//#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
//#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
//#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CUSTOM_test
#define RGB_MATRIX_STARTUP_SPD 32
#define RGB_MATRIX_STARTUP_HUE 100
#define RGB_MATRIX_LED_PROCESS_LIMIT DRIVER_LED_TOTAL // (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)

//#define WS2812_T0H 400
//#define WS2812_T1H 800
//#define WS2812_T0L 850
//#define WS2812_T1L 450
//#define WS2812_TIMING WS2812_T0H + WS2812_T0L
//#define WS2812_RES_US 100

//#define DEBUG_MATRIX_SCAN_RATE

/* key matrix size */
#define MATRIX_ROWS 11
#define MATRIX_COLS_LEFT 7
#define MATRIX_COLS_RIGHT 8
#define MATRIX_COLS 8

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

// Rows 0 to 5 are regular GPIO pins on the microcontroller.
// Rows 6 to 10 are on the right half via the MCP23017 GPIO expander
#define MATRIX_ROWS_LEFT 6
#define MATRIX_ROWS_RIGHT 5

// wiring
#define MATRIX_ROW_PINS_MCU \
    { E6, B4, B5, B7, D5, C7 }
#define MATRIX_COL_PINS_MCU \
    { F1, F0, B6, B2, B3, B1, F7 }
#define MATRIX_ROW_PINS_MCP \
    { B0, B1, B2, B3, B4 }
#define MATRIX_COL_PINS_MCP \
    { A0, A1, A2, A3, A4, A5, A6, A7 }
