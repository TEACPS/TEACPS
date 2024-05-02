#include <Arduino.h>

const int pin_microphone = 25;

void setup()
{
  Serial.begin(115200);
  pinMode(pin_microphone, INPUT);
}

void loop()
{
  int microphoneVal = analogRead(pin_microphone);
  Serial.print("Microphone value: ");
  Serial.println(microphoneVal);
  delay(100);
}