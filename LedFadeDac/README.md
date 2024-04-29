# Analog Output (DAC)

**Example:** *LedFadeDac*

The ESP32 has two ports that allow Digital-Analog-Conversion (pin 25 &
26). Instead of just switching the port on or off, you can adjust the
voltage it outputs. Among other use cases, this also allows fading the
LED.

In the circuit, almost no changes are necessary. Just use Pin 25
instead.

![Circuit design of the \"Analog Output (DAC)\" example to fade a LED
through an ESP32.](./media/circuit-analog-output-esp32.svg)

The more interesting change is in the code. Create another new project.
In the `loop()` function, you'll now use a small for-loop for fading in
the LED. To set the analog output, use the `dacWrite()` function. Its
first parameter is the port; the additional second parameter now allows
specifying a number giving the percentage in the range of $0 - 255$ (equals $0V$ – $5V$). Use a small delay within the loop so that it is not
too fast, and you can still see the fading process.

```c++
#include <Arduino.h>

int pin_led = 25;

void setup()
{
  // put your setup code here, to run once:
  pinMode(pin_led, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 255; i++)
  {
    dacWrite(pin_led, i);
    delay(10);
  }
}
```
