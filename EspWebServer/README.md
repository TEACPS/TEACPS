# ESP32 Web Server

**Example:** *EspWebServer*

Many ESP32 boards are cheap but at the same time very powerful. Many
support Wi-Fi and Bluetooth out of the box. This means you can easily
connect the board to an USB power bank and transmit measured sensor
values to a remote computer, without the need for any wires. Even more,
the ESP32 can also directly serve as a web server (like Node.js), where
other browsers can connect to, to show an interface or to get data.

First, create another new project through PIO Home. Make sure the
project is active:

![Switching the active project in
PlatformIO.](./media/platform-io-switching-active-project.png)

To get access to the Wi-Fi capabilities, install the *"ESP Async
Webserver"* library through PIO Home.\
Note: do not install the version with "-esphome" in the name – these
are variants for a home automation system. We need:

- **ESP Async WebServer** by Hristo Gochkov (yubox-node-org, Mathieu Carbou):\
    <https://github.com/mathieucarbou/ESPAsyncWebServer>

- **AsyncTSP** (dependency of the webserver, automatically
    installed):\
    <https://github.com/mathieucarbou/AsyncTCP>

Search for the "ESP Async WebServer" in the Registry-tab of Libraries.
Then click on "Add to Project" and select your project from the
drop-down list. Make sure you choose the more
recent version maintained by mathieucarbou / yubox-node-org.

![Adding the \"ESP Async WebServer\" library and
example.](./media/adding-esp-async-webserver.png)

![Adding the ESP Async Webserver project dependency in
PlatformIO.](./media/esp32-webserver-project-dependency.png)

To get the web server up and running, switch to the "simple_server"
example in the libraries tab of PIO Home (as also seen in the
screenshot). Copy the whole demo code into your `main.cpp` file. It is
also here for reference:

```c++
//
// A simple server implementation showing how to:
//  * serve static messages
//  * read GET and POST parameters
//  * handle missing pages / 404s
//

#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

const char* PARAM_MESSAGE = "message";

void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

void setup() {

    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.printf("WiFi Failed!\n");
        return;
    }

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", "Hello, world");
    });

    // Send a GET request to <IP>/get?message=<message>
    server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
        String message;
        if (request->hasParam(PARAM_MESSAGE)) {
            message = request->getParam(PARAM_MESSAGE)->value();
        } else {
            message = "No message sent";
        }
        request->send(200, "text/plain", "Hello, GET: " + message);
    });

    // Send a POST request to <IP>/post with a form field message set to <message>
    server.on("/post", HTTP_POST, [](AsyncWebServerRequest *request){
        String message;
        if (request->hasParam(PARAM_MESSAGE, true)) {
            message = request->getParam(PARAM_MESSAGE, true)->value();
        } else {
            message = "No message sent";
        }
        request->send(200, "text/plain", "Hello, POST: " + message);
    });

    server.onNotFound(notFound);

    server.begin();
}

void loop() {
}
```

As you can see, the example code sets the serial monitor speed to
$115200$. Update the serial monitor speed in the platformio.ini file
accordingly.

To get it working, you only need to adapt the two lines with the SSID
and password of your Wi-Fi network. **Note:** this will most likely not
work with the certificate-based encryption of the Wi-Fi at universities
or companies, but should work fine with the normal WPA2/3-encryption
typically used for private Wi-Fi networks.

Once you compile and run the project on your ESP32, it will
automatically attempt to connect to your Wi-Fi, get an IP and wait for
incoming connections. In the serial monitor, you will then see the IP
address that your ESP32 board got assigned in your local Wi-Fi.

![The IP address of the ESP32 board visible on the serial monitor in
PlatformIO.](./media/esp32-ip-address.png)

Next, connect to this IP address with your web browser. You should see
the "Hello, world" page displayed. Note that we are not using HTTPS but
instead the unencrypted HTTP protocol.

![\"Hello World\" page from the ESP32 running a web
server.](./media/esp32-hello-world.png)

To interact with the web server, you can use the standard HTTP GET and
POST requests. GET essentially supplies parameters directly in the URL
that you enter in the browser. POST requests send the data in the body
of the request, as is usually done with forms or generally larger
amounts of data.

The default routes provide a URL for both, and the web server is
configured in such a way that it expects a "message" parameter, which it
then sends back as an answer. To test this, open\
`http://<ESP32-IP>/get?message=Welcome`

You should see the message repeated in the response:

![Sending GET requests to the ESP32 web
server.](./media/esp32-webserver-get-request.png)

As you can see in the example, the web server setup is finished in the
`setup()` method. The handler functions for the web requests are anonymous
functions. Therefore, the `loop()` method is empty.

Let us combine this with some functionality of a previous example. When
we send `message=1`, it should turn the internal LED of the board on;
with `message=0`, it turns the light off.

After the `#include` statements, add a global variable:

```c++
int lightOn = LOW;
```

Note that in C++, you always need to set a default value for the
variable – otherwise, it would contain a "random" number. In contrast,
JavaScript always assigns $0$ to a new variable if you do not specify
something yourself.

In the route for `/get`, adapt the first part of the `if` statement to:

```c++
    if (request->hasParam(PARAM_MESSAGE))
    {
      message = request->getParam(PARAM_MESSAGE)->value();
      if (message.equals("0"))
      {
        lightOn = HIGH;
      }
      else if (message.equals("1"))
      {
        lightOn = LOW;
      }
    }
```

It checks if the string contained in the message variable contains "0"
or "1" and sets the internal LED variable accordingly.

Now, we only need to apply this to the internal LED pin. First, do not
forget the setup. Add the `pinMode()` call at the beginning of the `setup()`
function:

```c++
void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
```

Now, in `loop()`, you can use the variable for a `digitalWrite()` statement
on the same pin to switch the led on/off. When you then call the web
server through the browser providing the corresponding GET parameter,
you will see the board act.

![Triggering a port through a web
request.](./media/custom-get-request-for-triggering-led.png)

![LED triggered on through a web GET request on the
ESP32.](./media/led-on-esp32-triggered-through-http-get-request.jpeg)

**Exercise:** extend the application so that the response to a GET
request returns the measurement of the touch input by integrating the
code of the [touch input example](../TouchInput/README.md).
