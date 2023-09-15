# DerBard

![derbard](https://img.heuristic42.com/img/63ca4e6ab5e4.jpg)

An ergonomic split 65 key keyboard with inbuilt palmrests, backwards tilt and
per-key RGB lighting.

Blog post: https://www.heuristic42.com/blog/55/derbard-custom-split-mechanical-keyboard-prototype/

Print files: [Thingiverse](https://www.thingiverse.com/thing:6219499)

* Keyboard Maintainer: [Pyarelal Knowles](https://github.com/pknowles)
* Hardware Supported: Arduino ATmega32u4 (Tested with Elite-C V4 board), NeoKey PCBs, WS2812 LEDs, MCP23017 GPIO expander, SSD1306 128x32 display
* Hardware Availability: *TODO: Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make derbard:default

Flashing example for this keyboard:

    make derbard:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: Briefly press the button on the back of the PCB
* **Keycode in layout**: Hold bottom right key, then press top right key on the right half of the board. See `RESET` in `keymap.c`.
