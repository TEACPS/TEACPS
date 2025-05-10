#include <Arduino.h>
#include <Wire.h>
#include "MAX30105.h"

// Based on:
// https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library
// https://lastminuteengineers.com/max30102-pulse-oximeter-heart-rate-sensor-arduino-tutorial/

// Create sensor object
// The Max30105 has the same functions as the Max30102.
// The only difference is the I2C address.
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
  // Read values from sensor
  int red = particleSensor.getRed();
  int ir = particleSensor.getIR();

  // Better readable output for console
  // Serial.print(" R[");
  // Serial.print(red);
  // Serial.print("] IR[");
  // Serial.print(ir);
  // Serial.println("]");

  // For Arduino Serial Plotter
  Serial.print(">red:");
  Serial.println(red);
  
  Serial.print(">ir:");
  Serial.println(ir);
}
