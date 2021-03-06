#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys


#define A_S_T(kc) MT((MOD_LALT | MOD_LSFT), kc)


#define JA_CLON KC_QUOT  // : and +
#define JA_AT   KC_LBRC  // @ and `
#define JA_HAT  KC_EQL   // ^ and ~
#define JA_ENUN KC_RO    // \ and _ (EN mark and UNder score)
#define JA_ENVL KC_JYEN  // \ and | (EN mark and Vertical Line)
#define JA_LBRC KC_RBRC  // [ and {
#define JA_RBRC KC_BSLS  // ] and }

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,            KC_1,    KC_2,         KC_3,    KC_4,   KC_5, JA_HAT,
        A_S_T(KC_TAB),     KC_Q,    KC_W,         KC_E,    KC_R,   KC_T, KC_NO,
        LT(SYMB, KC_CAPS), KC_A,    KC_S,         KC_D,    KC_F,   KC_G,
        KC_LSFT,           KC_Z,    KC_X,         KC_C,    KC_V,   KC_B, KC_HENK,
        GUI_T(KC_NO),      KC_LALT, CTL_T(KC_NO), KC_LEFT, KC_RGHT,
                                                             KC_DELETE, TG(SYMB),
                                                                           KC_NO,
                                                          KC_MHEN, KC_SPC, KC_NO,

        // right hand
        JA_ENVL, KC_6, KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,
        JA_CLON, KC_Y, KC_U,  KC_I,    KC_O,    KC_P,    KC_MINS,
                 KC_H, KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_ENT,  KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                       KC_UP, KC_DOWN, JA_LBRC, JA_RBRC, LT(SYMB, JA_ENUN),
        TG(MDIA), KC_BSPC,
        KC_NO,
        KC_NO, CTL_T(KC_SPC), KC_MHEN
    ),
/* Keymap 1: Symbol Layer */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
        KC_TRNS, KC_F1,   KC_F2,  KC_F3,   KC_F4,         KC_F5,   KC_F6,
        KC_TRNS, KC_TRNS, KC_TAB, KC_SLSH, LSFT(JA_CLON), KC_MINS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_7,   KC_8,    KC_9,          LSFT(KC_SCLN),
        KC_TRNS, KC_TRNS, KC_4,   KC_5,    KC_6,          KC_ENT,  KC_HENK,
        KC_TRNS, KC_0,    KC_1,   KC_2,    KC_3,
                                                KC_TRNS, TG(KC_TRNS),
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,

       // right hand
       KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_DELETE,
       KC_TRNS, KC_TRNS, KC_TRNS,  KC_MINUS, JA_HAT,   JA_ENVL, JA_AT,
                KC_TRNS, KC_TRNS,  KC_TRNS,  JA_AT,    JA_LBRC, KC_ENT,
       KC_ENT,  KC_TRNS, KC_TRNS,  KC_SCLN,  JA_CLON,  JA_RBRC, KC_RSFT,
                         KC_COMMA, KC_DOT,   KC_SLASH, JA_ENUN, KC_NO,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_MS_WH_UP, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_MS_BTN3,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_WH_DOWN, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                                       KC_TRNS, KC_TRNS,
                                                                                KC_TRNS,
                                                              KC_WBAK, KC_TRNS, KC_TRNS,
    // right hand
       KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       TG(MDIA), KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
