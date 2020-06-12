/*PAD COM LIB*/
#include "Arduino.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include "altmanager.h"


float altitude1;
float altitude2;
float altitude3;
int altitude4;

float t;
float p;

//bool work = false;

float basealtitude;
float currentalt;

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)
Adafruit_BMP280 bmp;

void start(uint8_t address) {
	
	// Prepare the character array (the buffer) 
	
	if (!bmp.begin(address)) {
		 Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
		 while (1);
	}
	
}


void average(int times) {

	
	for (int i = 0; i < times; i++) {
		altitude1 = altitude1 + bmp.readAltitude(1013.25);
		delay(10);
	}
	basealtitude = altitude1 / times;
	Serial.print("Base Altitude:");
	Serial.print("");
	Serial.print(basealtitude);
}

int getAlt() {
	altitude2 = bmp.readAltitude(1013.25);
	currentalt = altitude2 - basealtitude;
	Serial.print("getAlt Altitude : ");
	Serial.print("");
	Serial.print(currentalt);
	return currentalt;
}

int rawAlt() {
	altitude3 = bmp.readAltitude(1013.25);
	Serial.print("rawalt Altitude : ");
	Serial.print("");
	Serial.print(altitude3);
	return altitude3;
}

int rawPres() {
	p = bmp.readPressure();
	Serial.print("rawpressure : ");
	Serial.print("");
	Serial.print(p);
	return p;
}

int rawTemp() {
	t = bmp.readTemperature();
	Serial.print("rawtemp : ");
	Serial.print("");
	Serial.print(t);
	return t;
}

bool altwork() {
	return true;
}