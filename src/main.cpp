#include "accel_led.h"
#include "accelerometer.h"
#include "yboard.h"
#include <Arduino.h>

/////////////////////////////////////////////////////////////////////////////////////

// Need to setup:
// 1. Serial Communication
// 2. Y-Board (includes accelerometer)
// 3. Off-Board OLED Display
// 4. 3D Axes (will be drawn on display)
void setup() {
  Serial.begin(115200); // Serial
  Serial.println("Starting up...");
  Yboard.setup();  // Y-Board
  setup_display(); // Display
  setup_axes();    // Axes
  Serial.println("All set, ready to go!");
}

void loop() {
  updateScreen();
  // light_LEDs();
}