/*
Copyright 2023 malayan-tapir

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

#pragma once


/* key matrix size */
#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROWS 5
#define MATRIX_COLS 14

// wiring of each half
#define MATRIX_ROW_PINS {B6, B5, B4, D7, E6 }
#define MATRIX_COL_PINS { D2, D1, D3, D5, D4, D6, C6, F0, F1, F4, F5, F6, F7, C7 }

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE