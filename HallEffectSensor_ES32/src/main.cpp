#include <Arduino.h>


void setup()
{
  Serial.begin(115200);
}

void loop()
{
  int hallVal = hallRead();
  Serial.print(">Hall effect value:");
  Serial.println(hallVal);
  delay(100);
}