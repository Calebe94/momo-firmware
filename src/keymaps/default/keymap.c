#include QMK_KEYBOARD_H
#include "keymap_brazilian_abnt2.h"

enum appa_layers { _QWERTY, _LOWER, _RAISE, _ADJUST };
enum appa_keycodes { QWERTY = SAFE_RANGE };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const key_override_t delete_key_override =           ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t comma_key_override =            ko_make_basic(MOD_MASK_SHIFT, KC_COMM, BR_SCLN);
const key_override_t dot_key_override =              ko_make_basic(MOD_MASK_SHIFT, KC_DOT, BR_COLN);
const key_override_t right_bracket_key_override =    ko_make_basic(MOD_MASK_SHIFT, KC_LABK, KC_RABK);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&delete_key_override,
	&comma_key_override,
	&dot_key_override,
	&right_bracket_key_override,
	NULL // Null terminate the array of overrides!
};

enum combo_events {
  MONITOR_1,
  MONITOR_2,
  SEND_TO_MONITOR_1,
  SEND_TO_MONITOR_2,
  TAG1,
  TAG2,
  TAG3,
  TAG4,
  TAG5,
  TAG6,
  TAG7,
  TAG8,
  TAG9,
  TAG0,
  SEND_TAG1,
  SEND_TAG2,
  SEND_TAG3,
  SEND_TAG4,
  SEND_TAG5,
  SEND_TAG6,
  SEND_TAG7,
  SEND_TAG8,
  SEND_TAG9,
  SEND_TAG0,
  HELLO_WORLD,
  OLA_MUNDO,
  MINUS,
  EQUAL,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM monitor_1_combo[] = {KC_W, KC_L, COMBO_END};
const uint16_t PROGMEM monitor_2_combo[] = {KC_W, KC_H, COMBO_END};
const uint16_t PROGMEM send_to_monitor_1_combo[] = {KC_LSFT, KC_W, KC_L, COMBO_END};
const uint16_t PROGMEM send_to_monitor_2_combo[] = {KC_LSFT, KC_W, KC_H, COMBO_END};
const uint16_t PROGMEM focus_on_tag_1[] = {KC_B, KC_Q, COMBO_END};
const uint16_t PROGMEM focus_on_tag_2[] = {KC_B, KC_W, COMBO_END};
const uint16_t PROGMEM focus_on_tag_3[] = {KC_B, KC_E, COMBO_END};
const uint16_t PROGMEM focus_on_tag_4[] = {KC_B, KC_R, COMBO_END};
const uint16_t PROGMEM focus_on_tag_5[] = {KC_B, KC_T, COMBO_END};
const uint16_t PROGMEM focus_on_tag_6[] = {KC_B, KC_Y, COMBO_END};
const uint16_t PROGMEM focus_on_tag_7[] = {KC_B, KC_U, COMBO_END};
const uint16_t PROGMEM focus_on_tag_8[] = {KC_B, KC_I, COMBO_END};
const uint16_t PROGMEM focus_on_tag_9[] = {KC_B, KC_O, COMBO_END};
const uint16_t PROGMEM focus_on_tag_0[] = {KC_B, KC_P, COMBO_END};
const uint16_t PROGMEM send_to_tag_1[] = {KC_LSFT, KC_B, KC_Q, COMBO_END};
const uint16_t PROGMEM send_to_tag_2[] = {KC_LSFT, KC_B, KC_W, COMBO_END};
const uint16_t PROGMEM send_to_tag_3[] = {KC_LSFT, KC_B, KC_E, COMBO_END};
const uint16_t PROGMEM send_to_tag_4[] = {KC_LSFT, KC_B, KC_R, COMBO_END};
const uint16_t PROGMEM send_to_tag_5[] = {KC_LSFT, KC_B, KC_T, COMBO_END};
const uint16_t PROGMEM send_to_tag_6[] = {KC_LSFT, KC_B, KC_Y, COMBO_END};
const uint16_t PROGMEM send_to_tag_7[] = {KC_LSFT, KC_B, KC_U, COMBO_END};
const uint16_t PROGMEM send_to_tag_8[] = {KC_LSFT, KC_B, KC_I, COMBO_END};
const uint16_t PROGMEM send_to_tag_9[] = {KC_LSFT, KC_B, KC_O, COMBO_END};
const uint16_t PROGMEM send_to_tag_0[] = {KC_LSFT, KC_B, KC_P, COMBO_END};
/* const uint16_t PROGMEM hello_world[]   = {KC_J, KC_K, COMBO_END}; */
/* const uint16_t PROGMEM ola_mundo[]     = {KC_K, KC_J, COMBO_END}; */
const uint16_t PROGMEM minus_combo[]   = {BR_CCED, BR_TILD, COMBO_END};
const uint16_t PROGMEM equal_combo[]   = {BR_LBRC, BR_RBRC, COMBO_END};
const uint16_t PROGMEM clear_line_combo[] = {KC_BSPC, KC_LSFT, COMBO_END};

combo_t key_combos[] = {
    [MONITOR_1] = COMBO(monitor_1_combo, LAG(KC_1)),
    [MONITOR_2] = COMBO(monitor_2_combo, LAG(KC_2)),
    [SEND_TO_MONITOR_1] = COMBO(send_to_monitor_1_combo, S(LAG(KC_1))),
    [SEND_TO_MONITOR_2] = COMBO(send_to_monitor_2_combo, S(LAG(KC_1))),
    [TAG1] = COMBO(focus_on_tag_1, LGUI(KC_1)),
    [TAG2] = COMBO(focus_on_tag_2, LGUI(KC_2)),
    [TAG3] = COMBO(focus_on_tag_3, LGUI(KC_3)),
    [TAG4] = COMBO(focus_on_tag_4, LGUI(KC_4)),
    [TAG5] = COMBO(focus_on_tag_5, LGUI(KC_5)),
    [TAG6] = COMBO(focus_on_tag_6, LGUI(KC_6)),
    [TAG7] = COMBO(focus_on_tag_7, LGUI(KC_7)),
    [TAG8] = COMBO(focus_on_tag_8, LGUI(KC_8)),
    [TAG9] = COMBO(focus_on_tag_9, LGUI(KC_9)),
    [TAG0] = COMBO(focus_on_tag_0, LGUI(KC_0)),
    [SEND_TAG1] = COMBO(send_to_tag_1, S(LGUI(KC_1))),
    [SEND_TAG2] = COMBO(send_to_tag_2, S(LGUI(KC_2))),
    [SEND_TAG3] = COMBO(send_to_tag_3, S(LGUI(KC_3))),
    [SEND_TAG4] = COMBO(send_to_tag_4, S(LGUI(KC_4))),
    [SEND_TAG5] = COMBO(send_to_tag_5, S(LGUI(KC_5))),
    [SEND_TAG6] = COMBO(send_to_tag_6, S(LGUI(KC_6))),
    [SEND_TAG7] = COMBO(send_to_tag_7, S(LGUI(KC_7))),
    [SEND_TAG8] = COMBO(send_to_tag_8, S(LGUI(KC_8))),
    [SEND_TAG9] = COMBO(send_to_tag_9, S(LGUI(KC_9))),

    /* [HELLO_WORLD] = COMBO_ACTION(hello_world), */
    /* [OLA_MUNDO] = COMBO_ACTION(ola_mundo), */
    [MINUS] = COMBO(minus_combo, KC_MINS),
    [EQUAL] = COMBO(equal_combo, KC_EQL),
};

void process_combo_event(uint16_t combo_index, bool pressed)
{
    switch(combo_index)
    {
        case HELLO_WORLD:
            if (pressed)
            {
                SEND_STRING("Hello World!");
            }
            break;
        case OLA_MUNDO:
            if (pressed)
            {
                SEND_STRING("Olá Mundo!");
            }
            break;
    }
}

bool get_combo_must_press_in_order(uint16_t combo_index, combo_t *combo)
{
    switch (combo_index)
    {
        /* List combos here that you want to only activate if their keys
         * are pressed in the same order as they are defined in the combo's key
         * array. */
        case HELLO_WORLD:
            return true;
        case OLA_MUNDO:
            return true;
        default:
            return false;
    }
}

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
    * | Ctrl |   \  | Alt  | GUI  |Lower | Space| ENTER| Raise|   /  | RAlt |   ´  |   <  |
    * `-----------------------------------------------------------------------------------'
*/
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    BR_CCED, BR_TILD,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  BR_LBRC, BR_RBRC,
        KC_LCTL, BR_BSLS, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_ENT, RAISE, BR_SLSH, KC_RALT, BR_ACUT, KC_LABK
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

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); */
/* } */

//********COLORES Y ANIMACIONES****************

uint32_t base_mode = 1; // solid
uint32_t lock_mode = 21; // Knight Rider

void keyboard_post_init_user(void)
{
    rgblight_enable_noeeprom();
    layer_state_set_user(layer_state);
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    uint8_t layer = biton32(state);
    switch (layer)
    {
        case _QWERTY:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case _LOWER:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case _RAISE:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case _ADJUST:
            rgblight_sethsv_noeeprom(HSV_YELLOW);
            break;
        default:
            rgblight_sethsv_noeeprom(7, 255, 230);
            break;
    }

    return state;
}

bool led_update_user(led_t led_state)
{
    if  (led_state.caps_lock)
    {
        rgblight_mode_noeeprom(lock_mode);
    }
    else
    {
        rgblight_mode_noeeprom(base_mode);
    }
    return true;
}
