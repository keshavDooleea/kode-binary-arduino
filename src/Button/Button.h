#ifndef BUTTON_H
#define BUTTON_H

#include <Constants.h>

class Button {
    public:
        Button(Pins pin);

        void init();
        void addPressListener();
        bool isPressed();

    private:
        int buttonPin;
};

#endif // BUTTON_H