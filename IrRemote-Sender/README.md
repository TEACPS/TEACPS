# Infrared Remote - Sender

Typical remote controls based on IR emitting LEDs (like they are used for TVs) are using pulsed light codes to send commands. This is part 2 of the Ir Receiver/Sender tutorial, the first part on receiving can be found [here](../IrRemote-Receiver/)
Using the [Arduino-IRRemote library](https://github.com/Arduino-IRremote/Arduino-IRremote) and a [IR-LED sender module (KY-005)](https://sensorkit.joy-it.net/en/sensors/ky-005) and [IR photodiode receiver module (KY-022)](https://sensorkit.joy-it.net/en/sensors/ky-022) we can easily use the remotes for our purposes, or remote control devices that are usually meant to be control from a handheld remote from our microcontroller.

In this example we'll explore how to use the sender.

## Technical background
TODO

# Setup

## IR Transmitter
The IR transmitter module ([KY-005](https://sensorkit.joy-it.net/en/sensors/ky-005)) consists simply of an IR LED. 

We just need to connect GND (the pin marked with `-`), and the signal output pin (marked as `S` - see below for details which pin you need to hook up on your board). The middle pin can also be connected to GND (it is separated from the signal pin with a 10k resistor).

> **Note**: The module we have available does not have a current limiting resistor. Directly hooking up the LED to the output pin and GND without the resistor is usually bad practice. However, due to the nature of the IR sendcodes, that only turn on the LED for very short pulses we can get away without one. Furthermore IR LEDs usually need much more current than the ESP32 outputpins can provide. For real world setups it is usually a better idea to use a transistor and a current limiting resistor [as described here](https://github.com/crankyoldgit/IRremoteESP8266/wiki#ir-sending). 

# Code
Import the [IRRemote library from the PlatformIO registry](https://registry.platformio.org/libraries/z3t0/IRremote) or directly from [Github](https://github.com/Arduino-IRremote/Arduino-IRremote). 



Congratulations, you can now use almost any IR remote to control your setup!
