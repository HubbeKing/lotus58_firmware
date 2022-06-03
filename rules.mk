# MCU name
MCU = atmega32u4

# Bootloader selection
#BOOTLOADER = caterina
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration		https://github.com/qmk/qmk_firmware/blob/master/docs/feature_bootmagic.md
MOUSEKEY_ENABLE = yes		# Mouse keys							https://github.com/qmk/qmk_firmware/blob/master/docs/feature_mouse_keys.md
EXTRAKEY_ENABLE = yes       # Audio control and System control
TAP_DANCE_ENABLE = yes		# Enable Tap Dance						https://github.com/qmk/qmk_firmware/blob/master/docs/feature_tap_dance.md
AUTO_SHIFT_ENABLE = no		# Enable auto-shift						https://github.com/qmk/qmk_firmware/blob/master/docs/feature_auto_shift.md

CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration

NKRO_ENABLE = yes			# USB Nkey Rollover

BACKLIGHT_ENABLE = no		# Enable keyboard backlighting			https://github.com/qmk/qmk_firmware/blob/master/docs/feature_backlight.md
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow			https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md
ENCODER_ENABLE = yes		# Enable encoder support				https://github.com/qmk/qmk_firmware/blob/master/docs/feature_encoders.md
OLED_ENABLE = yes			# Enable OLED support					https://github.com/qmk/qmk_firmware/blob/master/docs/feature_oled_driver.md
SPLIT_KEYBOARD = yes

LTO_ENABLE = yes			# enable Link Time Optimization to reduce firmware size

# work around bug with avr-gcc 12
EXTRAFLAGS += --param=min-pagesize=0
