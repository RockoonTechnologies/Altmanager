#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#include <altmanager.h>



float alt;
float alt;

void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));
  start(0x76);
  average(5);
 
}

void loop() {
    
    delay(2000);
    alt = getAlt();
    alt2 = rawAlt();
}