#include <ButtonLedPair/ButtonLedPair.h>
#include <Arduino.h>

ButtonLedPair::ButtonLedPair(int buttonPin, int ledPin) 
  : buttonPin(buttonPin), ledPin(ledPin), isPressed(false) {}

void ButtonLedPair::init() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void ButtonLedPair::listen() {
  isPressed = digitalRead(buttonPin) == HIGH;

  if (isPressed) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}