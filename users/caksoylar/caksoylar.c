#include "caksoylar.h"

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

__attribute__((weak)) void matrix_init_keymap(void) {}

void matrix_init_user(void) { matrix_init_keymap(); }

__attribute__((weak))
void keyboard_post_init_keymap(void){ }

void keyboard_post_init_user(void){
    userspace_config.raw = eeconfig_read_user();
    keyboard_post_init_keymap();
}

__attribute__((weak)) void matrix_scan_keymap(void) {}

void matrix_scan_user(void) { matrix_scan_keymap(); }

__attribute__ ((weak))
void eeconfig_init_keymap(void) {}

void eeconfig_init_user(void) {
    userspace_config.raw = 0;
    userspace_config.alternate_base = false;
    eeconfig_init_keymap();
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static const uint8_t colemak_dh[] = {KC_A, KC_V, KC_C, KC_S, KC_F, KC_T, KC_G,
                                         KC_M, KC_U, KC_N, KC_E, KC_I, KC_H, KC_K,
                                         KC_Y, KC_QUOT, KC_Q, KC_P, KC_R, KC_B, KC_L,
                                         KC_D, KC_W, KC_X, KC_J, KC_Z};
    static bool win_active = false;

    update_swapper(&win_active, KC_LALT, WIN_RT, KC_TAB, WIN_LT, S(KC_TAB), keycode, record->event.pressed);

    if (userspace_config.alternate_base) {
        switch (keycode) {
            case KC_A ... KC_Z:
                record->event.pressed ? register_code(colemak_dh[keycode - KC_A]) : unregister_code(colemak_dh[keycode - KC_A]);
                return false;
            case KC_QUOT:
                record->event.pressed ? register_code(KC_O) : unregister_code(KC_O);
                return false;
            case TG_CLMK:
                if (record->event.pressed) {
                    userspace_config.alternate_base = false;
                    eeconfig_update_user(userspace_config.raw);
                }
                return false;
        }
        return true;
    }
    if (keycode == TG_CLMK) {
        if (record->event.pressed) {
            userspace_config.alternate_base = true;
            eeconfig_update_user(userspace_config.raw);
        }
        return false;
    }
    return process_record_keymap(keycode, record);
}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_keyboard_master()) {
        switch (get_highest_layer(state)) {
            case DEF:
                combo_enable();
                break;
            default:
                combo_disable();
                break;
        }
    }
    state = update_tri_layer_state(state, SYM, NAV, FUN);
    return layer_state_set_keymap(state);
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_TAB:
        case CTL_ESC:
        case NAV_BSP:
        case SYM_SPC:
        case SFT_ENT:
        case ALT_DEL:
            return true;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV_BSP:
        case SYM_SPC:
            return true;
        default:
            return false;
    }
}
