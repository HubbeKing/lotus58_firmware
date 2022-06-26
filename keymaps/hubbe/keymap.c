#include QMK_KEYBOARD_H

// Layers
enum layers {
    _QWERTY,
    _GAMING,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _SYSTEM,
};

// Custom keycode declarations
enum custom_keycodes {
    KC_PREV_WORD = SAFE_RANGE,  // ensure macro codes get unique numbers internally
    KC_NEXT_WORD,
    QWERTY,
    COLEMAK,
    GAMING
};

// Custom keycode definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // navigation macros
        case KC_PREV_WORD:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));   // ctrl + left
            }
            return false;
        case KC_NEXT_WORD:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));  // ctrl + right
            }
            return false;
        // layout macros
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
    }
    return true;
}

// Layer shortcuts
#define RAISE MO(_RAISE)            // hold for _RAISE
#define LOWER MO(_LOWER)            // hold for _LOWER

// Oneshot mod shortcuts
#define OM_LSFT OSM(MOD_LSFT)
#define OM_LCTRL OSM(MOD_LCTL)
#define OM_LALT OSM(MOD_LALT)
#define OM_RALT OSM(MOD_RALT)

// Macro shortcuts
#define PRV_WRD KC_PREV_WORD
#define NXT_WRD KC_NEXT_WORD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.   ___              .-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |  | O |       ___   |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|  | L |      /   \  |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  | E |     (MUTE ) |   Y  |   U  |   I  |   O  |   P  |   =  |
 * |------+------+------+------+------+------|  |_D_|      \___/  |------+------+------+------+------+------|
 * |LCtrl |   A  |   S  |   D  |   F  |   G  |-------.    .-------|   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |\ Shft|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP|AltGr |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_QWERTY] = LAYOUT(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
    OM_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    OM_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_BSLS),
                       KC_NO,   OM_LALT, KC_LGUI, LOWER,  KC_SPC,   KC_ENT,   RAISE,   KC_BSPC, OM_RALT, KC_MUTE
),

// Identical to QWERTY but omit oneshot mods for easier Ctrl/Shift tapping in games
[_GAMING] = LAYOUT(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
    KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_BSLS),
                       KC_NO,   KC_LALT, KC_LGUI, LOWER,  KC_SPC,   KC_ENT,   RAISE,   KC_BSPC, KC_RALT, KC_MUTE
),

/* COLEMAK-DH
 * ,-----------------------------------------.   ___              .-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |  | O |       ___   |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|  | L |      /   \  |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |  | E |     (MUTE ) |   J  |   L  |   U  |   Y  |   ;  |   =  |
 * |------+------+------+------+------+------|  |_D_|      \___/  |------+------+------+------+------+------|
 * |LCtrl |   A  |   R  |   S  |   T  |   G  |-------.    .-------|   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |\ Shft|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP|AltGr |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_COLEMAK] = LAYOUT(
    KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL,
    OM_LCTRL,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    OM_LSFT,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_LBRC,  KC_RBRC,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_BSLS),
                        KC_NO,   OM_LALT, KC_LGUI, LOWER,  KC_SPC,   KC_ENT,   RAISE,   KC_BSPC, OM_RALT, KC_MUTE
),

/*LOWER
 * ,-----------------------------------------.   ___              .-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |  | O |       ___   |   ^  |   &  |   *  |   (  |   )  |   `  |
 * |------+------+------+------+------+------|  | L |      /   \  |------+------+------+------+------+------|
 * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |  | E |     (MUTE ) |      |      |      |      |   `  |   _  |
 * |------+------+------+------+------+------|  |_D_|      \___/  |------+------+------+------+------+------|
 * |LCtrl |  F6  |  F7  |  F8  |  F9  |  F10 |-------.    .-------|      |      |      |      |   :  |   "  |
 * |------+------+------+------+------+------|   {   |    |   }   |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|      |      |   <  |   >  |   ?  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | Del  |AltGr |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,  KC_PLUS,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COLN, KC_DQUO,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   KC_QUES, KC_PIPE,
                      KC_NO,   _______, _______, _______, _______, _______, _______, KC_DEL,  _______, KC_MUTE
),

/* RAISE
 * ,-----------------------------------------.   ___              .-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  | O |       ___   |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|  | L |      /   \  |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |  | E |     (MUTE ) | PgUp |PrvWrd|  Up  |NxtWrd|      |  F12 |
 * |------+------+------+------+------+------|  |_D_|      \___/  |------+------+------+------+------+------|
 * |LCtrl |      |      | Prev | Play | Next |-------.    .-------| PgDn | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|      | Home |      | End  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | Del  |AltGr |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PGUP, PRV_WRD, KC_UP,   NXT_WRD, XXXXXXX, KC_F12,
    _______, XXXXXXX, XXXXXXX, KC_MRWD, KC_MPLY, KC_MFFD,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, XXXXXXX,
                      KC_NO,   _______, _______, _______, _______, _______, _______, KC_DEL,  _______, KC_MUTE
),

/* SYSTEM
 * ,------------------------------------------.   ___              .-----------------------------------------.
 * |QK_BOOT|      |      |      |      |PrnScr|  | O |       ___   |NumLck|  7   |  8   |  9   |  +   |      |
 * |-------+------+------+------+------+------|  | L |      /   \  |------+------+------+------+------+------|
 * |NK_TOGG|QWERTY|      |      |      |      |  | E |     (MUTE ) |      |  4   |  5   |  6   |  -   |      |
 * |-------+------+------+------+------+------|  |_D_|      \___/  |------+------+------+------+------+------|
 * |       |      |      |      |      |GAMING|-------.    .-------|      |  1   |  2   |  3   |  *   |      |
 * |-------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |CapsLK |      |      |COLEMK|      |      |-------|    |-------|      |  0   |  0   |  .   |  /   |  =   |
 * `-----------------------------------------/       /     \       \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | / Space /       \ Enter \  |RAISE |BackSP|AltGr |
 *                   |      |      |      |/       /         \ (KP)  \ |      |      |      |
 *                   `----------------------------'           '-------''--------------------'
 */
// QK_BOOT = Put the keyboard into bootloader mode for flashing
// NK_TOGG = Toggle USB N-key rollover (for better BIOS compatibility)

  [_SYSTEM] = LAYOUT(
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,                   KC_NUM,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS, XXXXXXX,
  NK_TOGG, QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAMING,                    XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PAST, XXXXXXX,
  KC_CAPS, XXXXXXX, XXXXXXX, COLEMAK, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, KC_P0,   KC_P0,   KC_PDOT, KC_PSLS, KC_PEQL,
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
        case _LOWER:
            oled_write_P(PSTR("LOW "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("HIGH"), false);
            break;
        case _SYSTEM:
            oled_write_P(PSTR("SYS "), false);
            break;
        default:
            // for some reason, get_highest_layer(layer_state) returns _QWERTY
            // even if the default layer has been changed with DH() or set_single_persistent_default_layer()
            // default_layer_state should update properly in all cases
            if (default_layer_state == 1) {
                oled_write_P(PSTR("QRTY"), false);
                break;
            }
            else if (default_layer_state == 2) {
                oled_write_P(PSTR("GAME"), false);
                break;
            }
            else if (default_layer_state == 4) {
                oled_write_P(PSTR("CLMK"), false);
                break;
            }
            else {
                oled_write_P(PSTR("????"), false);
                break;
            }
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

void render_kro_status(void) {
    oled_write_P(PSTR(" "), false);
    if (keymap_config.nkro) {
        oled_write_P(PSTR("NKRO"), true);
    }
    else {
        oled_write_P(PSTR("6KRO"), false);
    }
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
    render_mod_status(get_mods() | get_oneshot_mods());  // or together mods and oneshots to get accurate status
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Render NKRO status
    render_kro_status();
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
