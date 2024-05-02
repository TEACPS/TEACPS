# Sparkfun Pulse Oximeter and Heart Rate Monitor (I^2^C)

The board is explained in detail here:\
<https://learn.sparkfun.com/tutorials/sparkfun-pulse-oximeter-and-heart-rate-monitor-hookup-guide/all>

The board is a combination of a MAX30101 sensor and a MAX32664
microcontroller. The sensor measures the heart rate and the oxygen
saturation of the blood. The microcontroller processes the data and
provides it via I^2^C. The board is powered by 3.3V and consumes about
10mA.

The board uses the I^2^C communication protocol to transmit its data,
which would also allow chaining several sensors together. A *Qwiic*
cable allows easy connection of power supply and the two required wires.

## Wiring

However, you might not have a *Qwiic* cable, and the *LOLIN D32 ESP32* board
does not have a connector. But that does not matter, we can still
connect the board, as the ESP32 platform supports I^2^C.

Use the following wiring (Pulse Oximeter board 🡪 ESP32):

- GND 🡪 GND
- 3V3 🡪 3V
- SDA 🡪 21
- SCL 🡪 22
- RST 🡪 4 (reset)
- MFIO 🡪 5 (required for configuring the board; our standard cables do
    not connect too well, but simply place the cable in the hole and
    check that it touches the contact of the board. Contact between the
    cable and the board is mainly needed while the board is being
    initialized)

The SDA (21) and SCL (22) ports for I^2^C are the default pins used
through `Wire.h`; see
<https://randomnerdtutorials.com/esp32-i2c-communication-arduino-ide/> .
Pins 4 and 5 are used by the Arduino examples and can also be easily
reconfigured if needed.

## Code

Next, install the *"SparkFun Bio Sensor Hub Library"* library. Copy the
"Example1_config_BPM_Mode1" code into `main.cpp`. Note that the example
uses a serial port speed of `115200`, so configure your `platform.ini` file
accordingly.

The code is a bit more complex than the previous examples, as it uses
the SparkFun library to communicate with the sensor. The library
initializes the sensor and reads the data. The data is then printed to
the serial port.

The sensor is configured to measure the heart rate and the oxygen
saturation of the blood. The sensor is then read four times per second,
and the data is printed to the serial port.

## Photos

![Wiring of the \"Sparkfun Pulse Oximeter and Heart Rate Monitor\"
example.](./media/wiring-sparkfun-pulse-oximeter-1.jpeg)

![Wiring of the \"Sparkfun Pulse Oximeter and Heart Rate Monitor\"
example.](./media/wiring-sparkfun-pulse-oximeter-2.jpeg)

Sample output:

![Output of the SparkFun Pulse
Oximeter.](./media/output-sparkfun-pulse-oximeter.png)
