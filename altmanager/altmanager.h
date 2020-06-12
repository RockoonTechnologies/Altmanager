/*This file is what the .cpp file looks for when it runs*/

#ifndef altmanager_h
#define altmanager_h

#include "Arduino.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

void start(uint8_t address);
void average(int times);
int getAlt();
int rawAlt();
int rawPres();
int rawTemp();
bool altwork();

#endif