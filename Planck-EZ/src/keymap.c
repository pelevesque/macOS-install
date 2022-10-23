#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
// #include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
// #include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
// #include "keymap_german_ch.h"
// #include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
// #include "keymap_norwegian.h"
#include "keymap_portuguese.h"
// #include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "keymap_croatian.h"
#include "keymap_turkish_q.h"
#include "keymap_slovak.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_MACRO_17,
  ST_MACRO_18,
  ST_MACRO_19,
  ST_MACRO_20,
  ST_MACRO_21,
  ST_MACRO_22,
  ST_MACRO_23,
  ST_MACRO_24,
  ST_MACRO_25,
  ST_MACRO_26,
  ST_MACRO_27,
  ST_MACRO_28,
  ST_MACRO_29,
  ST_MACRO_30,
  ST_MACRO_31,
  ST_MACRO_32,
  ST_MACRO_33,
  ST_MACRO_34,
  ST_MACRO_35,
};


enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _LAYER5,
  _LAYER6,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    LT(5,KC_ESCAPE),KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPACE,      
    MT(MOD_LCTL, KC_TAB),KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      MT(MOD_RCTL, KC_QUOTE),
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,      
    TG(6),          MO(4),          KC_LALT,        KC_LGUI,        LOWER,          KC_SPACE,       KC_NO,          LT(_RAISE, KC_ENTER),KC_RGUI,        KC_RALT,        MO(4),          KC_TRANSPARENT
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_UNDS,        KC_PLUS,        KC_LCBR,        KC_RCBR,        KC_PIPE,        
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_NONUS_HASH,  KC_NONUS_BSLASH,KC_HOME,        KC_END,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_DELETE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_MINUS,       KC_EQUAL,       KC_LBRACKET,    KC_RBRACKET,    KC_BSLASH,      
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_NONUS_HASH,  KC_NONUS_BSLASH,KC_PGUP,        KC_PGDOWN,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_SYSTEM_SLEEP,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SYSTEM_WAKE, 
    KC_DELETE,      KC_TRANSPARENT, AU_ON,          AU_OFF,         AU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,        RGB_VAI,        RGB_VAD,        KC_TRANSPARENT, RESET,          
    KC_TRANSPARENT, KC_TRANSPARENT, MU_ON,          MU_OFF,         MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, RGB_MOD,        RGB_HUI,        RGB_HUD,        KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER4] = LAYOUT_planck_grid(
    KC_TRANSPARENT, ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     ST_MACRO_3,     ST_MACRO_4,     ST_MACRO_5,     ST_MACRO_6,     ST_MACRO_7,     ST_MACRO_8,     ST_MACRO_9,     ST_MACRO_10,    
    ST_MACRO_11,    ST_MACRO_12,    ST_MACRO_13,    ST_MACRO_14,    ST_MACRO_15,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_16,    ST_MACRO_17,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_18,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_19,    ST_MACRO_20,    KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          ST_MACRO_21,    ST_MACRO_22,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER5] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER6] = LAYOUT_planck_grid(
    ST_MACRO_23,    ST_MACRO_24,    ST_MACRO_25,    ST_MACRO_26,    ST_MACRO_27,    ST_MACRO_28,    ST_MACRO_29,    X(0x00E0),    ST_MACRO_31,    ST_MACRO_32,    ST_MACRO_33,    ST_MACRO_34,    
    ST_MACRO_35,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_9) ));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_2) ));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_3) ));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_7) SS_TAP(X_4) ));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_7) SS_TAP(X_5) ));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_7) SS_TAP(X_6) ));

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_7) SS_TAP(X_7) ));

    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_7) SS_TAP(X_8) ));

    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_7) SS_TAP(X_9) ));

    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_7) SS_TAP(X_0) ));

    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_E) ));

    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_B) SS_TAP(X_6) SS_TAP(X_0) ));

    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_B) SS_TAP(X_6) SS_TAP(X_3) ));

    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_B) SS_TAP(X_6) SS_TAP(X_1) ));

    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_B) SS_TAP(X_6) SS_TAP(X_2) ));

    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_7) SS_TAP(X_A) SS_TAP(X_4) ));

    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_F) SS_TAP(X_F) SS_TAP(X_6) SS_TAP(X_2) ));

    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_F) SS_TAP(X_F) SS_TAP(X_6) SS_TAP(X_3) ));

    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_A) SS_TAP(X_9) ));

    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_A) SS_TAP(X_B) ));

    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_B) ));

    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_4) ));

    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_3) SS_TAP(X_1) SS_TAP(X_8) ));

    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_E) SS_TAP(X_7) ));

    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_E) SS_TAP(X_9) ));

    }
    break;
    case ST_MACRO_25:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_E) SS_TAP(X_2) ));

    }
    break;
    case ST_MACRO_26:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_E) SS_TAP(X_A) ));

    }
    break;
    case ST_MACRO_27:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_E) SS_TAP(X_E) ));

    }
    break;
    case ST_MACRO_28:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_F) SS_TAP(X_4) ));

    }
    break;
    case ST_MACRO_29:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_F) SS_TAP(X_B) ));

    }
    break;
    case ST_MACRO_30:
    if (record->event.pressed) {
      SEND_STRING("");

    }
    break;
    case ST_MACRO_31:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_E) SS_TAP(X_8) ));

    }
    break;
    case ST_MACRO_32:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_F) SS_TAP(X_9) ));

    }
    break;
    case ST_MACRO_33:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_E) SS_TAP(X_B) ));

    }
    break;
    case ST_MACRO_34:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_E) SS_TAP(X_F) ));

    }
    break;
    case ST_MACRO_35:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_F) SS_TAP(X_C) ));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint8_t layer_state_set_user(uint8_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


