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

  /*********************************************************************/
  /************************* PART 1 - ACCELEROMETER LAB PORTION **************************/
  /*********************************************************************/

  defaultProgram();

  // light_LEDs();

  /*********************************************************************/
  /************************* PART 2 - GPIO LAB PORTION **************************/
  /*********************************************************************/

  // Communication from the Y-board to external peripherals
  // Goal: Build a basic circuit on the breadboard and then control it with the Y-board.
  // blink_led();

  // Communication from external periperhals to the Y-board
  // onboard_led();

  display.display();
}

// blink_led() function
// 1) Function is set up to turn on LED when button 1 is pressed. Set up circuit and run this.
// 2) PLay around. Add some switches, buttons, and more LEDs. Find creative ways to light them 
void blink_led() {
  if (Yboard.get_button(1)) {  // the get_button analyzes the state of button 1. If it is pressed it report "TRUE" otherwise it will report "FALSE."
    digitalWrite(PERIPHERAL_PIN, HIGH);  // this command will put voltage onto the PERIPHERAL_PIN, which we have defined as pin 15 (see line 7).
  } else {
    digitalWrite(PERIPHERAL_PIN, LOW);   // This puts zero voltage onto the PERIPHERAL_PIN (pin 15).
  }
}


// onboard_led() function
// Blink onboard LEDs depending on the state of the external button/switch
void onboard_led() {
  if (digitalRead(PERIPHERAL_PIN)){ // digitalRead keeps an eye on the PERIPHERAL_PIN (pin 15).
    Yboard.set_all_leds_color(255,0,0); // If voltage is detected the PERIPHERAL_PIN, then all the Yborad LEDs will be set to red.
  } else {
    Yboard.set_all_leds_color(0,0,0); // If voltage is NOT detected the PERIPHERAL_PIN, then all the Yborad LEDs will be turned out.
  }
}