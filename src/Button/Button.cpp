#include <Button/Button.h>
#include <Arduino.h>
#include <Constants.h>

Button::Button(Pins pin) : buttonPin(pin) {
    Button::init();
}

void Button::init() {
  pinMode(buttonPin, INPUT_PULLUP);
}

void Button::addPressListener() {
  if (isPressed()) {
    digitalWrite(Pins::LED_YELLOW, HIGH);
  } else {
    digitalWrite(Pins::LED_YELLOW, LOW);
  }
}

bool Button::isPressed() {
    return digitalRead(buttonPin) == HIGH;
}
