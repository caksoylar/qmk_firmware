#pragma once
#include QMK_KEYBOARD_H

#include "wrappers.h"

enum layers {
    DEF,
    GME,
    CLM,
    SYM,
    NAV,
    FUN
};

enum custom_keycodes {
    TG_CLMK = SAFE_RANGE,
    WIN_RT,
    WIN_LT,
    KEYMAP_SAFE_RANGE  // use for keymap specific codes
};

// thumb keys
#define CTL_ESC CTL_T(KC_ESC)
#define NAV_BSP LT(NAV, KC_BSPC)
#define SYM_SPC LT(SYM, KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)

// navigation shortcuts
#define ALT_F4  A(KC_F4)
#define CTL_F4  C(KC_F4)
#define DSK_LT  C(G(KC_LEFT))
#define DSK_RT  C(G(KC_RGHT))
#define SFT_INS S(KC_INS)
#define TAB_RT  C(KC_TAB)
#define TAB_LT  C(S(KC_TAB))

// home row mod-taps
#define HM_A    CTL_T(KC_A)
#define HM_S    GUI_T(KC_S)
#define HM_D    LALT_T(KC_D)
#define HM_F    SFT_T(KC_F)
#define HM_J    RSFT_T(KC_J)
#define HM_K    RALT_T(KC_K)
#define HM_L    RGUI_T(KC_L)
#define HM_QUOT RCTL_T(KC_QUOT)

// extra keys
#define TG_GAME TG(GME)
#define GUI_TAB GUI_T(KC_TAB)
#define ALT_DEL RALT_T(KC_DEL)
