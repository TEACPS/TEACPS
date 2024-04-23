#include <Arduino.h>

const int pin_ldr = 25;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  int ldr_val = analogRead(pin_ldr);
  Serial.print("LDR raw value: ");
  Serial.println(ldr_val);
  delay(100);
}