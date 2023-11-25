#ifndef BUTTON_LED_H
#define BUTTON_LED_H

class ButtonLed {
    
    private:
        int byte;
        int buttonPin;
        int ledPin;
        int ledState;
        int currentBtnState;
        int previousBtnState;
        void (*onBtnClickedCb)(int byte, int btnLedPosition);

    public:
        ButtonLed(int byte, int buttonPin, int ledPin, 
            void (*onBtnClickedCb)(int byte, int btnLedPosition) = nullptr);

        void init();
        void read(int btnLedPosition);
        int getByte();
};

#endif // BUTTON_LED_H