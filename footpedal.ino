/*
  Project Name:   footpedal
  Developer:      Eric Klein Jr. (temp2@ericklein.com)
  Description:    USB keyboard from foot pedal device

  See README.md for target information, revision history, feature requests, etc.
*/

// Library initialization
#include <ProTrinketKeyboard.h>
#include "buttonhandler.h"

// Assign Arduino pins
#define pushButtonLeft 8
#define pushButtonMiddle 5
#define pushButtonRight 3

enum { BTN_NOPRESS = 0, BTN_SHORTPRESS, BTN_LONGPRESS };
const int buttonLongPressDelay = 3000;

// instantiate button objects
ButtonHandler keyLeft(pushButtonLeft,buttonLongPressDelay);
ButtonHandler keyMiddle(pushButtonMiddle,buttonLongPressDelay);
ButtonHandler keyRight(pushButtonRight,buttonLongPressDelay);

void setup()
{
  keyLeft.init();
  keyMiddle.init();
  keyRight.init();

  // start USB keyboard
  TrinketKeyboard.begin();
}

void loop()
{
  TrinketKeyboard.poll();
  // poll function must be called <= 10 ms or keystroke entered
  // else computer may think device has stopped working

  switch (keyLeft.handle()) {
  case BTN_SHORTPRESS:
    TrinketKeyboard.pressKey(0, KEYCODE_H);
    TrinketKeyboard.pressKey(0, 0); // this releases the key
    Serial.println("Left button short press"); //debug text
    break;
  case BTN_LONGPRESS:
    Serial.println("Left button long press"); //debug text
    break;
  }

  switch (keyMiddle.handle()) {
  case BTN_SHORTPRESS:
    TrinketKeyboard.pressKey(0, KEYCODE_J);
    TrinketKeyboard.pressKey(0, 0); // this releases the key
    Serial.println("Middle button short press"); //debug text
    break;
  case BTN_LONGPRESS:
    Serial.println("Middle button long press"); //debug text
    break;
  }

  switch (keyRight.handle()) {
  case BTN_SHORTPRESS:
    TrinketKeyboard.pressKey(0, KEYCODE_N);
    TrinketKeyboard.pressKey(0, 0); // this releases the key
    Serial.println("Right button short press"); //debug text
    break;
  case BTN_LONGPRESS:
    Serial.println("Right button long press"); //debug text
    break;
  }
}
