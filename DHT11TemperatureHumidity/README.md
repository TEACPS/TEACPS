# DHT11 Temperature and Humidity

The DHT11 is a low-cost digital temperature and humidity sensor. It uses a
capacitive humidity sensor and a thermistor to measure the surrounding air and
spits out a digital signal on the data pin (no analog input pins needed).

## Hardware and Project Setup

Connect 3V, GND and digital input (port 25 is OK). Go to PlatformIO
Home 🡪 install the [DHT sensor library by Adafruit](https://registry.platformio.org/libraries/adafruit/DHT%20sensor%20library) and the [Adafruit Unified Sensor](https://registry.platformio.org/libraries/adafruit/Adafruit%20Unified%20Sensor) libraries into the project.

No 10k Ohm pull-up resistor is needed for our mounted sensor. If you
look closely, you will see that it already has an operation LED as well
as two resistors on-board (for pull-up as well as the LED).

## Code

Copy the *"DHTtester"* example code from the *"DHT sensor library"* page of PIO
home. Modify the PIN configuration to the port you use (e.g., 25).
Un-comment the `#define` for `DHT11` (and comment `DHT22`). Also add the Arduino
library at the top, which is needed as we are working through Platform
IO and not the Arduino IDE:

```c++
#include "Arduino.h"
```

The full code is in the following file: [./src/main.cpp](./src/main.cpp).

## Wiring

![Board and wiring of the ESP32 connected to a DHT11
sensor.](./media/DHT11-wiring-1.jpeg)

![Board and wiring of the ESP32 connected to a DHT11
sensor.](./media/DHT11-wiring-2.jpeg)

## Sample output

![Sample output of the DHT11
sensor.](./media/dht11-sample-output.png)

## Tutorials

- <https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-sensor-arduino-ide/>
- <https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-web-server-arduino-ide/>
