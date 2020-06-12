# Altmanager
a lib that easily helps with BMP280 operation

# Installation

Install this lib via the .zip file

**This lib requires the Wire lib, SPI lib and the Adafruit bmp280 lib.

# Usage

The lib has three main operators:
- start();
- average();
- getAlt();

```start();``` is located in the setup function of your code, and it creates a bmp instance meaning that creating your own instance and declaring pins is not needed and may cause errors.

```average();``` gets the average altitude and sets that as the base altitude or zero, this means whenever a ```getAlt();``` takes place,
it is relative to the latest ```average();``` outcome. This only needs to be run once but can be ran multiple times. **Usage** ```average();``` takes a integer, and that is the amount of times it runs.

EX: ```average(5);``` - will run 5 times, the more it runs the higher accuaracy, but takes longer, etc.

```getAlt();``` gets altitude in respect to ```average();```. ```getAlt();```  is a function and returns the altitude so proper usage is: ```x = getAlt();```.

## Demo

There is a demo file, its super basic and just shows how things are used. Consult that for examples and usage.
