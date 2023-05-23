#include "keycodes.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
        /*
         * Base layer
         */
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T, /*|*/ KC_Y, KC_U,         KC_I,         KC_O,         KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, /*|*/ KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B, /*|*/ KC_N, KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
              MO(1), KC_TAB, KC_SPC, MO(2)
    ),
    [1] = LAYOUT_split_3x5_2(
        /*
         * Numpad layer
         */
        KC_ESC,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          /*|*/           KC_NO, KC_7, KC_8, KC_9, KC_BSPC,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ESC,          /*|*/           KC_BSPC, KC_4, KC_5, KC_6, KC_ENTER,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          /*|*/           KC_0,  KC_1, KC_2, KC_3, KC_DEL,
                                    KC_NO, KC_TAB,          /*|*/           KC_SPC, MO(3)
    ),
    [2] = LAYOUT_split_3x5_2(
        /*
         * Symbols layer
         */
        KC_ESC, KC_LBRC, KC_RBRC, RSFT(KC_4), RSFT(KC_5), /*|*/     RSFT(KC_6), RSFT(KC_7), KC_KP_ASTERISK, KC_QUOTE, KC_BSPC,

        RSFT(KC_LBRC), RSFT(KC_9), RSFT(KC_0), RSFT(KC_RBRC), KC_EQL,
                        /*|*/ KC_KP_PLUS, KC_MINUS, RSFT(KC_COMMA), RSFT(KC_DOT), RSFT(KC_QUOTE),

        RSFT(KC_GRV), KC_GRV, RSFT(KC_BACKSLASH), RSFT(KC_MINUS), KC_SLASH,
                        /*|*/ KC_BACKSLASH, RSFT(KC_2), RSFT(KC_3), RSFT(KC_1), RSFT(KC_SLASH),

                           MO(3), KC_TAB,          /*|*/           KC_SPC, KC_NO
    ),

    [3] = LAYOUT_split_3x5_2(
        /*
         * Navigation layer
         */
        KC_ESC,   KC_NO,   KC_NO,   KC_NO,   MO(4),          /*|*/          KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSPC,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ESC,          /*|*/          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_ENTER,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   MO(5),          /*|*/           KC_TAB,  KC_PRINT_SCREEN, KC_INSERT, KC_PAUSE, KC_DEL,
                                    KC_NO, KC_NO,          /*|*/            KC_NO, KC_NO
    ),
    [4] = LAYOUT_split_3x5_2(
        /*
         * Function
         */
        KC_ESC,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          /*|*/         KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ESC,          /*|*/         KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          /*|*/          KC_F11, KC_F12, KC_SCROLL_LOCK, KC_NO, KC_NO,
                                    KC_NO, KC_NO,          /*|*/           KC_NO, KC_NO
    ),
        [5] = LAYOUT_split_3x5_2(
        /*
         * Media/Config layer
         */
        QK_BOOT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        /*|*/          KC_MEDIA_STOP, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_NO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ESC,         /*|*/          KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          /*|*/          KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO,
                                    KC_NO, KC_NO,          /*|*/           KC_NO, KC_NO
    ),
};




