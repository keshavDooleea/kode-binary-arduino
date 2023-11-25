#include <ByteManager/ByteManager.h>
#include <Arduino.h>

ByteManager::ByteManager() {
    generateNewNumber();
    initActivatedBytes();
}

void ByteManager::generateNewNumber() {
    currNumber = 39;
}

void ByteManager::initActivatedBytes() {
    for (int i = 0; i < NB_OF_BUTTONS; ++i) {
        activatedBytes[i] = 0; 
    }
}

int ByteManager::getCurrNumber() {
    return currNumber;
}

void ByteManager::handleButtonClicked(int byte, int btnLedPosition) {
    int newValue = activatedBytes[btnLedPosition] == 0 ? byte : 0;
    activatedBytes[btnLedPosition] = newValue;

    Serial.println(activatedBytes[0]);
    Serial.println(activatedBytes[1]);
    Serial.println(activatedBytes[2]);
    Serial.println(activatedBytes[3]);
    Serial.println(activatedBytes[4]);
    Serial.println("AAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
}