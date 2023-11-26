#include <ButtonLed/ButtonLed.h>

ButtonLed::ButtonLed(int byte, int buttonPin, int ledPin, void (*onBtnClickedCb)(int byte, bool isPressed)) 
  : AbsButton(buttonPin), _byte(byte), _ledPin(ledPin), _ledState(LOW), onBtnClickedCb(onBtnClickedCb) {}

void ButtonLed::init() {
  AbsButton::init();
  pinMode(_ledPin, OUTPUT);
}

void ButtonLed::handleLed(int volt) {
  _ledState = volt;
  digitalWrite(_ledPin, _ledState);
}

void ButtonLed::turnOffLed() {
  handleLed(LOW);
}

void ButtonLed::setOnBtnClickedCb(void (*cb)(int byte, bool isPressed)) {
  onBtnClickedCb = cb;
}

void ButtonLed::onClick() {
  handleLed(_ledState == HIGH ? LOW : HIGH);
  onBtnClickedCb(_byte, _ledState);
}