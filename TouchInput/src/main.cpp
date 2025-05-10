#include <Arduino.h>

int pin_led = 25;
int pin_touch = 27;

void setup()
{
  pinMode(pin_led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  uint16_t touch_status = touchRead(pin_touch);

  Serial.print(">Touchstatus:");
  Serial.println(touch_status);

  digitalWrite(pin_led, touch_status < 40 ? HIGH : LOW);
  delay(10);
}