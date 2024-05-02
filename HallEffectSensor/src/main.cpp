#include <Arduino.h>

const int pin_hall = 25;

void setup()
{
  Serial.begin(115200);
  pinMode(pin_hall, INPUT);
}

void loop()
{
  int hallVal = analogRead(pin_hall);
  Serial.print("Hall effect value: ");
  Serial.println(hallVal);
  delay(100);
}