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
        void (*onBtnClickedCb)(int byte, bool isPressed);
        void handleLed(int volt);

    public:
        ButtonLed(int byte, int buttonPin, int ledPin, 
            void (*onBtnClickedCb)(int byte, bool isPressed) = nullptr);

        void init();
        void read();
        void turnOffLed();
        void setOnBtnClickedCb(void (*cb)(int byte, bool isPressed));
};

#endif // BUTTON_LED_H