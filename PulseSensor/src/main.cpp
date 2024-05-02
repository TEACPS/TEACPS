#include <Arduino.h>

const int pin_pulseoxymeter = 25;

void setup()
{
  Serial.begin(115200);
  pinMode(pin_pulseoxymeter, INPUT);
}

void loop()
{
  int pulseoxymeter_val = analogRead(pin_pulseoxymeter);
  Serial.print("PO value: ");
  Serial.println(pulseoxymeter_val);
  delay(100);
}
