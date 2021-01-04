#include "gergoplex.h"
#include "g/keymap_combo.h"

enum layers {
    DEF,
    GME,
    SYM,
    NAV,
    FUN
};

enum my_keycodes {
    TG_CLMK = SAFE_RANGE,
    WIN_RT,
    WIN_LT
};

// macros to prettify keymap
#define CTL_ESC CTL_T(KC_ESC)
#define SYM_BSP LT(SYM, KC_BSPC)
#define NAV_SPC LT(NAV, KC_SPC)

#define SFT_ENT SFT_T(KC_ENT)
#define SFT_Z   SFT_T(KC_Z)
#define GUI_X   GUI_T(KC_X)
#define ALT_C   RALT_T(KC_C)
#define CTL_SLS CTL_T(KC_SLSH)
#define GUI_DOT GUI_T(KC_DOT)
#define ALT_COM LALT_T(KC_COMM)
#define CTL_PEN CTL_T(KC_PENT)
#define GUI_P3  GUI_T(KC_P3)
#define ALT_P2  LALT_T(KC_P2)

#define ALT_F4  LALT(KC_F4)
#define CTL_F4  LCTL(KC_F4)
#define DSK_LT  LCTL(LGUI(KC_LEFT))
#define DSK_RT  LCTL(LGUI(KC_RGHT))
#define SFT_INS LSFT(KC_INS)

#define TG_GAME TG(GME)
#define GUI_TAB GUI_T(KC_TAB)
#define ALT_DEL RALT_T(KC_DEL)

    /* Combomap
     *
     * ,-----------------------------.      ,-----------------------------.
     * |    GRV    |     |     |     |      |     |    SCLN   |     |     |
     * |-----+--q----TAB----p--+-----|      |-----+--q----BSPC---p--+-----|
     * |     |    LBRC  LPRN   |     |      |     |    RPRN  RBRC  BSLS   |
     * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
     * |     |     |     |     |     |      |     |     |     |     |     |
     * `-----------------------------'      `-----------------------------'
     *          .-----------------.            .-----------------.
     *          |     |     |     |            |     |     |     |
     *          '-----------------'            '-----------------'
     */

typedef union {
    uint32_t raw;
    struct {
        bool alternate_base :1;
    };
} user_config_t;

user_config_t user_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,   KC_J,    KC_K,    KC_L,    KC_QUOT,
        SFT_Z,   GUI_X,   ALT_C,   KC_V,    KC_B,         KC_N,   KC_M,    ALT_COM, GUI_DOT, CTL_SLS,
                 GUI_TAB, CTL_ESC, SYM_BSP,                       NAV_SPC, SFT_ENT, ALT_DEL
    ),
    [GME] = LAYOUT_split_3x5_3(
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        KC_Z,    KC_X,    KC_C,    _______, _______,      _______, _______, _______, _______, _______,
                 KC_TAB,  KC_LCTL, KC_SPC,                         _______, _______, _______
    ),
    [SYM] = LAYOUT_split_3x5_3(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS,
        KC_LSFT, KC_LGUI, KC_RALT, KC_SCLN, KC_AMPR,      KC_ASTR, KC_BSLS, KC_LALT, KC_LGUI, KC_LCTL,
                 KC_LGUI, KC_LCTL, _______,                        _______, KC_LSFT, KC_RALT
    ),
    [NAV] = LAYOUT_split_3x5_3(
        ALT_F4,  CTL_F4,  KC_MPRV, KC_MNXT, KC_VOLU,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CALC,
        DSK_LT,  WIN_LT,  WIN_RT,  DSK_RT,  KC_VOLD,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PAUS,
        KC_LSFT, KC_LGUI, KC_LALT, SFT_INS, KC_MPLY,      KC_INS,  KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_LGUI, KC_LCTL, _______,                        _______, KC_LSFT, KC_RALT
    ),
    [FUN] = LAYOUT_split_3x5_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_CAPS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,       KC_NLCK, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT, KC_LGUI, KC_LALT, KC_F11,  KC_F12,       KC_P0,   KC_P1,   ALT_P2,  GUI_P3,  CTL_PEN,
                 KC_LGUI, TG_GAME, _______,                        _______, TG_CLMK, KC_RALT
    )
};

void update_swapper(bool *active,
                    uint16_t hold_key,
                    uint16_t trigger1,
                    uint16_t tap_key1,
                    uint16_t trigger2,
                    uint16_t tap_key2,
                    uint16_t keycode,
                    bool pressed) {
    if (keycode == trigger1 || keycode == trigger2) {
        if (pressed) {
            if (!*active) {
                *active = true;
                register_code16(hold_key);
            }
            register_code16(keycode == trigger1 ? tap_key1 : tap_key2);
        } else {
            unregister_code16(keycode == trigger1 ? tap_key1 : tap_key2);
            // Don't unregister hold_key until some other key is hit or released
        }
    } else if (*active) {
        unregister_code16(hold_key);
        *active = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static const uint8_t colemak_dh[] = {KC_A, KC_V, KC_C, KC_S, KC_F, KC_T, KC_G,
                                         KC_M, KC_U, KC_N, KC_E, KC_I, KC_H, KC_K,
                                         KC_Y, KC_QUOT, KC_Q, KC_P, KC_R, KC_B, KC_L,
                                         KC_D, KC_W, KC_X, KC_J, KC_Z};
    static bool sw_active = false;

    update_swapper(&sw_active, KC_LALT, WIN_RT, KC_TAB, WIN_LT, LSFT(KC_TAB), keycode, record->event.pressed);

    if (user_config.alternate_base) {
        switch (keycode) {
            case KC_A ... KC_Z:
                record->event.pressed ? register_code(colemak_dh[keycode - KC_A]) : unregister_code(colemak_dh[keycode - KC_A]);
                return false;
            case KC_QUOT:
                record->event.pressed ? register_code(KC_O) : unregister_code(KC_O);
                return false;
            case TG_CLMK:
                if (record->event.pressed) {
                    user_config.alternate_base = false;
                    eeconfig_update_user(user_config.raw);
                }
                return false;
        }
        return true;
    }
    if (keycode == TG_CLMK) {
        if (record->event.pressed) {
            user_config.alternate_base = true;
            eeconfig_update_user(user_config.raw);
        }
        return false;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case DEF:
            combo_enable();
            break;
        default:
            combo_disable();
            break;
    }
    return update_tri_layer_state(state, SYM, NAV, FUN);
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    return true;
    /*switch (keycode) {
        case SFT_ENT:
        case NAV_SPC:
        case SYM_BSP:
        case SFT_Z:
        case CTL_SLS:
        case GUI_X:
        case GUI_DOT:
        case ALT_C:
        case ALT_COM:
            return true;
        default:
            return false;
    }*/
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SYM_BSP:
        case NAV_SPC:
            return true;
        default:
            return false;
    }
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.alternate_base = false;
    eeconfig_update_user(user_config.raw);
}
