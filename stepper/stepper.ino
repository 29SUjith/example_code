
#include <Stepper.h>

// Define the number of steps per revolution and the motor pins
const int stepsPerRevolution =200;  // Change this value to match your stepper motor
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // Set the speed (RPM) of the motor
  myStepper.setSpeed(60);  // Change this value to set your desired speed
}

void loop() {
  // Step the motor one step in one direction:
  myStepper.step(stepsPerRevolution);
  delay(00);

  // Step the motor one step in the other direction:
  myStepper.step(-stepsPerRevolution);
  delay(00);
}