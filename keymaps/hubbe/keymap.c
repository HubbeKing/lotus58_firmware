#include QMK_KEYBOARD_H

// Layers
enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _SYSTEM,
};

// Custom keycodes
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    KC_Å,
    KC_Ä,
    KC_Ö,
    KC_EUR
};

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // EurKey macros for åäö€
        case KC_Å:
            if (record->event.pressed) {
                SEND_STRING(SS_ALGR("w"));
            }
            break;
        case KC_Ä:
            if (record->event.pressed) {
                SEND_STRING(SS_ALGR("a"));
            }
            break;
        case KC_Ö:
            if (record->event.pressed) {
                SEND_STRING(SS_ALGR("o"));
            }
            break;
        case KC_EUR:
            if (record->event.pressed) {
                SEND_STRING(SS_ALGR("5"));
            }
            break;
    }
    return true;
}

// Tap Dance declarations
enum {
    TD_RGUI_RALT
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for RGUI, twice for RAlt
    [TD_RGUI_RALT] = ACTION_TAP_DANCE_DOUBLE(KC_RGUI, KC_RALT)
};

// Tap Dance shortcuts
#define T_RGUI TD(TD_RGUI_RALT)     // Tap once for RGUI, twice for RAlt

// Tap-hold shortcuts
#define MT_EQ MT(MOD_RSFT, KC_EQL)  // hold for RShift, tap for =

// Layer shortcuts
#define RAISE MO(_RAISE)            // hold for _RAISE
#define LOWER MO(_LOWER)            // hold for _LOWER

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.   ___              .-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |  | O |       ___   |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|  | L |      /   \  |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  | E |     (MUTE ) |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|  |_D_|      \___/  |------+------+------+------+------+------|
 * |LCtrl |   A  |   S  |   D  |   F  |   G  |-------.    .-------|   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |=/Shft|
 * `-----------------------------------------|       /    \       |-----------------------------------------'
 *                    | LAlt | LGUI |LOWER| / Space /      \ Enter \ |RAISE |BackSP| RGUI |
 *                    |      |      |     |/       /        \       \|      |      | RAlt |
 *                    `-------------------'-------'          '-------'--------------------'
 */

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT_EQ,
                    KC_NO,   KC_LALT, KC_LGUI, LOWER,KC_SPC,   KC_ENT,   RAISE,   KC_BSPC, T_RGUI,  KC_MUTE
),

/*LOWER
 * ,-----------------------------------------.   ___              .-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |  | O |       ___   |   ^  |   &  |   *  |   (  |   )  |   `  |
 * |------+------+------+------+------+------|  | L |      /   \  |------+------+------+------+------+------|
 * |CapsLK|      |   Å  |   €  |      |      |  | E |     (MUTE ) |      |      |      |   Ö  |      |   |  |
 * |------+------+------+------+------+------|  |_D_|      \___/  |------+------+------+------+------+------|
 * |LCtrl |   Ä  |      |      |      |      |-------.    .-------|      |      |      |      |   :  |   "  |
 * |------+------+------+------+------+------|   {   |    |   }   |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|      |      |   <  |   >  |   ?  |   +  |
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *                    | LAlt | LGUI |LOWER| / Space /      \ Enter \ |RAISE | Del  | RGUI |
 *                    |      |      |     |/       /        \       \|      |      | RAlt |
 *                    `-------------------'-------'          '-------'--------------------'
 */
[_LOWER] = LAYOUT(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
  KC_CAPS, XXXXXXX, KC_Å,    KC_EUR,  XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_Ö,    XXXXXXX, KC_PIPE,
  _______, KC_Ä,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COLN, KC_DQUO,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUES, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   KC_QUES, KC_PLUS,
                    KC_NO,   _______, _______, _______, _______, _______, _______, KC_DEL,  _______, KC_MUTE
),

/* RAISE
 * ,-----------------------------------------.   ___              .-----------------------------------------.
 * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |  | O |       ___   |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+------|  | L |      /   \  |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |  | E |     (MUTE ) | PgUp |      |  Up  |      | Home |      |
 * |------+------+------+------+------+------|  |_D_|      \___/  |------+------+------+------+------+------|
 * |LCtrl |      |      | Prev | Play | Next |-------.    .-------| PgDn | Left | Down |Right | End  |      |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *                    | LAlt | LGUI |LOWER| / Space /      \ Enter \ |RAISE | Del  | RGUI |
 *                    |      |      |     |/       /        \       \|      |      | RAlt |
 *                    `-------------------'-------'          '-------'--------------------'
 */

[_RAISE] = LAYOUT(
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_PGUP, XXXXXXX, KC_UP,   XXXXXXX, KC_HOME, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, KC_MRWD, KC_MPLY, KC_MFFD,                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    KC_NO,   _______, _______, _______,  _______, _______,  _______, KC_DEL,  _______, KC_MUTE
),

/* SYSTEM
 * ,------------------------------------------.   ___              .-----------------------------------------.
 * |QK_BOOT|EE_CLR|QK_RBT|      |      |PrnScr|  | O |       ___   |NumLck|  7   |  8   |  9   |  -   |ScrLK |
 * |-------+------+------+------+------+------|  | L |      /   \  |------+------+------+------+------+------|
 * |NK_TOGG|      |      |      |      |      |  | E |     (MUTE ) |      |  4   |  5   |  6   |  +   |      |
 * |-------+------+------+------+------+------|  |_D_|      \___/  |------+------+------+------+------+------|
 * |CapsLK |      |      |      |      |      |-------.    .-------|      |  1   |  2   |  3   |  *   |      |
 * |-------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |       |      |      |      |      |      |-------|    |-------|      |  0   |  0   |  .   |  /   |  =   |
 * `------------------------------------------/       /    \       \-----------------------------------------'
 *                    | LAlt | LGUI |LOWER| / Space /      \ Enter \ |RAISE |BackSP| RGUI |
 *                    |      |      |     |/       /        \  (KP) \|      |      | RAlt |
 *                    `-------------------'-------'          '-------'--------------------'
 */
// QK_BOOT = Put the keyboard into bootloader mode for flashing
// EE_CLR  = Reinitializes the keyboard’s EEPROM (persistent memory)
// QK_RBT  = Reboot keyboard
// NK_TOGG = Toggle USB N-key rollover (for better BIOS compatibility)

  [_SYSTEM] = LAYOUT(
  QK_BOOT, EE_CLR,  QK_RBT,  XXXXXXX, XXXXXXX, KC_PSCR,                   KC_NUM,  KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_SCRL,
  NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX,
  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PAST, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0,   KC_P0,   KC_PDOT, KC_PSLS, KC_PEQL,
                    KC_NO,   _______, _______, _______, _______, KC_PENT, _______, KC_BSPC, _______, KC_MUTE
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // if _RAISE and _LOWER are both on, go to _SYSTEM layer
    state = update_tri_layer_state(state, _RAISE, _LOWER, _SYSTEM);
    return state;
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR(" "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QRTY"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOW "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("HIGH"), false);
            break;
        case _SYSTEM:
            oled_write_ln_P(PSTR("SYS"), false);
            break;
        default:
            oled_write_ln_P(PSTR("????"), false);
    }
}

void render_keylock_status(led_t led_state) {
    oled_write_ln_P(PSTR("Lock"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_write_ln_P(PSTR("S"), led_state.scroll_lock);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("Mods"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_magic_status(void) {
    oled_write_P(PSTR("Magic"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("NKRO"), keymap_config.nkro);
}

void render_status_main(void) {
    // Show keyboard layout
    render_default_layer_state();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show host keyboard led status
    render_keylock_status(host_keyboard_led_state());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show modifier status
    render_mod_status(get_mods());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Render Magic/NKRO status
    render_magic_status();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
}

bool oled_task_user(void) {
    render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    return false;
}

#endif // OLED_ENABLE

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_QWERTY)) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLD);
        }
        else {
            tap_code(KC_VOLU);
        }
    }
    else {  // on RAISE, LOWER, or SYSTEM layer
        // Navigation
        if (clockwise) {
            tap_code(KC_MS_WH_UP);
        }
        else {
            tap_code(KC_MS_WH_DOWN);
        }
    }
    return true;
}

#endif // ENCODER_ENABLE
