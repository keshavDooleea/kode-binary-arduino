#include <Arduino.h>
#include <Constants.h>
#include <Button/Button.h>

Button bitsButtons[nbOfButtons] = {
  Button(Pins::B_16),
  Button(Pins::B_8),
  Button(Pins::B_4),
  Button(Pins::B_2),
  Button(Pins::B_1),
};

void setup() {
  Serial.begin(baudRate);
  pinMode(Pins::LED_YELLOW, OUTPUT);

  for (int i = 0; i < nbOfButtons; ++i) {
    bitsButtons[i].init();
  }
}

void loop() {
  for (int i = 0; i < nbOfButtons; ++i) {
    bitsButtons[i].addPressListener();
  }
}