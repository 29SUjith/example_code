#include <Servo.h>
char val;
int servopin1=3; //left and right
int servopin2=9; // up and down
int ma1=5;
int ma2=6;
int i=90;
int j=100;
int led=12;
Servo myservo1;
Servo myservo2;
int ldr1; //up
int ldr2; //right
int ldr3; //down
int ldr4; //left


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo1.attach(servopin1);
  myservo2.attach(servopin2);
  pinMode(ma1,OUTPUT);
  pinMode(ma2,OUTPUT);
  pinMode(led,OUTPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  val=Serial.read();
  Serial.println(val);

  myservo1.write(i); //max=150(left) and min=30(right) 90 standard
  myservo2.write(j); //max=130(up) and min=70(down) 100 standard


  ldr1=analogRead(A1);
  Serial.print("ldr1=");
  Serial.println(ldr1);

  ldr2=analogRead(A2);
  Serial.print("ldr2=");
  Serial.println(ldr2);

  ldr3=analogRead(A3);
  Serial.print("ldr3=");
  Serial.println(ldr3);

  ldr4=analogRead(A0);
  Serial.print("ldr4=");
  Serial.println(ldr4);

  if(val=='A'){
    digitalWrite(ma1,HIGH);
    digitalWrite(ma2,LOW);
  }
  else if(val=='B'){
    digitalWrite(ma1,LOW);
    digitalWrite(ma2,LOW);
  }
  else if(val=='D'){
    digitalWrite(led,LOW);
  }
  else if(val=='C'){
    digitalWrite(led,HIGH);
  }


  if(ldr2>ldr4 & ldr2>750 & i>30){
    i=i-2;
  }
  else if(ldr4>ldr2 & ldr4>750 & i<150){
    i=i+2;
  }
  else if(ldr1>ldr3 & ldr1>750 & j<130){
    j=j+2;
  }
  else if(ldr3>ldr1 & ldr3>750 & j>70){
    j=j-2;
  }

  delay(00);
}
