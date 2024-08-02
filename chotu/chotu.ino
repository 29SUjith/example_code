#include <Servo.h>

int servopin1=8;
int sp1=90;
int servopin2=9;
int sp2=90;

Servo myservo1;
Servo myservo2;

int l1=22;
int l2=24;
int l3=26;
int l4=28;
int l5=30;
int l6=32;
int l7=34;
int l8=36;
int l9=38;
int l10=40;
char val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo1.attach(servopin1);
  myservo2.attach(servopin2);
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(l3,OUTPUT);
  pinMode(l4,OUTPUT);
  pinMode(l5,OUTPUT);
  pinMode(l6,OUTPUT);
  pinMode(l7,OUTPUT);
  pinMode(l8,OUTPUT);
  pinMode(l9,OUTPUT);
  pinMode(l10,OUTPUT);
}

void ledof(){
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(l3,LOW);
  digitalWrite(l4,LOW);
  digitalWrite(l5,LOW);
  digitalWrite(l6,LOW);
  digitalWrite(l7,LOW);
  digitalWrite(l8,LOW);
  digitalWrite(l9,LOW);
  digitalWrite(l10,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  val=Serial.read();
  Serial.println(val);

  myservo1.write(sp1);
  myservo2.write(sp2);

  Serial.println(sp1);
  Serial.println(sp2);

  if(val=='F'){ 
    digitalWrite(l2,HIGH);
    delay(5000);
  }
  else if(val=='B'){
    digitalWrite(l3,HIGH);
    delay(5000);
  }
  else if(val=='R'){
    digitalWrite(l4,HIGH);
    delay(5000);
  }
  else if(val=='L'){
    digitalWrite(l5,HIGH);
    delay(5000);
  }
  else if(val=='S'){
    digitalWrite(l6,HIGH);
    delay(5000);
  }
  else if(val=='1'){
    digitalWrite(l1,HIGH);
    delay(5000);
  }
  else if(val=='2'){
    sp1=sp1+1;
  }
  else if(val=='3'){
    sp1=sp1-1;
  }
  else if(val=='4'){
    sp2=sp2+1;
  }
  else if(val=='5'){
    sp2=sp2-1;
  }
  else{
    ledof();
  }
  delay(400);
}
