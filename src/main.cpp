#include <Arduino.h>
#include <Constants.h>
#include <ButtonLed/ButtonLed.h>
#include <ByteManager/ByteManager.h>
#include <ValidateButton/ValidateButton.h>

ByteManager byteManager;
ValidateButton validateButton(7, 13, A0, nullptr);

ButtonLed buttonLeds[NB_OF_BUTTONS] = {
  ButtonLed(16, 2, 8,  nullptr),
  ButtonLed(8,  3, 9,  nullptr),
  ButtonLed(4,  4, 10, nullptr),
  ButtonLed(2,  5, 11, nullptr),
  ButtonLed(1,  6, 12, nullptr),
};

void onByteBtnClickedCb(int byte, bool isPressed) {
  byteManager.handleByteButton(byte, isPressed);
}

void onValidateBtnClickedCb() {
  bool isConversionValid = byteManager.isConversionValid();
  validateButton.blinkLed(isConversionValid);

  if (!isConversionValid) {
    return;
  }

  byteManager.generateNewNumber();

  for (int i = 0; i < NB_OF_BUTTONS; ++i) {
    buttonLeds[i].turnOffLed();
  }
}

void setup() {
  randomSeed(analogRead(A1));
  Serial.begin(BAUD_RATE);

  byteManager.generateNewNumber();
  
  validateButton.init();
  validateButton.setOnBtnClickedCb(onValidateBtnClickedCb);
  
  for (int i = 0; i < NB_OF_BUTTONS; ++i) {
    buttonLeds[i].init();
    buttonLeds[i].setOnBtnClickedCb(onByteBtnClickedCb);
  }
}

void loop() {
  validateButton.read();
  
  for (int i = 0; i < NB_OF_BUTTONS; ++i) {
    buttonLeds[i].read();
  }
}