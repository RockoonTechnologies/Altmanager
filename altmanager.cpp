/*PAD COM LIB*/
#include "Arduino.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include "altmanager.h"


float altitude1;
float altitude2;
float basealtitude;

void average(int times) {
	int i;
	while (i < times) {
		altitude1 = altitude1 + bmp.readAltitude(SEALEVEL);
	}
	basealtitude = altitude1 / times;
	Serial.print("basealt" + basealtitude);
}

int getAlt() {
	altitude2 = bmp.readAltitude(SEALEVEL);
	currentalt = altitude2 - basealtitude;
	Serial.print("current alt" + currentalt);
	return currentalt;
}

