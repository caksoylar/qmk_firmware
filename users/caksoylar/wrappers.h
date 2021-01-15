#pragma once
#include "caksoylar.h"

#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
#define LAYOUT_wrapper(...)              LAYOUT(__VA_ARGS__)
#define LAYOUT_split_3x5_3_wrapper(...)  LAYOUT_split_3x5_3(__VA_ARGS__)
#define LAYOUT_split_3x5_2_wrapper(...)  LAYOUT_split_3x5_2(__VA_ARGS__)

#define _________________QWERTY_L1_________________    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________    KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________    SFT_Z,   GUI_X,   ALT_C,   KC_V,    KC_B

#define _________________QWERTY_R1_________________    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT
#define _________________QWERTY_R3_________________    KC_N,    KC_M,    ALT_COM, GUI_DOT, CTL_SLS

#define ______________COLEMAK_MOD_DH_L1____________    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________    KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________    SFT_Z,   GUI_X,   ALT_C,   KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT
#define ______________COLEMAK_MOD_DH_R2____________    KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ______________COLEMAK_MOD_DH_R3____________    KC_K,    KC_H,    ALT_COM, GUI_DOT, CTL_SLS

#define __________________GAM_L3___________________    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define __________________GAM_R3___________________    KC_N,    KC_M,    KC_COMM, KC_DOT,  TG_GAME

#define ________________NUMBER_LEFT________________    KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________    KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________BLANK___________________    _______, _______, _______, _______, _______


#define __________________SYM_L1___________________    ________________NUMBER_LEFT________________
#define __________________SYM_L2___________________    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define __________________SYM_L3___________________    KC_LSFT, KC_LGUI, KC_RALT, KC_SCLN, KC_AMPR

#define __________________SYM_R1___________________    ________________NUMBER_RIGHT_______________
#define __________________SYM_R2___________________    KC_CIRC, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS
#define __________________SYM_R3___________________    KC_ASTR, KC_BSLS, KC_LALT, KC_LGUI, KC_LSFT


#define __________________NAV_L1___________________    ALT_F4,  TAB_LT,  TAB_RT,  CTL_F4,  KC_VOLU
#define __________________NAV_L2___________________    DSK_LT,  WIN_LT,  WIN_RT,  DSK_RT,  KC_VOLD
#define __________________NAV_L3___________________    KC_LCTL, KC_LGUI, KC_LALT, SFT_INS, XXXXXXX

#define __________________NAV_R1___________________    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CALC
#define __________________NAV_R2___________________    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PAUS
#define __________________NAV_R3___________________    KC_INS,  KC_DEL,  KC_MPLY, KC_MPRV, KC_MNXT


#define __________________FUN_L1___________________    _________________FUNC_LEFT_________________
#define __________________FUN_L2___________________    _________________FUNC_RIGHT________________
#define __________________FUN_L3___________________    KC_LSFT, KC_LGUI, KC_LALT, KC_F11,  KC_F12

#define __________________FUN_R1___________________    KC_CAPS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS
#define __________________FUN_R2___________________    KC_NLCK, KC_P4,   KC_P5,   KC_P6,   KC_PPLS
#define __________________FUN_R3___________________    KC_P0,   KC_P1,   ALT_P2,  GUI_P3,  CTL_PEN


#define _________________RAISE_L1__________________    ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________    ___________________BLANK___________________
#define _________________RAISE_L3__________________    ___________________BLANK___________________

#define _________________RAISE_R1__________________    ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________    _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END


#define  __DEF2_THUMB_L__    CTL_ESC, NAV_BSP
#define  __DEF2_THUMB_R__    SYM_SPC, SFT_ENT

#define  __GAM2_THUMB_L__    KC_LCTL, KC_SPC

#define  __LAY2_THUMB_L__    KC_LCTL, _______
#define  __LAY2_THUMB_R__    _______, KC_LSFT

#define  __FUN2_THUMB_L__    TG_GAME, _______
#define  __FUN2_THUMB_R__    _______, TG_CLMK

#define  ______DEF3_THUMB_L_______    GUI_TAB, __DEF2_THUMB_L__
#define  ______DEF3_THUMB_R_______    __DEF2_THUMB_R__, ALT_DEL

#define  ______GAM3_THUMB_L_______    KC_TAB,  __GAM2_THUMB_L__

#define  ______LAY3_THUMB_L_______    KC_LGUI, __LAY2_THUMB_L__
#define  ______LAY3_THUMB_R_______    __LAY2_THUMB_R__, KC_RALT

#define  ______FUN3_THUMB_L_______    KC_LGUI, __FUN2_THUMB_L__
#define  ______FUN3_THUMB_R_______    __FUN2_THUMB_R__, KC_RALT

// clang-format on
