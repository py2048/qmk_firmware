// Copyright 2021 py2048
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

// layers, ordering is important!
enum layers {
    _MAC,
    _BASE,
    /* _MAC, */
    _FN1,
    _FNMAC,
    _FN2,
    _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Base layer
  * ,--------------------------------------------------------------------------------------------------.
  * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  Backspace  | `    |
  * |-------------------------------------------------------------------------------------------+------+
  * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \     | PgUp |
  * |-------------------------------------------------------------------------------------------+------+
  * |LT(F1,ESC)|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |     Enter    | PgDn |
  * |-------------------------------------------------------------------------------------------+------+
  * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift    | Up  | Del  |
  * +-------------------------------------------------------------------------┬---┬-------------+------+
  * |  Ctrl | LGUI | Meh  |               Space                 | Alt | MO(2) |   | Left  | Dn  | Rght |
  * `-------------------------------------------------------------------------┘   └-------------+------´
  */
	[_BASE] = LAYOUT_65_ansi_blocker(
		KC_ESC,           KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,           KC_MINS,   KC_EQL,    KC_BSPC,   KC_GRV,
		KC_TAB,           KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,           KC_LBRC,   KC_RBRC,   KC_BSLS,   KC_PGUP,
		LT(_FN1,KC_ESC),  KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,        KC_QUOT,              KC_ENT,    KC_PGDN,
		KC_LSFT,          KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,        MT(MOD_RSFT, KC_F12), KC_UP,     KC_DEL,
		KC_LCTRL,         KC_LGUI,   KC_MEH,                         KC_SPC,                                      KC_RALT,  MO(_FN2),                   KC_LEFT,   KC_DOWN,   KC_RGHT
		),

  /* FN 1 layer (Pressed with control)
  * ,--------------------------------------------------------------------------------------------------.
  * |     |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  Backspace  | Ins  |
  * |-------------------------------------------------------------------------------------------+------+
  * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \     |  V+  |
  * |-------------------------------------------------------------------------------------------+------+
  * |          |  A  |  S  |  D  |  F  |  G  | Lft | Dwn | Up  | Rgt |  ;  |  '  |     Enter    |  V-  |
  * |-------------------------------------------------------------------------------------------+------+
  * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift    | Home| Mute |
  * +-------------------------------------------------------------------------┬---┬-------------+------+
  * |  Ctrl | LGUI | LAlt |               Space                 |      | MO(3)|   |  Prev | End | Next |
  * `-------------------------------------------------------------------------┘   └-------------+------´
  */
	[_FN1] = LAYOUT_65_ansi_blocker(
		_______,       KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F6,        KC_F7,        KC_F8,           KC_F9,          KC_F10,          KC_F11,          KC_F12,          LCTL(KC_BSPC),   KC_INS,
		LCTL(KC_TAB),  LCTL(KC_Q),   LCTL(KC_W),   LCTL(KC_E),   LCTL(KC_R),   LCTL(KC_T),   LCTL(KC_Y),   LCTL(KC_U),   LCTL(KC_I),      LCTL(KC_O),     LCTL(KC_P),      LCTL(KC_LBRC),   LCTL(KC_RBRC),   LCTL(KC_BSLS),   KC_VOLU,
		_______,       LCTL(KC_A),   LCTL(KC_S),   LCTL(KC_D),   LCTL(KC_F),   LCTL(KC_G),   KC_LEFT,      KC_DOWN,      KC_UP,           KC_RGHT,        LCTL(KC_SCLN),   LCTL(KC_QUOT),                    LCTL(KC_ENT),    KC_VOLD,
		KC_RSFT,       LCTL(KC_Z),   LCTL(KC_X),   LCTL(KC_C),   LCTL(KC_V),   LCTL(KC_B),   LCTL(KC_N),   LCTL(KC_M),   LCTL(KC_COMM),   LCTL(KC_DOT),   LCTL(KC_SLSH),   _______,                          KC_HOME,         KC_MUTE,
		KC_LCTRL,      KC_LGUI,      KC_LALT,                                  KC_SPC,                                                    KC_RALT,        MO(_FN3),                         KC_HOME,         KC_END,          KC_END
        ),

	/* MacOS layer
  * ,--------------------------------------------------------------------------------------------------.
  * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  Backspace  | `    |
  * |-------------------------------------------------------------------------------------------+------+
  * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \     | PgUp |
  * |-------------------------------------------------------------------------------------------+------+
  * |LT(m,ESC) |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |     Enter    | PgDn |
  * |-------------------------------------------------------------------------------------------+------+
  * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift    | Up  | Del  |
  * +-------------------------------------------------------------------------┬---┬-------------+------+
  * |  Ctrl | LGUI | Meh  |               Space                 | Alt | MO(2) |   | Left  | Dn  | Rght |
  * `-------------------------------------------------------------------------┘   └-------------+------´
  */

	[_MAC] = LAYOUT_65_ansi_blocker(
		KC_ESC,             KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,           KC_MINS,   KC_EQL,    KC_BSPC,   KC_GRV,
		KC_TAB,             KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,           KC_LBRC,   KC_RBRC,   KC_BSLS,   KC_PGUP,
		LT(_FNMAC,KC_ESC),  KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,        KC_QUOT,              KC_ENT,    KC_PGDN,
		KC_LSFT,            KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,        MT(MOD_RSFT, KC_F12), KC_UP,     KC_DEL,
		KC_LCTRL,           KC_LGUI,   KC_MEH,                         KC_SPC,                                      KC_RALT,  MO(_FN2),                   KC_LEFT,   KC_DOWN,   KC_RGHT
		),

  /* FN 1 layer (MacOS) (Pressed with Command)
  * ,--------------------------------------------------------------------------------------------------.
  * |     |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  Backspace  | Ins  |
  * |-------------------------------------------------------------------------------------------+------+
  * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \     |  V+  |
  * |-------------------------------------------------------------------------------------------+------+
  * |          |  A  |  S  |  D  |  F  |  G  | Lft | Dwn | Up  | Rgt |  ;  |  '  |     Enter    |  V-  |
  * |-------------------------------------------------------------------------------------------+------+
  * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift    | Home| Mute |
  * +-------------------------------------------------------------------------┬---┬-------------+------+
  * |  Ctrl | LGUI | LAlt |               Space                 |     |  MO(3)|   |  Prev | End | Next |
  * `-------------------------------------------------------------------------┘   └-------------+------´
  */

	[_FNMAC] = LAYOUT_65_ansi_blocker(
		_______,       KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,        KC_F9,       KC_F10,       KC_F11,       KC_F12,       G(KC_BSPC),   KC_INS,
		LCTL(KC_TAB),  G(KC_Q),   G(KC_W),   G(KC_E),   G(KC_R),   G(KC_T),   G(KC_Y),   G(KC_U),   G(KC_I),      G(KC_O),     G(KC_P),      G(KC_LBRC),   G(KC_RBRC),   G(KC_BSLS),   KC_VOLU,
		_______,       G(KC_A),   G(KC_S),   G(KC_D),   G(KC_F),   G(KC_G),   KC_LEFT,   KC_DOWN,   KC_UP,        KC_RGHT,     G(KC_SCLN),   G(KC_QUOT),                 G(KC_ENT),    KC_VOLD,
		KC_RSFT,       G(KC_Z),   G(KC_X),   G(KC_C),   G(KC_V),   G(KC_B),   G(KC_N),   G(KC_M),   G(KC_COMM),   G(KC_DOT),   G(KC_SLSH),   _______,                    G(KC_UP),     KC_MUTE,
		KC_LCTRL,      KC_LGUI,      KC_LALT,                                  KC_SPC,                            KC_RALT,     MO(_FN3),                   G(KC_RGHT),   G(KC_DOWN),   G(KC_LEFT)
		),
	/* FN 2 layer
  * ,--------------------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |     Reset   | EEPR |
  * |-------------------------------------------------------------------------------------------+------+
  * |        |     |     |     |     |     |     |     |     |     |     |     |     |          |  V + |
  * |-------------------------------------------------------------------------------------------+------+
  * |          |     |     |     |     |     |     |     |     |     |     |     |              |  V - |
  * |-------------------------------------------------------------------------------------------+------+
  * |            |     |     |     |     |     |     |     |     |     |     |            | V + | Mute |
  * +-------------------------------------------------------------------------┬---┬-------------+------+
  * |       |      | Alt  |             Backlight               |      |      |   |  H -  | V - |  H + |
  * `-------------------------------------------------------------------------┘   └-------------+------´
  */
	[_FN2] = LAYOUT_65_ansi_blocker(
		_______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   DF(_MAC),  DF(_BASE),  _______,    EEP_RST,
		_______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,    KC_VOLU,
		_______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,               _______,    KC_VOLD,
		_______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,               C(KC_UP),   KC_MUTE,
		_______,   _______,   KC_LALT,                         RGB_TOG,                                    MO(_FN3),  _______,             C(KC_LEFT), C(KC_DOWN), C(KC_RGHT)
    ),

  /* FN 3 layer
  * ,--------------------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |             |      |
  * |-------------------------------------------------------------------------------------------+------+
  * |        |     |     |     |     |     |     |     |     |     |     |     |     |          |      |
  * |-------------------------------------------------------------------------------------------+------+
  * |          |     |     |     |     |     |     |     |     |     |     |     |              |      |
  * |-------------------------------------------------------------------------------------------+------+
  * |            |     |     |     |     |     |     |     |     |     |     |            |     |      |
  * +-------------------------------------------------------------------------┬---┬-------------+------+
  * |       |      |      |                                     |      |      |   |       |     |      |
  * `-------------------------------------------------------------------------┘   └-------------+------´
  */
  [_FN3] = LAYOUT_65_ansi_blocker(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   RESET,     _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,
    _______,   _______,   _______,                         _______,                                    _______,   _______,              _______,   _______,   _______
    )
};


