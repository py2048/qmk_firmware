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
    _BASE = 1,
    _MAC = 0,
    _FN1 = 2,
    _FNMAC,
    _FNMAC2,
    _FNMACRO,
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
		LT(_FNMACRO,KC_ESC),KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,           KC_MINS,   KC_EQL,    KC_BSPC,   KC_GRV,
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
		_______,       MEH(KC_1),   MEH(KC_2),   MEH(KC_3),   MEH(KC_4),   MEH(KC_5),   MEH(KC_6),   MEH(KC_7),   MEH(KC_8),      MEH(KC_9),     MEH(KC_0),      MEH(KC_MINS),   MEH(KC_EQL),    G(KC_BSPC),     KC_INS,
		LCTL(KC_TAB),  G(KC_Q),     G(KC_W),     MEH(KC_E),   MEH(KC_R),   G(KC_T),     MEH(KC_Y),   MEH(KC_U),   MEH(KC_I),      MEH(KC_O),     MEH(KC_P),      MEH(KC_LBRC),   MEH(KC_RBRC),   MEH(KC_BSLS),   KC_VOLU,
		_______,       MEH(KC_A),   MEH(KC_S),   MEH(KC_D),   MEH(KC_F),   MEH(KC_G),   KC_LEFT,     KC_DOWN,     KC_UP,          KC_RGHT,       MEH(KC_SCLN),   MEH(KC_QUOT),                   MEH(KC_ENT),    KC_VOLD,
		MO(_FNMAC2),   MEH(KC_Z),   MEH(KC_X),   MEH(KC_C),   C(S(KC_V)),   MEH(KC_B),   MEH(KC_N),   MEH(KC_M),   MEH(KC_COMM),   MEH(KC_DOT),   MEH(KC_SLSH),   _______,                        G(KC_UP),       KC_MUTE,
		KC_LCTRL,      KC_LGUI,     KC_LALT,                               LCAG(KC_SPC),                                          KC_RALT,       MO(_FN3),                       G(KC_LEFT),     G(KC_DOWN),     G(KC_RGHT)
		),

	[_FNMAC2] = LAYOUT_65_ansi_blocker(
		_______,       HYPR(KC_1),   HYPR(KC_2),   HYPR(KC_3),   HYPR(KC_4),   HYPR(KC_5),   HYPR(KC_6),   HYPR(KC_7),   HYPR(KC_8),      HYPR(KC_9),     HYPR(KC_0),      HYPR(KC_MINS),   HYPR(KC_EQL),    HYPR(KC_BSPC),   KC_INS,
		LCTL(KC_TAB),  HYPR(KC_Q),   HYPR(KC_W),   HYPR(KC_E),   HYPR(KC_R),   HYPR(KC_T),   HYPR(KC_Y),   HYPR(KC_U),   HYPR(KC_I),      HYPR(KC_O),     HYPR(KC_P),      HYPR(KC_LBRC),   HYPR(KC_RBRC),   HYPR(KC_BSLS),   KC_VOLU,
		_______,       HYPR(KC_A),   HYPR(KC_S),   HYPR(KC_D),   HYPR(KC_F),   HYPR(KC_G),   HYPR(KC_H),   HYPR(KC_J),   HYPR(KC_K),      HYPR(KC_L),     HYPR(KC_SCLN),   HYPR(KC_QUOT),                    HYPR(KC_ENT),    KC_VOLD,
		MO(_FNMAC2),   HYPR(KC_Z),   HYPR(KC_X),   HYPR(KC_C),   HYPR(KC_V),   HYPR(KC_B),   HYPR(KC_N),   HYPR(KC_M),   HYPR(KC_COMM),   HYPR(KC_DOT),   HYPR(KC_SLSH),   _______,                          HYPR(KC_UP),     KC_MUTE,
		KC_LCTRL,      KC_LGUI,      KC_LALT,                                  HYPR(KC_SPC),                                              KC_RALT,        MO(_FN3),                         HYPR(KC_LEFT),   HYPR(KC_DOWN),   HYPR(KC_RGHT)
		),


    // Macro layer
    [_FNMACRO] = LAYOUT_65_ansi_blocker(
        _______,   DM_PLY1,   DM_PLY1,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   DM_REC1,   DM_REC2,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   DM_RSTP,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,
        _______,   _______,   _______,                         _______,                                    _______,   _______,              _______,   _______,   _______
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
		KC_ESC,    KC_F1,     KC_F2,     KC_F3,     KC_F4,      KC_F5,    KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    DF(_MAC),  DF(_BASE),  _______,    EEP_RST,
		_______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,    KC_VOLU,
		MO(_FN3),  DM_RSTP,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,               _______,    KC_VOLD,
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


