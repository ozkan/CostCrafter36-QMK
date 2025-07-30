/* Copyright 2023 ozkan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include QMK_KEYBOARD_H
#include "keymap_turkish_q.h"


enum cost_crafter36_layer {
    _COLEMAK,
    _QWERTY,
    _LOWER,
    _RAISE,
    _FNL,
    _FNR,
    _ARROW,
    _ADJUST
};

enum cost_crafter36_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY
};



#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define FNL    MO(_FNL)
#define FNR    MO(_FNR)
#define ARROW  MO(_ARROW)
#define ADJUST MO(_ADJUST)


#define FNR_SPC     LT(FNR, KC_SPC)
#define FNL_ENT     LT(FNL, KC_TAB)
#define ARROW_T     LT(ARROW, KC_T)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// COLEMAK
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤  W   │  F   │  P   │  G   │                │  J   │  L   │  U   │  Y   ├──────╮
//  │   Q  ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤ BSPC │
//  ├──────┤  R   │  S   │NAV T │  D   │                │  H   │  N   │  E   │  I   ├──────┤
//  │   A  ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  O   │
//  ├──────┤CTL X │SFT C │  V   │  B   │                │  K   │  M   │SFT , │CTL . ├──────┤
//  │ALT Z ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤ALT / │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤ SPACE │ SPACE  ├──────╯
//                                     ╰───────┴────────╯ 

  [_COLEMAK] = LAYOUT_36(
    TR_Q,          TR_W,          TR_F,          TR_P,     TR_G,               TR_J,  TR_L,  TR_U,             TR_Y,            KC_BSPC,  
    TR_A,          TR_R,          TR_S,          ARROW_T,  TR_D,               TR_H,  TR_N,  TR_E,             TR_IDOT,         TR_O,      
    LALT_T(TR_Z),  LCTL_T(TR_X),  LSFT_T(TR_C),  TR_V,     TR_B,               TR_K,  TR_M,  RSFT_T(TR_COMM),  RCTL_T(TR_DOT),  TR_SLSH,   
                               KC_LALT,   LOWER,    FNL_ENT,   FNR_SPC,   RAISE,   KC_RGUI
  ),



                    

  [_QWERTY] = LAYOUT_36(
    TR_Q,  TR_W,  TR_E,  TR_R,  TR_T,              TR_Y,  TR_U,  TR_IDOT,  TR_O,    TR_P,    
    TR_A,  TR_S,  TR_D,  TR_F,  TR_G,              TR_H,  TR_J,  TR_K,     TR_L,    TR_SCLN, 
    TR_Z,  TR_X,  TR_C,  TR_V,  TR_B,              TR_N,  TR_M,  TR_COMM,  TR_DOT,  TR_SLSH,  
            KC_LALT,   LOWER,    FNL_ENT,  FNR_SPC,   RAISE,   KC_RGUI

  ),
  
// LOWER
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤      │      │      │      │                │  (   │  )   │  =   │  &   ├──────╮
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  |   │
//  ├──────┤      │      │      │      │                │  {   │  }   │  _   │  $   ├──────┤
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  '   │
//  ├──────┤      │      │      │      │                │  [   │  ]   │  <   │  >   ├──────┤
//  │      ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤  \   │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤ SPACE │ ENTER  ├──────╯
//                                     ╰───────┴────────╯ 


  [_LOWER] = LAYOUT_36(
  _______,  _______,   _______,  _______,   _______,              TR_LPRN,  TR_RPRN,   TR_EQL,   TR_AMPR,  TR_PIPE, 
  _______,  _______,   _______,  _______,   _______,              TR_LCBR,  TR_RCBR,   TR_UNDS,  TR_DLR,   TR_QUOT,
  _______,  _______,   _______,  _______,   _______,              TR_LBRC,  TR_RBRC,   TR_LABK,  TR_RABK,  TR_BSLS,
                              KC_LALT,   LOWER,    _______,  KC_ENT,   RAISE,   KC_RGUI
                                                         

  ),

 
// RAISE
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤  1   │  2   │  3   │  +   │                │ F10  │  F1  │  F2  │  F3  ├──────╮
//  │  -   ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤ DEL  │
//  ├──────┤  4   │  5   │  6   │  "   │                │ F11  │  F4  │  F5  │  F6  ├──────┤
//  │  *   ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤      │
//  ├──────┤  7   │  8   │  9   │  0   │                │ F12  │  F7  │  F8  │  F9  ├──────┤
//  │  %   ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤      │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤  DEL  │ SPACE  ├──────╯
//                                     ╰───────┴────────╯ 
                  
   

  [_RAISE] = LAYOUT_36(
    TR_MINS,  TR_1,  TR_2,  TR_3,  TR_PLUS,              KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_DEL, 
    TR_ASTR,  TR_4,  TR_5,  TR_6,  TR_DQUO,              KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______, 
    TR_PERC,  TR_7,  TR_8,  TR_9,  TR_0,                 KC_F12,  KC_7,    KC_F8,   KC_9,    _______, 
               KC_LALT,   LOWER,    FNL_ENT, FNR_SPC,   RAISE,   KC_RGUI

  ),

 
// FNR 
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤      │  €   │  £   │  Ğ   │                │      │      │      │      ├──────╮
//  │ ESC  ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤      │
//  ├──────┤  @   │  Ş   │  ₺   │  `   │                │      │      │      │      ├──────┤
//  │  !   ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤      │
//  ├──────┤      │  Ç   │      │  #   │                │      │      │      │      ├──────┤
//  │ CAPS ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤      │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤ SPACE │ SPACE  ├──────╯
//                                     ╰───────┴────────╯


  [_FNR] = LAYOUT_36(
    KC_ESC,  _______,  TR_EURO,  TR_PND,  TR_GBRV,              _______,  _______,  _______,  _______,  _______, 
    TR_EXLM,  TR_AT,    TR_SCED,  TR_LIRA,  TR_GRV,               _______,  _______,  _______,  _______,  _______, 
    KC_CAPS,  _______,  TR_CCED,  _______,  TR_HASH,              _______,  _______,  _______,  _______,  _______, 
                         KC_LALT,   LOWER,    FNL_ENT,  FNR_SPC,   RAISE,   KC_RGUI 
  ),

// FNL
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤      │      │      │      │                │      │      │  Ü   │      ├──────╮
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  :   │
//  ├──────┤      │      │      │      │                │      │      │  I   │  I   ├──────┤
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤   Ö  │
//  ├──────┤      │      │      │      │                │      │      │  ^   │  ~   ├──────┤
//  │      ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤   ?  │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤ SPACE │ SPACE  ├──────╯
//                                     ╰───────┴────────╯ 


  [_FNL] = LAYOUT_36(
    _______,  _______,  _______,  _______,  _______,              _______,  _______,  TR_UDIA,   _______,  TR_COLN, 
    _______,  _______,  _______,  _______,  _______,              _______,  _______,  S(TR_I),  TR_I,      TR_ODIA, 
    _______,  _______,  _______,  _______,  _______,              _______,  _______,  TR_CIRC,  TR_TILD,   TR_QUES,  
                          KC_LALT,   LOWER,    FNL_ENT,  KC_ENT,   RAISE,   KC_RGUI    
  ),

// ARROW
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤      │      │      │      │                │C_PREV│ PGUP │  UP  │ MUTE ├──────╮
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤ T-PLY│
//  ├──────┤      │      │      │      │                │ HOME │ LEFT │ DOWN │ RGHT ├──────┤
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤ END  │
//  ├──────┤      │      │      │      │                │C_NEXT│PGDOWN│      │VLDOWN├──────┤
//  │      ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤ VLUP │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤ SPACE │ SPACE  ├──────╯
//                                     ╰───────┴────────╯


  [_ARROW] = LAYOUT_36(
    _______,  _______,   _______,  _______,   _______,              KC_MPRV,   KC_PGUP,    KC_UP,      _______,     _______,  
    _______,  _______,   _______,  _______,   _______,              KC_HOME,   KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_END,   
    _______,  _______,   _______,  _______,   _______,              KC_MNXT,   KC_PGDN,    _______,    KC_VOLD,     KC_VOLU,  
                              KC_LALT,   LOWER,    FNL_ENT,  FNR_SPC,   RAISE,   KC_RGUI

  ),


// ADJUST
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤ SAT+ │ HUE+ │ ANI+ │ TOG  │                │      │      │      │      ├──────╮
//  │ BRI+ ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤      │
//  ├──────┤ SAT- │ HUE- │ ANI- │      │                │      │      │      │      ├──────┤
//  │ BRI- ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤      │
//  ├──────┤      │      │      │      │                │REBOOT│ BOOT │EE_CLR│      ├──────┤
//  │      ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤      │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤ SPACE │ SPACE  ├──────╯
//                                     ╰───────┴────────╯ 


  [_ADJUST] = LAYOUT_36(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,    RGB_TOG,            XXXXXXX,  XXXXXXX,  QWERTY,  XXXXXXX,  COLEMAK,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,     
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,    XXXXXXX,            QK_RBT,   QK_BOOT,  EE_CLR,  XXXXXXX,     XXXXXXX,     
                              KC_LALT,   LOWER,    FNL_ENT,  FNR_SPC,   RAISE,   KC_RGUI
  ),
};




layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}