#include <ByteManager/ByteManager.h>
#include <Arduino.h>

ByteManager::ByteManager() : _isConversionValid(false) {
    generateNewNumber();
    initActivatedBytes();
}

void ByteManager::generateNewNumber() {
    _currNumber = 3;
}

void ByteManager::initActivatedBytes() {
    for (int i = 0; i < NB_OF_BUTTONS; ++i) {
        _activatedBytes[i] = 0; 
    }
}

bool ByteManager::isConversionValid() {
    return _isConversionValid;
}

void ByteManager::updateConversion() {
    int total = 0;

    for (int i = 0; i < NB_OF_BUTTONS; ++i) {
        total += _activatedBytes[i]; 
    } 

    _isConversionValid = total == _currNumber;
}

void ByteManager::handleByteButton(int byte, int btnLedPosition) {
    int newValue = _activatedBytes[btnLedPosition] == 0 ? byte : 0;
    _activatedBytes[btnLedPosition] = newValue;
    
    updateConversion();
}