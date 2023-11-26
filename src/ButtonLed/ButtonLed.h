#ifndef BUTTON_LED_H
#define BUTTON_LED_H

#include <Arduino.h>
#include <AbsButton/AbsButton.h>

class ButtonLed : public AbsButton {
    
    private:
        int _byte;
        int _ledPin;
        int _ledState;
        void (*onBtnClickedCb)(int byte, bool isPressed);
        void handleLed(int volt);

    public:
        ButtonLed(int byte, int buttonPin, int ledPin, void (*onBtnClickedCb)(int byte, bool isPressed) = nullptr);

        void init() override;
        void onClick() override;

        void turnOffLed();
        void setOnBtnClickedCb(void (*cb)(int byte, bool isPressed));
};

#endif // BUTTON_LED_H