#include <Arduino.h>

int pin_led = 25;
int pwm_channel = 0;

void setup()
{
  // Assign LED pin to PWM channel 0
  ledcAttachPin(pin_led, pwm_channel);
  // Configure PWM channel
  // channel 0-15, frequency, resolution (bits)
  // Here: channel 0, 4kHz, 8 bit resolution
  ledcSetup(pwm_channel, 4000, 8);
}

void loop()
{
  // put your main code here, to run repeatedly:
  for (int i = 255; i >= 0; i--)
  {
    ledcWrite(pwm_channel, i);
    delay(5);
  }
}