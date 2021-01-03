#include "gergoplex.h"

#define OS_CTRL OSM(MOD_LCTL)
#define OS_SHFT OSM(MOD_LSFT)
#define OS_ALT  OSM(MOD_LALT)
#define OS_GUI  OSM(MOD_LGUI)

#define CG_LT LCTL(LGUI(KC_LEFT))
#define CG_RT LCTL(LGUI(KC_RGHT))

#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)

enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
};

enum keycodes {
    SW_WIN = SAFE_RANGE,  // Switch to next window (alt-tab)
    SW_WINP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                          XXXXXXX, LA_NAV,  KC_BSPC, KC_SPC,  LA_SYM, XXXXXXX
    ),

    [SYM] = LAYOUT_split_3x5_3(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_ESC,  KC_MINS, KC_EQL,  KC_UNDS, KC_PLUS, XXXXXXX, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,
        KC_GRV,  KC_TILD, KC_BSLS, KC_PIPE, KC_QUOT, KC_DQUO, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,
                          XXXXXXX, _______, _______, _______, _______, XXXXXXX
    ),

    [NAV] = LAYOUT_split_3x5_3(
        KC_TAB,  SW_WINP, SW_WIN,  KC_CALC, KC_VOLU, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,
        OS_GUI,  OS_ALT,  OS_CTRL, OS_SHFT, KC_VOLD, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        CG_LT,   CG_RT,   KC_MPRV, KC_MNXT, KC_MPLY, KC_INS,  RESET,   KC_CAPS, XXXXXXX, KC_BSPC,
                          XXXXXXX, _______, _______, _______, _______, XXXXXXX
    ),

    [NUM] = LAYOUT_split_3x5_3(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        OS_GUI,  OS_ALT,  OS_CTRL, OS_SHFT, KC_F11,  KC_F12,  OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
                          XXXXXXX, _______, _______, _______, _______, XXXXXXX
    ),
};

bool sw_active = false;

void update_swapper(bool *active,
                    uint16_t cmdish,
                    uint16_t tabish1,
                    uint16_t tabish2,
                    uint16_t trigger1,
                    uint16_t trigger2,
                    uint16_t keycode,
                    keyrecord_t *record) {
    if (keycode == trigger1 || keycode == trigger2) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code16(cmdish);
            }
            register_code16(keycode == trigger1 ? tabish1 : tabish2);
        } else {
            unregister_code16(keycode == trigger1 ? tabish1 : tabish2);
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (*active) {
        unregister_code16(cmdish);
        *active = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(&sw_active, KC_LALT, KC_TAB, LSFT(KC_TAB), SW_WIN, SW_WINP, keycode, record);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}
