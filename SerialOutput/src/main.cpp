#include <Arduino.h>

int ledOn = LOW;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  ledOn = (ledOn == LOW) ? HIGH : LOW;
  digitalWrite(LED_BUILTIN, ledOn);
  Serial.print("LED status: ");
  Serial.println(ledOn);
  delay(500);
}