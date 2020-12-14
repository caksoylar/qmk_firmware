#include "gergoplex.h"
#include "g/keymap_combo.h"

enum layers {
    _BASE,
    _GAME,
    _EXTR,
    _FUNC
};

enum my_keycodes {
    TG_CLMK = SAFE_RANGE,
};

// shortcut definitions
#define CTL_ESC CTL_T(KC_ESC)
#define ALT_BSP RALT_T(KC_BSPC)
#define GUI_TAB GUI_T(KC_TAB)
#define EXT_SPC LT(_EXTR, KC_SPC)
#define EXT_BSP LT(_EXTR, KC_BSPC)
#define SFT_ENT SFT_T(KC_ENT)
#define FUN_DEL LT(_FUNC, KC_DEL)
#define SFT_Z   SFT_T(KC_Z)
#define SFT_INS LSFT(KC_INS)
#define CG_LT   LCTL(LGUI(KC_LEFT))
#define CG_RT   LCTL(LGUI(KC_RGHT))
#define TG_GAME TG(_GAME)

    /* Combomap
     *
     * ,-----------------------------.      ,-----------------------------.
     * |    GRV    |     |     |     |      |     |    QUOT   |     |     |
     * |-----+--q----TAB----p--+-----|      |-----+--q----BSPC---p--+-----|
     * |     |    LBRC  LPRN   |     |      |     |    RPRN  RBRC  BSLS   |
     * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
     * |     |    UNDS  MINS   |     |      |     |    EQL   PLUS   |     |
     * `-----------------------------'      `-----------------------------'
     *          .-----------------.            .-----------------.
     *          |     |     |     |            |     |     |     |
     *          '-----------------'            '-----------------'
     */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN,
        SFT_Z,   KC_X,    KC_C,    KC_V,    KC_B,         KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                 GUI_TAB, CTL_ESC, ALT_BSP,                       EXT_SPC, SFT_ENT, FUN_DEL
    ),
    [_GAME] = LAYOUT_split_3x5_3(
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        KC_Z,    _______, _______, _______, _______,      _______, _______, _______, _______, _______,
                 KC_TAB,  KC_LCTL, KC_SPC,                         EXT_BSP, _______, _______
    ),
    [_EXTR] = LAYOUT_split_3x5_3(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP,
        KC_LSFT, KC_CIRC, KC_AMPR, KC_ASTR, SFT_INS,      KC_INS,  KC_DEL,  KC_HOME, KC_END,  KC_PGDN,
                 KC_LGUI, KC_LCTL, KC_LALT,                        _______, _______, _______
    ),
    [_FUNC] = LAYOUT_split_3x5_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,  TG_CLMK,       KC_MPRV, KC_MNXT, KC_P7,    KC_P8,    KC_P9,
        KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_CALC,       KC_VOLU, KC_MUTE, KC_P4,    KC_P5,    KC_P6,
        KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_PAUS,       KC_VOLD, KC_P0,   KC_P1,    KC_P2,    KC_P3,
                 TG_GAME, CG_LT,   CG_RT,                          KC_MPLY, KC_NLCK, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool alternate_base = false;
    static const uint8_t colemak_dh[] = {KC_A, KC_V, KC_C, KC_S, KC_F, KC_T, KC_G,
                                         KC_M, KC_U, KC_N, KC_E, KC_I, KC_H, KC_K,
                                         KC_Y, KC_SCLN, KC_Q, KC_P, KC_R, KC_B, KC_L,
                                         KC_D, KC_W, KC_X, KC_J, KC_Z};
    if (alternate_base) {
        switch (keycode) {
            case KC_A ... KC_Z:
                record->event.pressed ? register_code(colemak_dh[keycode - KC_A]) : unregister_code(colemak_dh[keycode - KC_A]);
                return false;
            case KC_SCLN:
                record->event.pressed ? register_code(KC_O) : unregister_code(KC_O);
                return false;
            case TG_CLMK:
                if (record->event.pressed) alternate_base = false;
                return false;
        }
        return true;
    }
    if (keycode == TG_CLMK) {
        if (record->event.pressed) alternate_base = true;
        return false;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BASE:
            combo_enable();
            break;
        default:
            combo_disable();
            break;
    }
    return state;
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_ENT:
        case SFT_Z:
        case EXT_SPC:
            return true;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_Z:
        case EXT_SPC:
            return true;
        default:
            return false;
    }
}
