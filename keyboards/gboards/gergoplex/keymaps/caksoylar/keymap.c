#include "gergoplex.h"
#include "g/keymap_combo.h"

#include "caksoylar.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,   KC_J,    KC_K,    KC_L,    KC_QUOT,
        SFT_Z,   GUI_X,   ALT_C,   KC_V,    KC_B,         KC_N,   KC_M,    ALT_COM, GUI_DOT, CTL_SLS,
                 GUI_TAB, CTL_ESC, NAV_BSP,                       SYM_SPC, SFT_ENT, ALT_DEL
    ),
    [GME] = LAYOUT_split_3x5_3(
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        KC_Z,    KC_X,    KC_C,    _______, _______,      _______, _______, _______, _______, _______,
                 KC_TAB,  KC_LCTL, KC_SPC,                         _______, _______, TG_GAME
    ),
    [SYM] = LAYOUT_split_3x5_3(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS,
        KC_LSFT, KC_LGUI, KC_RALT, KC_SCLN, KC_AMPR,      KC_ASTR, KC_BSLS, KC_LALT, KC_LGUI, KC_LSFT,
                 KC_LGUI, KC_LCTL, _______,                        _______, KC_LSFT, KC_RALT
    ),
    [NAV] = LAYOUT_split_3x5_3(
        ALT_F4,  TAB_LT,  TAB_RT,  CTL_F4,  KC_VOLU,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CALC,
        DSK_LT,  WIN_LT,  WIN_RT,  DSK_RT,  KC_VOLD,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PAUS,
        KC_LCTL, KC_LGUI, KC_LALT, SFT_INS, XXXXXXX,      KC_INS,  KC_DEL,  KC_MPLY, KC_MPRV, KC_MNXT,
                 KC_LGUI, KC_LCTL, _______,                        _______, KC_LSFT, KC_RALT
    ),
    [FUN] = LAYOUT_split_3x5_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_CAPS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,       KC_NLCK, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT, KC_LGUI, KC_LALT, KC_F11,  KC_F12,       KC_P0,   KC_P1,   ALT_P2,  GUI_P3,  CTL_PEN,
                 KC_LGUI, TG_GAME, _______,                        _______, TG_CLMK, KC_RALT
    )
};
