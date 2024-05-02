# Microphone

The microphone sensor (**KY-038**) provides both an analog and digital output. You can
use the digital output to simply detect if the volume exceeds a
threshold (which you can modify using the screw on the blue box, the
onboard LED2 indicates if the volume is above the current threshold).

For the first test, use GND and 3V (VCC) pins, and connect `AO` to pin 25.
Directly read and print the analog reading through the serial port. If
you read quickly enough, you can plot all the recorded values and should
be able to get a familiar waveform-looking output.

## Wiring

![Wiring of the microphone connected to an
ESP32.](./media/wiring-microphone.jpeg)

## Code

The full code is in the following file: [./src/main.cpp](./src/main.cpp).

## Sample output

![Sample output of the microphone connected to an
ESP32.](./media/output-microphone.png)

## Tutorial

- <https://diyi0t.com/sound-sensor-arduino-esp8266-esp32/>
