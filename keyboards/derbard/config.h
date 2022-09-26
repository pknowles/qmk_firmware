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

#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

// keyboards/sowbug/68keys/config.h
// https://www.reddit.com/r/olkb/comments/sbvefp/has_anyone_gotten_qmk_rgb_matrix_effects_working/
// Seems very important but not mentioned in the docs!!
#define RGBLED_NUM 37
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_DI_PIN D7
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 64
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON
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
