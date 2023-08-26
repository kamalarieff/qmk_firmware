#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"

// CALLUM mods
#define LA_ARROW LT(_ARROW,KC_ESCAPE)
#define LA_NUMBER LT(_NUMBER,KC_ENTER)
#define LA_SYMBOL LT(_SYMBOL,KC_DELETE)

// Mod Tap
#define SHFT_T LSFT_T(KC_T)
#define CTRL_S LCTL_T(KC_S)
#define GUI_R LGUI_T(KC_R)
#define SHFT_N LSFT_T(KC_N)
#define CTRL_E LCTL_T(KC_E)
#define GUI_I LGUI_T(KC_I)
#define ALT_O LALT_T(KC_O)

// Layer Tap
// #define FN_DEL LT(_FN, KC_DELETE)

// Tap Hold
#define V_ENTER LT(0, KC_V)
#define P_NUMBER LT(0, KC_P)
#define Q_F12 LT(0, KC_Q)

// Layers
#define _COLEMAKDH 0
#define _ARROW 1
#define _NUMBER 2
#define _SYMBOL 3
#define _FN 4
#define _BROWSER 5
#define _ARROW_LHAND 6
#define _GAMING 7

enum custom_keycodes {
  LEFT_MONITOR = ML_SAFE_RANGE,
  RIGHT_MONITOR,
  SWITCH_APPS,
  ARROW,
  FATARROW,
  BRACES,
  CBRACES,
  ANGLED_BRACKETS,
  DQUO,
  PARENS,
  DELETE_BRACES,
  OS_SHFT,
  OS_CTRL,
  OS_ALT,
  OS_CMD
};

enum tap_dance_codes {
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_11,
  DANCE_12,
  DANCE_13,
  DANCE_14,
};

enum combos {
  YBACKSPACE_QUOTE,
  HCOMMA_SEMICOLON,
  LEFT_BRACKET_RIGHT_BRACKET,
  LEFT_PRN_RIGHT_PRN,
  LEFT_CBR_RIGHT_CBR,
  LEFT_ABK_RIGHT_ABK,
  WF_ESCAPE,
  XC_TAB,
  COMMAPERIOD_ENTER
};

const uint16_t PROGMEM hcomma_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM ybackspace_combo[] = {KC_Y, KC_BSPACE, COMBO_END};
const uint16_t PROGMEM leftbracket_rightbracket_combo[] = {KC_LBRACKET, KC_RBRACKET, COMBO_END};
const uint16_t PROGMEM leftprn_rightprn_combo[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM leftcbr_rightcbr_combo[] = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM leftabk_rightabk_combo[] = {KC_LABK, KC_RABK, COMBO_END};
const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM commaperiod_combo[] = {KC_COMMA, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [YBACKSPACE_QUOTE] = COMBO(ybackspace_combo, KC_QUOTE),
  [HCOMMA_SEMICOLON] = COMBO(hcomma_combo, KC_SCOLON),
  [LEFT_BRACKET_RIGHT_BRACKET] = COMBO_ACTION(leftbracket_rightbracket_combo),
  [LEFT_PRN_RIGHT_PRN] = COMBO_ACTION(leftprn_rightprn_combo),
  [LEFT_CBR_RIGHT_CBR] = COMBO_ACTION(leftcbr_rightcbr_combo),
  [LEFT_ABK_RIGHT_ABK] = COMBO_ACTION(leftabk_rightabk_combo),
  [WF_ESCAPE] = COMBO(wf_combo, KC_ESCAPE),
  [XC_TAB] = COMBO(xc_combo, KC_TAB),
  [COMMAPERIOD_ENTER] = COMBO(commaperiod_combo, KC_ENTER),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case LEFT_BRACKET_RIGHT_BRACKET:
      if (pressed) {
        SEND_STRING("[]");
        tap_code(KC_LEFT);  // Move cursor between braces.
      }
      break;
    case LEFT_PRN_RIGHT_PRN:
      if (pressed) {
        SEND_STRING("()");
        tap_code(KC_LEFT);  // Move cursor between braces.
      }
      break;
    case LEFT_CBR_RIGHT_CBR:
      if (pressed) {
        SEND_STRING("{}");
        tap_code(KC_LEFT);  // Move cursor between braces.
      }
      break;
    case LEFT_ABK_RIGHT_ABK:
      if (pressed) {
        SEND_STRING("<>");
        tap_code(KC_LEFT);  // Move cursor between braces.
      }
      break;
  }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case COMMAPERIOD_ENTER:
            return 100;
    }

    return COMBO_TERM;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case SHFT_T:
      case CTRL_S:
      case CTRL_E:
      case SHFT_N:
        return 180;
      case LA_NUMBER:
        return 110;
      case V_ENTER:
      case P_NUMBER:
      case Q_F12:
        return 250;
      default:
        return TAPPING_TERM;
    }
}

// https://getreuer.info/posts/keyboards/triggers/index.html#tap-vs.-long-press
static bool process_tap_or_long_press_key(
    keyrecord_t* record, uint16_t long_press_keycode) {
  if (record->tap.count == 0) {  // Key is being held.
    if (record->event.pressed) {
      tap_code16(long_press_keycode);
    }
    return false;  // Skip default handling.
  }
  return true;  // Continue default handling.
}

// https://getreuer.info/posts/keyboards/triggers/index.html#tap-vs.-long-press
static bool process_tap_or_long_press_layer_change(
    keyrecord_t* record, uint16_t long_press_layer) {
  if (record->tap.count == 0) {  // Key is being held.
    if (record->event.pressed) {
      layer_on(long_press_layer);
    }
    return false;  // Skip default handling.
  }
  return true;  // Continue default handling.
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // colemak-dh base
  [_COLEMAKDH] = LAYOUT_moonlander(
    KC_GRAVE,             KC_1,                KC_2,            KC_3,           KC_4,                      KC_5,           DYN_REC_START1,     DYN_REC_START2,   KC_6,                KC_7,                  KC_8,                  KC_9,                KC_0,             TO(_GAMING),
    KC_TAB,               Q_F12,               KC_W,            KC_F,           P_NUMBER,                  KC_B,           DYN_MACRO_PLAY1,    DYN_MACRO_PLAY2,  KC_J,                KC_L,                  KC_U,                  KC_Y,                KC_BSPACE,        LCTL(KC_A),
    OSM(MOD_LCTL),        LALT_T(KC_A),        GUI_R,           CTRL_S,         SHFT_T,                    KC_G,           DYN_REC_STOP,       DYN_REC_STOP,     KC_M,                SHFT_N,                CTRL_E,                GUI_I,               ALT_O,            KC_QUOTE,
    OSM(MOD_LSFT),        KC_Z,                KC_X,            KC_C,           KC_D,                      KC_V,                                                 KC_K,                KC_H,                  KC_COMMA,              KC_DOT,              KC_SLASH,         KC_ENTER,
    KC_LEAD,              _______,             _______,         KC_LALT,        MO(_ARROW),                _______,                                              _______,             MO(_NUMBER),           LA_SYMBOL,             _______,             _______,          TO(_GAMING),
    KC_SPACE,             MO(_DESKTOP),        CAPS_WORD,                                                                                                        CAPS_WORD,           MO(_DESKTOP),          KC_BSPACE
  ),
  // arrow keys
  [_ARROW] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              LALT(KC_Q),          LALT(KC_W),      KC_F,           RIGHT_MONITOR,             XXXXXXX,        _______,            _______,          LCTL(KC_Y),          LSFT(KC_INSERT),       LCTL(KC_INSERT),       _______,             _______,           _______, 
    _______,              OSM(MOD_LALT),       OSM(MOD_LGUI),   OSM(MOD_LCTL),  OSM(MOD_LSFT),             XXXXXXX,        _______,            _______,          KC_LEFT,             KC_DOWN,               KC_UP,                 KC_RIGHT,            _______,           _______, 
    _______,              SWITCH_APPS,         LGUI(KC_TAB),    XXXXXXX,        XXXXXXX,                   XXXXXXX,                                              KC_HOME,             KC_PGDOWN,             KC_PGUP,               KC_END,              KC_ENTER,          _______, 
    _______,              _______,             _______,         _______,        _______,                   _______,                                              _______,             _______,               KC_DELETE,             _______,             _______,           TO(_COLEMAKDH), 
    KC_SPACE,             XXXXXXX,             XXXXXXX,                                                                                                          _______,             _______,               KC_BSPACE
  ),
  // number layer
  [_NUMBER] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    KC_TAB,               KC_GRAVE,            KC_7,            KC_8,           KC_9,                      KC_RABK,        _______,            _______,          XXXXXXX,             LCTL(KC_A),            _______,               XXXXXXX,             KC_QUOTE,          _______, 
    _______,              KC_SCOLON,           KC_4,            KC_5,           KC_6,                      KC_EQUAL,       _______,            _______,          KC_BSPACE,           OSM(MOD_LSFT),         OSM(MOD_LCTL),         OSM(MOD_LGUI),       OSM(MOD_LALT),     _______, 
    _______,              KC_BSLASH,           KC_1,            KC_2,           KC_3,                      KC_MINUS,                                             XXXXXXX,             OSL(_SYMBOL),          _______,               OSL(_TMUX),          _______,           _______, 
    _______,              _______,             _______,         _______,        KC_0,                      _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              KC_MINUS,            _______,                                                                                                          _______,             XXXXXXX,               _______
  ),
  // shifted number layer
  [_SYMBOL] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    TO(_COLEMAKDH),       KC_GRAVE,            _______,         KC_LPRN,        KC_RPRN,                   ARROW,          _______,            _______,          _______,             ARROW,                 FATARROW,              ANGLED_BRACKETS,     DQUO,           _______, 
    _______,              KC_COLN,             _______,         KC_LBRACKET,    KC_RBRACKET,               _______,        _______,            _______,          _______,             PARENS,                BRACES,                CBRACES,             _______,     _______, 
    _______,              KC_LABK,             KC_RABK,         KC_LCBR,        KC_RCBR,                   _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,         _______,        _______,                   _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,                                                                                                          _______,             _______,               _______
  ),
  // fn layer
  [_FN] = LAYOUT_moonlander(
    KC_F18,               KC_F19,              KC_F20,          KC_F21,         KC_F22,                    KC_F23,         _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    KC_F17,               KC_F12,              KC_F7,           KC_F8,          KC_F9,                     KC_PSCREEN,     _______,            _______,          _______,             XXXXXXX,               XXXXXXX,               XXXXXXX,             XXXXXXX,           _______, 
    KC_F16,               KC_F11,              KC_F4,           KC_F5,          KC_F6,                     KC_SCROLLLOCK,  _______,            _______,          XXXXXXX,             KC_LSHIFT,             KC_LCTRL,              KC_LGUI,             KC_LALT,           _______,
    KC_F15,               KC_F10,              KC_F1,           KC_F2,          KC_F3,                     KC_PAUSE,                                             _______,             _______,               _______,               _______,             _______,           _______, 
    KC_F14,               KC_F13,              _______,         _______,        KC_APPLICATION,            _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    KC_SPACE,             KC_TAB,              KC_F24,                                                                                                           _______,             _______,               _______
  ),
  // browser layer
  [_BROWSER] = LAYOUT_moonlander(
    XXXXXXX,              _______,             _______,         _______,        _______,                   XXXXXXX,        _______,            _______,          XXXXXXX,             _______,               XXXXXXX,               _______,             _______,           _______,          
    TO(_COLEMAKDH),       XXXXXXX,             LCTL(KC_W),      TD(DANCE_2),    LCTL(KC_R),                TD(DANCE_3),    _______,            _______,          XXXXXXX,             XXXXXXX,               XXXXXXX,               XXXXXXX,             XXXXXXX,           XXXXXXX,          
    XXXXXXX,              XXXXXXX,             TD(DANCE_4),     TD(DANCE_5),    TD(DANCE_6),               XXXXXXX,        _______,            _______,          TD(DANCE_7),         TD(DANCE_8),           TD(DANCE_9),           TD(DANCE_10),        XXXXXXX,           XXXXXXX,          
    _______,              XXXXXXX,             XXXXXXX,         XXXXXXX,        XXXXXXX,                   XXXXXXX,                                              XXXXXXX,             XXXXXXX,               XXXXXXX,               XXXXXXX,             XXXXXXX,           _______, 
    _______,              _______,             XXXXXXX,         XXXXXXX,        _______,                   _______,                                              _______,             _______,               XXXXXXX,               XXXXXXX,             _______,           _______, 
    _______,              _______,             XXXXXXX,                                                                                                          XXXXXXX,             XXXXXXX,               XXXXXXX
  ),
  // arrow left hand layer
  [_ARROW_LHAND] = LAYOUT_moonlander(
    XXXXXXX,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______,          
    TO(_COLEMAKDH),       _______,             XXXXXXX,         KC_UP,          XXXXXXX,                   XXXXXXX,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______,          
    _______,              _______,             KC_LEFT,         KC_DOWN,        KC_RIGHT,                  _______,        _______,            _______,          KC_LEFT,             KC_DOWN,               KC_UP,                 KC_RIGHT,            _______,           _______,          
    _______,              _______,             _______,         _______,        _______,                   _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,         _______,        _______,                   _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,                                                                                                          _______,             _______,               _______
  ),
  // gaming layer
  [_GAMING] = LAYOUT_moonlander(
    KC_ESCAPE,            KC_1,                KC_2,            KC_3,           KC_4,                      KC_5,           KC_BSLASH,          KC_PSCREEN,       KC_6,                KC_7,                  KC_8,                  KC_9,                 KC_0,             KC_MINUS,       
    KC_TAB,               KC_Q,                KC_W,            KC_E,           KC_R,                      KC_T,           KC_DELETE,          TO(_COLEMAKDH),   KC_Y,                KC_U,                  KC_I,                  KC_O,                 KC_P,             KC_BSPACE,       
    _______,              KC_A,                KC_S,            KC_D,           KC_F,                      KC_G,           KC_BSPACE,          KC_BSPACE,        KC_H,                KC_J,                  KC_K,                  KC_L,                 KC_SCOLON,        KC_ENTER,       
    KC_LSHIFT,            KC_Z,                KC_X,            KC_C,           KC_V,                      KC_B,                                                 KC_N,                KC_M,                  KC_COMMA,              KC_DOT,               KC_SLASH,         KC_RSHIFT,      
    KC_LCTRL,             KC_LGUI,             KC_LEFT,         KC_RIGHT,       KC_LALT,                   KC_ESCAPE,                                            KC_ESCAPE,           KC_UP,                 KC_DOWN,               KC_LBRACKET,          KC_RBRACKET,      KC_RCTRL,       
    KC_SPACE,             KC_LCTRL,            KC_LGUI,                                                                                                          KC_DELETE,           KC_ENTER,              KC_BSPACE
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// this starts at top left and it moves down
// the formula is zsa[0] = h / 1.4, zsa[1] = s / 0.39, zsa[2] = v / 0.39 
// h ranges from [0, 360]
// s ranges from [0, 100]
// v ranges from [0, 100]
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_COLEMAKDH] = { {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {146,224,255}, {205,255,255}, {0,0,0}, {0,0,0}, {205,255,255}, {146,224,255}, {146,224,255}, {105,255,255}, {0,0,0}, {205,255,255}, {146,224,255}, {205,255,255}, {105,255,255}, {0,0,0}, {205,255,255}, {146,224,255}, {205,255,255}, {154,255,255}, {105,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0},     {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {146,224,255}, {205,255,255}, {0,0,0}, {0,0,0}, {205,255,255}, {146,224,255}, {146,224,255}, {105,255,255}, {252,119,255}, {205,255,255}, {146,224,255}, {205,255,255}, {105,255,255}, {146,224,255}, {205,255,255}, {146,224,255}, {205,255,255}, {154,255,255}, {105,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {0,0,0} },

    [_ARROW] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {154,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {205,255,255}, {205,255,255}, {154,255,255}, {0,0,0}, {105,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0} },

    [_NUMBER] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {205,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {205,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {205,255,255}, {205,255,255}, {205,255,255}, {154,255,255}, {0,0,0}, {105,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_SYMBOL] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {32,176,255}, {154,255,255}, {154,255,255}, {32,176,255}, {0,0,0}, {105,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0} },

    [_FN] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {249,228,255}, {0,0,255}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_GAMING] = { {205,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {154,255,255}, {205,255,255}, {205,255,255}, {255,220,201}, {205,255,255}, {154,255,255}, {205,255,255}, {255,220,201}, {255,220,201}, {205,255,255}, {154,255,255}, {205,255,255}, {205,255,255}, {255,220,201}, {205,255,255}, {35,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {35,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {154,255,255}, {154,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {105,255,255}, {154,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {35,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {35,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {105,255,255}, {0,0,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {154,255,255} },

    [_BROWSER] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {0,0,0}, {154,255,255}, {0,0,0}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {0,0,0}, {105,255,255}, {0,0,0}, {154,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0} },

    [_ARROW_LHAND] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {15,166,195}, {0,0,0}, {0,0,0}, {0,0,0}, {15,166,195}, {15,166,195}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {15,166,195}, {0,0,0}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {15,166,195}, {0,0,0}, {0,0,0}, {15,166,195}, {0,0,0}, {15,166,195}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {15,166,195}, {0,0,0}, {154,255,255}, {0,0,0}, {0,0,0}, {15,166,195}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case _COLEMAKDH:
      set_layer_color(_COLEMAKDH);
      break;
    case _ARROW:
      set_layer_color(_ARROW);
      break;
    case _NUMBER:
      set_layer_color(_NUMBER);
      break;
    case _SYMBOL:
      set_layer_color(_SYMBOL);
      break;
    case _FN:
      set_layer_color(_FN);
      break;
    case _GAMING:
      set_layer_color(_GAMING);
      break;
    case _BROWSER:
      set_layer_color(_BROWSER);
      break;
    case _ARROW_LHAND:
      set_layer_color(_ARROW_LHAND);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

uint16_t key_timer;

static uint16_t idle_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // Get current mod and one-shot mod states.
  uint8_t mods = get_mods();
  uint8_t oneshot_mods = get_oneshot_mods();
  // https://www.reddit.com/r/ergodox/comments/qhp3sd/sharing_neat_configuration_tricks/
  // This is the macro for inserting brackets
  // SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_LEFT));
  switch (keycode) {
    // https://getreuer.info/posts/keyboards/macros/
    case BRACES:  // Types [], {}, or <> and puts cursor between braces.
      if (record->event.pressed) {
        clear_mods();  // Temporarily disable mods.
        clear_oneshot_mods();
        if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
          SEND_STRING("{}");
        } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
          SEND_STRING("<>");
        } else if ((mods | oneshot_mods) & MOD_MASK_ALT) {
          SEND_STRING("()");
        } else {
          SEND_STRING("[]");
        }
        tap_code(KC_LEFT);  // Move cursor between braces.
        set_mods(mods);  // Restore mods.
      } else {
          clear_oneshot_layer_state(ONESHOT_PRESSED);
      }
      return false;
    case PARENS:  // Types () and puts cursor between parens.
      if (record->event.pressed) {
        SEND_STRING("()");
        tap_code(KC_LEFT);  // Move cursor between parens.
        set_mods(mods);  // Restore mods.
      } else {
          clear_oneshot_layer_state(ONESHOT_PRESSED);
      }
      return false;
    case CBRACES:  // Types () and puts cursor between parens.
      if (record->event.pressed) {
        SEND_STRING("{}");
        tap_code(KC_LEFT);  // Move cursor between parens.
        set_mods(mods);  // Restore mods.
      } else {
          clear_oneshot_layer_state(ONESHOT_PRESSED);
      }
      return false;
    case ARROW:  // Arrow macro, types -> or =>.
      if (record->event.pressed) {
        if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {  // Is shift held?
          del_mods(MOD_MASK_SHIFT);  // Temporarily delete shift.
          del_oneshot_mods(MOD_MASK_SHIFT);
          SEND_STRING("=>");
          set_mods(mods);            // Restore mods.
        } else {
          SEND_STRING("->");
        }
      } else {
          clear_oneshot_layer_state(ONESHOT_PRESSED);
      }
      return false;
    case FATARROW:  // Arrow macro, types -> or =>.
      if (record->event.pressed) {
        SEND_STRING("=>");
      }
      return false;
    case ANGLED_BRACKETS:  // Arrow macro, types -> or =>.
      if (record->event.pressed) {
        SEND_STRING("<>");
        tap_code(KC_LEFT);  // Move cursor between parens.
      }
      return false;
    case DQUO:  // Arrow macro, types -> or =>.
      if (record->event.pressed) {
        SEND_STRING("''");
        tap_code(KC_LEFT);  // Move cursor between parens.
      }
      return false;
    case DELETE_BRACES:
      if (record->event.pressed) {
        tap_code(KC_BSPACE);  // Move cursor between braces.
        tap_code(KC_DELETE);  // Move cursor between braces.
      }
      return false;
    // https://www.reddit.com/r/olkb/comments/afm9ii/qmk_macro_in_modtap_keys/
    case SWITCH_APPS:
      if (record->event.pressed) {
          SEND_STRING(SS_LGUI("`"));
      }
      return false;
    case LEFT_MONITOR:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL(";s"));
      }
      return false;
    case RIGHT_MONITOR:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL(";f"));
      }
      return false;
    case V_ENTER:  // V on tap, Enter on long press.
      return process_tap_or_long_press_key(record, KC_ENTER);
    case Q_F12:  // V on tap, Enter on long press.
      return process_tap_or_long_press_key(record, KC_F12);
    case P_NUMBER:  // P on tap, Switch to _NUMBER layer on long press.
      return process_tap_or_long_press_layer_change(record, _NUMBER);
  }

  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[15];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PGUP);
        tap_code16(KC_PGUP);
        tap_code16(KC_PGUP);
    }
    if(state->count > 3) {
        tap_code16(KC_PGUP);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_PGUP); break;
        case SINGLE_HOLD: register_code16(KC_UP); break;
        case DOUBLE_TAP: register_code16(KC_PGUP); register_code16(KC_PGUP); break;
        case DOUBLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PGUP); register_code16(KC_PGUP);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_PGUP); break;
        case SINGLE_HOLD: unregister_code16(KC_UP); break;
        case DOUBLE_TAP: unregister_code16(KC_PGUP); break;
        case DOUBLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PGUP); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_T));
        tap_code16(LCTL(KC_T));
        tap_code16(LCTL(KC_T));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_T));
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_T)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_T))); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_T)); register_code16(LCTL(KC_T)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_T)); register_code16(LCTL(KC_T));
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_T)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_T))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_T)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_T)); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(LSFT(KC_TAB)));
        tap_code16(LCTL(LSFT(KC_TAB)));
        tap_code16(LCTL(LSFT(KC_TAB)));
    }
    if(state->count > 3) {
        tap_code16(LCTL(LSFT(KC_TAB)));
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(LCTL(LSFT(KC_TAB))); break;
        case SINGLE_HOLD: register_code16(LALT(KC_LEFT)); break;
        case DOUBLE_TAP: register_code16(LCTL(LSFT(KC_TAB))); register_code16(LCTL(LSFT(KC_TAB))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(LSFT(KC_TAB))); register_code16(LCTL(LSFT(KC_TAB)));
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(LCTL(LSFT(KC_TAB))); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_LEFT)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(LSFT(KC_TAB))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(LSFT(KC_TAB))); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PGDOWN);
        tap_code16(KC_PGDOWN);
        tap_code16(KC_PGDOWN);
    }
    if(state->count > 3) {
        tap_code16(KC_PGDOWN);
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_PGDOWN); break;
        case SINGLE_HOLD: register_code16(KC_DOWN); break;
        case DOUBLE_TAP: register_code16(KC_PGDOWN); register_code16(KC_PGDOWN); break;
        case DOUBLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PGDOWN); register_code16(KC_PGDOWN);
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_PGDOWN); break;
        case SINGLE_HOLD: unregister_code16(KC_DOWN); break;
        case DOUBLE_TAP: unregister_code16(KC_PGDOWN); break;
        case DOUBLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PGDOWN); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_TAB));
        tap_code16(LCTL(KC_TAB));
        tap_code16(LCTL(KC_TAB));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_TAB));
    }
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_TAB)); break;
        case SINGLE_HOLD: register_code16(LALT(KC_RIGHT)); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_TAB)); register_code16(LCTL(KC_TAB)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_TAB)); register_code16(LCTL(KC_TAB));
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_TAB)); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_RIGHT)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_TAB)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_TAB)); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(LSFT(KC_TAB)));
        tap_code16(LCTL(LSFT(KC_TAB)));
        tap_code16(LCTL(LSFT(KC_TAB)));
    }
    if(state->count > 3) {
        tap_code16(LCTL(LSFT(KC_TAB)));
    }
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(LCTL(LSFT(KC_TAB))); break;
        case SINGLE_HOLD: register_code16(LALT(KC_LEFT)); break;
        case DOUBLE_TAP: register_code16(LCTL(LSFT(KC_TAB))); register_code16(LCTL(LSFT(KC_TAB))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(LSFT(KC_TAB))); register_code16(LCTL(LSFT(KC_TAB)));
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(LCTL(LSFT(KC_TAB))); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_LEFT)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(LSFT(KC_TAB))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(LSFT(KC_TAB))); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PGDOWN);
        tap_code16(KC_PGDOWN);
        tap_code16(KC_PGDOWN);
    }
    if(state->count > 3) {
        tap_code16(KC_PGDOWN);
    }
}

void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_PGDOWN); break;
        case SINGLE_HOLD: register_code16(KC_DOWN); break;
        case DOUBLE_TAP: register_code16(KC_PGDOWN); register_code16(KC_PGDOWN); break;
        case DOUBLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PGDOWN); register_code16(KC_PGDOWN);
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_PGDOWN); break;
        case SINGLE_HOLD: unregister_code16(KC_DOWN); break;
        case DOUBLE_TAP: unregister_code16(KC_PGDOWN); break;
        case DOUBLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PGDOWN); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(qk_tap_dance_state_t *state, void *user_data);
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_9(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PGUP);
        tap_code16(KC_PGUP);
        tap_code16(KC_PGUP);
    }
    if(state->count > 3) {
        tap_code16(KC_PGUP);
    }
}

void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_PGUP); break;
        case SINGLE_HOLD: register_code16(KC_UP); break;
        case DOUBLE_TAP: register_code16(KC_PGUP); register_code16(KC_PGUP); break;
        case DOUBLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PGUP); register_code16(KC_PGUP);
    }
}

void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_PGUP); break;
        case SINGLE_HOLD: unregister_code16(KC_UP); break;
        case DOUBLE_TAP: unregister_code16(KC_PGUP); break;
        case DOUBLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PGUP); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(qk_tap_dance_state_t *state, void *user_data);
void dance_10_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_10_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_10(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_TAB));
        tap_code16(LCTL(KC_TAB));
        tap_code16(LCTL(KC_TAB));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_TAB));
    }
}

void dance_10_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_TAB)); break;
        case SINGLE_HOLD: register_code16(LALT(KC_RIGHT)); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_TAB)); register_code16(LCTL(KC_TAB)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_TAB)); register_code16(LCTL(KC_TAB));
    }
}

void dance_10_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_TAB)); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_RIGHT)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_TAB)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_TAB)); break;
    }
    dance_state[10].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_Q) {
      tap_code(KC_F12);
    }
    SEQ_ONE_KEY(KC_W) {
      layer_on(_BROWSER);
    }
    SEQ_ONE_KEY(KC_F) {
      layer_on(_ARROW_LHAND);
    }
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _ARROW, _NUMBER, _FN);
    return state;
}
