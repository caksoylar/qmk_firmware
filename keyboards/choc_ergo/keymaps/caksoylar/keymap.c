#include "choc_ergo.h"
#include "g/keymap_combo.h"

#include "caksoylar.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x5_2_wrapper(
        _________________QWERTY_L1_________________,      _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________,      _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________,      _________________QWERTY_R3_________________,
                          __DEF2_THUMB_L__,                        __DEF2_THUMB_R__
    ),
    [GME] = LAYOUT_split_3x5_2_wrapper(
        _________________QWERTY_L1_________________,      _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________,      _________________QWERTY_R2_________________,
        __________________GAM_L3___________________,      __________________GAM_R3___________________,
                          __GAM2_THUMB_L__,                        __DEF2_THUMB_R__
    ),
    [CLM] = LAYOUT_split_3x5_2_wrapper(
        ______________COLEMAK_MOD_DH_L1____________,      ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________,      ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________,      ______________COLEMAK_MOD_DH_R3____________,
                          __DEF2_THUMB_L__,                        __DEF2_THUMB_R__
    ),
    [SYM] = LAYOUT_split_3x5_2_wrapper(
        __________________SYM_L1___________________,      __________________SYM_R1___________________,
        __________________SYM_L2___________________,      __________________SYM_R2___________________,
        __________________SYM_L3___________________,      __________________SYM_R3___________________,
                          __LAY2_THUMB_L__,                        __LAY2_THUMB_R__
    ),
    [NAV] = LAYOUT_split_3x5_2_wrapper(
        __________________NAV_L1___________________,      __________________NAV_R1___________________,
        __________________NAV_L2___________________,      __________________NAV_R2___________________,
        __________________NAV_L3___________________,      __________________NAV_R3___________________,
                          __LAY2_THUMB_L__,                        __LAY2_THUMB_R__
    ),
    [FUN] = LAYOUT_split_3x5_2_wrapper(
        __________________FUN_L1___________________,      __________________FUN_R1___________________,
        __________________FUN_L2___________________,      __________________FUN_R2___________________,
        __________________FUN_L3___________________,      __________________FUN_R3___________________,
                          __FUN2_THUMB_L__,                        __FUN2_THUMB_R__
    )
};

#ifdef LAYER_LEDS
#define PRO_MICRO_LED_TX D5  // right pin
#define PRO_MICRO_LED_RX B0  // left pin

void matrix_init_keymap(void) {
    if (is_keyboard_left()) {
        setPinOutput(PRO_MICRO_LED_TX);  // write 1 for off, 0 for on
        setPinOutput(PRO_MICRO_LED_RX);
    }
}

layer_state_t layer_state_set_keymap(layer_state_t state) {
    if (is_keyboard_left()) {
        switch (get_highest_layer(state)) {
            case NAV:
                writePin(PRO_MICRO_LED_TX, 1);
                writePin(PRO_MICRO_LED_RX, 0);
                break;
            case SYM:
                writePin(PRO_MICRO_LED_TX, 0);
                writePin(PRO_MICRO_LED_RX, 1);
                break;
            case FUN:
                writePin(PRO_MICRO_LED_TX, 0);
                writePin(PRO_MICRO_LED_RX, 0);
                break;
            default:
                writePin(PRO_MICRO_LED_TX, 1);
                writePin(PRO_MICRO_LED_RX, 1);
        }
    }
    return state;
}
#endif
