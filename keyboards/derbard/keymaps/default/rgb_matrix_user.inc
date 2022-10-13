
// !!! DO NOT ADD #pragma once !!! //
RGB_MATRIX_EFFECT(layer1)
RGB_MATRIX_EFFECT(test)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool layer1(effect_params_t* params) {
    static uint8_t ticks;
    static uint8_t layer_from = 0;
    static const RGB layer_colors[] = {{RGB_OFF}, {RGB_GREEN}, {RGB_RED}};
    uint8_t layer_to = get_highest_layer(layer_state);
    if (params->init) ticks = 0;
    uint8_t step = ticks / 30;
    ++ticks;
    bool done = step >= 3;
    //RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (int i = 0; i < 3; ++i)
    {

        RGB col = layer_colors[i < step + 1 ? layer_from : layer_to];
        rgb_matrix_set_color(6 + i, col.r, col.g, col.b);
    }
    if (done) layer_from = layer_to;
    return done;
}

static bool test(effect_params_t* params) {
    static uint8_t ticks = 0;
    HSV hsv = {ticks++, 255, RGB_MATRIX_MAXIMUM_BRIGHTNESS};
    RGB rgb = hsv_to_rgb(hsv);
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return false;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
