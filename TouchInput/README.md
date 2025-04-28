# Touch Input

**Example:** *TouchInput*

Instead of the program automatically running, we now want to influence
the program. The ESP32 platform provides several PINs that have a touch
input functionality. This corresponds to a capacitive sensing – you
simply connect a cable to the PIN and can then determine if you touch it
with your finger or not.

Refer to the pinout reference at the beginning of this document. Touch
sensor $7$ is for example corresponding to GPIO 27 (= PIN 27).

Create a circuit where you can control the status of a LED by touching
the cable on PIN 27.

![Circuit design of the \"Touch Input\" example, which triggers a LED
when touching a cable.](./media/circuit-touch-input.svg)

You can then read the current value using the `touchRead(pin)` function.
Print out the value to the serial port and switch on / off the external
LED based on if the value is below a certain threshold (= if you're
touching the cable or not). Look at the values when you touch the cable
or not to determine a suitable threshold for your setup.

```c++
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
  Serial.print("Touch status: ");
  Serial.println(touch_status);
  digitalWrite(pin_led, touch_status < 40 ? HIGH : LOW);
  delay(10);
}
```

Of course, touching a cable is probably not a good user interface. But
it is easy to build a simple touch-sensitive surface. Attach for example
a piece of aluminum to the cable and run the example again. You will
likely need to change the threshold values. See this page for more
details: <https://randomnerdtutorials.com/esp32-touch-pins-arduino-ide/>

**Exercise:** if you look closely, you will notice that the more you
touch the cable, the lower the value gets. Try to dim the LED depending
on the touch intensity instead of switching it completely on / off.