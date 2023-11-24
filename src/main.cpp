#include <Arduino.h>

int myFunction(int, int);

const int buttonPin = 2;
const int ledPin = 8;

const int baudRate = 9600;

void setup() {
  Serial.begin(baudRate);

  // int result = myFunction(2, 3);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  delay(50);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  } else {
    digitalWrite(ledPin, LOW);   // turn the LED off by making the voltage LOW
  }
}

int myFunction(int x, int y) {
  return x + y;
}