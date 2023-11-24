#include <Arduino.h>

int myFunction(int, int);

const int buttonPin = 2;
const int ledPin = 12;

const int baudRate = 9600;

int buttonState;

void setup() {
  Serial.begin(baudRate);

  // int result = myFunction(2, 3);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // buttonState = digitalRead(buttonPin);

  // Serial.println(buttonState);

  // if (buttonState == HIGH) {
  //   digitalWrite(ledPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  // } else {
  //   digitalWrite(ledPin, LOW);   // turn the LED off by making the voltage LOW
  // }

  digitalWrite(ledPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(ledPin, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);
}

int myFunction(int x, int y) {
  return x + y;
}