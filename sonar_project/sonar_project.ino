/*Ultrasonic radar system.
  *Upload the following code first.
  *Serial monitor readings.
  *created by indian wings rc.
  *Read the code below and use it for any of your creations.
*/
#include <Servo.h>//include library
Servo myServo;//create object your own name
int dis;
int ledpin=12;
int buzzer=13;
void setup() {
  pinMode(2, OUTPUT);//define arduino pin
  pinMode(3, INPUT);//define arduino pin
  Serial.begin(9600);//enable serial monitor
  myServo.attach(9);//servo connect pin
  pinMode(ledpin,OUTPUT);
  pinMode(buzzer,OUTPUT);
}
void loop() {
  for (int x = 0; x <= 180; x++) { //servo turn left
    myServo.write(x);//rotete servo
    dis=distance();
    Serial.print(x);//print servo angle
    Serial.print(",");
    Serial.print(dis);//print ultrasonic readings
    Serial.print(".");
    delay(50);
  }
  for (int y = 179; y > 0; y--) {//servo turn right
    myServo.write(y);//rotete servo
    dis=distance();
    Serial.print(y);////print servo angle
    Serial.print(",");
    Serial.print(dis);//print ultrasonic readings
    Serial.print(".");
    delay(50);
  }
  if (dis<30){
    digitalWrite(ledpin,HIGH);
    digitalWrite(buzzer,HIGH);
  }
  else if(dis>10){
    digitalWrite(ledpin,LOW);
    digitalWrite(buzzer,LOW);
  }
}
//ultrasonic sensor code
int distance() {
  digitalWrite(2, LOW);
  delayMicroseconds(4);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
 
 
  int t = pulseIn(3, HIGH);
  int cm = t / 29 / 2; //time convert distance
  return cm;//return value


}