#include <Servo.h>

int servopin=5;
int servoposition=120;
int servopin2=9;
int servopin3=11;
Servo myservo;
Servo myservo2;
Servo myservo3;
int sw1=12;
int sws1;
int sw2=11;
int sws2;

int joyv1;
int joy1=A0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myservo.attach(servopin);
myservo2.attach(servopin2);
myservo3.attach(servopin3);
pinMode(sw1,INPUT_PULLUP);
pinMode(sw2,INPUT_PULLUP);
pinMode(joy1,INPUT);
}

void loop() {
  sws1=digitalRead(sw1);
  Serial.println(sws1);
  sws2=digitalRead(sw2);
  Serial.println(sws2);

  joyv1=analogRead(joy1);
  Serial.print("joy1=");
  Serial.print(joyv1);

  int servoposition1 =map(joyv1,0,730,0,180);
 // int servoposition2 =map(joyv2,730,0,35,110);

  myservo.write(90);
  myservo2.write(90); 
  myservo3.write(180);

  /*if(sws1==0){
    myservo.write(100);
    myservo2.write(80);

  }
  else if(sws2==0){
    myservo.write(80);
    myservo2.write(100); 
  }
  else{
    myservo.write(90);
    myservo2.write(90);

  }*/
  
  //delay(5000);
  // myservo.write(90);
  //delay(2000);
}
