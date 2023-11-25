#ifndef BUTTON_LED_PAIR_H
#define BUTTON_LED_PAIR_H

#include <Constants.h>

class ButtonLedPair {
    public:
        ButtonLedPair(int buttonPin, int ledPin);

        void init();
        void listen();

    private:
        int buttonPin;
        int ledPin;
        int isPressed;
};

#endif // BUTTON_LED_PAIR_H