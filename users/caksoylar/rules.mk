SRC += rotary_lock.c

ifeq ($(strip $(USE_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += secrets.c
    endif
endif
