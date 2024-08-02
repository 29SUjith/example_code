#include <DHT.h>
#include <DHT_U.h>
#include <Servo.h>

int servopin=9;
Servo myservo;
char value;
int sencePin=4;
DHT HT(sencePin,DHT11);
float tempC;
float tempF;
int motorpin=12;
int ledpin=13;
int motionpin=2;
int motion;
int buzzer=11;
int gas=10;
int gass;


void setup() {
  // put your setup code here, to run once:
  HT.begin();
  Serial.begin(9600);
  myservo.attach(servopin);
  pinMode(motorpin,OUTPUT);
  pinMode(ledpin,OUTPUT);
  pinMode(motionpin,INPUT);
  pinMode(gas,INPUT);
  pinMode(buzzer,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  value=Serial.read();  
  motion=digitalRead(motionpin);
  gass=digitalRead(gas);

  tempC=HT.readTemperature();
  Serial.print('temperature');
  Serial.print(tempC);

  if(value=='A'){
    digitalWrite(ledpin,HIGH);
    Serial.println('light on');
  }

  else if(value=='B'){
    digitalWrite(ledpin,LOW);
    Serial.println('light off');
  }

  else if(value=='D'){
    digitalWrite(motorpin,LOW);
    Serial.println('motor off');
  }

  else if(value=='C'){
    digitalWrite(motorpin,HIGH);
    Serial.println('motor on');
  }

  if(motion==1){
    digitalWrite(ledpin,HIGH);
    myservo.write(90);
  }

  else if(motion==0){
    digitalWrite(ledpin,LOW);
    myservo.write(0);
  } 
  if(gass==0){
    Serial.println("Gas Detected");
    for(int i=1;i<=10;i++)
    {
    digitalWrite(buzzer, HIGH);
    delay(250);
    digitalWrite(buzzer, LOW);
    delay(250);
    }
  }
  else if(gass==1){
    digitalWrite(buzzer,LOW);
  }

  if(value=='V'){
    Serial.write('HELLO');
  }
  else if(value=='I'){
    Serial.write('hi');
  }
}
