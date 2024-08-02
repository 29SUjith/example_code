// Include library
#include "SevSeg.h"
 
// Create object
SevSeg sevseg;
 
// Number of digits in display
byte numDigits = 1;
// Display select pins (not used with single display)
byte digitPins[] = {};
// Display segment pins A,B,C,D,E,F,G,DP
byte segmentPins[] = {2,3,4,5,6,7,8};
// Dropping resistors used
bool resistorsOnSegments = true;
// Display type
byte hardwareConfig = COMMON_CATHODE;
int i=0;
 
void setup() {
 
  // Start display object
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  // Set brightness
  sevseg.setBrightness(90);
 
}
 
void loop() {
 
  // Set number to display
  sevseg.setNumber(i+7);
  // Refresh the display
  sevseg.refreshDisplay();
}