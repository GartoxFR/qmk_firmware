#include "action_layer.h"
#include "keycodes.h"
#include "quantum/keycode.h"
#include "quantum/quantum_keycodes.h"
#include "users/callum/oneshot.h"
#include "specials.h"

#include QMK_KEYBOARD_H

enum Layers {
    BASE,
    NUM,
    SYM,
    NAV,
    FN,
    MEDIA,
    SPC,
    LOL,
    LOL_FN,
    GAME,
    GAME_FN,
    FACTORIO,
    FACTORIO_FN,
    OSU,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_2(
        /*
         * Base layer
         */
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T, /*|*/ KC_Y, KC_U,         KC_I,         KC_O,         KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, /*|*/ KC_H, RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN),
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B, /*|*/ KC_N, KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
              KC_TAB, MO(NUM), MO(SYM), KC_SPC
    ),
    [NUM] = LAYOUT_split_3x5_2(
        /*
         * Numpad layer
         */
        KC_ESC,   KC_NO,   KC_NO,   OSL(SPC),   KC_NO,          /*|*/           KC_NO, KC_7, KC_8, KC_9, KC_BSPC,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ESC,          /*|*/           KC_BSPC, KC_4, KC_5, KC_6, KC_ENTER,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TAB,          /*|*/           KC_0,  KC_1, KC_2, KC_3, KC_DEL,
                                    KC_NO, KC_NO,          /*|*/             _______, KC_SPC
    ),
    [SYM] = LAYOUT_split_3x5_2(
        /*
         * Symbols layer
         */
        CW_TOGG, KC_LBRC, KC_RBRC, KC_DLR, KC_PERC, /*|*/     RSFT(KC_6), RSFT(KC_7), KC_KP_ASTERISK, KC_QUOTE, KC_BSPC,

        KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_EQL,
                        /*|*/ KC_KP_PLUS, KC_MINUS, RSFT(KC_COMMA), RSFT(KC_DOT), RSFT(KC_QUOTE),

        RSFT(KC_GRV), KC_GRV, RSFT(KC_BACKSLASH), KC_UNDS, KC_SLASH,
                        /*|*/ KC_BACKSLASH, RSFT(KC_2), RSFT(KC_3), RSFT(KC_1), RSFT(KC_SLASH),

                           KC_TAB, _______,          /*|*/           KC_NO, KC_NO
    ),

    [NAV] = LAYOUT_split_3x5_2(
        /*
         * Navigation layer
         */
        KC_ESC,   UC_NEXT,   KC_NO,   KC_NO,   MO(FN),          /*|*/          KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSPC,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ESC,          /*|*/          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_ENTER,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   MO(MEDIA),          /*|*/           KC_TAB,  KC_PRINT_SCREEN, KC_INSERT, KC_PAUSE, KC_DEL,
                                    KC_NO, KC_NO,          /*|*/            KC_NO, KC_NO
    ),
    [FN] = LAYOUT_split_3x5_2(
        /*
         * Function
         */
        KC_ESC,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          /*|*/         KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ESC,          /*|*/         KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          /*|*/          KC_F11, KC_F12, KC_SCROLL_LOCK, KC_NO, KC_NO,
                                    KC_NO, KC_NO,          /*|*/           KC_NO, KC_NO
    ),
        [MEDIA] = LAYOUT_split_3x5_2(
        /*
         * Media/Config layer
         */
        QK_BOOT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        /*|*/          KC_MEDIA_STOP, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_NO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ESC,         /*|*/          KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO,
        DF(OSU),   DF(FACTORIO),   DF(GAME),   DF(LOL),   KC_NO,          /*|*/          KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO,
                                    KC_NO, KC_NO,          /*|*/           KC_NO, KC_NO
    ),
        [SPC] = LAYOUT_split_3x5_2(
            XP(AE1,AE2),XP(EA1,EA2),XP(EG1,EG2),X(RGSTD),   X(TM),      X(YEN),     XP(UG1,UG2),XP(IT1,IT2),XP(OE1,OE2),X(POUND),
            XP(AG1,AG2),XP(ET1,ET2),XP(EC1,EC2),X(EURO),    X(LAQOT),   X(RAQOT),   XP(UC1,UC2),XP(IC1,IC2),XP(OC1,OC2),X(IQEST),
            XP(AC1,AC2),X(CROSS),   XP(CC1,CC2),X(CPYRT),   X(DEG),     XP(NT1,NT2),X(MU),      X(MDOT),    X(ELIPS),   XXXXXXX,
                                            _______,    X(NBSPC),   KC_RSFT,    _______
        ),
        [LOL] = LAYOUT_split_3x5_2(
        /*
         * Media/Config layer
         */
        KC_ESC,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_P,        /*|*/          KC_1,  KC_2, KC_3, KC_4, KC_5,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         /*|*/          KC_O, KC_Q, KC_W, KC_E, KC_R,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,          /*|*/          KC_S, KC_A, KC_D, KC_F, KC_LEFT_SHIFT,
                                    XXXXXXX, XXXXXXX,          /*|*/           MO(LOL_FN), KC_SPC
    ),
        [LOL_FN] = LAYOUT_split_3x5_2(
        /*
         * Media/Config layer
         */
        _______,   _______,   _______,   _______,   _______,        /*|*/          KC_P,  LCTL(KC_Q), LCTL(KC_W), LCTL(KC_E), LCTL(KC_R),
        _______, _______, _______, _______, _______,         /*|*/          KC_LCTL, LALT(KC_Q), LALT(KC_W), LALT(KC_E), LALT(KC_R),
        _______,   _______,   _______,   _______,   _______,          /*|*/          KC_B, KC_F1,KC_F2, KC_F3,KC_F4,
                                    _______, DF(BASE),          /*|*/           _______, _______
    ),
        [GAME] = LAYOUT_split_3x5_2(
        /*
         * Media/Config layer
         */
        KC_ESC,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_P,        /*|*/          KC_1,  KC_2, KC_3, KC_4, KC_5,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         /*|*/          KC_R, KC_A, KC_W, KC_D, KC_RIGHT_SHIFT,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,          /*|*/          KC_C, KC_Q, KC_S, KC_E, KC_LEFT_CTRL,
                                    XXXXXXX, DF(BASE),          /*|*/           MO(GAME_FN), KC_SPC
    ),
        [GAME_FN] = LAYOUT_split_3x5_2(
        /*
         * Media/Config layer
         */
        KC_ESC,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_P,        /*|*/          KC_6,  KC_7, KC_8, KC_9, KC_0,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         /*|*/          KC_T, KC_I, KC_L, KC_U, KC_LEFT_SHIFT,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,          /*|*/          KC_H, KC_G, KC_M, KC_O, KC_RIGHT_CTRL,
                                    XXXXXXX, DF(BASE),          /*|*/           KC_F, KC_SPC
    ),
        [FACTORIO] = LAYOUT_split_3x5_2(
        /*
         * Media/Config layer
         */
        KC_ESC,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_T,        /*|*/          KC_1,  KC_2, KC_3, KC_4, KC_5,
        KC_ENTER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         /*|*/          KC_R, KC_A, KC_W, KC_D, KC_RIGHT_SHIFT,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,          /*|*/          KC_C, KC_Q, KC_S, KC_E, KC_LEFT_CTRL,
                                    KC_TAB, XXXXXXX,          /*|*/           MO(FACTORIO_FN), KC_SPC
    ),
        [FACTORIO_FN] = LAYOUT_split_3x5_2(
        /*
         * Media/Config layer
         */
        KC_ESC,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_T,        /*|*/          KC_6,  KC_7, KC_8, KC_9, KC_0,
        KC_ENTER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         /*|*/          LCTL(KC_X), _______, _______, _______, KC_RIGHT_SHIFT,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,          /*|*/          KC_T, LCTL(KC_C), LCTL(KC_V), KC_B, LCTL(KC_Z),
                                    KC_TAB, DF(BASE),          /*|*/           XXXXXXX, KC_SPC
    ),
        [OSU] = LAYOUT_split_3x5_2(
            /*
             * Osu!
             */
            KC_ESC,         KC_W,         KC_E,         KC_R,         KC_T, /*|*/ KC_F1, KC_F2,         KC_F3,         KC_F4,         KC_F5,
            KC_A, KC_S, KC_D, KC_F, KC_G, /*|*/ KC_H, KC_J, KC_K, KC_L, KC_SCLN,
            KC_Z,         KC_X,         KC_C,         KC_V,         KC_B, /*|*/ KC_N, KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                  KC_TAB, DF(BASE), DF(BASE), KC_SPC
        ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, NUM, SYM, NAV);
}

