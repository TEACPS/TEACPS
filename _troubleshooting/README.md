# Troubleshooting

## Uploading issues
Certain combinations of the UART chips on the ESP32 boards with PC USB chipsets produce issues.

Before continuing make sure you have the latest drivers for the UART chips installed. 
* Windows: 
  * LOLIN D32/Pro and LOLIN32 boards require the driver from [here](https://www.wch-ic.com/downloads/CH341SER_ZIP.html)
* Macs should have the necessary drivers preinstalled

### CH340 and AMD Ryzen USB Chipsets
AMD Ryzen based computers and the LOLIN D32 (Pro) boards have issues when trying to upload a sketch from VSCode/PlatformIO. Symptoms: the uploader cannot bring the ESP into flash mode and after some waiting time will terminate with an error.

#### Solution
Manually bring the ESP into the downloading mode by:

* connecting GPIO 0 to GND
* press the RESET button
* (terminal will notify you that it is in *download mode*)
* upload the sketch to your board
* remove connection between GPIO 0 and GND