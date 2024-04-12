# Blink Demo for Onboard LED of the ESP32 / Arduino

**Example:** *BlinkLed*

Go to PIO Home and click on *"+ New Project"*:

![Creating a new project in
PlatformIO](./media/blinkled-platformio.png)

In the New Project Wizard, give the project the name *"BlinkLed"*, choose
the *"WEMOS LOLIN D32" (PRO)* board and choose the *"Arduino"*
framework. To keep your projects organized, do not use the default
location, but instead choose a path on your PC to place your project. As
usual, it is best if you don't use special characters in the path --
`C:\\Source\\esp32` would be a good place.

![Project wizard of
PlatformIO.](./media/platformio-project-wizard.png)

The first project creation might take a few minutes, as it needs to
download and compile additional dependencies. Afterwards, it is a good
idea to also save the Visual Studio Code workspace to easily switch
between projects going forward.

Extend the code to look like this:\
*(Note: many Arduino examples don't have the first `#include` line, as the
Arduino IDE adds that automatically if not present. If it's missing in
an example, just add it at the top of the file!)*

```c++
#include <Arduino.h>

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(300);
  digitalWrite(LED_BUILTIN, LOW);
  delay(300);
}
```

Next, use the button in the blue bar at the bottom to compile & upload
the code to the board:

![Uploading and running a project on an ESP32 or Arduino-board through
PlatformIO](./media/upload-platformio.png)

Monitor the compile output in the terminal. After a few seconds, the
upload should be complete, and the board will immediately start to run
your project. The LED will blink.

![Photo of the internal LED of the ESP32
blinking.](./media/esp32-internal-led.jpeg)

Note that the micro controller usually only has the one purpose to run
the program you have uploaded. Therefore, if you disconnect the power
and reconnect it, the LED will immediately start blinking again.
