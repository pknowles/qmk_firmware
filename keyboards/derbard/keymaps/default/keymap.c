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