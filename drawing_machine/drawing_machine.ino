#include <Stepper.h>
#include <Servo.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;
float a=0.42;
float b=0.42;
float c=0.63;
float d=0.59;
int servopin=10;
Servo myservo;
int sws1;
int sws2;
int sws3;
int sws4;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 2, 4, 3, 5);
Stepper myStepper2 = Stepper(stepsPerRevolution, 6, 8, 7, 9);

void setup() {
  Serial.begin(9600);
  myservo.attach(servopin);
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  pinMode(A2,INPUT_PULLUP);
  pinMode(A3,INPUT_PULLUP);
}

void rectangle(){
    myservo.write(90);
    delay(500);

    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*b; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);

    myStepper.setSpeed(10);
    myStepper2.setSpeed(10);
    for (int i = 0; i < stepsPerRevolution*a; i++) {
        myStepper.step(1);
        myStepper2.step(1);
    }
    delay(1000);

    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*c; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);

    myStepper.setSpeed(10);
    myStepper2.setSpeed(10);
    for (int i = 0; i < stepsPerRevolution*a; i++) {
        myStepper.step(1);
        myStepper2.step(1);
    }
    delay(1000);

    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*b; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);

    myStepper.setSpeed(10);
    myStepper2.setSpeed(10);
    for (int i = 0; i < stepsPerRevolution*a; i++) {
        myStepper.step(1);
        myStepper2.step(1);
    }
    delay(1000);

    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*c; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);
    myservo.write(10);


    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*1.5; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);
    
}

void square(){
   myservo.write(90);
   delay(500);
    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*b; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);

    myStepper.setSpeed(10);
    myStepper2.setSpeed(10);
    for (int i = 0; i < stepsPerRevolution*a; i++) {
        myStepper.step(1);
        myStepper2.step(1);
    }
    delay(1000);

    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*b; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);

    myStepper.setSpeed(10);
    myStepper2.setSpeed(10);
    for (int i = 0; i < stepsPerRevolution*a; i++) {
        myStepper.step(1);
        myStepper2.step(1);
    }
    delay(1000);

    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*b; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);

    myStepper.setSpeed(10);
    myStepper2.setSpeed(10);
    for (int i = 0; i < stepsPerRevolution*a; i++) {
        myStepper.step(1);
        myStepper2.step(1);
    }
    delay(1000);

    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*b; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);
    myservo.write(10);


    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*1.5; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);
    
}

void circle(){
   myservo.write(90);
   delay(500);
    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*3.5; i++) {
        myStepper.step(1);
        myStepper2.step(0);
    }
    delay(1000);
    myservo.write(10);


    // Rotate both motors CCW quickly at 10 RPM
    myStepper.setSpeed(10);
    myStepper2.setSpeed(10);
    for (int i = 0; i < stepsPerRevolution*1.5; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);
}

void triangle(){
   myservo.write(90);
   delay(500);
    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*a; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);

    myStepper.setSpeed(10);
    myStepper2.setSpeed(10);
    for (int i = 0; i < stepsPerRevolution*c; i++) {
        myStepper.step(1);
        myStepper2.step(1);
    }
    delay(1000);

    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*d; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);

    myStepper.setSpeed(10);
    myStepper2.setSpeed(10);
    for (int i = 0; i < stepsPerRevolution*c; i++) {
        myStepper.step(1);
        myStepper2.step(1);
    }
    delay(1000);

    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*a; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);
    myservo.write(10);

    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*1.5; i++) {
        myStepper.step(1);
        myStepper2.step(-1);
    }
    delay(1000);
}

void stop(){
   myservo.write(10);
    myStepper.setSpeed(15);
    myStepper2.setSpeed(15);
    for (int i = 0; i < stepsPerRevolution*b; i++) {
        myStepper.step(0);
        myStepper2.step(0);
    }
    delay(1000);

    // Rotate both motors CCW quickly at 10 RPM
   /* myStepper.setSpeed(10);
    myStepper2.setSpeed(10);
    for (int i = 0; i < stepsPerRevolution*a; i++) {
        myStepper.step(0);
        myStepper2.step(0);
    }
    delay(1000);*/


}

void loop() {
  // Set speeds for both motors
  sws1=digitalRead(A0);
  sws2=digitalRead(A1);
  sws3=digitalRead(A2);
  sws4=digitalRead(A3);
  myservo.write(20);

  if(sws1==0){
    circle();
  }
  else if(sws2==0){
    square();
  }
  else if(sws3==0){
    rectangle();
  }
  else if(sws4==0){
    triangle();
  }
  else {
    stop();
  }
  
}
