/*
  Project Name:   footpedal
  Developer:      Eric Klein Jr. (temp2@ericklein.com)
  Description:    USB keyboard from foot pedal device

  See README.md for target information, revision history, feature requests, etc.
*/

#include <ProTrinketKeyboard.h>  // Ensure the library is installed

// Switches are connected from ground to these defined pins
const int PIN_BUTTON_LEFT = 8;
const int PIN_BUTTON_MIDDLE = 5;
const int PIN_BUTTON_RIGHT = 3;

void setup()
{
  // Declare button pins as inputs
  pinMode(PIN_BUTTON_LEFT, INPUT);
  pinMode(PIN_BUTTON_MIDDLE, INPUT);
  pinMode(PIN_BUTTON_RIGHT, INPUT);
  
  // setting input pins to high means turning on internal pull-up resistors
  digitalWrite(PIN_BUTTON_LEFT, HIGH);
  digitalWrite(PIN_BUTTON_MIDDLE, HIGH);
  digitalWrite(PIN_BUTTON_RIGHT, HIGH);
  // remember, the buttons are active-low, they read LOW when they are not pressed

  // start USB stuff
  TrinketKeyboard.begin();
}

void loop()
{
  TrinketKeyboard.poll();
  // poll function must be called >= 10 ms or keystroke entered
  // else computer may think device has stopped working

  if (digitalRead(PIN_BUTTON_LEFT) == LOW)
  {
    TrinketKeyboard.pressKey(0, KEYCODE_A);
    TrinketKeyboard.pressKey(0, 0); // this releases the key
  }

  if (digitalRead(PIN_BUTTON_MIDDLE) == LOW)
  {
    TrinketKeyboard.pressKey(0, KEYCODE_B);
    TrinketKeyboard.pressKey(0, 0); // this releases the key
  }
  
  if (digitalRead(PIN_BUTTON_RIGHT) == LOW)
  {
    TrinketKeyboard.pressKey(0, KEYCODE_C);
    TrinketKeyboard.pressKey(0, 0); // this releases the key
  }
}
