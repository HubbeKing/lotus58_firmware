/*
Copyright 2021 TweetyDaBird

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

#include "config_common.h"

// USB Device descriptor parameter
#define VENDOR_ID    0x0079
#define PRODUCT_ID   0x0058
#define DEVICE_VER   0x0001
#define MANUFACTURER TweetyDaBird
#define PRODUCT      Lotus58 Glow

// Keyboard Matrix (Rows are doubled)
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4 }
#define MATRIX_COL_PINS { B1, B2, B3, B6, F7, F6 }
#define DIODE_DIRECTION COL2ROW

// Encoder support
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }
#define ENCODERS_PAD_A_RIGHT { F4 }
#define ENCODERS_PAD_B_RIGHT { F5 }
#define ENCODER_RESOLUTION 4

// Define detection pin handedness
#define SPLIT_HAND_PIN B5

// Define Communication
#define USE_SERIAL
#define SOFT_SERIAL_PIN D2

// Detects USB and assigns master (Not recommended on Elite C/Pro Micro mix)
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_USB_TIMEOUT_POLL 10

// Allows dual displays to show modifiers etc
#define SERIAL_USE_MULTI_TRANSACTION
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_TRANSPORT_MIRROR

// Set maximum length of tap to 180ms
// Longer than 180ms is a hold
#define TAPPING_TERM 180

// Debounce - wait for 10ms after state change before sending keypresses, to prevent unintended inputs due to noise
#define DEBOUNCE 10

// timeout oneshot mods after 1.5 seconds
#define ONESHOT_TIMEOUT 1500

// set OLED brightness (0-255)
#define OLED_BRIGHTNESS 255
