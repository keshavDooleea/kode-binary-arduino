#include <ButtonLed/ButtonLed.h>
#include <Arduino.h>

ButtonLed::ButtonLed(int byte, int buttonPin, int ledPin, void (*onBtnClickedCb)(int byte, bool isPressed)) 
  : byte(byte), buttonPin(buttonPin), ledPin(ledPin),
  ledState(LOW), currentBtnState(LOW), previousBtnState(LOW), 
  onBtnClickedCb(onBtnClickedCb) {}

void ButtonLed::init() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void ButtonLed::handleLed(int volt) {
  ledState = volt;
  digitalWrite(ledPin, ledState);
}

void ButtonLed::turnOffLed() {
  handleLed(LOW);
}

void ButtonLed::setOnBtnClickedCb(void (*cb)(int byte, bool isPressed)) {
  onBtnClickedCb = cb;
}

void ButtonLed::read() {
  currentBtnState = digitalRead(buttonPin);

  if (previousBtnState != currentBtnState && currentBtnState == LOW) {
    handleLed(ledState == HIGH ? LOW : HIGH);
    onBtnClickedCb(byte, ledState);
  }

  previousBtnState = currentBtnState;
}