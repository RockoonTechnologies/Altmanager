/*PAD COM LIB*/
#include "Arduino.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include "altmanager.h"


float altitude1;
float altitude2;
float basealtitude;
float currentalt;

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)
Adafruit_BMP280 bmp;

void start() {
	
	if (!bmp.begin()) {
		Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
		while (1);
	}
}

void average(int times) {
	
	int i;
	while (i < times) {
		altitude1 = altitude1 + bmp.readAltitude(1013.25);
	}
	basealtitude = altitude1 / times;
	Serial.print(basealtitude);
}

int getAlt() {
	altitude2 = bmp.readAltitude(1013.25);
	currentalt = altitude2 - basealtitude;
	Serial.print(currentalt);
	return currentalt;
}

