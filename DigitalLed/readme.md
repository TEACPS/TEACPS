# LED on Digital Out

**Example:** *DigitalLed*

Disconnect the board from power. Create new project from PIO Home:
*DigitalLed*.

You can use almost the same circuit as before. Instead of connecting the
LED to th 3V port, change the wiring to Port 18.

![Circuit design of the \"LED on Digital Out\" example, triggering an
external LED through code on an
ESP32.](./media/digital-led-circuit.svg)

Next, reconfigure the code to use Port 18 and run the project again.
Make sure to switch the active project in the blue bar at the bottom of
Visual Studio Code.

![Switching an active project on
PlatformIO.](./media/platformio-active-project.png)

Now add a global config variable defined at the beginning of the script
to set the port only once (type int).

```c++
#include <Arduino.h>

int pin_led = 18;

void setup()
{
  // put your setup code here, to run once:
  pinMode(pin_led, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(pin_led, HIGH);
  delay(300);
  digitalWrite(pin_led, LOW);
  delay(300);
}
```
