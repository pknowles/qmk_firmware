#include QMK_KEYBOARD_H

#define LAYOUT(NAK, \
	K00, K01, K02, K03, K04, K05, K06, \
	K10, K11, K12, K13, K14, K15, K16, \
	K20, K21, K22, K23, K24, K25, K26, \
	K30, K31, K32, K33, K34, K35, K36,  \
	                    K37, K38, K39,  \
	                    K40, K41, K42  \
) \
	{ K00, K01, K02, K03, K04, K05, K06, NAK }, \
	{ K10, K11, K12, K13, K14, K15, K16, NAK }, \
	{ K20, K21, K22, K23, K24, K25, K26, NAK }, \
	{ K30, K31, K32, K33, K34, K35, K36, NAK }, \
	{ K42, K38, K37, NAK, NAK, NAK, NAK, NAK }, \
	{ K39, K41, K40, NAK, NAK, NAK, NAK, NAK }

#define LAYOUT_R(NAK, \
	     K00, K01, K02, K03, K04, K05, K06, \
	     K10, K11, K12, K13, K14, K15, K16, \
	     K20, K21, K22, K23, K24, K25, K26, \
	K40, K41, K31, K32, K33, K34, K35, K36,  \
	K50, K51 \
) \
	{ K06, K05, K04, K03, K02, K01, K00, NAK }, \
	{ K16, K15, K14, K13, K12, K11, K10, NAK }, \
	{ K26, K25, K24, K23, K22, K21, K20, NAK }, \
	{ K36, K35, K34, K33, K32, K31, K41, K40 }, \
	{ NAK, NAK, NAK, NAK, NAK, NAK, K51, K50 }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │Ctrl│GUI │Alt │                        │ Alt│ GUI│Menu│Ctrl│
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
    [0] = {LAYOUT(KC_NO,
                 KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,
                 RGB_MOD, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_DEL,
                 KC_LGUI, KC_A, KC_S, KC_D, KC_F, KC_G, KC_TAB,
                 KC_ESC, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LCTL,
                                     KC_LSFT, MO(1), MO(2),
                                     KC_LCTL, KC_LALT, KC_LGUI
        ), LAYOUT_R(KC_NO,
                 KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
                 KC_BSPC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
                 KC_NO, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOTE,
          KC_RGUI, MO(1), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH, MO(2),
          KC_RSFT, KC_SPC
        )},
    [1] = {LAYOUT(KC_NO,
                 KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                     KC_TRNS, KC_TRNS, KC_TRNS,
                                     KC_TRNS, KC_TRNS, KC_TRNS
        ), LAYOUT_R(KC_NO,
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                   KC_DEL, KC_TRNS, KC_HOME, KC_UP,   KC_END,   KC_PGUP, KC_TRNS,
                   KC_ENT, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS
        )},
    [2] = {LAYOUT(KC_NO,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                     KC_TRNS, KC_TRNS, KC_TRNS,
                                     KC_TRNS, KC_TRNS, KC_TRNS
        ), LAYOUT_R(KC_NO,
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(3),
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS
        )},
    [3] = {LAYOUT(KC_NO,
                 KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,
                                   KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS
        ), LAYOUT_R(KC_NO,
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS
        )}
};

led_config_t g_led_config = {
  // Key Matrix to LED Index
  {LAYOUT(NO_LED,
                 30, 31, 32, 33, 34, 35, 36,
                 29, 28, 27, 26, 25, 24, 23,
                 16, 17, 18, 19, 20, 21, 22,
                 15, 14, 13, 12, 11, 10,  9,
                                     5, 4, 1,
                                     3, 2, 0
   ),
   LAYOUT_R(NO_LED,
                 67, 66, 65, 64, 63, 62, 61,
                 54, 55, 56, 57, 58, 59, 60,
                 53, 52, 51, 50, 49, 48, 47,
             39, 40, 41, 42, 43, 44, 45, 46,
             38, 37
   )
   }, {
    // LED Index to Physical PositionLAYOUT(NO_LED,
    // Thumb
    {70, 70},
    {75, 65}, {65, 60}, {55, 55},
    {70, 55}, {60, 50},

    // Indicators
    {75, 65}, {65, 60}, {55, 55},

    // Main keys
    {60, 30}, {50, 30}, {40, 30}, {30, 30}, {20, 30}, {10, 30}, {0, 30},
    {0, 20}, {10, 20}, {20, 20}, {30, 20}, {40, 20}, {50, 20}, {60, 20},
    {60, 10}, {50, 10}, {40, 10}, {30, 10}, {20, 10}, {10, 10}, {0, 10},
    {0, 0}, {10, 0}, {20, 0}, {30, 0}, {40, 0}, {50, 0}, {60, 0},

    // R Main keys
    {60, 30}, {50, 30}, {40, 30}, {30, 30}, {20, 30}, {10, 30}, {0, 30},
    {0, 20}, {10, 20}, {20, 20}, {30, 20}, {40, 20}, {50, 20}, {60, 20},
    {60, 10}, {50, 10}, {40, 10}, {30, 10}, {20, 10}, {10, 10}, {0, 10},
    {0, 0}, {10, 0}, {20, 0}, {30, 0}, {40, 0},

    // R Indicators
    {75, 65}, {65, 60}, {55, 55},
}, {
  // LED Index to Flag
  // Thumb = LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER
  5, 5, 5, 5, 5, 5,
  // Indicator = LED_FLAG_INDICATOR
  8, 8, 8,
  // Main keys
  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4,

  // R Main keys
  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4,

  // R Indicator = LED_FLAG_INDICATOR
  8, 8, 8,
} };

bool indicator_color(int index, int layer_from, int layer_to, int ticks)
{
    static const RGB layer_colors[] = {{RGB_OFF}, {0x00, 0x80, 0x00}, {0x80, 0x00, 0x00}, {0x00, 0x00, 0xFF}};
    const uint8_t stepTime = 4;
    uint8_t step = ticks / stepTime;
    uint8_t interp = step < index ? 0 : (step > index ? stepTime : ticks - step * stepTime);
    //interp = (interp * interp) / 8;
    RGB a = layer_colors[layer_from];
    RGB b = layer_colors[layer_to];
    RGB rgb;
    rgb.r = (a.r * (stepTime - interp) + b.r * interp) / stepTime;
    rgb.g = (a.g * (stepTime - interp) + b.g * interp) / stepTime;
    rgb.b = (a.b * (stepTime - interp) + b.b * interp) / stepTime;
    rgb_matrix_set_color(index + 6, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(70 - index, rgb.r, rgb.g, rgb.b);
    bool done = step >= 3;
    return done;
}

//
void rgb_matrix_indicators_kb(void) {
    /*
    if (layer_state & 2)
        rgb_matrix_set_color(6, RGB_GREEN);
    else
        rgb_matrix_set_color(6, RGB_OFF);
    if (layer_state & 4)
        rgb_matrix_set_color(7, RGB_RED);
    else
        rgb_matrix_set_color(7, RGB_OFF);
    if (layer_state & 8)
        rgb_matrix_set_color(8, RGB_BLUE);
    else
        rgb_matrix_set_color(8, RGB_OFF);
    */
    
    static uint8_t ticks = 0;
    static uint8_t old_layer = 0;
    static uint8_t last_layer = 0;
    uint8_t layer = get_highest_layer(layer_state);
    if (layer > 3) layer = 3;
    if (layer != last_layer)
    {
        old_layer = last_layer;
        ticks = 0;
    }
    last_layer = layer;
    indicator_color(0, old_layer, layer, ticks);
    indicator_color(1, old_layer, layer, ticks);
    if (!indicator_color(2, old_layer, layer, ticks))
        ++ticks;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 2:
    case 1:
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_test);
        break;
    default:
        //rgb_matrix_mode(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_test);
        break;
    }
  return state;
}

//float mysong[][2] = SONG(PREONIC_SOUND);
//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  PLAY_SONG(mysong);
//  return false;
//}

//void keyboard_post_init_user(void) {
//    rgb_matrix_mode(RGB_MATRIX_HUE_WAVE);
//}

typedef struct __attribute__((__packed__)) {
    uint16_t position;
    uint32_t bit;
} LogoAnim;

static uint32_t oled32_read(uint16_t line)
{
    oled_buffer_reader_t current = oled_read_raw(line);
    uint32_t result =  (uint32_t)current.current_element[0] << 0;
    result |= (uint32_t)current.current_element[128] << 8;
    result |= (uint32_t)current.current_element[256] << 16;
    result |= (uint32_t)current.current_element[384] << 24;
    return result;
}

static uint32_t oled32_read_ptr(const uint8_t* ptr, uint16_t line)
{
    ptr += line;
    uint32_t result =  (uint32_t)ptr[0] << 0;
    result |= (uint32_t)ptr[128] << 8;
    result |= (uint32_t)ptr[256] << 16;
    result |= (uint32_t)ptr[384] << 24;
    return result;
}

static void oled32_write(uint32_t bits, uint16_t line)
{
    if(line >= OLED_DISPLAY_WIDTH)
    {
        oled_clear();
        oled_invert(true);
        return;
    }

    oled_write_raw_byte((uint8_t)(bits >> 0), line + 0);
    oled_write_raw_byte((uint8_t)(bits >> 8), line + 128);
    oled_write_raw_byte((uint8_t)(bits >> 16), line + 256);
    oled_write_raw_byte((uint8_t)(bits >> 24), line + 384);
}

static const char PROGMEM logo[] = {
    0x08, 0x0c, 0x0c, 0x0c, 0x0c, 0x1c, 0x1c, 0x7c, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xe0, 0xe0, 
    0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x88, 0x08, 0x0c, 0x0c, 0x0c, 0x1c, 0x1c, 0xfc, 0xfc, 0xfc, 
    0xfc, 0xfc, 0xf8, 0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xc0, 0x00, 0x00, 0x80, 0x80, 
    0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x70, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0x1f, 0x07, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0xc0, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x20, 0xf0, 0xf8, 0xf8, 0xfc, 
    0xfe, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xe0, 0xc0, 0x20, 0x70, 0xf8, 0xf8, 0xfc, 0xfe, 0xfe, 
    0xff, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x20, 0x80, 0x80, 0x80, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xe0, 0xf0, 0xf8, 0xf8, 0xff, 0x7f, 0x3f, 0x1f, 0x1f, 0x03, 0x03, 0x03, 0x03, 
    0x07, 0x07, 0x0f, 0x3f, 0xff, 0xfe, 0xfc, 0xf8, 0xb0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 
    0xf8, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x70, 0xe0, 
    0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0x7e, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0d, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0x70, 0x3f, 0x0f, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x05, 0x0f, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0x03, 0x07, 0x07, 0x0f, 0x1f, 0xff, 0xfe, 0xfe, 0xfc, 0x38, 0x10, 0x10, 0x38, 
    0xf8, 0xfc, 0xfe, 0xff, 0xff, 0x07, 0x7f, 0xff, 0xff, 0xfe, 0xf8, 0xe0, 0xc0, 0x80, 0x00, 0x00, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x1f, 0x0f, 0x03, 0x00, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xe0, 
    0x70, 0x78, 0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x30, 0x3f, 0x3f, 0x7f, 0x7f, 
    0xff, 0xf8, 0x3c, 0x1c, 0x0e, 0x0e, 0x06, 0x06, 0x06, 0x00, 0x10, 0x3f, 0x3f, 0x7f, 0x7f, 0xff, 
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xff, 0xff, 0xff, 
    0x7f, 0x3f, 0x3f, 0x7c, 0x78, 0x78, 0xf8, 0xfe, 0x7f, 0x7f, 0x3f, 0x1f, 0x0e, 0x00, 0x10, 0x38, 
    0x3f, 0x7f, 0x7f, 0xff, 0xff, 0x7e, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x10, 
    0x3f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x1f, 
    0x1f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3c, 0x38, 0xf8, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x30, 0x20, 0x00
};

static uint16_t fill_line = 0;
static uint16_t active_anim = 0;
static uint16_t active_anims = 0;

#define ANIMS 4
static LogoAnim anim[ANIMS] = {};

static void logo_anim_pixel(void)
{
    if(active_anims < 4)
    {
        uint32_t mask = (uint32_t)1 << ((active_anim + active_anims) % 32);
        anim[(active_anim + active_anims) % ANIMS].position = 127;
        anim[(active_anim + active_anims) % ANIMS].bit = oled32_read_ptr((uint8_t*)logo, fill_line) & mask;
        active_anims++;
    }
}

static void render_logo(void) {
    //oled_write_raw_P(logo, sizeof(logo));

    for (uint16_t i = active_anim; i < active_anim + active_anims; ++i)
    {
        uint16_t anim_idx = i % ANIMS;
        if(anim[anim_idx].position > fill_line)
        {
            oled32_write(0, anim[anim_idx].position--);
            if (anim[anim_idx].position == fill_line) {
                oled32_write(oled32_read(fill_line) | anim[anim_idx].bit, fill_line);
                #if 1
                active_anim++;
                active_anims--;
                if(active_anim >= 32)
                {
                    active_anim -= 32;
                    i -= 32;
                    fill_line++;
                    if(fill_line >= 128)
                    {
                        oled_clear();
                        fill_line = 0;
                    }
                }
                #endif
            } else {
                oled32_write(anim[anim_idx].bit, anim[anim_idx].position);
            }
        }
        else
        {
            break;
        }
    }
}

static uint32_t info_timeout_start = 0;
bool info_timed_out = true;

extern int mydebug;
int mydebug = 0;

bool oled_task_user(void)
{
#if 0
    {
        char debug_str[12];
        itoa(mydebug, debug_str, 10);
        //oled_clear();
        oled_set_cursor(1, 1);
        oled_write_P(PSTR("Debug: "), false);
        oled_write_ln(debug_str, false);
        static int counter = 0;
        itoa(counter++, debug_str, 10);
        oled_set_cursor(1, 2);
        oled_write_P(PSTR("Counter:  "), false);
        oled_write_ln(debug_str, false);
        return false;
    }
#endif

    render_logo();

#if 0
    static int test = 0;
    if(test == 0)
        oled_clear();
    else
        oled32_write(oled32_read(test - 1)<<8, test-1);
    oled32_write((uint32_t)1 << (test % 32), test);
    test = (test + 1) % (128);
#endif

    return false;
/*
    uint32_t timer_now = timer_read32();
    bool timed_out = TIMER_DIFF_32(timer_now, info_timeout_start) > 10000;
    bool dirty = timed_out != info_timed_out;
    info_timed_out = timed_out;
    if (info_timed_out)
    {
        if (dirty)
            render_logo();
    }
    else
    {
        if (dirty)
            oled_clear();

        #ifdef DEBUG_MATRIX_SCAN_RATE
        char rate_str[12];
        itoa(get_matrix_scan_rate(), rate_str, 10);
        oled_set_cursor(1, 1);
        oled_write_P(PSTR("Scan: "), false);
        oled_write_ln(rate_str, false);
        itoa(get_rgb_matrix_display_rate(), rate_str, 10);
        oled_set_cursor(1, 2);
        oled_write_P(PSTR("RGB:  "), false);
        oled_write_ln(rate_str, false);
        #endif
    }
    return false;*/
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record)
{
    info_timeout_start = timer_read32();

    if (record->event.pressed)
        logo_anim_pixel();
}

// keyboards/sowbug/68keys/config.h
void suspend_power_down_kb(void)
{
    rgb_matrix_set_suspend_state(true);
}

// keyboards/sowbug/68keys/config.h
void suspend_wakeup_init_kb(void)
{
    rgb_matrix_set_suspend_state(false);
}