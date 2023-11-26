#ifndef LCD_MANAGER_H
#define LCD_MANAGER_H

#include <TM1637.h>

class LcdManager {

    private:
        TM1637 _tm;
        static const int BRIGHTNESS = 5;

    public:
        LcdManager(int CLK, int DIO);

        void init();
        void clear();
        void display(int number);
};

#endif // LCD_MANAGER_H