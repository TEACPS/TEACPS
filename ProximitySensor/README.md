# Proximity Sensor

The simple proximity sensor is a digital sensor that can detect objects
in front of it. It is a low-cost sensor that can be used in various
applications. The sensor is connected to the ESP32 microcontroller, and
the sensor output is read using the `digitalRead()` function.

## Hardware and Project Setup

Connect red cable to USB pin for $5V$ instead of $3V$ pin for VCC. This
gives you more for this specific sensor. Again, use pin $25$ for the OUT port.
Use `digitalRead()` for the connected PIN to get the value.
It will either return `0` / `1` for `LOW` / `HIGH`,
depending on the proximity of an object in front of the sensor. You can
configure the proximity using a screw on the board.

## Wiring

![Wiring and board for the ESP32 connected to a proximity
sensor.](./media/wiring-proximity.jpeg)

![Wiring and board for the ESP32 connected to a proximity sensor, with a
finger on the proximity sensor to trigger
it.](./media/wiring-proximity-finger.jpeg)

## Code

The full code is in the following file: [./src/main.cpp](./src/main.cpp).
It reads and prints the proximity sensor value to the serial monitor.

## Sample output

![Sample output of the proximity
sensor.](./media/sample-output-proximity.png)
