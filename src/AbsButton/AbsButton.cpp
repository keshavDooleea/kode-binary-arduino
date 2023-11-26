#include <AbsButton/AbsButton.h>

AbsButton::AbsButton(int buttonPin) : _buttonPin(buttonPin), _currentBtnState(LOW), _previousBtnState(LOW) {}

void AbsButton::init() {
  pinMode(_buttonPin, INPUT_PULLUP);
}

void AbsButton::read() {
  _currentBtnState = digitalRead(_buttonPin);

  if (_previousBtnState != _currentBtnState && _currentBtnState == LOW) {
    onClick();
  }

  _previousBtnState = _currentBtnState;
}