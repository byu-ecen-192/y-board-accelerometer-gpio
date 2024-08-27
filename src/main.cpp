#include "accel_led.h"
#include "accelerometer.h"
#include "accelerometer.cpp"
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
  display.clearDisplay();

  // This is the default accelerometer program I wrote for this lab.
  // Everything for this function happens inside ../lib/accelerometer.cpp
  defaultProgram();

  // This is another function I wrote to light up the board's LEDs
  // based on how the board is rotated in 3D space.
  // Uncomment this line to give it a try!
  // light_LEDs();

  /*********************************************************************/
  /************************* EXTRA TINKERING ***************************/
  /*********************************************************************/
  // Below are some functions for you to mess around with. Try changing the
  // numbers in each function call to change how each shape is drawn or what
  // letters are typed on the screen.

  // Draw a line
  // display.drawLine(2, 2, 37, 15, ON);

  // Draw some shapes
  // display.drawCircle(111, 52, 8, ON);
  // display.fillTriangle(96, 60, 89, 27, 73, 26, ON);
  // display.drawRect(104, 12, 16, 14, ON);
  // display.drawRoundRect(12, 34, 30, 17, 5, ON);

  // Write on the screen
  // display.setTextSize(3);
  // display.setCursor(0, 0);
  // display.print("Word");

  display.display();
}