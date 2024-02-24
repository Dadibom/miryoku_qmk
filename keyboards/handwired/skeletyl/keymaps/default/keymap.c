// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(
        KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,   KC_J,  KC_L,   KC_U,   KC_Y,   KC_QUOT,
        KC_A,   KC_R,   KC_S,   KC_T,   KC_G,   KC_M,  KC_N,   KC_E,   KC_I,   KC_O,
        KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   KC_K,  KC_H,   KC_COMM,KC_DOT, KC_SLSH,
                    KC_ESC, KC_SPACE, KC_TAB,  KC_ENT,KC_BSPC, KC_DEL
    )
};

void keyboard_pre_init_user(void) {
    setPinOutput(B0);  // initialize B0 for LED
    setPinOutput(B1);  // initialize B1 for LED
}

// define led pins constants
#define RX 17
#define TX 30

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case TAP:
            writePinHigh(RX);
            writePinLow(TX);
            break;
        case EXTRA:
            writePinHigh(TX);
            writePinLow(RX);
            break;
        default:
            writePinLow(RX);
            writePinLow(TX);
            break;
    }
}
