/*
  Project Name:   footpedal
  Description:    USB keyboard from foot pedal device
*/

// Library initialization
#include <ProTrinketKeyboard.h>
#include <ezButton.h>
#include "config.h"

// instantiate button objects
ezButton buttonLeft(buttonLeftPin);
ezButton buttonMiddle(buttonMiddlePin);
ezButton buttonRight(buttonRightPin);

void setup()
{
  // handle Serial first so debugMessage() works
  #ifdef DEBUG
    Serial.begin(115200);
    // wait for serial port connection
    while (!Serial);
  #endif

  debugMessage("footpedal started",1);
  debugMessage(String("debounce time set to ") + buttonDebounceDelay + " ms",1);

  buttonLeft.setDebounceTime(buttonDebounceDelay); 
  buttonMiddle.setDebounceTime(buttonDebounceDelay); 
  buttonRight.setDebounceTime(buttonDebounceDelay); 

  // start USB keyboard
  TrinketKeyboard.begin();
}

void loop()
{
  // poll function must be called <= 10 ms or keystroke entered
  // else computer may think device has stopped working
  TrinketKeyboard.poll();

  buttonLeft.loop();   // MUST call the loop() function first
  buttonMiddle.loop();
  buttonRight.loop();

  if (buttonLeft.isPressed())
  {
    TrinketKeyboard.pressKey(0, KEYCODE_H);
    TrinketKeyboard.pressKey(0, 0); // this releases the key
    debugMessage("Left button press",1);
  }

  if (buttonMiddle.isPressed())
  {
    TrinketKeyboard.pressKey(0, KEYCODE_J);
    TrinketKeyboard.pressKey(0, 0);
    debugMessage("Middle button press",1);
  }

  if (buttonRight.isPressed())
  {
    TrinketKeyboard.pressKey(0, KEYCODE_N);
    TrinketKeyboard.pressKey(0, 0);
    debugMessage("Right button press",1);
  }
}

void debugMessage(String messageText, int messageLevel)
// wraps Serial.println as #define conditional
{
  #ifdef DEBUG
    if (messageLevel <= DEBUG)
    {
      Serial.println(messageText);
      Serial.flush();  // Make sure the message gets output (before any sleeping...)
    }
  #endif
}