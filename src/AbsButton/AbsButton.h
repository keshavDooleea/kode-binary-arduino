#ifndef ABS_BUTTON_H
#define ABS_BUTTON_H

#include <Arduino.h>

class AbsButton {
    
    protected:
        int _buttonPin;
        int _currentBtnState;
        int _previousBtnState;

        virtual void onClick() = 0;

    public:
        AbsButton(int buttonPin);

        virtual void init();
        void read();
};

#endif // ABS_BUTTON_H