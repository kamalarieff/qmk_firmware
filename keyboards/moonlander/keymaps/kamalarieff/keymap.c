#include QMK_KEYBOARD_H
#include "version.h"
#include "features/oneshot.h"
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

// Mod Tap
#define SHFT_T LSFT_T(KC_T)
#define CTRL_S LCTL_T(KC_S)
#define SHFT_N LSFT_T(KC_N)
#define CTRL_E LCTL_T(KC_E)

// Layer Tap
#define APP_TAB LT(_APPLICATION, KC_TAB)
// #define FN_DEL LT(_FN, KC_DELETE)

// Tap Hold
#define V_ENTER LT(0, KC_V)
// #define KEYNAV_LEFT LT(0, KC_R)
// #define KEYNAV_DOWN LT(0, KC_S)
// #define KEYNAV_UP LT(0, KC_F)
// #define KEYNAV_RIGHT LT(0, KC_T)

// #define KEYNAV_LEFT TD(DANCE_11)
// #define KEYNAV_DOWN TD(DANCE_12)
// #define KEYNAV_UP TD(DANCE_13)
// #define KEYNAV_RIGHT TD(DANCE_14)

// Layers
#define _COLEMAKDH 0
#define _ARROW 1
#define _NUMBER 2
#define _SYMBOL 3
#define _FN 4
#define _APPLICATION 5
#define _TMUX 6
#define _KEYNAV 7
#define _PLOVER 8
#define _BROWSER 9
#define _ARROW_LHAND 10
#define _GAMING 11

#define IDLE_TIMEOUT_MS 1000

enum custom_keycodes {
  PLOVER_ON = ML_SAFE_RANGE,
  PLOVER_OFF,
  PLOVER_LOOKUP,
  LEFT_MONITOR,
  RIGHT_MONITOR,
  SWITCH_APPS,
  KEYNAV,
  ARROW,
  BRACES,
  PARENS,
  DELETE_BRACES,
  OS_SHFT,
  OS_CTRL,
  OS_ALT,
  OS_CMD,
  CUSTOM_OSM_SHIFT,
  CUSTOM_OSM_CTRL,
  CUSTOM_OSM_ALT,
  TMUX_FZF,
  TMUX_FZF_SESSION,
  TMUX_SWITCH_SESSION,
  TMUX_ALT_TAB,
  TMUX_CLOSE_PANE,
  TMUX_LEFT_PANE,
  TMUX_DOWN_PANE,
  TMUX_UP_PANE,
  TMUX_RIGHT_PANE,
};

enum tap_dance_codes {
  DANCE_1,
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
  UY_LEFT_BRACKET,
  YQUOTE_RIGHT_BRACKET,
  HCOMMA_SEMICOLON,
  LEFT_BRACKET_RIGHT_BRACKET,
  LEFT_PRN_RIGHT_PRN,
  LEFT_CBR_RIGHT_CBR,
  LEFT_ABK_RIGHT_ABK,
};

const uint16_t PROGMEM hcomma_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM yquote_combo[] = {KC_Y, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM leftbracket_rightbracket_combo[] = {KC_LBRACKET, KC_RBRACKET, COMBO_END};
const uint16_t PROGMEM leftprn_rightprn_combo[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM leftcbr_rightcbr_combo[] = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM leftabk_rightabk_combo[] = {KC_LABK, KC_RABK, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [UY_LEFT_BRACKET] = COMBO(uy_combo, KC_LBRACKET),
  [YQUOTE_RIGHT_BRACKET] = COMBO(yquote_combo, KC_RBRACKET),
  [HCOMMA_SEMICOLON] = COMBO(hcomma_combo, KC_SCOLON),
  [LEFT_BRACKET_RIGHT_BRACKET] = COMBO_ACTION(leftbracket_rightbracket_combo),
  [LEFT_PRN_RIGHT_PRN] = COMBO_ACTION(leftprn_rightprn_combo),
  [LEFT_CBR_RIGHT_CBR] = COMBO_ACTION(leftcbr_rightcbr_combo),
  [LEFT_ABK_RIGHT_ABK] = COMBO_ACTION(leftabk_rightabk_combo),
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


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHFT_T:
        case CTRL_S:
        case CTRL_E:
            return 140;
        case SHFT_N:
            return 100;
        case LA_NUMBER:
            return 120;
        default:
            return TAPPING_TERM;
      // case KEYNAV_LEFT:
      // case KEYNAV_DOWN:
      // case KEYNAV_UP:
      // case KEYNAV_RIGHT:
      case TD(DANCE_11):
      case TD(DANCE_12):
      case TD(DANCE_13):
      case TD(DANCE_14):
        return 110;
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // colemak-dh base
  [_COLEMAKDH] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   KC_MEH,         DYN_REC_START1,     DYN_REC_START2,   KC_HYPR,             _______,               _______,               _______,             _______,          TO(_GAMING),         
    KC_LEAD,              KC_Q,                KC_W,            KC_F,           KC_P,                      KC_B,           DYN_MACRO_PLAY1,    DYN_MACRO_PLAY2,  KC_J,                KC_L,                  KC_U,                  KC_Y,                KC_QUOTE,         KC_LEAD,
    KC_LEAD,              LGUI_T(KC_A),        LALT_T(KC_R),    CTRL_S,         SHFT_T,                    KC_G,           DYN_REC_STOP,       DYN_REC_STOP,     KC_M,                SHFT_N,                CTRL_E,                LALT_T(KC_I),        LGUI_T(KC_O),     _______,
    KC_LEAD,              KC_Z,                KC_X,            KC_C,           KC_D,                      V_ENTER,                                              KC_K,                KC_H,                  KC_COMMA,              KC_DOT,              KC_SLASH,         _______,
    _______,              _______,             _______,         APP_TAB,        LA_ARROW,                  _______,                                              _______,             LA_NUMBER,             KC_DELETE,             _______,             _______,          _______,
    KC_SPACE,             _______,             PLOVER_ON,                                                                                                        _______,             _______,               KC_BSPACE
  ),
  // arrow keys
  [_ARROW] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    TO(_COLEMAKDH),       KC_TAB,              LEFT_MONITOR,    TD(DANCE_1),    RIGHT_MONITOR,             XXXXXXX,        _______,            _______,          LCTL(KC_Y),          LSFT(KC_INSERT),       LCTL(KC_INSERT),       _______,             _______,           _______, 
    _______,              OS_CMD,              OS_ALT,          OS_CTRL,        OS_SHFT,                   XXXXXXX,        _______,            _______,          KC_LEFT,             KC_DOWN,               KC_UP,                 KC_RIGHT,            _______,           _______, 
    _______,              SWITCH_APPS,         LGUI(KC_TAB),    XXXXXXX,        XXXXXXX,                   XXXXXXX,                                              KC_HOME,             KC_PGDOWN,             KC_PGUP,               KC_END,              KC_ENTER,          _______, 
    _______,              _______,             _______,         _______,        _______,                   _______,                                              _______,             _______,               KC_DELETE,             _______,             _______,           _______, 
    KC_SPACE,             XXXXXXX,             XXXXXXX,                                                                                                          _______,             _______,               KC_BSPACE
  ),
  // number layer
  [_NUMBER] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    // NOTE: can try to remove KC_TAB if you find it less used and replace it with KC_GRAVE and move KC_TILD into the grave position in the _SYMBOL layer
    // NOTE: 2022 September 07 KC_TAB is too useful in this layer
    _______,              KC_GRAVE,            KC_7,            KC_8,           KC_9,                      KC_RABK,        _______,            _______,          XXXXXXX,             LCTL(KC_A),            TMUX_ALT_TAB,          XXXXXXX,             KC_QUOTE,          _______, 
    _______,              KC_SCOLON,           KC_4,            KC_5,           KC_6,                      KC_EQUAL,       _______,            _______,          KC_BSPACE,           OS_SHFT,               OS_CTRL,               OS_ALT,              OS_CMD,            _______, 
    _______,              KC_BSLASH,           KC_1,            KC_2,           KC_3,                      KC_MINUS,                                             XXXXXXX,             OSL(_SYMBOL),          OSL(_APPLICATION),     OSL(_TMUX),          _______,           _______, 
    _______,              _______,             _______,         _______,        KC_0,                      _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              KC_MINUS,            _______,                                                                                                          _______,             XXXXXXX,               _______
  ),
  // shifted number layer
  [_SYMBOL] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    TO(_COLEMAKDH),       KC_GRAVE,            KC_TILD,         KC_LPRN,        KC_RPRN,                   ARROW,          _______,            _______,          _______,             ARROW,                 BRACES,                PARENS,              KC_DQUO,           _______, 
    _______,              KC_COLN,             KC_LABK,         KC_LBRACKET,    KC_RBRACKET,               KC_PLUS,        _______,            _______,          _______,             CUSTOM_OSM_SHIFT,      CUSTOM_OSM_CTRL,       CUSTOM_OSM_ALT,      OSM(MOD_LGUI),     _______, 
    _______,              KC_PIPE,             KC_RABK,         KC_LCBR,        KC_RCBR,                   KC_UNDS,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,         _______,        _______,                   _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,                                                                                                          _______,             _______,               _______
  ),
  // fn layer
  [_FN] = LAYOUT_moonlander(
    KC_F18,               KC_F19,              KC_F20,          KC_F21,         KC_F22,                    KC_F23,         _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    KC_F17,               KC_F12,              KC_F7,           KC_F8,          KC_F9,                     KC_PSCREEN,     _______,            _______,          _______,             XXXXXXX,               XXXXXXX,               XXXXXXX,             XXXXXXX,           _______, 
    KC_F16,               KC_F11,              KC_F4,           KC_F5,          KC_F6,                     KC_SCROLLLOCK,  _______,            _______,          XXXXXXX,             KC_LSHIFT,             KC_LCTRL,              KC_LALT,             KC_LGUI,           _______,
    KC_F15,               KC_F10,              KC_F1,           KC_F2,          KC_F3,                     KC_PAUSE,                                             _______,             _______,               _______,               _______,             _______,           _______, 
    KC_F14,               KC_F13,              _______,         _______,        KC_APPLICATION,            _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    KC_SPACE,             KC_TAB,              KC_F24,                                                                                                           _______,             _______,               _______
  ),
  // applications layer
  [_APPLICATION] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             HYPR(KC_7),      HYPR(KC_8),     HYPR(KC_9),                _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             HYPR(KC_4),      HYPR(KC_5),     HYPR(KC_6),                _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             HYPR(KC_1),      HYPR(KC_2),     HYPR(KC_3),                _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,         _______,        _______,                   _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,                                                                                                          _______,             _______,               _______
  ),
  // tmux layer
  [_TMUX] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,         TMUX_FZF,       _______,                   TMUX_SWITCH_WINDOW,_______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,         TMUX_FZF_SESSION,_______,                  _______,        _______,            _______,          TMUX_LEFT_PANE,      TMUX_DOWN_PANE,        TMUX_UP_PANE,          TMUX_RIGHT_PANE,     _______,           _______, 
    _______,              TMUX_ALT_TAB,        TMUX_CLOSE_PANE, _______,        _______,                   TMUX_SWITCH_SESSION,                                  _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,         _______,        _______,                   _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,                                                                                                          _______,             _______,               _______
  ),
  // keynav layer
  [_KEYNAV] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,          _______,         
    TO(_COLEMAKDH),       KC_Q,                KC_W,            TD(DANCE_13),   KC_P,                      KC_B,           _______,            _______,          KC_J,                KC_L,                  KC_U,                  KC_Y,                KC_QUOTE,         _______,
    _______,              KC_A,                TD(DANCE_11),    TD(DANCE_12),   TD(DANCE_14),              KC_G,           _______,            _______,          KC_M,                KC_N,                  KC_E,                  KC_I,                KC_O,             _______,
    _______,              KC_MS_WH_UP,         KC_X,            KC_MS_WH_DOWN,  KC_D,                      KC_V,                                                 KC_K,                KC_H,                  KC_COMMA,              KC_DOT,              KC_SLASH,         _______,
    _______,              _______,             _______,         _______,        KC_ESCAPE,                 _______,                                              _______,             _______,               _______,               _______,             _______,          _______,
    KC_SPACE,             _______,             _______,                                                                                                          _______,             _______,               KC_BSPACE
  ),
  // plover layer
  [_PLOVER] = LAYOUT_moonlander(
    XXXXXXX,              KC_1,                KC_2,            KC_3,           KC_4,                      KC_5,           XXXXXXX,            XXXXXXX,          KC_6,                KC_7,                  KC_8,                  KC_9,                KC_0,              XXXXXXX,
    PLOVER_OFF,           KC_Q,                KC_W,            KC_E,           KC_R,                      KC_T,           XXXXXXX,            _______,          KC_Y,                KC_U,                  KC_I,                  KC_O,                KC_P,              KC_LBRACKET,
    _______,              KC_A,                KC_S,            KC_D,           KC_F,                      KC_G,           XXXXXXX,            KC_ASTG,          KC_H,                KC_J,                  KC_K,                  KC_L,                KC_SCOLON,         KC_QUOTE,
    _______,              SWITCH_APPS,         XXXXXXX,         XXXXXXX,        XXXXXXX,                   PLOVER_LOOKUP,                                        _______,             XXXXXXX,               XXXXXXX,               XXXXXXX,             XXXXXXX,           _______,
    _______,              _______,             XXXXXXX,         KC_C,           KC_V,                      _______,                                              _______,             KC_N,                  KC_M,                  XXXXXXX,             _______,           _______,
    _______,              _______,             PLOVER_OFF,                                                                                                       _______,             XXXXXXX,               KC_BSPACE
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
    KC_GRAVE,             KC_1,                KC_2,            KC_3,           KC_4,                      KC_5,           KC_BSLASH,          KC_PSCREEN,       KC_6,                KC_7,                  KC_8,                  KC_9,                 KC_0,             KC_MINUS,       
    KC_TAB,               KC_Q,                KC_W,            KC_E,           KC_R,                      KC_T,           KC_DELETE,          TO(_COLEMAKDH),   KC_Y,                KC_U,                  KC_I,                  KC_O,                 KC_P,             KC_EQUAL,       
    KC_CAPSLOCK,          KC_A,                KC_S,            KC_D,           KC_F,                      KC_G,           KC_BSPACE,          KC_BSPACE,        KC_H,                KC_J,                  KC_K,                  KC_L,                 KC_SCOLON,        KC_QUOTE,       
    KC_LSHIFT,            KC_Z,                KC_X,            KC_C,           KC_V,                      KC_B,                                                 KC_N,                KC_M,                  KC_COMMA,              KC_DOT,               KC_SLASH,         KC_RSHIFT,      
    KC_LCTRL,             KC_LGUI,             KC_LALT,         KC_LEFT,        KC_RIGHT,                  KC_ESCAPE,                                            KC_ESCAPE,           KC_UP,                 KC_DOWN,               KC_LBRACKET,          KC_RBRACKET,      KC_LCTRL,       
    KC_SPACE,             KC_TAB,              KC_ESCAPE,                                                                                                        KC_DELETE,           KC_ENTER,              KC_BSPACE
  ),
};

extern bool g_suspend_state;
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

    [_PLOVER] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,0}, {0,183,238}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,0}, {0,183,238}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,183,238}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,0}, {0,183,238}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,0}, {0,183,238}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,0}, {0,0,0}, {85,203,158}, {33,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {169,120,255} },

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
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
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
    case _PLOVER:
      set_layer_color(_PLOVER);
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

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_ARROW:
    case LA_NUMBER:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_ARROW:
    case LA_NUMBER:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

static uint16_t idle_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // https://www.reddit.com/r/olkb/comments/wrgv05/can_i_prevent_hold_action_for_taphold_keys_unless/#
  // https://getreuer.info/posts/keyboards/triggers/index.html
  idle_timer = (record->event.time + IDLE_TIMEOUT_MS) | 1;

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
    case DELETE_BRACES:
      if (record->event.pressed) {
        tap_code(KC_BSPACE);  // Move cursor between braces.
        tap_code(KC_DELETE);  // Move cursor between braces.
      }
      return false;
    // https://www.reddit.com/r/olkb/comments/afm9ii/qmk_macro_in_modtap_keys/
    case TMUX_ALT_TAB:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("a") SS_LCTL("a"));
      }
      return false;
    case TMUX_FZF:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("a") SS_LSFT("f"));
      }
      return false;
    case TMUX_FZF_SESSION:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("a")"s");
      }
      return false;
    case TMUX_CLOSE_PANE:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("a")"x");
      }
      return false;
    case TMUX_LEFT_PANE:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("a")SS_TAP(X_LEFT));
      }
      return false;
    case TMUX_DOWN_PANE:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("a")SS_TAP(X_DOWN));
      }
      return false;
    case TMUX_UP_PANE:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("a")SS_TAP(X_UP));
      }
      return false;
    case TMUX_RIGHT_PANE:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("a")SS_TAP(X_RIGHT));
      }
      return false;
    case TMUX_SWITCH_SESSION:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("a")"v");
      }
      return false;
    case KEYNAV:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("`"));
      }
      return false;
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
    case CUSTOM_OSM_SHIFT:
      if (record->event.pressed) {
          set_oneshot_mods(MOD_MASK_SHIFT);
          set_oneshot_layer(_SYMBOL, ONESHOT_START);
      }
      return false;
    case CUSTOM_OSM_CTRL:
      if (record->event.pressed) {
          set_oneshot_mods(MOD_MASK_CTRL);
          set_oneshot_layer(_SYMBOL, ONESHOT_START);
      }
      return false;
    case CUSTOM_OSM_ALT:
      if (record->event.pressed) {
          set_oneshot_mods(MOD_MASK_ALT);
          set_oneshot_layer(_SYMBOL, ONESHOT_START);
      }
      return false;
    case PLOVER_LOOKUP:
      if (record->event.pressed) {
        register_code(KC_E);
        register_code(KC_R);
        register_code(KC_F);
        register_code(KC_C);
        register_code(KC_V);
        register_code(KC_K);
        register_code(KC_L);
      } else {
        unregister_code(KC_E);
        unregister_code(KC_R);
        unregister_code(KC_F);
        unregister_code(KC_C);
        unregister_code(KC_V);
        unregister_code(KC_K);
        unregister_code(KC_L);

        register_code(KC_Q);
        register_code(KC_W);
        register_code(KC_E);
        register_code(KC_R);

        unregister_code(KC_Q);
        unregister_code(KC_W);
        unregister_code(KC_E);
        unregister_code(KC_R);
         
        layer_on(_COLEMAKDH);
        layer_off(_PLOVER);
      }
      return false;
    case PLOVER_ON:
      if (record->event.pressed) {
        register_code(KC_LCTRL);
        register_code(KC_LSHIFT);
        register_code(KC_LGUI);
        register_code(KC_W);
        unregister_code(KC_W);
        unregister_code(KC_LGUI);
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LCTRL);
        // You have to do this in order to trigger Plover
        register_code(KC_Q);
        register_code(KC_W);
        register_code(KC_E);
        register_code(KC_R);
      } else {
        unregister_code(KC_Q);
        unregister_code(KC_W);
        unregister_code(KC_E);
        unregister_code(KC_R);
        combo_disable();
        layer_off(_COLEMAKDH);
        layer_on(_PLOVER);
      }
      return false;
    case PLOVER_OFF:
      if (record->event.pressed) {
        register_code(KC_Q);
        register_code(KC_W);
        register_code(KC_E);
        register_code(KC_R);
      } else {
        unregister_code(KC_Q);
        unregister_code(KC_W);
        unregister_code(KC_E);
        unregister_code(KC_R);
        combo_enable();
        layer_on(_COLEMAKDH);
        layer_off(_PLOVER);
      }
      return false;
    // case KEYNAV_LEFT:
    //   return process_tap_or_long_press_key(record, S(KC_R));
    // case KEYNAV_DOWN:
    //   return process_tap_or_long_press_key(record, S(KC_S));
    // case KEYNAV_UP:
    //   return process_tap_or_long_press_key(record, S(KC_F));
    // case KEYNAV_RIGHT:
    //   return process_tap_or_long_press_key(record, S(KC_T));
  }

  update_oneshot(
      &os_shft_state, KC_LSFT, OS_SHFT,
      keycode, record
  );
  update_oneshot(
      &os_ctrl_state, KC_LCTL, OS_CTRL,
      keycode, record
  );
  update_oneshot(
      &os_alt_state, KC_LALT, OS_ALT,
      keycode, record
  );
  update_oneshot(
      &os_cmd_state, KC_LGUI, OS_CMD,
      keycode, record
  );
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_A:
    case KC_G:
    case KC_ESCAPE:
    case KC_SPACE:
      if (layer_state_is(_KEYNAV)) {
        layer_move(_COLEMAKDH);
      }
      break;
  }
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

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: 
          register_code16(KC_LCTL); 
          register_code16(KC_GRAVE); 
          layer_on(_KEYNAV);
          break;
        case SINGLE_HOLD:
          register_code16(KC_LSFT); 
          register_code16(KC_LCTL); 
          register_code16(KC_GRAVE); 
          layer_on(_KEYNAV);
          break;
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: 
          unregister_code16(KC_LCTL); 
          unregister_code16(KC_GRAVE); 
          break;
        case SINGLE_HOLD:
          unregister_code16(KC_LSFT); 
          unregister_code16(KC_LCTL); 
          unregister_code16(KC_GRAVE); 
          break;
    }
    dance_state[1].step = 0;
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

void dance_11_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_11_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_R); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_R)); break;
    }
}

void dance_11_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_R); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_R)); break;
    }
    dance_state[11].step = 0;
}

void dance_12_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_12_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_12_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_S); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_S)); break;
    }
}

void dance_12_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_S); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_S)); break;
    }
    dance_state[12].step = 0;
}

void dance_13_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_13_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_13_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_F); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_F)); break;
    }
}

void dance_13_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_F); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_F)); break;
    }
    dance_state[13].step = 0;
}

void dance_14_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_14_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_14_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(KC_T); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_T)); break;
    }
}

void dance_14_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(KC_T); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_T)); break;
    }
    dance_state[14].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        // KEYNAV_LEFT
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_11_finished, dance_11_reset),
        // KEYNAV_DOWN
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_12_finished, dance_12_reset),
        // KEYNAV_UP
        [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_13_finished, dance_13_reset),
        // KEYNAV_RIGHT
        [DANCE_14] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_14_finished, dance_14_reset),
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
