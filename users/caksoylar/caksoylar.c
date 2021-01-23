#include "caksoylar.h"

void update_swapper(bool *active, uint16_t hold_key, uint16_t trigger1, uint16_t tap_key1, uint16_t trigger2, uint16_t tap_key2, uint16_t keycode, bool pressed) {
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

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) { keyboard_post_init_keymap(); }

__attribute__((weak)) void matrix_scan_keymap(void) {}

void matrix_scan_user(void) { matrix_scan_keymap(); }

__attribute__((weak)) void eeconfig_init_keymap(void) {}

void eeconfig_init_user(void) { eeconfig_init_keymap(); }

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool win_active = false;
    update_swapper(&win_active, KC_LALT, WIN_RT, KC_TAB, WIN_LT, S(KC_TAB), keycode, record->event.pressed);

    if (keycode == TG_CLMK && record->event.pressed) {
        switch (get_highest_layer(default_layer_state)) {
            case DEF:
                set_single_persistent_default_layer(CLM);
                break;
            case CLM:
                set_single_persistent_default_layer(DEF);
                break;
        }
        return false;
    }
    return process_record_keymap(keycode, record);
}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case DEF:
        case CLM:
            combo_enable();
            break;
        default:
            combo_disable();
            break;
    }
    state = update_tri_layer_state(state, SYM, NAV, FUN);
    return layer_state_set_keymap(state);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_Z:
        case GUI_X:
        case ALT_C:
        case CTL_SLS:
        case GUI_DOT:
        case ALT_COM:
        case CTL_PEN:
        case GUI_P3:
        case ALT_P2:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
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
