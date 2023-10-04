This is an Arduino IDE library for the XPT2046 touchscreen controller chip. This code uses bitbanging, so this is a last resort if your touchscreen is hard wired to the wrong pins. 

## Why
The ESP32 Cheap Yellow Displays (CYD) aka 2432S028R and 2432S024R have the XPT wired to non-hardware SPI. This example code should work with those boards. TFT_eSPI or LGVL could be used with this.

## Features
* Begin and init screen
* Get touch 
* Calibrate
* Load/Save Calibrate to SPIFFS

## Usage 
* Install the library zip or put it in your Arduino/libraries directory
* File > Examples > XPT2046 > basic_touch
