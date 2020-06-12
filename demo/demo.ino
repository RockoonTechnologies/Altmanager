

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#include <altmanager.h>



int alt;


void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));
  start();
 
}

void loop() {
    average(5);
    delay(2000);
    alt = getAlt();
}
