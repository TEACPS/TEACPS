#include <Arduino.h>

const int pin_proximity = 25;

void setup()
{
  Serial.begin(115200);
  pinMode(pin_proximity, INPUT);
}

void loop()
{
  int proximityVal = digitalRead(pin_proximity);
  Serial.print("proximity value: ");
  Serial.println(proximityVal);
  delay(100);
}