#include <Wire.h> // imports dependency
#include <SPI.h>  // imports dependency
#include <Adafruit_BMP280.h> // imports dependency

#include <altmanager.h> // imports lib



float alt;
float alt2;

void setup() {
  Serial.begin(9600); // how many times you want to average starts serial
  Serial.println(F("BMP280 test"));
  start(0x76); //set this to your desired i2c address
  average(5); // how many times you want to average
 
}

void loop() {
    
    delay(2000);
    alt = getAlt(); // gets alt based on average
    alt2 = rawAlt(); // gets alt based on sealevel
}