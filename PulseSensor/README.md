# Pulse Sensor (icstation.com)

This example is a basic demonstration of how to use a low-level pulse sensor,
based on a chip that was bought from icstation.com. It seems to be a clone
of the [pulse sensor open hardware project](https://pulsesensor.com/pages/open-hardware).
The code doesn't do processing of the sensor data to calculate the heart rate.

The sensor is connected to an analog input port and the value is read and printed to the serial output.

Connect to 3V, GND and analog input port (e.g., port $25$). Configure the
pin for input in `setup()`. Make sure you set up the serial port speed
both in `platformio.ini` and in the `Serial.begin()` command in `setup()`. Use
`analogRead()` to get the value from the sensor.

## Wiring

![Photo of the \"Pulse Sensor\"
example.](./media/wiring-pulse-sensor-1.jpeg)

![Photo of the \"Pulse Sensor\"
example.](./media/wiring-pulse-sensor-2.jpeg)

## Code

Refer to the [src/main.cpp](src/main.cpp) file for the source code.
The code is in this case only reading the analog value from the sensor and
printing it to the serial output. It doesn't do any further processing.

## Sample output

![Output of the pulse sensor on the serial
output.](./media/pulse-sensor-output.png)
