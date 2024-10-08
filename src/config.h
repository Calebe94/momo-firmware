/*
Copyright 2019 Takuya Urakawa (dm9records.com)

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
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on
 * diode) ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS                                                        \
  { GP2, GP3, GP4, GP5 }
#define MATRIX_COL_PINS                                                        \
  { GP6, GP7, GP8, GP9, GP10, GP11, GP12, GP13, GP14, GP15, GP16, GP17 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION ROW2COL

#define USB_MAX_POWER_CONSUMPTION 500

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in
 * your rules.mk, and define SOFT_SERIAL_PIN.
 */
// #define SOFT_SERIAL_PIN D0 // or D1, D2, D3, E6

// #define BACKLIGHT_PIN B7
// #define BACKLIGHT_BREATHING
// #define BACKLIGHT_LEVELS 3

// #define RGB_DI_PIN E2
// #ifdef RGB_DI_PIN
//   #define RGBLED_NUM 16
//   #define RGBLIGHT_HUE_STEP 8
//   #define RGBLIGHT_SAT_STEP 8
//   #define RGBLIGHT_VAL_STEP 8
//   #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
//   #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched
//   off when the host goes to sleep */
// /*== all animations enable ==*/
//   #define RGBLIGHT_ANIMATIONS
// /*== or choose animations ==*/
//   #define RGBLIGHT_EFFECT_BREATHING
//   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//   #define RGBLIGHT_EFFECT_SNAKE
//   #define RGBLIGHT_EFFECT_KNIGHT
//   #define RGBLIGHT_EFFECT_CHRISTMAS
//   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//   #define RGBLIGHT_EFFECT_RGB_TEST
//   #define RGBLIGHT_EFFECT_ALTERNATING
// #endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is
 * not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
 */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is userful for the Windows task manager shortcut (ctrl+shift+esc).
 */
// #define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in
 * the makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during
 * a power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* Bootmagic Lite key configuration */
// #define BOOTMAGIC_LITE_ROW 0
// #define BOOTMAGIC_LITE_COLUMN 0

#define COMBO_MUST_PRESS_IN_ORDER 1
#define COMBO_MUST_PRESS_IN_ORDER_PER_COMBO 1
/* #define COMBO_TERM 50 */

#define WS2812_DI_PIN GP23
#define RGB_DI_PIN GP23
#define RGBLED_NUM 57
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LIMIT_VAL 128
/* #define WS2812_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the WS2812 implementation uses the PIO0 peripheral */
/* #define NOP_FUDGE 0.4 */
#define RGBLIGHT_LAYER_BLINK

#define ENCODERS_PAD_A { GP22 }
#define ENCODERS_PAD_B { GP28 }

#define DIP_SWITCH_PINS { GP20, GP21, GP29 }

#define ANALOG_JOYSTICK_X_AXIS_PIN GP27
#define ANALOG_JOYSTICK_Y_AXIS_PIN GP26
#define ANALOG_JOYSTICK_SPEED_REGULATOR 10
#define ANALOG_JOYSTICK_SPEED_MAX 5
#define ANALOG_JOYSTICK_AXIS_MIN 20
