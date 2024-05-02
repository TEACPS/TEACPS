# Hall-Effect Sensor A3144

Use a magnet to detect proximity (the sensor measures the magnitude of a magnetic
field). This sensor has both analog (AO) and digital (DO) pins. The digital pin is not used in this example. The analog pin is connected to the ESP32 to read the analog value.

Use the GND and 3V (VCC) pins from ESP32. Connect the data to Pin 25 and `AO` for reading the
analog value through `analogRead()`. But even if using analog values, the
physical distance range for getting values between $0 .. 4095$ is tiny.

## Wiring

![Wiring of the ESP32 with a Hall-Effect Sensor
connected.](./media/wiring-hall-effect.jpeg)

![Wiring of the hall-effect sensor connected to an ESP32
board.](./media/wiring-hall-effect-2.jpeg)

![Moving a magnet towards the hall-effect sensor connected to an
ESP32.](./media/magnet-hall-effect.jpeg)

## Code

The full code is in the following file: [./src/main.cpp](./src/main.cpp).
It reads the analog value from the Hall-Effect sensor and prints it to the serial monitor.

## Sample output

![Sample output of the hall effect
sensor.](./media/output-hall-effect.png)