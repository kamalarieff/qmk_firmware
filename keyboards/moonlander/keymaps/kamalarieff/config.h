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
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 6

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 64

#define AUTO_SHIFT_TIMEOUT 200
#define NO_AUTO_SHIFT_ALPHA
#define FIRMWARE_VERSION u8"oqXm4/e007J"
#define RGB_MATRIX_STARTUP_SPD 60

#define COMBO_COUNT 2
#define COMBO_TERM 15
