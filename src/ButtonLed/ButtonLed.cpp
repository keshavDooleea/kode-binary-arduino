#include <ButtonLed/ButtonLed.h>
#include <Arduino.h>

ButtonLed::ButtonLed(int byte, int buttonPin, int ledPin, void (*onBtnClickedCb)(int byte, int btnLedPosition)) 
  : byte(byte), buttonPin(buttonPin), ledPin(ledPin),
  ledState(LOW), currentBtnState(LOW), previousBtnState(LOW), 
  onBtnClickedCb(onBtnClickedCb) {}

void ButtonLed::init() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

int ButtonLed::getByte() {
  return byte;
}

void ButtonLed::read(int btnLedPosition) {
  currentBtnState = digitalRead(buttonPin);

  if (previousBtnState != currentBtnState && currentBtnState == LOW) {
    ledState = ledState == HIGH ? LOW : HIGH;
    digitalWrite(ledPin, ledState);
    onBtnClickedCb(byte, btnLedPosition);
  }

  previousBtnState = currentBtnState;
}