/*
  Project Name:   footpedal
  Description:    public (non-secret) configuration data
*/

// Configuration Step 1: Set debug message output
// comment out to turn off; 1 = summary, 2 = verbose
// #define DEBUG 1

// Assign Arduino pins
#define buttonLeftPin   8
#define buttonMiddlePin 5
#define buttonRightPin  3

const int buttonDebounceDelay = 50; // time in milliseconds to debounce button

// Configuration variables that are less likely to require changes
