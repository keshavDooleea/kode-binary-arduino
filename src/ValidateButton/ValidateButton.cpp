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

void ValidateButton::read() {
  currentBtnState = digitalRead(buttonPin);

  if (previousBtnState != currentBtnState && currentBtnState == LOW) {
    onBtnClickedCb();
  }

  previousBtnState = currentBtnState;
}