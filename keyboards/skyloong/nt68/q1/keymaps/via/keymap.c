// Copyright 2021 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define WIN_LOCK_INDEX 60
#define WIN_MOD_INDEX 17
#define MAC_MOD_INDEX 18

enum layer_names {
    _WIN,
    _MAC,
    _WIN_INDEX,
    _MAC_INDEX,
};

int FN_ON = 0;
bool WIN_LOCK = 0;
bool L_WIN = 0;
bool L_MAC = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WIN] = LAYOUT(
         KC_ESC,            KC_1,     KC_2,     KC_3,     KC_4,    KC_5,     KC_6,     KC_7,      KC_8,     KC_9,      KC_0,    KC_MINS,   KC_EQL,   KC_BSPC,    KC_INS,
         KC_TAB,            KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,     KC_Y,     KC_U,      KC_I,     KC_O,      KC_P,    KC_LBRC,  KC_RBRC,   KC_BSLS,    KC_DEL,
        KC_CAPS,            KC_A,     KC_S,     KC_D,     KC_F,    KC_G,     KC_H,     KC_J,      KC_K,     KC_L,   KC_SCLN,    KC_QUOT,   KC_ENT,              KC_PGUP,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,     KC_N,     KC_M,   KC_COMM,   KC_DOT,   KC_SLSH,    KC_RSFT,    KC_UP,              KC_PGDN,
        MO(_WIN_INDEX),  KC_LCTL,  KC_LGUI,  KC_LALT,            KC_SPC,                                 KC_RALT,   KC_RCTL,    KC_LEFT,  KC_DOWN,             KC_RIGHT
    ),

     [_MAC] = LAYOUT(
         KC_ESC,            KC_1,     KC_2,     KC_3,     KC_4,    KC_5,     KC_6,     KC_7,       KC_8,     KC_9,      KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,    KC_INS,
         KC_TAB,            KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,     KC_Y,     KC_U,       KC_I,     KC_O,      KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,    KC_DEL,
        KC_CAPS,            KC_A,     KC_S,     KC_D,     KC_F,    KC_G,     KC_H,     KC_J,       KC_K,     KC_L,   KC_SCLN,     KC_QUOT,   KC_ENT,              KC_PGUP,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,     KC_N,     KC_M,    KC_COMM,   KC_DOT,   KC_SLSH,     KC_RSFT,    KC_UP,              KC_PGDN,
        MO(_MAC_INDEX),  KC_LCTL,  KC_LALT,  KC_LGUI,            KC_SPC,                                  KC_RGUI,   KC_RALT,     KC_LEFT,  KC_DOWN,             KC_RIGHT
    ),

    [_WIN_INDEX] =  LAYOUT(
         KC_GRV,    KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,      KC_F8,    KC_F9,   KC_F10,    KC_F11,   KC_F12,    KC_DEL,    KC_INS,
        _______,  _______,   _______,  _______,  _______,  _______,     _______,  _______,    _______,  _______,  _______,   RM_PREV,  RM_NEXT,   RM_TOGG,    KC_DEL,
        _______,  _______,   _______,  _______,  _______,  _______,     _______,  _______,    _______,  _______,  _______,   _______,  _______,              KC_HOME,
        _______,  _______,   _______,  _______,  _______,  _______,     _______,  _______,    _______,  _______,  _______,   _______,  RM_VALU,               KC_END,
        _______,  _______,   KC_LGUI,  KC_LALT,            _______,                                     KC_RALT,   KC_APP,   RM_SPDD,  RM_VALD,              RM_SPDU
    ),

    [_MAC_INDEX] = LAYOUT(
        KC_GRV ,   KC_F14,    KC_F15, C(KC_UP),  G(KC_D), G(KC_SPC),  LSG(KC_4),  KC_MPRV,    KC_MPLY,  KC_MNXT,  KC_MUTE,   KC_VOLD,  KC_VOLU,    KC_DEL,    KC_INS,
        _______,  _______,   _______,  _______,  _______,   _______,    _______,  _______,    _______,  _______,  _______,   RM_PREV,  RM_NEXT,   RM_TOGG,    KC_DEL,
        _______,  _______,   _______,  _______,  _______,   _______,    _______,  _______,    _______,  _______,  _______,   _______,  _______,              KC_HOME,
        _______,  _______,   _______,  _______,  _______,   _______,    _______,  _______,    _______,  _______,  _______,   _______,  RM_VALU,               KC_END,
        _______,  _______,   KC_LALT,  KC_LGUI,             _______,                                    KC_RGUI,  KC_RALT,   RM_SPDD,  RM_VALD,              RM_SPDU
    )
};

#if defined(DIP_SWITCH_MAP_ENABLE)
const uint16_t PROGMEM dip_switch_map[NUM_DIP_SWITCHES][NUM_DIP_STATES] = {
    DIP_SWITCH_OFF_ON(DF(_WIN), DF(_MAC)),
};
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    if (WIN_LOCK) {
        RGB_MATRIX_INDICATOR_SET_COLOR(WIN_LOCK_INDEX, 255, 255, 255);
    } else {
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(WIN_LOCK_INDEX, 0, 0, 0);
        }
    }

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
    case DF(_WIN):
      if (record->event.pressed) {
       L_WIN = 1;
       L_MAC = 0;
       layer_move(0);
       set_single_persistent_default_layer(0); // Save default layer 0 to eeprom
      } else {
       L_WIN = 0;
      }
      return false; // cancel all further processing of this key

    case DF(_MAC):
      if (record->event.pressed) {
       L_MAC = 1;
       L_WIN = 0;
       layer_move(1);
       set_single_persistent_default_layer(1);  //Save default layer 1 to eeprom
      } else {
       L_MAC = 0;
      }
      return false; // cancel  all further processing of this key

    case MO(_WIN_INDEX):
      if (record->event.pressed) {
       FN_ON = 1;
      } else {
       FN_ON = 0;
      }
      return true;

    case MO(_MAC_INDEX):
      if (record->event.pressed) {
       FN_ON = 1;
      } else {
       FN_ON = 0;
      }
      return true;

    case KC_LGUI:
      if (FN_ON){
          if ( record->event.pressed){
             WIN_LOCK = !WIN_LOCK ; //change win lock state
            }
          if (!WIN_LOCK) {
             return false; //windows key locked do nothing
            }
        }
      if (WIN_LOCK) {
             return false; //windows key locked do nothing
            }
      return true;  // continue all further processing of this key

    default:
       L_MAC = 0;
       L_WIN = 0;
      return true;
    }
}
