#include <ByteManager/ByteManager.h>
#include <Constants.h>
#include <Arduino.h>

ByteManager::ByteManager() { }

void ByteManager::generateNewNumber() {
    int maxBytesRange = 1 << NB_OF_BUTTONS;
    _generatedNumber = random(1, maxBytesRange);
    _currentTotal = 0;

    Serial.println("Number is: " + String(_generatedNumber));
}

bool ByteManager::isConversionValid() {
    return _currentTotal == _generatedNumber;
}

void ByteManager::handleByteButton(int byte, bool isPressed) {
    if (isPressed) {
        _currentTotal += byte;
    } else {
        _currentTotal -= byte;
    }
}