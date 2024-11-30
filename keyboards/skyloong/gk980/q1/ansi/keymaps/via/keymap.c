// Copyright 2023 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define WIN_MOD_INDEX 23
#define MAC_MOD_INDEX 24

int FN_WIN = 0;
int FN_MAC = 0;
int L_WIN = 0;
int L_MAC = 0;

enum layer_names {
    _WIN,
    _MAC,
    _WIN_INDEX,
    _MAC_INDEX
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_WIN] =  LAYOUT_all(
         KC_ESC,              KC_F1,    KC_F2,    KC_F3,    KC_F4,       KC_F5,     KC_F6,     KC_F7,    KC_F8,     KC_F9,    KC_F10,   KC_F11,       KC_F12,    KC_MUTE,  KC_DEL,  KC_PGUP, KC_PGDN,   KC_PSCR,
         KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,       KC_8,     KC_9,      KC_0,   KC_MINS,   KC_EQL,      KC_BSPC,               KC_NUM,  KC_PSLS, KC_PAST,  KC_PMNS,
         KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,       KC_I,     KC_O,      KC_P,   KC_LBRC,  KC_RBRC,      KC_BSLS,                KC_P7,    KC_P8,   KC_P9,  KC_PPLS,
        KC_CAPS,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,       KC_K,     KC_L,   KC_SCLN,   KC_QUOT,                 KC_ENT,                KC_P4,    KC_P5,   KC_P6,
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,    KC_COMM,   KC_DOT,   KC_SLSH,                           KC_RSFT,      KC_UP,    KC_P1,    KC_P2,   KC_P3,  KC_PENT,
        KC_LCTL,  KC_LGUI,  KC_LALT,             KC_SPC,   KC_SPC,                 KC_SPC,             KC_RALT,     MO(_WIN_INDEX),    KC_RCTL,       KC_LEFT,    KC_DOWN,  KC_RGHT,    KC_P0,  KC_PDOT
    ),

     [_MAC] =  LAYOUT_all(
         KC_ESC,             KC_F14,   KC_F15, C(KC_UP),  G(KC_D),   G(KC_SPC), LAG(KC_EJCT),    KC_MPRV,  KC_MPLY,        KC_MNXT,   KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,   KC_DEL,  KC_PGUP, KC_PGDN,  KC_PSCR,
         KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,         KC_7,       KC_8,     KC_9,           KC_0,   KC_MINS,   KC_EQL,  KC_BSPC,               KC_NUM,  KC_PSLS, KC_PAST,  KC_PMNS,
         KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,         KC_U,       KC_I,     KC_O,           KC_P,   KC_LBRC,  KC_RBRC,  KC_BSLS,                KC_P7,    KC_P8,   KC_P9,  KC_PPLS,
        KC_CAPS,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,         KC_J,       KC_K,     KC_L,        KC_SCLN,   KC_QUOT,             KC_ENT,                KC_P4,    KC_P5,   KC_P6,
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,         KC_M,    KC_COMM,   KC_DOT,        KC_SLSH,                       KC_RSFT,      KC_UP,    KC_P1,    KC_P2,   KC_P3,  KC_PENT,
        KC_LCTL,  KC_LALT,  KC_LGUI,             KC_SPC,   KC_SPC,                    KC_SPC,              KC_RCMD, MO(_MAC_INDEX),  KC_RALT,             KC_LEFT,    KC_DOWN,  KC_RGHT,    KC_P0,  KC_PDOT
    ),

    [_WIN_INDEX] =  LAYOUT_all(
        _______,             KC_F14,   KC_F15, G(KC_TAB),  KC_WSCH,  G(C(KC_S)),   KC_SLEP,   KC_MPRV,  KC_MPLY,         KC_MNXT,   KC_MUTE,  KC_VOLD,     KC_VOLU,   G(KC_SPC),      KC_INS,      KC_HOME,  KC_END, KC_PAUSE,
        _______,  _______,  _______,  _______,   _______,  _______,    DF(_WIN),  DF(_MAC),   _______,  _______,         RM_TOGG,   RM_PREV,  RM_NEXT,      KC_DEL,                   KC_NUM,      KC_PSLS, KC_PAST,  KC_PMNS,
        _______,  _______,  _______,  _______,   _______,  _______,     _______,   _______,   _______,  _______,         _______,   _______,  _______,     _______,                    KC_P7,        KC_P8,   KC_P9,  KC_PPLS,
        _______,  _______,  _______,  _______,   _______,  _______,     _______,   _______,   _______,  _______,         _______,   _______,               _______,                    KC_P4,        KC_P5,   KC_P6,
        _______,  _______,  _______,  _______,   _______,  _______,     _______,   _______,   _______,  _______,         _______,                          _______,  RM_VALU,          KC_P1,        KC_P2,   KC_P3,  KC_PENT,
        KC_LCTL,  KC_LGUI,  KC_LALT,             _______,  _______,                _______,             KC_RALT,         _______,    KC_APP,               RM_SPDD,  RM_VALD,      RM_SPDU,          KC_P0,  KC_PDOT
    ),

    [_MAC_INDEX] = LAYOUT_all(
        _______,              KC_F1,    KC_F2,    KC_F3,    KC_F4,       KC_F5,     KC_F6,     KC_F7,    KC_F8,          KC_F9,     KC_F10,   KC_F11,   KC_F12,   G(KC_SPC),      KC_INS,      KC_HOME,  KC_END, KC_PAUSE,
        _______,  _______,  _______,  _______,  _______,  _______,    DF(_WIN),  DF(_MAC),   _______,  _______,        RM_TOGG,    RM_PREV,  RM_NEXT,   KC_DEL,                   KC_NUM,      KC_PSLS, KC_PAST,  KC_PMNS,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,   _______,   _______,  _______,        _______,    _______,  _______,  _______,                    KC_P7,        KC_P8,   KC_P9,  KC_PPLS,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,   _______,   _______,  _______,        _______,    _______,            _______,                    KC_P4,        KC_P5,   KC_P6,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,   _______,   _______,  _______,        _______,                        _______,  RM_VALU,          KC_P1,        KC_P2,   KC_P3,  KC_PENT,
        KC_LCTL,  KC_LALT,  KC_LGUI,            _______,  _______,                _______,             KC_RCMD,        _______,    KC_RALT,            RM_SPDD,  RM_VALD,      RM_SPDU,          KC_P0,  KC_PDOT
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_WIN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RM_VALD, RM_VALU),ENCODER_CCW_CW(C(MS_WHLD), C(MS_WHLU)), ENCODER_CCW_CW(G(C(KC_LEFT)), G(C(KC_RGHT)))},
    [_MAC] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_F14, KC_F15),ENCODER_CCW_CW(G(KC_MINS), G(KC_EQL)), ENCODER_CCW_CW(C(KC_UP), C(KC_DOWN))},
    [_WIN_INDEX] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RM_HUED, RM_HUEU), ENCODER_CCW_CW(RM_VALD, RM_VALU),ENCODER_CCW_CW(RM_SPDD, RM_SPDU), ENCODER_CCW_CW(RM_SATD, RM_SATU)},
    [_MAC_INDEX] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RM_HUED, RM_HUEU), ENCODER_CCW_CW(RM_VALD, RM_VALU),ENCODER_CCW_CW(RM_SPDD, RM_SPDU), ENCODER_CCW_CW(RM_SATD, RM_SATU)}
};
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

   switch (get_highest_layer(layer_state)) {
      case _WIN_INDEX:{
        RGB_MATRIX_INDICATOR_SET_COLOR(WIN_MOD_INDEX, 255, 255, 255);
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(MAC_MOD_INDEX, 0, 0, 0);
         }
      } break;
      case _MAC_INDEX:{
        RGB_MATRIX_INDICATOR_SET_COLOR(MAC_MOD_INDEX, 255, 255, 255);
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(WIN_MOD_INDEX, 0, 0, 0);
         }
      } break;

      case _WIN:{
       if (L_WIN) {
            RGB_MATRIX_INDICATOR_SET_COLOR(WIN_MOD_INDEX, 255, 255, 255);
            if (!rgb_matrix_get_flags()) {
               RGB_MATRIX_INDICATOR_SET_COLOR(MAC_MOD_INDEX, 0, 0, 0);
            }
            }else{
                if (!rgb_matrix_get_flags()) {
                   RGB_MATRIX_INDICATOR_SET_COLOR(WIN_MOD_INDEX, 0, 0, 0);
                 }
              }
         } break;

     case _MAC:{
       if (L_MAC) {
            RGB_MATRIX_INDICATOR_SET_COLOR(MAC_MOD_INDEX, 255, 255, 255);
            if (!rgb_matrix_get_flags()) {
               RGB_MATRIX_INDICATOR_SET_COLOR(WIN_MOD_INDEX, 0, 0, 0);
            }
            }else{
                if (!rgb_matrix_get_flags()) {
                   RGB_MATRIX_INDICATOR_SET_COLOR(MAC_MOD_INDEX, 0, 0, 0);
                 }
              }
         } break;

      default:{
         if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(WIN_MOD_INDEX, 0, 0, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(MAC_MOD_INDEX, 0, 0, 0);
         }
      }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#  ifdef RGB_MATRIX_ENABLE
    case RM_TOGG:
         if (record->event.pressed) {
            switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                    } break;
            }
        }
        return false;
    case RM_VALU:
       rgb_matrix_set_flags(LED_FLAG_ALL);
       return true;
#    endif
     case DF(_WIN):
      if (record->event.pressed) {
       L_WIN = 1;
       L_MAC = 0;
       layer_move(_WIN);
       set_single_persistent_default_layer(_WIN); // Save default layer 0 to eeprom
      } else {
       L_WIN = 0;
      }
      return false; // cancel all further processing of this key

     case MO(_WIN_INDEX):
      if (record->event.pressed) {
       FN_WIN = 1;
      } else {
       FN_WIN = 0;
      }
      return true; // continue all further processing of this key

     case DF(_MAC):
      if (record->event.pressed) {
       L_MAC = 1;
       L_WIN = 0;
       layer_move(_MAC);
       set_single_persistent_default_layer(_MAC);  //Save default layer 1 to eeprom
      } else {
       L_MAC = 0;
      }
      return false; // cancel  all further processing of this key

     case MO(_MAC_INDEX):
      if (record->event.pressed) {
       FN_MAC = 1;
      } else {
       FN_MAC = 0;
      }
      return true; // continue all further processing of this key
    default:
       L_MAC = 0;
       L_WIN = 0;
      return true;
    }
}
