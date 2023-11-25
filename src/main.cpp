#include <Arduino.h>
#include <Constants.h>
#include <ButtonLedPair/ButtonLedPair.h>

ButtonLedPair buttonLedPair[nbOfButtons] = {
  ButtonLedPair(2, 8),
  ButtonLedPair(3, 9),
  ButtonLedPair(4, 10),
  ButtonLedPair(5, 11),
  ButtonLedPair(6, 12),
};

void setup() {
  Serial.begin(baudRate);
  
  for (int i = 0; i < nbOfButtons; ++i) {
    buttonLedPair[i].init();
  }
}

void loop() {
  for (int i = 0; i < nbOfButtons; ++i) {
    buttonLedPair[i].listen();
  }
}