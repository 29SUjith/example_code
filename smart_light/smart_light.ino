
#include "SevSeg.h"
int timer_output=A0;
int read;
int read1;
int trig1=A1;
int echo1=A2;
int trig2=11;
int echo2=12;
int duration1;
long distance1;
int duration2;
long distance2;
int relay=13;
int timer=A4;
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
  Serial.begin(9600);
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
  pinMode(timer_output,INPUT_PULLUP);
  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(relay,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(timer,OUTPUT);
 
}
 
void loop() {

digitalWrite(trig1,LOW);
delayMicroseconds(2);
digitalWrite(trig1,HIGH);
delayMicroseconds(10);
digitalWrite(trig1,LOW);
duration1=pulseIn(echo1,HIGH);
distance1=(duration1/2)*0.0343;
Serial.print("distance1=");
Serial.println(distance1);


digitalWrite(trig2,LOW);
delayMicroseconds(2);
digitalWrite(trig2,HIGH);
delayMicroseconds(10);
digitalWrite(trig2,LOW);
duration2=pulseIn(echo2,HIGH);
distance2=(duration2/2)*0.0343;
Serial.print("distance2=");
Serial.println(distance2);

read1=digitalRead(timer);
Serial.println(read1);
read=digitalRead(timer_output);
Serial.println(read);

sevseg.setNumber(i);
sevseg.refreshDisplay();
Serial.print("i=");
Serial.println(i);
delay(1000);

if(distance2<95){
  digitalWrite(timer,LOW);
}
else{
   digitalWrite(timer,HIGH);
}
 
if(read==1 && i<=9){
  if(distance1<90 && distance1>0){
     i+=1;
     delay(2000);

  }
}
else if(distance1<90 && i>0 && distance1>0){
   i-=1;
    delay(1000);
}


if(i>0){
  digitalWrite(relay,HIGH);
}
else if(i<0){
  digitalWrite(relay,LOW);
}
else{
  digitalWrite(relay,LOW);
}

}

