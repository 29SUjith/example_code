#include <Servo.h>

Servo myservo;
int joyx=0;
int joyvalue;

void setup() {
  // put your setup code here, to run once:
myservo.attach(6);
}

void loop() {
  // put your main code here, to run repeatedly:
joyvalue=analogRead(joyx);
joyvalue=map (joyvalue,0,1023,0,180);
myservo.write(joyvalue);
}
