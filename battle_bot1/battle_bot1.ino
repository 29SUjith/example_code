#include <Servo.h>

int servopin=3;
int servopin2=5;
Servo myservo;
Servo myservo2;

char value;
int ma1=12;
int ma2=11;
int mb1=10;
int mb2=8;
int light=13;
int joy1=A5;
int joy2=A4;
int joyv1;
int joyv2;
int gun1=9;
int power=6;


void setup(){
Serial.begin(9600);
pinMode(ma1,OUTPUT);
pinMode(ma2,OUTPUT);
pinMode(mb1,OUTPUT);
pinMode(mb2,OUTPUT);
pinMode(light,OUTPUT);
pinMode(gun1,OUTPUT);
pinMode(power,OUTPUT);
digitalWrite(light,LOW);
pinMode(joy1,INPUT);
pinMode(joy2,INPUT);
myservo.attach(servopin);
myservo2.attach(servopin2);
}

void loop(){
analogWrite(power,15);
joyv1=analogRead(joy1);
Serial.print("joy1=");
Serial.print(joyv1);
joyv2=analogRead(joy2);
Serial.print("joy2=");
Serial.println(joyv2);

value=Serial.read();
Serial.println(value);

int servoposition1 =map(joyv1,0,730,0,180);
int servoposition2 =map(joyv2,730,0,35,110);

myservo.write(servoposition1);
myservo2.write(servoposition2); 



if(value=='R'){
  digitalWrite(ma1,HIGH);
  digitalWrite(mb1,HIGH);
  digitalWrite(ma2,LOW);
  digitalWrite(mb2,LOW);
  Serial.println("Right");
}
else if(value=='L'){
  digitalWrite(ma2,HIGH);
  digitalWrite(mb2,HIGH);
  digitalWrite(ma1,LOW);
  digitalWrite(mb1,LOW);
  Serial.println("Left");
}

else if(value=='B'){
  digitalWrite(ma1,HIGH);
  digitalWrite(mb2,HIGH);
  digitalWrite(ma2,LOW);
  digitalWrite(mb1,LOW);
  Serial.println("Back");
}

else if(value=='F'){
  digitalWrite(ma2,HIGH);
  digitalWrite(mb1,HIGH);
  digitalWrite(ma1,LOW);
  digitalWrite(mb2,LOW);
  Serial.println("Front");
}

else if(value=='X'){
  digitalWrite(gun1,HIGH);
}

else if(value=='W'){
  digitalWrite(light,HIGH);
}
else if(value=='A'){
  digitalWrite(light,LOW);
  digitalWrite(gun1,LOW);
}


else if(value=='S'){
  digitalWrite(ma2,LOW);
  digitalWrite(mb1,LOW);
  digitalWrite(ma1,LOW);
  digitalWrite(mb2,LOW);
  Serial.println("off");
}

/*else{
  digitalWrite(gun1,LOW);
}*/

delay(500);
}