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

// bottom row mod-taps
#define SFT_Z   SFT_T(KC_Z)
#define GUI_X   GUI_T(KC_X)
#define ALT_C   RALT_T(KC_C)
#define CTL_SLS CTL_T(KC_SLSH)
#define GUI_DOT GUI_T(KC_DOT)
#define ALT_COM LALT_T(KC_COMM)
#define CTL_PEN CTL_T(KC_PENT)
#define GUI_P3  GUI_T(KC_P3)
#define ALT_P2  LALT_T(KC_P2)

// navigation shortcuts
#define ALT_F4  A(KC_F4)
#define CTL_F4  C(KC_F4)
#define DSK_LT  C(G(KC_LEFT))
#define DSK_RT  C(G(KC_RGHT))
#define SFT_INS S(KC_INS)
#define TAB_RT  C(KC_TAB)
#define TAB_LT  C(S(KC_TAB))

// extra keys
#define TG_GAME TG(GME)
#define GUI_TAB GUI_T(KC_TAB)
#define ALT_DEL RALT_T(KC_DEL)
