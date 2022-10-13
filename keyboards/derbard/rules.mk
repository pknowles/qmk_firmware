# This file intentionally left blank

# https://www.reddit.com/r/olkb/comments/sbvefp/has_anyone_gotten_qmk_rgb_matrix_effects_working/
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
CIE1931_CURVE = yes
RGB_MATRIX_CUSTOM_USER = yes

# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
LTO_ENABLE = yes
CFLAGS += -ffunction-sections -fdata-sections -fauto-inc-dec -fcompare-elim -fcprop-registers -fdce
CXXFLAGS += -ffunction-sections -fdata-sections -fauto-inc-dec -fcompare-elim -fcprop-registers -fdce -fssa-dce
LDFLAGS += -ffunction-sections -fdata-sections -Wl,--gc-sections

# TODO
# keyboards/ergodox_ez/matrix.c
#SRC += matrix.c
