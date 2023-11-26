#include <LcdManager/LcdManager.h>

LcdManager::LcdManager(int CLK, int DIO) : _tm(CLK, DIO) { }

void LcdManager::init() {
    _tm.init();
    _tm.set(LcdManager::BRIGHTNESS);
    clear();
}

void LcdManager::clear() {
    _tm.clearDisplay();
}

void LcdManager::display(int number) {
    if (number > 9) {
        _tm.display(2, number / 10);
        _tm.display(3, number % 10);
    } else {
        _tm.display(3, number);
    }
}

