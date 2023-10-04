#include <XPT2046_Bitbang.h>

#define MOSI_PIN 32
#define MISO_PIN 39
#define CLK_PIN  25
#define CS_PIN   33

#define RERUN_CALIBRATE true

XPT2046_Bitbang touchscreen(MOSI_PIN, MISO_PIN, CLK_PIN, CS_PIN);

void setup() {
  Serial.begin(115200);

  // Initialize SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("An error has occurred while mounting SPIFFS");
    return;
  }

  // Initialize the touchscreen
  touchscreen.begin();

  // Check for existing calibration data
  if (!touchscreen.loadCalibration()) {
    Serial.println("Failed to load calibration data from SPIFFS.");
  }

  // Check if we need to re-run calibration
  #if RERUN_CALIBRATE
    Serial.println("Re-running calibration as requested...");
    delay(2000); //wait for user to see serial
    touchscreen.calibrate();
    touchscreen.saveCalibration();
  #endif
}

void loop() {
  Point touch = touchscreen.getTouch();

  // Display touches that aren't at the coordinate (0,0)
  if (touch.x != 0 || touch.y != 0) {
    Serial.print("Touch at X: ");
    Serial.print(touch.x);
    Serial.print(", Y: ");
    Serial.println(touch.y);
  }

  delay(100);  // Adjust delay as needed for responsiveness vs. serial output frequency
}
