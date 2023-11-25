#include <Arduino.h>
#include <Constants.h>
#include <ButtonLed/ButtonLed.h>
#include <ByteManager/ByteManager.h>
#include <ValidateButton/ValidateButton.h>

ByteManager byteManager;

void onByteBtnClickedCb(int byte, int btnLedPosition) {
  byteManager.handleByteButton(byte, btnLedPosition);
}

void onValidateBtnClickedCb() {
  Serial.println("CLICK");
  Serial.println(byteManager.isConversionValid());
}

ButtonLed buttonLeds[NB_OF_BUTTONS] = {
  ButtonLed(16, 2, 8,  onByteBtnClickedCb),
  ButtonLed(8,  3, 9,  onByteBtnClickedCb),
  ButtonLed(4,  4, 10, onByteBtnClickedCb),
  ButtonLed(2,  5, 11, onByteBtnClickedCb),
  ButtonLed(1,  6, 12, onByteBtnClickedCb),
};

ValidateButton validateButton(7, 14, 15, onValidateBtnClickedCb);

void setup() {
  Serial.begin(BAUD_RATE);

  byteManager.generateNewNumber();
  validateButton.init();
  
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