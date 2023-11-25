#ifndef BUTTON_LED_H
#define BUTTON_LED_H

#include <Constants.h>

class ButtonLed {
    public:
        ButtonLed(int buttonPin, int ledPin);

        void init();
        void listen();

    private:
        int buttonPin;
        int ledPin;
        int isPressed;
};

#endif // BUTTON_LED_H