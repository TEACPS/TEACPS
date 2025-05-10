# Hall-Effect Sensor (ESP32 Internal)

Use a magnet to detect proximity (the sensor measures the magnitude of a magnetic
field). The ESP32 has an integrated hall effect sensor that can be used without any additional wiring.


## Code

The full code is in the following file: [./src/main.cpp](./src/main.cpp).
It uses the `hallRead()` command to get a value from the sensor.

## Sample output

When a magnet is close to the chip you can see the values increasing or decreasing depending on the polarity of the magnet.