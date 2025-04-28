# Serial Output

**Example:** *SerialOutput*

LEDs (especially the internal one) can be used to show some status
information. However, you often need to output more details to see raw
data or to debug the code. This is what the serial monitor is for. In
this example, we will use the internal LED again and output its status
to the serial monitor.

In `setup()`, start the serial output and specify the speed. Use `9600` for
now. In the `loop()` function, you can then use `Serial.print()` or
`Serial.println()` to print to the serial monitor. The difference is that
the function with `ln` at the end (short for *line*) also inserts a new
line after printing the contents you send via the parameter.

```c++
#include <Arduino.h>

int ledOn = LOW;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  ledOn = (ledOn == LOW) ? HIGH : LOW;
  digitalWrite(LED_BUILTIN, ledOn);
  Serial.print("LED status: ");
  Serial.println(ledOn);
  delay(500);
}
```

Also note that we now store the status of the LED in an extra variable
called `ledOn`, which is defined at the beginning of the program. This
makes it a global variable, which means it can be accessed from all
functions. The `ledOn` variable is toggled between `HIGH` and `LOW` in
each loop iteration. The `?` operator is a shorthand for an `if` statement.

Compile and run the program. Once this is finished, open the serial
monitor from the blue bar at the bottom. You should see that status
output in the terminal window.

![Serial output view in PlatformIO on Visual Studio
Code](./media/serial-output-platform-io.png)

Note that the `Serial.print()`-functions can print both strings and
numbers. However, simply concatenating a string with a number does not
automatically convert the number to readable text. The easiest solution
is to use two separate `print()` statements like shown in this example. To
stop the terminal output, press *Ctrl+C*.

In case you get the following error message:

`could not open port \'COM4\': could not open port \'COM4\':
PermissionError(13, \'Access is denied.\', None, 5)`

This means that the port is already in use by another terminal that was
not closed. Try closing all terminal windows and reconnecting the USB
cable.

![Closing a terminal instance in Visual Studio
Code.](./media/close-terminal-instance-vs-code.png)

The speed of `9600` is measured in baud. This value is rather slow, and if
you are transmitting a lot of information, it would not be able to keep
up. A common speed to use is `115200`. Change the configuration in
`Serial.begin(115200)`. However, when you run the example again, the
output will be garbled like this:

![Garbage shown in the serial console when the transmission speed isn\'t
configured correctly.](./media/serial-output-wrong-transmission-speed.png)

To solve this, you also need to configure the serial monitor. Open PIO
Home, go to the project and choose "Configure" for the *SerialOutput*
project:

![Finding the project configuration in the projects view of PlatformIO
in Visual Studio Code.](./media/platform-io-project-configuration.png)

You will see the current configuration of your project, which is a
visual interface to the `platformio.ini` file.

![Changing the connection speed through the visual interface of
PlatformIO, which will integrate it into the platformio.ini
file.](./media/platform-io-monitor-speed.png)

In the *"New Option"* segment, search for speed and choose the
*"monitor_speed"*. In the new option that appears at the bottom, enter the
same speed value you used in the code (`115200`). Do not forget to click
the blue save button at the top.

![Entering a monitor_speed of 115200 in the project configuration of
PlatformIO.](./media/platform-io-setting-monitor-speed.png)

Restart the program, open the serial monitor again and you should see
the outputs once again. Instead of using the Platform IO configuration
UI, you can also directly configure the speed and other parameters in
the `platformio.ini` file in the main directory of your project. It should
now contain the `monitor_speed` setting.

```json
[env:lolin_d32]
platform = espressif32
board = lolin_d32
framework = arduino
monitor_speed = 115200
```
