#ifndef VALIDATE_BUTTON_H
#define VALIDATE_BUTTON_H

class ValidateButton {
    
    private:
        int buttonPin;
        int greenLedPin;
        int redLedPin;
        int currentBtnState;
        int previousBtnState;
        void (*onBtnClickedCb)();

    public:
        ValidateButton(int buttonPin, int greenLedPin, int redLedPin, void (*onBtnClickedCb)() = nullptr);

        void init();
        void read();
};

#endif // VALIDATE_BUTTON_H