#include <Arduino.h>
#include <Constants.h>
#include <ButtonLed/ButtonLed.h>

ButtonLed buttonLeds[nbOfButtons] = {
  ButtonLed(2, 8),
  ButtonLed(3, 9),
  ButtonLed(4, 10),
  ButtonLed(5, 11),
  ButtonLed(6, 12),
};

void setup() {
  Serial.begin(baudRate);
  
  for (int i = 0; i < nbOfButtons; ++i) {
    buttonLeds[i].init();
  }
}

void loop() {
  for (int i = 0; i < nbOfButtons; ++i) {
    buttonLeds[i].listen();
  }
}