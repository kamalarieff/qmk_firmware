/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 191

// https://www.reddit.com/r/olkb/comments/qu7vd8/taphold_settings_for_fast_typers/
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD

#define TAPPING_FORCE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0


// Use constant speed for mouse keys
#define MK_3_SPEED

#undef MK_C_OFFSET_0
#define MK_C_OFFSET_0 8

#undef MK_C_OFFSET_1
#define MK_C_OFFSET_1 16

#undef MK_C_OFFSET_2
#define MK_C_OFFSET_2 64

#define MK_MOMENTARY_ACCEL

/* #undef MK_COMBINED
#define MK_COMBINED */

#define FIRMWARE_VERSION u8"7B4by/mJeJm"
#define RGB_MATRIX_STARTUP_SPD 60

#define COMBO_COUNT 5
#define COMBO_TERM 30

#undef LEADER_NO_TIMEOUT
#define LEADER_NO_TIMEOUT

/* #undef LEADER_PER_KEY_TIMING
#define LEADER_PER_KEY_TIMING */

#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 250
