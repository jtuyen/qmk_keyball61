#include QMK_KEYBOARD_H
#include "quantum.h"

enum layers {
    MAC_BASE = 0,
    MAC_SYMBOL,
    MAC_NAVIGATION,
    WIN_BASE,
    WIN_SYMBOL,
    WIN_NAVIGATION,
    OPTIONS,
};

enum combos {
    MAC_AZ_UNDO,
    MAC_SW_ALFRED_SNIPPET,
    MAC_SX_CUT,
    MAC_DC_COPY,
    MAC_FR_ALFRED_PASTE,
    MAC_FV_PASTE,
    MAC_QA_MISSION_CTRL,
    WINMAC_SCLN_QUOT_ENT,
    WINMAC_DF_CTRL,
    WINMAC_JK_CTRL,
    WINMAC_MCOMMA_ALT,
    WINMAC_CV_ALT,
    WIN_AZ_UNDO,
    WIN_SX_CUT,
    WIN_DC_COPY,
    WIN_FR_CLIP_HISTORY,
    WIN_FV_PASTE,
};

enum insomnia {
    INSOMNIA,
};

enum tapdances {
    TD_MEDIA_NEXT,
    TD_MEDIA_PREV,
    TD_MEDIA_MUTE,
    TD_MEDIA_PLAY,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_MEDIA_NEXT] = ACTION_TAP_DANCE_DOUBLE(KC_AUDIO_VOL_UP, KC_MFFD),
    [TD_MEDIA_PREV] = ACTION_TAP_DANCE_DOUBLE(KC_AUDIO_VOL_DOWN, KC_MRWD),
    [TD_MEDIA_MUTE] = ACTION_TAP_DANCE_DOUBLE(KC_NO, KC_AUDIO_MUTE),
    [TD_MEDIA_PLAY] = ACTION_TAP_DANCE_DOUBLE(KC_NO, KC_MPLY),
};

const uint16_t PROGMEM mac_az_combo[] = {KC_A, KC_Z, COMBO_END};
const uint16_t PROGMEM mac_sx_combo[] = {KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM mac_sw_combo[] = {KC_S, KC_W, COMBO_END};
const uint16_t PROGMEM mac_dc_combo[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM mac_fv_combo[] = {KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM mac_fr_combo[] = {KC_F, KC_R, COMBO_END};
const uint16_t PROGMEM mac_qa_combo[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM winmac_scln_quot_ent[] = {KC_SCLN, KC_QUOT, COMBO_END};
const uint16_t PROGMEM winmac_df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM winmac_jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM winmac_mcomma_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM winmac_cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM win_az_combo[] = {KC_A, KC_Z, COMBO_END};
const uint16_t PROGMEM win_sx_combo[] = {KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM win_dc_combo[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM win_fr_combo[] = {KC_F, KC_R, COMBO_END};
const uint16_t PROGMEM win_fv_combo[] = {KC_F, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [MAC_AZ_UNDO] = COMBO(mac_az_combo, LGUI(KC_Z)),
  [MAC_SW_ALFRED_SNIPPET] = COMBO(mac_sw_combo, LSG(KC_W)),
  [MAC_SX_CUT] = COMBO(mac_sx_combo, LGUI(KC_X)),
  [MAC_DC_COPY] = COMBO(mac_dc_combo, LGUI(KC_C)),
  [MAC_FR_ALFRED_PASTE] = COMBO(mac_fr_combo, LSG(KC_V)),
  [MAC_FV_PASTE] = COMBO(mac_fv_combo, LGUI(KC_V)),
  [MAC_QA_MISSION_CTRL] = COMBO(mac_qa_combo, LCTL(KC_UP)),
  [WINMAC_SCLN_QUOT_ENT] = COMBO(winmac_scln_quot_ent, (KC_ENT)),
  [WINMAC_DF_CTRL] = COMBO(winmac_df_combo, LCTL_T(KC_LCTL)),
  [WINMAC_JK_CTRL] = COMBO(winmac_jk_combo, LCTL_T(KC_LCTL)),
  [WINMAC_MCOMMA_ALT] = COMBO(winmac_mcomma_combo, LALT_T(KC_LALT)),
  [WINMAC_CV_ALT] = COMBO(winmac_cv_combo, LALT_T(KC_LALT)),
  [WIN_AZ_UNDO] = COMBO(win_az_combo, RCTL(KC_Z)),
  [WIN_SX_CUT] = COMBO(win_sx_combo, RCTL(KC_X)),
  [WIN_DC_COPY] = COMBO(win_dc_combo, RCTL(KC_C)),
  [WIN_FV_PASTE] = COMBO(win_fv_combo, RCTL(KC_V)),
  [WIN_FR_CLIP_HISTORY] = COMBO(win_fr_combo, LGUI(KC_V)),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAC_BASE] = LAYOUT_universal(
    KC_GRV,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPC,
    KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_DEL,
    ALL_T(KC_ESC),KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,
    KC_LSFT,KC_Z,KC_X,KC_C,KC_V,KC_B,LCTL_T(KC_SPC),LALT_T(KC_MINS),KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_BSLS,
    TD(TD_MEDIA_MUTE),TD(TD_MEDIA_PLAY),MT(MOD_MEH,KC_ESC),KC_LGUI,QK_LEAD,KC_ENT,TT(2),MO(1),KC_SPC,KC_NO,KC_NO,KC_NO,KC_BTN2,KC_BTN1
  ),

  [MAC_SYMBOL] = LAYOUT_universal(
    KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_TRNS,
    KC_GRV,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_TRNS,
    KC_GRV,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_MINS,
    KC_LSFT,KC_LPRN,KC_RPRN,KC_LBRC,KC_RBRC,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_COMM,KC_DOT,KC_SLSH,KC_EQL,
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,TO(0),KC_TRNS,KC_NO,KC_NO,KC_NO,KC_NO,KC_TRNS,KC_TRNS
  ),

  [MAC_NAVIGATION] = LAYOUT_universal(
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_TRNS,
    KC_NO, LGUI(KC_Q), LGUI(KC_W), LGUI(KC_E), LGUI(KC_R), LGUI(KC_T), LGUI(KC_LEFT), LCTL(KC_TAB), KC_PGUP, LGUI(KC_RIGHT), KC_NO, KC_BSPC,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LCTL(KC_B), LSG(KC_4),
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LSA(KC_LEFT), RCS(KC_TAB), KC_PGDN, LSA(KC_RIGHT), TD(TD_MEDIA_PREV), TD(TD_MEDIA_NEXT),
    SCRL_MO,SCRL_MO_HOR,KC_NO,KC_NO,KC_NO,KC_NO,TO(0), TO(6),KC_NO,KC_NO,KC_NO,KC_NO,KC_TRNS,KC_TRNS
  ),

  [WIN_BASE] = LAYOUT_universal(
    KC_GRV,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL,
    LGUI_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, LCTL_T(KC_SPC), LALT_T(KC_MINS), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
    TD(TD_MEDIA_MUTE), TD(TD_MEDIA_PLAY), MT(MOD_MEH,KC_ESC), KC_LWIN, QK_LEAD, KC_ENT, TT(5), MO(4), KC_SPC, KC_NO, KC_NO, KC_NO, KC_BTN2, KC_BTN1
  ),

  [WIN_SYMBOL] = LAYOUT_universal(
    KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_TRNS,
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
    KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
    KC_LSFT, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_COMM, KC_DOT, KC_SLSH, KC_EQL,
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,TO(3),KC_TRNS,KC_NO,KC_NO,KC_NO,KC_NO,KC_TRNS,KC_TRNS
  ),

  [WIN_NAVIGATION] = LAYOUT_universal(
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_TRNS,
    KC_NO, KC_NO, KC_NO, LGUI(KC_E), LCTL(KC_F5), LSG(KC_RIGHT), LALT(KC_LEFT), LCTL(KC_TAB), KC_PGUP, LALT(KC_RIGHT), KC_NO, KC_BSPC,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LCTL(KC_B), LSG(KC_S),
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RCS(KC_LEFT), RCS(KC_TAB), KC_PGDN, RCS(KC_RIGHT), TD(TD_MEDIA_PREV), TD(TD_MEDIA_NEXT),
    SCRL_MO, SCRL_MO_HOR, KC_NO, KC_NO, KC_NO, KC_NO, TO(3), TO(6), KC_NO,KC_NO,KC_NO,KC_NO,KC_TRNS,KC_TRNS
  ),

  [OPTIONS] = LAYOUT_universal(
    TO(0),TO(3),KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_TRNS,
    RGB_VAI, RGB_SPI, RGB_M_K, RGB_HUI, RGB_SAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    RGB_VAD, RGB_SPD, RGB_M_B, RGB_HUD, RGB_SAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, INSOMNIA
  ),

};

#ifdef OLED_ENABLE

#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

bool is_insomnia_active = false;
bool is_macro_active = false;
bool insomnia_direction = false; // used to alternate direction
uint16_t insomnia_frequency = 5000; // how often to move the mouse (5 seconds)
uint16_t insomnia_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case INSOMNIA:
            if (record->event.pressed) {
                if (layer_state_is(MAC_BASE)) {
                    break;
                } else if (layer_state_is(WIN_BASE)) {
                    break;
                } else {
                is_insomnia_active = !is_insomnia_active;
                }
            }
            break;
        case TO(0):
            if (record->event.pressed) {
                is_insomnia_active = false;
            }
            break;
        case TO(3):
            if (record->event.pressed) {
                is_insomnia_active = false;
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (is_keyboard_master()) {
        // initialize timer on master half only, remove if statement above for non-split
        if (insomnia_timer == 0) insomnia_timer = timer_read();
    };

    if (is_insomnia_active) {
        if (timer_elapsed(insomnia_timer) > insomnia_frequency) {
            insomnia_timer = timer_read();
            if (insomnia_direction) {
                tap_code(KC_MS_L);
            } else {
                tap_code(KC_MS_R);
            }
            insomnia_direction = !insomnia_direction;
        }
    };
}

void leader_end_user(void) {
    // tmux open new window
    if (leader_sequence_one_key(KC_C)) {
        tap_code16(C(KC_B));
        tap_code16(KC_C);
    // tmux rename current window
    } else if (leader_sequence_one_key(KC_COMMA)) {
        tap_code16(C(KC_B));
        tap_code16(KC_COMMA);
    // tmux close current window
    } else if (leader_sequence_one_key(KC_X)) {
        tap_code16(C(KC_B));
        tap_code16(KC_X);
    // tmux split horizontal window
    } else if (leader_sequence_one_key(KC_Z)) {
        tap_code16(C(KC_B));
        SEND_STRING("\"");
    // tmux split vertical window
    } else if (leader_sequence_one_key(KC_V)) {
        tap_code16(C(KC_B));
        tap_code16(KC_PERC);
    // tmux move to previous window
    } else if (leader_sequence_one_key(KC_H)) {
        tap_code16(C(KC_B));
        tap_code16(KC_P);
    // tmux move to next window
    } else if (leader_sequence_one_key(KC_L)) {
        tap_code16(C(KC_B));
        tap_code16(KC_N);
    // tmux move up a pane
    } else if (leader_sequence_one_key(KC_K)) {
        tap_code16(C(KC_B));
        tap_code16(KC_UP);
    // tmux move down a pane
    } else if (leader_sequence_one_key(KC_J)) {
        tap_code16(C(KC_B));
        tap_code16(KC_DOWN);
    // tmux detach session
    } else if (leader_sequence_one_key(KC_D)) {
        tap_code16(C(KC_B));
        tap_code16(KC_D);
    // tmux enter copy mode
    } else if (leader_sequence_one_key(KC_SLSH)) {
        tap_code16(C(KC_B));
        tap_code16(KC_LBRC);
    // tmux paste buffer in copy mode
    } else if (leader_sequence_one_key(KC_P)) {
        tap_code16(C(KC_B));
        tap_code16(KC_RBRC);
    // tmux move between windows
    } else if (leader_sequence_one_key(KC_O)) {
        tap_code16(C(KC_B));
        tap_code16(KC_O);
    // winmac: alt tab or gui tab
    } else if (leader_sequence_one_key(KC_TAB)) {
        if (layer_state_is(MAC_BASE)) {
            tap_code16(G(KC_TAB));
        };
        if (layer_state_is(WIN_BASE)) {
            tap_code16(A(KC_TAB));
        };
    // winmac: close window/tab
    } else if (leader_sequence_one_key(KC_W)) {
        if (layer_state_is(MAC_BASE)) {
            tap_code16(G(KC_W));
        };
        if (layer_state_is(WIN_BASE)) {
            tap_code16(C(KC_W));
        };
    // winmac: new tab
    } else if (leader_sequence_one_key(KC_T)) {
        if (layer_state_is(MAC_BASE)) {
            tap_code16(G(KC_T));
        };
        if (layer_state_is(WIN_BASE)) {
            tap_code16(C(KC_T));
        };
    // winmac: quit/close window
    } else if (leader_sequence_one_key(KC_Q)) {
        if (layer_state_is(MAC_BASE)) {
            tap_code16(G(KC_Q));
        };
        if (layer_state_is(WIN_BASE)) {
            tap_code16(A(KC_F4));
        };
    // winmac: refresh window
    } else if (leader_sequence_one_key(KC_R)) {
        if (layer_state_is(MAC_BASE)) {
            tap_code16(G(KC_R));
        };
        if (layer_state_is(WIN_BASE)) {
            tap_code16(A(KC_F5));
        };
    }
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case WIN_AZ_UNDO: {
            if (layer_state_is(MAC_BASE)) {
                return false;
            }
            break;
        }
        case WIN_SX_CUT: {
            if (layer_state_is(MAC_BASE)) {
                return false;
            }
            break;
        }
        case WIN_DC_COPY: {
            if (layer_state_is(MAC_BASE)) {
                return false;
            }
            break;
        }
        case WIN_FR_CLIP_HISTORY: {
            if (layer_state_is(MAC_BASE)) {
                return false;
            }
            break;
        }
        case WIN_FV_PASTE: {
            if (layer_state_is(MAC_BASE)) {
                return false;
            }
            break;
        }
        case MAC_SW_ALFRED_SNIPPET: {
            if (layer_state_is(WIN_BASE)) {
                return false;
            }
            break;
        }
        case MAC_AZ_UNDO: {
            if (layer_state_is(WIN_BASE)) {
                return false;
            }
            break;
        }
        case MAC_SX_CUT: {
            if (layer_state_is(WIN_BASE)) {
                return false;
            }
            break;
        }
        case MAC_DC_COPY: {
            if (layer_state_is(WIN_BASE)) {
                return false;
            }
            break;
        }
        case MAC_FR_ALFRED_PASTE: {
            if (layer_state_is(WIN_BASE)) {
                return false;
            }
            break;
        }
        case MAC_FV_PASTE: {
            if (layer_state_is(WIN_BASE)) {
                return false;
            }
            break;
        }
        case MAC_QA_MISSION_CTRL: {
            if (layer_state_is(WIN_BASE)) {
                return false;
            }
            break;
        }
    }
   return true;
}
