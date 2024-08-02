#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;
float a=0.7;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 2, 4, 3, 5);
Stepper myStepper2 = Stepper(stepsPerRevolution, 6, 8, 7, 9);

void setup() {
    // Nothing to do (Stepper Library sets pins as outputs)
}

void loop() {
    // Set speeds for both motors
    /*myStepper.setSpeed(15);
    myStepper2.setSpeed(15);

    // Rotate both motors CW slowly at 15 RPM
    for (int i = 0; i < stepsPerRevolution*a; i++) {
        myStepper.step(1);
        myStepper2.step(1);
    }
    delay(1000);*/

    // Rotate both motors CCW quickly at 10 RPM
    myStepper.setSpeed(2);
    myStepper2.setSpeed(2);
    for (int i = 0; i < stepsPerRevolution*a; i++) {
        myStepper.step(-1);
        myStepper2.step(-1);
    }
    delay(1000);
}
