#include QMK_KEYBOARD_H
#include "keymap_brazilian_abnt2.h"

enum appa_layers { _QWERTY, _LOWER, _RAISE, _ADJUST };

enum appa_keycodes { QWERTY = SAFE_RANGE };

const key_override_t delete_key_override =           ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t comma_key_override =            ko_make_basic(MOD_MASK_SHIFT, KC_COMM, BR_SCLN);
const key_override_t dot_key_override =              ko_make_basic(MOD_MASK_SHIFT, KC_DOT, BR_COLN);
const key_override_t right_bracket_key_override =    ko_make_basic(MOD_MASK_SHIFT, KC_RABK, KC_LABK);


// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&delete_key_override,
	&comma_key_override,
	&dot_key_override,
	&right_bracket_key_override,
	NULL // Null terminate the array of overrides!
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// array of keys considered modifiers for led purposes
const uint16_t modifiers[] = {KC_LCTL, KC_RCTL, KC_LALT, KC_RALT, KC_LSFT, KC_RSFT, KC_LGUI, KC_RGUI, LOWER, RAISE};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ç  |  ~   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   [  |   ]  |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Ctrl |   \  | Alt  | GUI  |Lower | Space| ENTER| Raise| RAlt |   /  |   ´  |   >  |
    * `-----------------------------------------------------------------------------------'
*/
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    BR_CCED, BR_TILD,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  BR_LBRC, BR_RBRC,
        KC_LCTL, BR_BSLS, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_ENT, RAISE, KC_RALT, BR_SLSH, BR_ACUT, KC_RABK
    ),

/* Lower
    * ,-----------------------------------------------------------------------------------.
    * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F12  | F12  |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |      |      |      |  ←   |   ↓  |  ↑   |   →  |      |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |      |      |      | HOME | Pg Dn| Pg Up| End  |      |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
    * `-----------------------------------------------------------------------------------'
*/
    [_LOWER] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN, KC_END,   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD,  KC_VOLU, KC_MPLY
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |   -  |   =  |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * |Reset |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT(
        QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
