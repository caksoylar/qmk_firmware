SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE   = no
MAGIC_ENABLE       = no
COMMAND_ENABLE     = no

ifeq ($(strip $(USE_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += rotary_lock.c secrets.c
    else
        OPT_DEFS += -DNO_SECRETS
    endif
else
    OPT_DEFS += -DNO_SECRETS
endif
