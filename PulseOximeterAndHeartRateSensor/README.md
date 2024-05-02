# Pulse Oximeter and Heart Rate Sensor (MAX30102)

The [MAX30102 sensor](https://www.maximintegrated.com/en/products/interface/sensor-interface/MAX30102.html) is an integrated pulse oximetry and heart rate
monitor module. It features both a red and infrared LED, a temperature
sensor and comes with a ready-made library that makes working with the
data easier.

To set up the module with our ESP32 board, follow this guide. You can
then also run through the other examples presented here:
<https://lastminuteengineers.com/max30102-pulse-oximeter-heart-rate-sensor-arduino-tutorial/>

## Setting up the Project

First, create a new project for the ESP32 board. Change the monitor
speed to `115200`. Next, search for *max30\** in the libraries section of
PIO Home and add the *"SparkFun MAX3010x Pulse and Proximity Sensor
Library"* to the project.

![Installing the SparkFun Pulse and Proximity Sensor Library in the
PlatformIO libraries
view.](./media/sparkfun-max3010x.png)

Ultimately, your `platform.ini` file should look like this:

```json
[env:lolin_d32]
platform = espressif32
board = lolin_d32
framework = arduino
monitor_speed = 115200
lib_deps = sparkfun/SparkFun MAX3010x Pulse and Proximity Sensor
Library@^1.1.2
```

## I2C

Connect the external sensor to `GND` and the `3V` connector. The data
transfer follows the I^2^C (Inter-Integrated Circuit) standard, which
allows chaining sensors together and requires only two cables. These
are: `SDA` plus a separate clock (`SCL`).

Some ESP32-boards like the LOLIN D32 Pro have a specific connector for
*Qwiic* cables that have these two ports plus the power supply. However,
this sensor doesn't have the connector soldered to it.

Which ports can you use? For the LOLIN D32 (Pro), the defaults are:

- **SDA** = 21
- **SCL** = 22

You can easily find out which ports are the default for your board. If
your project is already configured correctly, simply type `SDA` in your
code; it's a const value set by the libraries included through
`Arduino.h`. If you check the context information through Visual
Studio Code (or ctrl+click or F11), you will see the GPIO definition
from `d32_core.h`.

![Using Syntax Completion for checking the port used on your ESP32
board.](./media/esp32-sda-port-definition.png)

In case you use the default GPIOs to connect, you don't need to
configure anything. The Arduino library implementation for the ESP32
supports the I2C protocol through the pre-installed *"Arduino Wire
Library"*. You can read more about it here:
<https://docs.espressif.com/projects/arduino-esp32/en/latest/api/i2c.html>

*Optional:* In case you want to use other GPIOs, you can configure the
Wire library accordingly at the beginning of `setup()`:

```c++
Wire.setPins(21, 22); // SDA, SCL
```

## Circuit Design

According to these PINs and the labels printed on the bottom of the
module, connect the sensor accordingly. Make sure you connect the cables
to the right side of the board, as the connectors at the top and bottom
are different. Use the side with the `SDA` & `SCL` labels.

![Circuit design of the \"MAX30102 Pulse Oximeter and Heart Rate
Sensor\" example.](./media/circuit-MAX30102.svg)

A photo of the same setup:

![Photo of the ESP32 connected to the MAX30102
sensor.](./media/esp32-MAX30102-setup.jpeg)

## Code

Once everything is set up, use the example code from:
<https://lastminuteengineers.com/max30102-pulse-oximeter-heart-rate-sensor-arduino-tutorial/>\
or: <https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library>

For reference, the code of the basic example:

```c++
#include <Arduino.h>
#include <Wire.h>
#include "MAX30105.h"

// Based on:
// https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library
// https://lastminuteengineers.com/max30102-pulse-oximeter-heart-rate-sensor-arduino-tutorial/

MAX30105 particleSensor;

void setup()
{
  Serial.begin(115200);

  // Initialize sensor
  if (particleSensor.begin() == false)
  {
    Serial.println("MAX30102 was not found. Please check wiring/power.");
    while (1)
      ;
  }

  particleSensor.setup(); // Configure sensor. Use 6.4mA for LED drive
}

void loop()
{
  // Better readable output for console
  Serial.print(" R[");
  Serial.print(particleSensor.getRed());
  Serial.print("] IR[");
  Serial.print(particleSensor.getIR());
  Serial.println("]");
}
```

This prints out the raw values of the red and IR measurements. You can
clearly see a difference if a finger is present on the sensor or not.

This is a sample of when a finger is placed on the MAX30102:

![Output of the MAX30102
sensor.](./media/MAX30102-output.png)

## Visualizing the Results

To better visualize the values, you have multiple options.
Unfortunately, [PlatformIO](https://platformio.org/) doesn't have plotting capabilities includes
yet. One possible option is the Arduino Serial Plotter, another is
building a custom [VVVV](https://visualprogramming.net/) patch.

Most plotting tools expect a very simple output: a list of
comma-separated values in each line. It's easy to rewrite our output to
match that. In the `loop()` function, replace the previous code with:

```c++
  // For Arduino Serial Plotter
  Serial.print(particleSensor.getRed());
  Serial.print(", ");
  Serial.println(particleSensor.getIR());
```

### Arduino IDE

To visualize this output with the Arduino Serial Plotter, download and
install the Arduino IDE 2.0+: <https://www.arduino.cc/en/software>

To enable ESP32 deployments from the IDE, you can add the platform to
the board manager. Go to *File -\> Preferences*. Next, click on the symbol
next to the *"Additional boards manager URLs"*.

![Using the Arduino IDE for ESP32
development.](./media/arduino-ide-additional-boards-manager-urls.png)

In the following dialog, click on the link to open a web site containing
a list of possible 3^rd^ party board manager URLs. In the long list,
search for *"Espressif ESP32"*. Copy the URL into the Arduino IDE
interface:
<https://espressif.github.io/arduino-esp32/package_esp32_index.json>

![Unofficially supported boards in the Arduino
IDE.](./media/arduino-ide-unofficially-supported-boards.png)

Next, restart the IDE. In the boards manager, you can now install *"esp32
by Espressif Systems"*:

![Installing ESP32 support within the Arduino
IDE.](./media/arduino-ide-install-esp32-board-support.png)

Make sure that Visual Studio Code isn't currently having a serial
monitor session open; if yes, stop it using Ctrl-C.

Now, you can choose the board in the Arduino IDE from *Tools -\> Board -\> esp32 -\> WEMOS
LOLIN32*. Next, also configure the Port through *Tools -\> Port*.

Everything is in place to start the plotter through *Tools -\> Serial
Plotter*. In the interface, you also need to update the baud rate to the
rate we've set for the serial out (`115200` baud). You should see a nice
auto-scaling plot of the real-time values our ESP32 sends through the
serial output. The following screenshot was generated by repeatedly
tapping the sensor:

![Graphical user interface Description automatically generated with low
confidence](./media/MAX30102-arduino-ide-visualization.png)

### Alternatives: VVVV and teleplot

Alternatively, you can execute the *VVVV* based visualization tool
*ReceiveSerialAndMakeGraph* by Matthias Husinsky (Windows only). Simply
select the COM-port and you should be ready to go.

![Visualization of the sensor data using a simple VVVV
patch.](./media/MAX30102-vvvv-visualization.png)

Another option is the *teleplot* tool. It's a simple
tool that can plot data from the serial port and integrates into PlatformIO.
You can find it here: <https://docs.platformio.org/en/latest/integration/ide/vscode.html#serial-udp-plotter>
