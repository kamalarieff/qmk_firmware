/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// https://www.reddit.com/r/olkb/comments/qu7vd8/taphold_settings_for_fast_typers/
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD

#define TAPPING_FORCE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0

#undef MK_KINETIC_SPEED
#define MK_KINETIC_SPEED

/* #undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 8

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 8 */

/* #undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 10

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 20 */

#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 10

#undef MOUSEKEY_INITIAL_SPEED
#define MOUSEKEY_INITIAL_SPEED 25

#undef MOUSEKEY_BASE_SPEED
#define MOUSEKEY_BASE_SPEED 1000

#undef MOUSEKEY_ACCELERATED_SPEED
#define MOUSEKEY_ACCELERATED_SPEED 500

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0

/* // Use constant speed for mouse keys
#define MK_3_SPEED

#undef MK_C_OFFSET_UNMOD
#define MK_C_OFFSET_UNMOD 32

#undef MK_C_OFFSET_0
#define MK_C_OFFSET_0 4

#undef MK_C_OFFSET_1
#define MK_C_OFFSET_1 16

#undef MK_C_OFFSET_2
#define MK_C_OFFSET_2 64

#define MK_MOMENTARY_ACCEL */

#undef MOUSEKEY_BASE_SPEED
#define MOUSEKEY_BASE_SPEED 500

#undef MK_COMBINED
#define MK_COMBINED

#define FIRMWARE_VERSION u8"7B4by/mJeJm"
#define RGB_MATRIX_STARTUP_SPD 60

#define COMBO_COUNT 7
#define COMBO_TERM 30

#undef LEADER_NO_TIMEOUT
#define LEADER_NO_TIMEOUT

/* #undef LEADER_PER_KEY_TIMING
#define LEADER_PER_KEY_TIMING */

#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 250
