#ifndef VALIDATE_BUTTON_H
#define VALIDATE_BUTTON_H

#include <Arduino.h>
#include <AbsButton/AbsButton.h>

class ValidateButton : public AbsButton {
    
    private:
        int _greenLedPin;
        int _redLedPin;
        void (*onBtnClickedCb)();

    public:
        ValidateButton(int buttonPin, int greenLedPin, int redLedPin, void (*onBtnClickedCb)() = nullptr);

        void init() override;
        void onClick() override;

        void blinkLed(bool isGreen);
        void setOnBtnClickedCb(void (*cb)());
};

#endif // VALIDATE_BUTTON_H