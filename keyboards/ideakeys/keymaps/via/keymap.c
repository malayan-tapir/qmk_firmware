/*
Copyright 2024 malayan-tapir

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "led.h"

enum layers { _BASE, _LAYER1, _LAYER2, _LAYER3 };

// LEDが接続されたピンの定義
#define LED_PIN_LAYER1 B3
#define LED_PIN_LAYER2 B2
#define LED_PIN_LAYER3 B6

// レイヤー切り替えキーコード
#define LAYER1_TOGGLE MT(MOD_LCTL, KC_TRNS)
#define LAYER2_TOGGLE MT(MOD_LALT, KC_TRNS)
#define LAYER3_TOGGLE MT(MOD_LSFT, KC_TRNS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,    KC_PSLS,    LAYER1_TOGGLE,
        KC_P4,   KC_P5,   KC_P6,    KC_PAST,    LAYER3_TOGGLE,
        KC_P1,   KC_P2,   KC_P3,    KC_PMNS,    
        KC_P0,          KC_PDOT,    KC_PPLS,    KC_TAB   
    ),
    [_LAYER1] = LAYOUT(
        XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    
        XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX
    ),
    [_LAYER2] = LAYOUT(
        XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    
        XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX
    ),
    [_LAYER3] = LAYOUT(
        XXXXXXX,      XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,      XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,      XXXXXXX,   XXXXXXX,    XXXXXXX,    
        XXXXXXX,                  XXXXXXX,   XXXXXXX,    XXXXXXX
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LAYER1_TOGGLE:
            if (record->event.pressed) {
                layer_on(_LAYER1);
            } else {
                layer_off(_LAYER1);
            }
            return false;
        case LAYER2_TOGGLE:
            if (record->event.pressed) {
                layer_on(_LAYER2);
            } else {
                layer_off(_LAYER2);
            }
            return false;
        case LAYER3_TOGGLE:
            if (record->event.pressed) {
                layer_on(_LAYER3);
            } else {
                layer_off(_LAYER3);
            }
            return false;
    }
    return true;
}

void matrix_init_user(void) {
    setPinOutput(LED_PIN_LAYER1);
    setPinOutput(LED_PIN_LAYER2);
    setPinOutput(LED_PIN_LAYER3);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BASE:
            writePin(LED_PIN_LAYER1, true);
            writePin(LED_PIN_LAYER2, true);
            writePin(LED_PIN_LAYER3, true);
            break;
        case _LAYER1:
            writePin(LED_PIN_LAYER1, true);
            writePin(LED_PIN_LAYER2, false);
            writePin(LED_PIN_LAYER3, false);
            break;
        case _LAYER2:
            writePin(LED_PIN_LAYER1, false);
            writePin(LED_PIN_LAYER2, true);
            writePin(LED_PIN_LAYER3, false);
            break;
        case _LAYER3:
            writePin(LED_PIN_LAYER1, false);
            writePin(LED_PIN_LAYER2, false);
            writePin(LED_PIN_LAYER3, true);
            break;
    }
    return state;
}
