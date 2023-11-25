#include <Arduino.h>
#include <Constants.h>
#include <ButtonLed/ButtonLed.h>
#include <ByteManager/ByteManager.h>
#include <ValidateButton/ValidateButton.h>

ByteManager byteManager;
ValidateButton validateButton(7, 13, 14, nullptr);

void onByteBtnClickedCb(int byte, int btnLedPosition) {
  byteManager.handleByteButton(byte, btnLedPosition);
}

void onValidateBtnClickedCb() {
  validateButton.blinkLed(byteManager.isConversionValid());
  // byteManager.generateNewNumber();
}

ButtonLed buttonLeds[NB_OF_BUTTONS] = {
  ButtonLed(16, 2, 8,  onByteBtnClickedCb),
  ButtonLed(8,  3, 9,  onByteBtnClickedCb),
  ButtonLed(4,  4, 10, onByteBtnClickedCb),
  ButtonLed(2,  5, 11, onByteBtnClickedCb),
  ButtonLed(1,  6, 12, onByteBtnClickedCb),
};

void setup() {
  Serial.begin(BAUD_RATE);

  byteManager.generateNewNumber();
  validateButton.init();
  validateButton.setOnBtnClickedCb(onValidateBtnClickedCb);
  
  for (int i = 0; i < NB_OF_BUTTONS; ++i) {
    buttonLeds[i].init();
  }
}

void loop() {
  validateButton.read();
  
  for (int i = 0; i < NB_OF_BUTTONS; ++i) {
    buttonLeds[i].read(i);
  }
}