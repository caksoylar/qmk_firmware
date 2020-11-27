#pragma once
#include QMK_KEYBOARD_H

#if (__has_include("secrets.h"))
    #include "secrets.h"
#else
    #define COMBINATION { 200 }
    #define START_CW true
#endif

#define TOLERANCE 3

void update_dial(bool direction);
