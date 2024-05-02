# TEACPS – Tangible user interfaces, Electronics, Actors, Components, Physical computing, Sensors

This repository contains examples of courses related to tangible user interfaces, electronics, and physical computing at the St. Pölten University of Applied Sciences in Austria.

## ESP32 / Arduino Labs

The following code examples are based on the [ESP32 microcontroller](https://www.espressif.com/en/products/socs/esp32) and the [Arduino framework](https://www.arduino.cc/). They are written in C++ and can be used with the [PlatformIO IDE](https://platformio.org/) for [Visual Studio Code](https://code.visualstudio.com/).

The examples are structured in a way that they can be used in a lab setting. Each example contains a `README.md` file that explains the setup and the code. The examples are designed to be used in a linear fashion, starting with the `ESP32Setup` example.

- [ESP32Setup](ESP32Setup/README.md) – Setting up the ESP32 with PlatformIO for Visual Studio Code
- [BlinkLed](BlinkLed/README.md) – Blinking onboard LED
- [SimpleLed](SimpleLed/README.md) – Lighting up an external LED
- [DigitalLed](DigitalLed/README.md) – Digitally controlled external LED
- [LedFadeDac](LedFadeDac/README.md) – Fading an external LED using the digital/analog converter
- [LedFadePwm](LedFadePwm/README.md) – Fading an external LED using pulse width modulation
- [SerialOutput](SerialOutput/README.md) – Outputting data to the serial monitor
- [TouchInput](TouchInput/README.md) – Touch input using capacitive sensing
- [LDR](LDR/README.md) – Reading the brightness using a light-dependent resistor
- [ESPWebServer](EspWebServer/README.md) – Setting up a web server on the ESP32
- [ESP32WebSockets](ESP32-WebSockets/README.md) – Transmitting LDR measurements from an ESP32 to a web socket client

## Sensor Labs

These additional examples are more high-level and focus on specific sensors. They are also based on the ESP32 microcontroller and the Arduino framework.

- [PulseOximeterAndHeartRateSensor](PulseOximeterAndHeartRateSensor/README.md) – Reading pulse oximeter and heart rate data from a MAX30102 sensor

## License

This repository is licensed under the GPLv3 license. See [LICENSE](LICENSE) for details.
