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

#define FIRMWARE_VERSION u8"7B4by/mJeJm"
#define RGB_MATRIX_STARTUP_SPD 60

#define COMBO_COUNT 9
#define COMBO_TERM 75
#define COMBO_TERM_PER_COMBO

#define LEADER_NO_TIMEOUT

#define LEADER_TIMEOUT 250
