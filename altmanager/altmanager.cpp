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

float pressure;
float temp;

bool working = false;

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
	working = true;
}


void average(int times) {

	
	for (int i = 0; i < times; i++) {
		altitude1 = altitude1 + bmp.readAltitude(1013.25);
	}
	basealtitude = altitude1 / times;
	Serial.print("Base Altitude:");
	Serial.print(basealtitude);
}

int getAlt() {
	altitude2 = bmp.readAltitude(1013.25);
	currentalt = altitude2 - basealtitude;
	Serial.print("getAlt Altitude : ");
	Serial.print(currentalt);
	return currentalt;
}

int rawAlt() {
	altitude3 = bmp.readAltitude(1013.25);
	Serial.print("rawalt Altitude : ");
	Serial.print(altitude3);
	return altitude3;
}

int rawPres() {
	pressure = bmp.readPressure();
	Serial.print("rawpressure : ");
	Serial.print(pressure);
	return pressure;
}

int rawTemp() {
	temp = bmp.readTemperature();
	Serial.print("rawtemp : ");
	Serial.print(temp);
	return temp;
}

bool altwork() {
	if (working == true) {
		return true;
	}
	if (working == false) {
		return false;
	}
}