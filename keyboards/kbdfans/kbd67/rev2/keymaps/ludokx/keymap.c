/* Copyright 2020 'elmo-space'
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <print.h>

uint32_t base_mode = 1; // Unlocked animation (solid)
uint32_t lock_mode = 5; // Locked animation (breathing)
uint16_t hue = 64;
uint16_t sat = 255;
uint16_t val = 255;

  /* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Home|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |PgUp|
   * |----------------------------------------------------------------|
   * |Caps   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Opt |Cmd |        Space          | Alt  | FN  |Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
[0] = LAYOUT_65_ansi_blocker(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, \
  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,  \
  KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RALT, MO(1),            KC_LEFT, KC_DOWN, KC_RGHT),
*/
[0] = LAYOUT_65_ansi_blocker(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, \
  KC_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,  \
  KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RALT, MO(1),            KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap Fn Layer
   * ,----------------------------------------------------------------.
   * |~ `|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |    |    |Up |   |RGB|   |   |   |PSc|SLk|Pau|   |   |     |    |
   * |----------------------------------------------------------------|
   * |      |Lef|Dow|Rig|   |   |   |   |   |   |   |   |        |    |
   * |----------------------------------------------------------------|
   * |        |Hud|Hui|Sad|Sai|Vad|Vai|   |   |   |   |      |PUp|    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |Hom|PDn|End |
   * `----------------------------------------------------------------'
   */
/*
[1] = LAYOUT_65_ansi_blocker(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS,  \
  KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
  KC_TRNS, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_PGUP, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS,          KC_HOME, KC_PGDN, KC_END),
*/

  /* Keymap Fn Layer
   * ,----------------------------------------------------------------.
   * |~ `|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |    |    |Up |   |RGB|   |   |   |PSc|SLk|Pau|   |   |     |    |
   * |----------------------------------------------------------------|
   * |      |Lef|Dow|Rig|   |   |   |   |   |   |   |   |        |    |
   * |----------------------------------------------------------------|
   * |        |Hud|Hui|Sad|Sai|Vad|Vai|   |   |   |   |      |PUp|    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |Hom|PDn|End |
   * `----------------------------------------------------------------'


   */
[1] = LAYOUT_65_ansi_blocker(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS,  \
  KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
  KC_TRNS, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, BL_TOGG, BL_DEC, BL_INC, BL_BRTG, KC_TRNS, KC_TRNS, KC_TRNS,          KC_PGUP, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS,          KC_HOME, KC_PGDN, KC_END),

};

void matrix_init_user() {
  rgblight_mode(base_mode);
  rgblight_enable();
  rgblight_sethsv(hue, sat, val);
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  led_t led_state = host_keyboard_led_state();
  switch (layer) {
    case 0: // Name of my 0-th layer (includes alphas and caps-lock)
      matrix_init_user();
    //   if (led_state.caps_lock) {
    //     rgblight_mode(lock_mode);
    //   } else {
    //     rgblight_mode(base_mode);
    //   }
      rgblight_disable();
      break;

    case 1: // Name of my 1st layer (includes 10-key and num-lock)
      rgblight_enable();
      rgblight_sethsv(130, 255, 255); // Blue
      if (led_state.num_lock) {
        rgblight_mode(lock_mode);
      } else {
        rgblight_mode(base_mode);
      }
      break;

    // case _ADVANCED: // Name of my 2nd layer
    //   rgblight_mode(base_mode);
    //   rgblight_sethsv(0, 255, 255); // red
    //   break;
  }
  return state;
}

bool led_update_user(led_t led_state) {
    if (led_state.caps_lock & layer_state_is(0)) {
      rgblight_mode(lock_mode);
    }
    else if (led_state.num_lock & layer_state_is(1)) {
      rgblight_mode(lock_mode);
    }
    else {
      rgblight_mode(base_mode);
    }
    return true;
}
