#include "accel_led.h"
#include "accelerometer.h"
#include "accelerometer.cpp"
#include "yboard.h"
#include <Arduino.h>

#define PERIPHERAL_PIN 15

/////////////////////////////////////////////////////////////////////////////////////

void blink_led();
void onboard_led();

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
  // pinMode(PERIPHERAL_PIN, OUTPUT); // Works in conjunction with blink_led()
  // pinMode(PERIPHERAL_PIN, INPUT); // Works in conjunction with oboard_led()
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
  /************************* GPIO LAB PORTION **************************/
  /*********************************************************************/

  // Communication from the Y-board to external peripherals
  // Goal: Build a basic circuit on the breadboard and then control it
  // with the Y-board.
  // blink_led();

  // Communication from external periperhals to the Y-board
  // onboard_led();

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

// blink_led
// turn on LED while button 1 is active
void blink_led() {
  if (Yboard.get_button(1)) {
    digitalWrite(PERIPHERAL_PIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  } else {
    digitalWrite(PERIPHERAL_PIN, LOW);   // turn the LED off by making the voltage LOW
  }
}

// onboard_led
// Blink onboard LEDs depending on the state of the external button/switch
void onboard_led() {
  if (digitalRead(PERIPHERAL_PIN)){
    Yboard.set_all_leds_color(255,0,0);
  } else {
    Yboard.set_all_leds_color(0,0,0);
  }
}