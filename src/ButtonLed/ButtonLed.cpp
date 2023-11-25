#include <ButtonLed/ButtonLed.h>
#include <Arduino.h>

ButtonLed::ButtonLed(int buttonPin, int ledPin) 
  : buttonPin(buttonPin), ledPin(ledPin), isPressed(false) {}

void ButtonLed::init() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void ButtonLed::listen() {
  isPressed = digitalRead(buttonPin) == HIGH;

  if (isPressed) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}