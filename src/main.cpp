#include <Arduino.h>

#define LAYOUT_US_INTERNATIONAL
#include <DigiKeyboard.h>

#define EJECT_PIN (1 << 0)
#define UP_PIN (1 << 1)
#define DOWN_PIN (1 << 2)

#define INPUT_MASK (EJECT_PIN | UP_PIN | DOWN_PIN)

void setup() {
    // Input with internal pullup
    DDRB &= ~INPUT_MASK;
    PORTB |= INPUT_MASK;
}

void loop() {
    // Debounce the whole PINB regisster.
    // Use pinb instead of PINB in your code to get the debounced value
    static uint8_t pinb, counter_msb, counter_lsb;
    uint8_t scratch = pinb ^ PINB;
    counter_lsb = ~(counter_lsb & scratch);
    counter_msb = counter_lsb ^ (counter_msb & scratch);
    scratch &= counter_msb & counter_lsb;
    pinb ^= scratch;

    // CTRL-E
    static uint8_t ctrl_e_state;
    if (!(pinb & EJECT_PIN)) {
        ctrl_e_state ^= static_cast<uint8_t>(KEY_E);
        DigiKeyboard.sendKeyStroke(ctrl_e_state, static_cast<uint8_t>(MOD_CONTROL_LEFT));
    } else if (!(pinb & UP_PIN)) {
        DigiKeyboard.sendKeyPress(static_cast<uint8_t>(KEY_COMMA), static_cast<uint8_t>(MOD_ALT_LEFT));
    } else if (!(pinb & DOWN_PIN)) {
        DigiKeyboard.sendKeyPress(static_cast<uint8_t>(KEY_PERIOD), static_cast<uint8_t>(MOD_ALT_LEFT));
    } else {
        DigiKeyboard.sendKeyStroke(0);
    }
}