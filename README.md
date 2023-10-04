# XPT2046_Bitbang Library for Arduino

`XPT2046_Bitbang` is an Arduino library that provides a bit-banged SPI interface to communicate with XPT2046 touchscreen controllers. This library is ideal for users who require greater flexibility in pin choice for the MOSI, MISO, CLK, and CS lines.  

Really I made this for those esp32-2432S028R and esp32-2432S024R ESP32 Cheap Yellow Displays, though it should be compatible with a lot more. It's just that those boards had unusual hard-wired software SPI.
![image](https://github.com/ddxfish/XPT2046_Bitbang_Arduino_Library/assets/6764685/f4632b60-1434-4d6c-9532-9eee6c1122a5)


## Features
- Manual bit-banging SPI communication
- Calibration of the touchscreen
- Storing calibration data to SPIFFS
- Getting touchscreen coordinates

## Installation

1. Download the repository as a zip file.
2. In the Arduino IDE, go to `Sketch` -> `Include Library` -> `Add .ZIP Library` and select the downloaded zip file.
3. The library should now be available in your Arduino IDE.

## Usage

### Initialization
```cpp
#define MOSI_PIN 32
#define MISO_PIN 39
#define CLK_PIN  25
#define CS_PIN   33

#include <XPT2046_Bitbang.h>

XPT2046_Bitbang touchscreen(MOSI_PIN, MISO_PIN, CLK_PIN, CS_PIN);
```

## Basic methods

- `begin()`: Initializes the touchscreen.
- `calibrate()`: Calibrates the touchscreen and displays prompts via Serial.
- `getTouch()`: Gets the current touch point. Returns a `Point` struct with `x` and `y` members.
- `loadCalibration()`: Loads calibration data from SPIFFS.
- `saveCalibration()`: Saves calibration data to SPIFFS.

## Example

Refer to `XPT2046_BitbangExample.ino` for a comprehensive usage example. This example demonstrates the initialization, calibration, and reading of touch points.

## Contributing

Pull requests are welcome! For major changes, please open an issue first to discuss what you'd like to change.
