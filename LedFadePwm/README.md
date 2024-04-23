# (More or less) Analog Output

**Example:** *LedFadePwm*

The ESP32 only has two analog outputs; many simpler boards like the
standard Arduino do not have such a port at all. Instead, it is common
to use *Pulse Width Modulation* (PWM) instead – this generates a square
wave, essentially switching off and on a specific pin rapidly – far
quicker than our eyes can see.

![Pulse Width Modulation. Image by Arduino,
https://docs.arduino.cc/learn/microcontrollers/analog-output/](./media/pwm.gif)

The ESP32 can generate PWM modulations on several channels, and you can
then assign such a channel to one or more pins. You can also choose the
resolution of the PWM signal, from 1 bit to 16 bits – this controls how
many intermediate values you have between always-off and always-on.

You can keep the same circuit configuration from the [previous example](../LedFadeDac/README.md),
with the LED attached to pin 25. The following code fades from on to off
with a quicker speed (lower delay) than before:

```c++
#include <Arduino.h>

int pin_led = 25;
int pwm_channel = 0;

void setup()
{
  // Assign LED pin to PWM channel 0
  ledcAttachPin(pin_led, pwm_channel);

  // Configure PWM channel
  // channel 0-15, frequency, resolution (bits)
  // Here: channel 0, 4kHz, 8 bit resolution (allows 0 .. 255)
  ledcSetup(pwm_channel, 4000, 8);
}

void loop()
{
  // put your main code here, to run repeatedly:
  for (int i = 255; i \>= 0; i\--)
  {
    ledcWrite(pwm_channel, i);
    delay(5);
  }
}
```

Next, try using the same PWM channel for two LEDs attached to two
different PINs. See this tutorial for reference:
<https://randomnerdtutorials.com/esp32-pwm-arduino-ide/>
