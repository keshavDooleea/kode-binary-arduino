#include <ValidateButton/ValidateButton.h>

ValidateButton::ValidateButton(int buttonPin, int greenLedPin, int redLedPin, void (*onBtnClickedCb)()) 
  : AbsButton(buttonPin), _greenLedPin(greenLedPin), _redLedPin(redLedPin), onBtnClickedCb(onBtnClickedCb) {}

void ValidateButton::init() {
  AbsButton::init();
  pinMode(_greenLedPin, OUTPUT);
  pinMode(_redLedPin, OUTPUT);
}

void ValidateButton::setOnBtnClickedCb(void (*cb)()) {
  onBtnClickedCb = cb;
}

void ValidateButton::blinkLed(bool isGreen) {
  int blinkCount = 5;
  int blinkDelay = 175;
  int ledPin = isGreen ? _greenLedPin : _redLedPin;

  for (int i = 0; i < blinkCount; ++i) {
    digitalWrite(ledPin, HIGH); 
    delay(blinkDelay); 
    digitalWrite(ledPin, LOW); 
    delay(blinkDelay); 
  }

  delay(1000);
}

void ValidateButton::onClick() {
  onBtnClickedCb();
}