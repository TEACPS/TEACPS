#include <Arduino.h>

int pin_led = 18;

void setup()
{
  // put your setup code here, to run once:
  pinMode(pin_led, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(pin_led, HIGH);
  delay(300);
  digitalWrite(pin_led, LOW);
  delay(300);
}