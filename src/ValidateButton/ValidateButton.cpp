#include <ValidateButton/ValidateButton.h>
#include <Arduino.h>

ValidateButton::ValidateButton(int buttonPin, int greenLedPin, int redLedPin, void (*onBtnClickedCb)()) 
  : buttonPin(buttonPin), greenLedPin(greenLedPin), redLedPin(redLedPin), 
  currentBtnState(LOW), previousBtnState(LOW), onBtnClickedCb(onBtnClickedCb) {}

void ValidateButton::init() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void ValidateButton::setOnBtnClickedCb(void (*cb)()) {
  onBtnClickedCb = cb;
}

void ValidateButton::blinkLed(bool isGreen) {
  int blinkCount = 5;
  int blinkDelay = 175;
  int ledPin = isGreen ? greenLedPin : redLedPin;

  for (int i = 0; i < blinkCount; ++i) {
    digitalWrite(ledPin, HIGH); 
    delay(blinkDelay); 
    digitalWrite(ledPin, LOW); 
    delay(blinkDelay); 
  }

  delay(1000);
}

void ValidateButton::read() {
  currentBtnState = digitalRead(buttonPin);

  if (previousBtnState != currentBtnState && currentBtnState == LOW) {
    onBtnClickedCb();
  }

  previousBtnState = currentBtnState;
}