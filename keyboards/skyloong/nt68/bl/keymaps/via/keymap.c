// Copyright 2021 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
        KC_LCTL,  MO(_WIN_INDEX),  KC_LGUI,  KC_LALT,            KC_SPC,                                 KC_RALT,    KC_APP,    KC_LEFT,  KC_DOWN,             KC_RIGHT
    ),

     [_MAC] = LAYOUT(
         KC_ESC,            KC_1,     KC_2,     KC_3,     KC_4,    KC_5,     KC_6,     KC_7,       KC_8,     KC_9,      KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,    KC_INS,
         KC_TAB,            KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,     KC_Y,     KC_U,       KC_I,     KC_O,      KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,    KC_DEL,
        KC_CAPS,            KC_A,     KC_S,     KC_D,     KC_F,    KC_G,     KC_H,     KC_J,       KC_K,     KC_L,   KC_SCLN,     KC_QUOT,   KC_ENT,              KC_PGUP,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,     KC_N,     KC_M,    KC_COMM,   KC_DOT,   KC_SLSH,     KC_RSFT,    KC_UP,              KC_PGDN,
        KC_LCTL,  MO(_MAC_INDEX),  KC_LALT,  KC_LGUI,            KC_SPC,                                  KC_RGUI,   KC_RALT,     KC_LEFT,  KC_DOWN,             KC_RIGHT
    ),

    [_WIN_INDEX] =  LAYOUT(
         KC_GRV,    KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,      KC_F8,    KC_F9,   KC_F10,    KC_F11,   KC_F12,    KC_DEL,    KC_INS,
        _______,  _______,   _______,  _______,  _______,  _______,     _______,  _______,    _______,  _______,  _______,   BL_TOGG,  BL_BRTG,   BL_BRTG,    KC_DEL,
        _______,  _______,   _______,  _______,  _______,  _______,     _______,  _______,    _______,  _______,  _______,   _______,  _______,              KC_HOME,
        _______,  _______,   _______,  _______,  _______,  _______,     _______,  _______,    _______,  _______,  _______,   _______,    BL_UP,               KC_END,
        _______,  _______,   KC_LGUI,  KC_LALT,            _______,                                     KC_RALT,  KC_RCTL,    BL_OFF,  BL_DOWN,                BL_ON
    ),

    [_MAC_INDEX] = LAYOUT(
        KC_GRV ,   KC_F14,    KC_F15, C(KC_UP),  G(KC_D), G(KC_SPC),  LSG(KC_4),  KC_MPRV,    KC_MPLY,  KC_MNXT,  KC_MUTE,   KC_VOLD,  KC_VOLU,    KC_DEL,    KC_INS,
        _______,  _______,   _______,  _______,  _______,   _______,    _______,  _______,    _______,  _______,  _______,   BL_TOGG,  BL_BRTG,   BL_BRTG,    KC_DEL,
        _______,  _______,   _______,  _______,  _______,   _______,    _______,  _______,    _______,  _______,  _______,   _______,  _______,              KC_HOME,
        _______,  _______,   _______,  _______,  _______,   _______,    _______,  _______,    _______,  _______,  _______,   _______,    BL_UP,               KC_END,
        _______,  _______,   KC_LALT,  KC_LGUI,             _______,                                    KC_RGUI,  KC_RALT,    BL_OFF,  BL_DOWN,                BL_ON
    )
};

#if defined(DIP_SWITCH_MAP_ENABLE)
const uint16_t PROGMEM dip_switch_map[NUM_DIP_SWITCHES][NUM_DIP_STATES] = {
    DIP_SWITCH_OFF_ON(DF(_WIN), DF(_MAC)),
};
#endif


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
