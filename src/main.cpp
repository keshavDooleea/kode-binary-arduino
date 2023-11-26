#include <Arduino.h>
#include <ButtonLed/ButtonLed.h>
#include <ByteManager/ByteManager.h>
#include <ValidateButton/ValidateButton.h>
#include <LcdManager/LcdManager.h>

ByteManager byteManager;
LcdManager lcdManager(A1, A2);
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
  lcdManager.clear();

  for (int i = 0; i < NB_OF_BUTTONS; ++i) {
    buttonLeds[i].turnOffLed();
  }
}

void setup() {
  randomSeed(analogRead(A5));
  Serial.begin(BAUD_RATE);
  
  byteManager.generateNewNumber();

  lcdManager.init();
  
  validateButton.init();
  validateButton.setOnBtnClickedCb(onValidateBtnClickedCb);
  
  for (int i = 0; i < NB_OF_BUTTONS; ++i) {
    buttonLeds[i].init();
    buttonLeds[i].setOnBtnClickedCb(onByteBtnClickedCb);
  }
}

void loop() {
  lcdManager.display(byteManager.getGeneratedNumber());
  validateButton.read();

  for (int i = 0; i < NB_OF_BUTTONS; ++i) {
    buttonLeds[i].read();
  }
}