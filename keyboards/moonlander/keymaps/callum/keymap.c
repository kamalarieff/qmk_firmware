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

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

#define _COLEMAKDH 0
#define _SYMBOL 1
#define _ARROW 2
#define _FN 3
#define _BACKUP 4
#define _ARROW1 5
#define _MOUSE 6
#define _NUMBER 7
#define _SYMBOL1 8
#define _FN1 9
#define _ADDITIONAL 10
#define _GAMING 11

enum custom_keycodes {
  PLOVER_ON = ML_SAFE_RANGE,
  PLOVER_OFF,
  PLOVER_LOOKUP,
  LEFT_MONITOR,
  RIGHT_MONITOR,
  NEXT_DESKTOP,
  PREV_DESKTOP,
  SWITCH_APPS,
  TOGGL,
  KEYNAV,
  ARROW,
  BRACES,
  PARENS,
  DELETE_BRACES,
  TOGGLE_LAYOUT,
  LTAP_ADDITIONAL_ESCAPE,
  TMUX_ALT_TAB,
};


enum combos {
  HCOMMA_SEMICOLON
};

const uint16_t PROGMEM hcomma_combo[] = {KC_H, KC_COMMA, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [HCOMMA_SEMICOLON] = COMBO(hcomma_combo, KC_SCOLON),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // colemak-dh base
  [_COLEMAKDH] = LAYOUT_moonlander(
    TO(_BACKUP),          _______,             _______,         _______,        _______,                   KC_MEH,         DYN_REC_START1,     DYN_REC_START2,   KC_HYPR,             _______,               _______,               _______,             _______,          TO(_GAMING),         
    KC_LEAD,              KC_Q,                KC_W,            KC_F,           KC_P,                      KC_B,           DYN_MACRO_PLAY1,    DYN_MACRO_PLAY2,  KC_J,                KC_L,                  KC_U,                  KC_Y,                KC_QUOTE,         KC_BSPACE,
    TO(_COLEMAKDH),       KC_A,                KC_R,            KC_S,           KC_T,                      KC_G,           DYN_REC_STOP,       DYN_REC_STOP,     KC_M,                KC_N,                  KC_E,                  KC_I,                KC_O,             _______,
    TOGGLE_LAYOUT,        KC_Z,                KC_X,            KC_C,           KC_D,                      KC_V,                                                 KC_K,                KC_H,                  KC_COMMA,              KC_DOT,              KC_SLASH,         LCTL(KC_A),
    _______,              _______,             _______,         _______,        MO(_ARROW),                _______,                                              _______,             MO(_SYMBOL),           _______,               _______,             _______,          _______,
    KC_SPACE,            _______,             _______,                                                                                                          _______,             _______,               KC_BSPACE
  ),
  // symbol layer
  [_SYMBOL] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              KC_TAB,              KC_LBRACKET,     KC_LCBR,        KC_LPRN,                   KC_TILD,        _______,            _______,          KC_CIRC,             KC_RPRN,               KC_RCBR,               KC_RBRACKET,         KC_GRAVE,          _______, 
    _______,              KC_MINUS,            KC_ASTERISK,     KC_EQUAL,       KC_UNDS,                   KC_DLR,         _______,            _______,          KC_HASH,             OSM(MOD_LSFT),         OSM(MOD_LCTL),         OSM(MOD_LALT),       OSM(MOD_LGUI),     _______, 
    _______,              KC_PLUS,             KC_PIPE,         KC_AT,          KC_SLASH,                  KC_PERC,                                              XXXXXXX,             KC_BSLASH,             KC_AMPR,               KC_QUES,             KC_EXLM,           _______, 
    _______,              _______,             _______,         _______,        _______,                   _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,                                                                                                          _______,             _______,               _______
  ),
  // arrow keys
  [_ARROW] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              KC_ESCAPE,           LEFT_MONITOR,    _______,        RIGHT_MONITOR,             _______,        _______,            _______,          RESET,               LSFT(KC_INSERT),       LCTL(KC_INSERT),       KC_CAPSLOCK,         KC_DELETE,         _______, 
    _______,              OSM(MOD_LGUI),       OSM(MOD_LALT),   OSM(MOD_LCTL),  OSM(MOD_LSFT),             _______,        _______,            _______,          KC_LEFT,             KC_DOWN,               KC_UP,                 KC_RIGHT,            KC_BSPACE,         _______,
    _______,              SWITCH_APPS,         LGUI(KC_TAB),    _______,        _______,                   _______,                                              KC_HOME,             KC_PGDOWN,             KC_PGUP,               KC_END,              KC_ENTER,          _______, 
    _______,              _______,             _______,         _______,        _______,                   _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,                                                                                                          _______,             _______,               _______
  ),
  // fn layer
  [_FN] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              KC_F1,               KC_F2,           KC_F3,          KC_F4,                     KC_F5,          _______,            _______,          KC_F6,               KC_F7,                 KC_F8,                 KC_F9,               KC_F10,            _______, 
    _______,              OSM(MOD_LGUI),       OSM(MOD_LALT),   OSM(MOD_LCTL),  OSM(MOD_LSFT),             KC_F11,         _______,            _______,          KC_F12,              OSM(MOD_LSFT),         OSM(MOD_LCTL),         OSM(MOD_LALT),       OSM(MOD_LGUI),     _______, 
    _______,              KC_1,                KC_2,            KC_3,           KC_4,                      KC_5,                                                 KC_6,                KC_7,                  KC_8,                  KC_9,                KC_0,              _______,
    _______,              _______,             _______,         _______,        _______,                   _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,                                                                                                          _______,             _______,               _______
  ),
  // backup
  [_BACKUP] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   KC_MEH,         DYN_REC_START1,     DYN_REC_START2,   KC_HYPR,             _______,               _______,               _______,             _______,          TO(_GAMING),         
    KC_LEAD,              KC_Q,                KC_W,            KC_F,           KC_P,                      KC_B,           DYN_MACRO_PLAY1,    DYN_MACRO_PLAY2,  KC_J,                KC_L,                  KC_U,                  KC_Y,                KC_QUOTE,         KC_BSPACE,
    _______,              LGUI_T(KC_A),        LALT_T(KC_R),    LCTL_T(KC_S),   LSFT_T(KC_T),              KC_G,           DYN_REC_STOP,       DYN_REC_STOP,     KC_M,                RSFT_T(KC_N),          LCTL_T(KC_E),          LALT_T(KC_I),        LGUI_T(KC_O),     _______,
    TOGGLE_LAYOUT,        KC_Z,                KC_X,            KC_C,           KC_D,                      KC_V,                                                 KC_K,                KC_H,                  KC_COMMA,              KC_DOT,              KC_SLASH,         LCTL(KC_A),
    _______,              _______,             LALT(KC_RIGHT),  LALT(KC_LEFT),  LT(_ADDITIONAL,KC_ESCAPE), _______,                                              _______,             LT(_FN1,KC_DELETE),    LALT(KC_LEFT),         LALT(KC_RIGHT),      _______,          _______,
    LT(_ARROW1,KC_SPACE), LT(_MOUSE,KC_TAB),   PLOVER_ON,                                                                                                        _______,             LT(_SYMBOL1,KC_ENTER), LT(_NUMBER,KC_BSPACE)
  ),
  // arrow backup
  [_ARROW1] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              XXXXXXX,             XXXXXXX,         XXXXXXX,        XXXXXXX,                   XXXXXXX,        _______,            _______,          LCTL(KC_Y),          LSFT(KC_INSERT),       LCTL(KC_INSERT),       LSFT(KC_DELETE),     LCTL(KC_Z),        _______, 
    _______,              KC_LGUI,             KC_LALT,         KC_LCTRL,       KC_LSHIFT,                 XXXXXXX,        _______,            _______,          KC_LEFT,             KC_DOWN,               KC_UP,                 KC_RIGHT,            KC_CAPSLOCK,       _______, 
    _______,              XXXXXXX,             KC_RALT,         XXXXXXX,        XXXXXXX,                   XXXXXXX,                                              KC_HOME,             KC_PGDOWN,             KC_PGUP,               KC_END,              KC_INSERT,         _______, 
    _______,              _______,             _______,         _______,        XXXXXXX,                   _______,                                              _______,             KC_DELETE,             _______,               _______,             _______,           _______, 
    _______,              XXXXXXX,             XXXXXXX,                                                                                                          _______,             KC_ENTER,              KC_BSPACE
  ),
  // mouse keys
  [_MOUSE] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              XXXXXXX,             KC_MS_WH_UP,     KC_MS_UP,       KC_MS_WH_DOWN,             _______,        _______,            _______,          XXXXXXX,             KC_MS_ACCEL2,          KC_MS_ACCEL1,          KC_MS_ACCEL0,        XXXXXXX,           _______, 
    _______,              KC_LGUI,             KC_MS_LEFT,      KC_MS_DOWN,     KC_MS_RIGHT,               _______,        _______,            _______,          XXXXXXX,             KC_LSHIFT,             KC_LCTRL,              KC_LALT,             KC_LGUI,           _______, 
    _______,              XXXXXXX,             KC_MS_BTN1,      KC_MS_BTN3,     KC_MS_BTN2,                _______,                                              KC_MS_WH_LEFT,       KC_MS_WH_DOWN,         KC_MS_WH_UP,           KC_MS_WH_RIGHT,      XXXXXXX,           _______, 
    _______,              _______,             _______,         _______,        _______,                   _______,                                              _______,             KC_MS_BTN2,            _______,               _______,             _______,           _______, 
    _______,              _______,             _______,                                                                                                          _______,             KC_MS_BTN1,            KC_MS_BTN3
  ),
  // number layer
  [_NUMBER] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              KC_LBRACKET,         KC_7,            KC_8,           KC_9,                      KC_RBRACKET,    _______,            _______,          XXXXXXX,             LCTL(KC_A),            TMUX_ALT_TAB,          XXXXXXX,             _______,           _______, 
    _______,              KC_SCOLON,           KC_4,            KC_5,           KC_6,                      KC_EQUAL,       _______,            _______,          KC_BSPACE,           _______,               _______,               _______,             _______,           _______, 
    _______,              KC_GRAVE,            KC_1,            KC_2,           KC_3,                      KC_BSLASH,                                            XXXXXXX,             XXXXXXX,               XXXXXXX,               XXXXXXX,             _______,           _______, 
    _______,              _______,             _______,         _______,        KC_DOT,                    _______,                                              _______,             XXXXXXX,               _______,               _______,             _______,           _______, 
    KC_0,                 KC_MINUS,            _______,                                                                                                          _______,             XXXXXXX,               XXXXXXX
  ),
  // shifted number layer
  [_SYMBOL1] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              KC_LCBR,             ARROW,           BRACES,         PARENS,                    KC_RCBR,        _______,            _______,          _______,             XXXXXXX,               XXXXXXX,               XXXXXXX,             _______,           _______, 
    _______,              KC_COLN,             KC_DLR,          KC_PERC,        KC_CIRC,                   KC_PLUS,        _______,            _______,          DELETE_BRACES,       _______,               _______,               _______,             _______,           _______, 
    _______,              KC_TILD,             KC_EXLM,         KC_AT,          KC_HASH,                   KC_PIPE,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              _______,             _______,         _______,        KC_LPRN,                   _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    KC_RPRN,              KC_UNDS,             _______,                                                                                                          _______,             _______,               _______
  ),
  // fn backup
  [_FN1] = LAYOUT_moonlander(
    KC_F18,               KC_F19,              KC_F20,          KC_F21,         KC_F22,                    KC_F23,         _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    KC_F17,               KC_F12,              KC_F7,           KC_F8,          KC_F9,                     KC_PSCREEN,     _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    KC_F16,               KC_F11,              KC_F4,           KC_F5,          KC_F6,                     KC_SCROLLLOCK,  _______,            _______,          XXXXXXX,             _______,               _______,               _______,             _______,           _______, 
    KC_F15,               KC_F10,              KC_F1,           KC_F2,          KC_F3,                     KC_PAUSE,                                             _______,             _______,               _______,               _______,             _______,           _______, 
    KC_F14,               KC_F13,              _______,         _______,        KC_APPLICATION,            _______,                                              _______,             _______,               _______,               _______,             _______,           _______, 
    KC_SPACE,             KC_TAB,              KC_F24,                                                                                                           _______,             _______,               _______
  ),
  // additional layer
  [_ADDITIONAL] = LAYOUT_moonlander(
    _______,              _______,             _______,         _______,        _______,                   _______,        _______,            _______,          _______,             _______,               _______,               _______,             _______,           _______, 
    _______,              PREV_DESKTOP,        XXXXXXX,         XXXXXXX,        XXXXXXX,                   NEXT_DESKTOP,   _______,            _______,          XXXXXXX,             KC_BRIGHTNESS_DOWN,    KC_BRIGHTNESS_UP,      XXXXXXX,             XXXXXXX,           _______, 
    _______,              TOGGL,               LEFT_MONITOR,    KC_LCTRL,       RIGHT_MONITOR,             XXXXXXX,        _______,            _______,          KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN,     KC_AUDIO_VOL_UP,       KC_MEDIA_NEXT_TRACK, XXXXXXX,           _______, 
    _______,              SWITCH_APPS,         LGUI(KC_TAB),    XXXXXXX,        KEYNAV,                    XXXXXXX,                                              XXXXXXX,             XXXXXXX,               XXXXXXX,               XXXXXXX,             XXXXXXX,           _______, 
    _______,              _______,             _______,         _______,        _______,                   _______,                                              _______,             KC_AUDIO_MUTE,         _______,               _______,             _______,           _______, 
    XXXXXXX,              XXXXXXX,             XXXXXXX,                                                                                                          _______,             KC_MEDIA_STOP,         KC_MEDIA_PLAY_PAUSE
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

    [_ARROW1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {154,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {205,255,255}, {205,255,255}, {154,255,255}, {0,0,0}, {105,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0} },

    [_MOUSE] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {32,176,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {105,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {205,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0} },

    [_ADDITIONAL] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {205,255,255}, {0,0,0}, {205,255,255}, {0,0,0}, {0,0,0}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {35,255,255}, {35,255,255}, {0,0,0}, {0,0,0} },

    [_NUMBER] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {205,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {205,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {205,255,255}, {205,255,255}, {205,255,255}, {154,255,255}, {0,0,0}, {105,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_SYMBOL] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {32,176,255}, {154,255,255}, {154,255,255}, {32,176,255}, {0,0,0}, {105,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0} },

    [_SYMBOL1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {32,176,255}, {154,255,255}, {154,255,255}, {32,176,255}, {0,0,0}, {105,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0} },

    [_FN] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {249,228,255}, {0,0,255}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_FN1] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {249,228,255}, {0,0,255}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_GAMING] = { {205,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {154,255,255}, {205,255,255}, {205,255,255}, {255,220,201}, {205,255,255}, {154,255,255}, {205,255,255}, {255,220,201}, {255,220,201}, {205,255,255}, {154,255,255}, {205,255,255}, {205,255,255}, {255,220,201}, {205,255,255}, {35,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {35,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {154,255,255}, {154,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {105,255,255}, {154,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {35,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {35,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {105,255,255}, {0,0,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {154,255,255} },

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
    case _ARROW1:
      set_layer_color(_ARROW1);
      break;
    case _MOUSE:
      set_layer_color(_MOUSE);
      break;
    case _ADDITIONAL:
      set_layer_color(_ADDITIONAL);
      break;
    case _NUMBER:
      set_layer_color(_NUMBER);
      break;
    case _SYMBOL:
      set_layer_color(_SYMBOL);
      break;
    case _SYMBOL1:
      set_layer_color(_SYMBOL1);
      break;
    case _FN:
      set_layer_color(_FN);
      break;
    case _FN1:
      set_layer_color(_FN1);
      break;
    case _GAMING:
      set_layer_color(_GAMING);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

uint16_t key_timer;

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
      }
      return false;
    case PARENS:  // Types () and puts cursor between parens.
      if (record->event.pressed) {
        SEND_STRING("()");
        tap_code(KC_LEFT);  // Move cursor between parens.
        set_mods(mods);  // Restore mods.
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
    case KEYNAV:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("`"));
      }
      return false;
    case TOGGL:
      if (record->event.pressed) {
          SEND_STRING(SS_LGUI("4"));
      }
      return false;
    case SWITCH_APPS:
      if (record->event.pressed) {
          SEND_STRING(SS_LGUI("`"));
      }
      return false;
    case PREV_DESKTOP:
      if (record->event.pressed) {
          SEND_STRING(SS_LGUI("["));
      }
      return false;
    case NEXT_DESKTOP:
      if (record->event.pressed) {
          SEND_STRING(SS_LGUI("]"));
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
      }
      return false;
  }
  return true;
}


LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_Q) {
      layer_on(_NUMBER);
    }
    SEQ_ONE_KEY(KC_P) {
      layer_on(_MOUSE);
    }
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMBOL, _ARROW, _FN);
}
