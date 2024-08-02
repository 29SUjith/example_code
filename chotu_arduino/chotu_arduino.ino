#include <Servo.h>
char val;
int servopin1=3;
int i=90;
int servopin2=9;
int j=90;

Servo myservo1;
Servo myservo2;

int ma1=13;
int ma2=7;
int mb1=12;
int mb2=11;
int sp1=5;
int sp2=6;
int k;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo1.attach(servopin1);
  myservo2.attach(servopin2);
  pinMode(ma1,OUTPUT);
  pinMode(ma2,OUTPUT);
  pinMode(mb1,OUTPUT);
  pinMode(mb2,OUTPUT);
  pinMode(sp1,OUTPUT);
  pinMode(sp2,OUTPUT);

}
void back(){
  digitalWrite(ma1,HIGH);
  digitalWrite(ma2,LOW);
  digitalWrite(mb1,HIGH);
  digitalWrite(mb2,LOW);
}
void front(){
  digitalWrite(ma1,LOW);
  digitalWrite(ma2,HIGH);
  digitalWrite(mb1,LOW);
  digitalWrite(mb2,HIGH);
}
void right(){
  digitalWrite(ma1,HIGH);
  digitalWrite(ma2,LOW);//right
  digitalWrite(mb1,LOW);
  digitalWrite(mb2,HIGH);
}
void left(){
  digitalWrite(ma1,HIGH);
  digitalWrite(ma2,LOW);//right
  digitalWrite(mb1,HIGH);
  digitalWrite(mb2,LOW);
}
void stop(){
  digitalWrite(ma1,LOW);
  digitalWrite(ma2,LOW);//right
  digitalWrite(mb1,LOW);
  digitalWrite(mb2,LOW);
}


void loop() {
  // put your main code here, to run repeatedly:
  val= Serial.read();
  Serial.println(k);
  

  myservo1.write(i);
  myservo2.write(j); 
  analogWrite(sp1,k);
  analogWrite(sp2,k);

 
  if(val=='1'){
    k=170;
  }
  else if(val=='2'){
    k=210;
  }
  else if(val=='3'){
    k=255;
  }
  else if(val=='0'){
    k=0;
  }

  if(val=='F'){
    front();
  }
  else if(val=='B'){
    back();
  }
  else if(val=='R'){
    right();
  }
  else if(val=='L'){
    left();
  }
  else if(val=='S'){
    stop();
  }

  if(val=='X' & i<180){
    i=i+10;
  }
  else if(val=='W' & i>0){
    i=i-10;
  }
  else if(val=='Y' & j<170){
    j=j+10;
  }
  else if(val=='Z' & j>0){
    j=j-10;
  }

    
}
