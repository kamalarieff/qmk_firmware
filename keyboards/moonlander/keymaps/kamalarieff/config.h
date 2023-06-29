/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 191

#define PERMISSIVE_HOLD

#define TAPPING_FORCE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0


/* #undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 20

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 14

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 50 */

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

#define AUTO_SHIFT_TIMEOUT 200
#define NO_AUTO_SHIFT_ALPHA
#define FIRMWARE_VERSION u8"7B4by/mJeJm"
#define RGB_MATRIX_STARTUP_SPD 60

#define COMBO_COUNT 5
#define COMBO_TERM 30
