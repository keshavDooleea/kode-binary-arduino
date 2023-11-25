#include <Arduino.h>
#include <Constants.h>
#include <ButtonLed/ButtonLed.h>
#include <ByteManager/ByteManager.h>

ByteManager byteManager;

void btnClickedCb(int byte, int btnLedPosition) {
  byteManager.handleButtonClicked(byte, btnLedPosition);
}

ButtonLed buttonLeds[NB_OF_BUTTONS] = {
  ButtonLed(16, 2, 8,  btnClickedCb),
  ButtonLed(8,  3, 9,  btnClickedCb),
  ButtonLed(4,  4, 10, btnClickedCb),
  ButtonLed(2,  5, 11, btnClickedCb),
  ButtonLed(1,  6, 12, btnClickedCb),
};

void setup() {
  Serial.begin(BAUD_RATE);

  byteManager.generateNewNumber();
  
  for (int i = 0; i < NB_OF_BUTTONS; ++i) {
    buttonLeds[i].init();
  }
}

void loop() {
  for (int i = 0; i < NB_OF_BUTTONS; ++i) {
    buttonLeds[i].read(i);
  }
}