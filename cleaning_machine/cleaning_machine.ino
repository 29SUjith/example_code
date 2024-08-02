#include <Servo.h>
char val;
int servopin=9;
Servo myservo;

int trigpin1=11;
int echopin1=10;
int echopin2=12;
int trigpin2=13;
int pingtraveltime1;
long duration1;
int distance1;

int pingtraveltime2;
long duration2;
int distance2;
int sws;
int i=14;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(servopin);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  pinMode(trigpin1,OUTPUT);
  pinMode(echopin1,INPUT);
  pinMode(trigpin2,OUTPUT);
  pinMode(echopin2,INPUT);
  pinMode(A5,INPUT_PULLUP);

}

void front(){
        //front
    digitalWrite(3,LOW);//L
    digitalWrite(4,HIGH); 
    digitalWrite(5,LOW);//R
    digitalWrite(6,HIGH);
}
void back(){
        //back
    digitalWrite(4,LOW);
    digitalWrite(3,HIGH); //L
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);//r
}
void right(){
      //right
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH); 
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
}
void left(){
        //left
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW); 
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
}
void stop(){
      //stop
    digitalWrite(3,LOW);
    digitalWrite(4,LOW); 
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  sws=digitalRead(A5);
  Serial.println(sws);
  digitalWrite(trigpin1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin1,LOW);
  duration1=pulseIn(echopin1,HIGH);
  distance1=duration1*0.034/2;
  Serial.print("distance1=");
  Serial.println(distance1);


  digitalWrite(trigpin2,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin2,LOW);
  duration2=pulseIn(echopin2,HIGH);
  distance2=duration2*0.034/2;
  Serial.print("distance2=");
  Serial.println(distance2);

  myservo.write(i);
  val=Serial.read();
  Serial.println(val);
  if(sws==1){
    if(val=='F' & distance1>28){
      front();
    }

    else if(val=='B' ){
      back();
    }

    else if(val=='L' & distance1>28){
      left();
    }

    else if(val=='R' & distance1>28){
      right();
    }

    else if(val=='S'){
      stop();
    } 
  }

  if (sws==0){
    if(distance1>50){
      front();
    }
    else if(distance1<50){
      i=104;
      right();     
      delay(2000);
    }
  }
  delay(300);
}