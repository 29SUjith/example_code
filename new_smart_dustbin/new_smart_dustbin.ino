#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int servopin=9;
Servo myservo;
int i=90;
int moisture;
int metal=12;
int led=13;
int metalv;
int ma1=3;
int ma2=4;

int trigPin=6;
int echoPin=7;
int pingTravelTime;
float pingTravelDistance;
float distance;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin();
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  myservo.attach(servopin);
  pinMode(metal,INPUT_PULLUP);
  pinMode(ma1,OUTPUT);
  pinMode(ma2,OUTPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  moisture=analogRead(A0);
  Serial.print("moisture=");
  Serial.println(moisture);

  metalv=digitalRead(metal);
  Serial.print("metal=");
  Serial.println(metalv);

  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  pingTravelTime=pulseIn(echoPin,HIGH);
  delay(25);
  pingTravelDistance=(pingTravelTime*765.*5280.*12)/(3600.*1000000);
  distance=pingTravelDistance/2;
  Serial.println(distance); 

    if(moisture<700){
      delay(1000);
      if(distance<2){
        digitalWrite(led,HIGH);
        myservo.write(180);
        Serial.println("wet waste");
        lcd.setCursor(0, 0);
        lcd.print("Wet   Waste");
        delay(2000);
        digitalWrite(ma1,HIGH);
        digitalWrite(ma2,LOW);
        delay(100);
        digitalWrite(ma1,LOW);
        digitalWrite(ma2,LOW);
        delay(2000);
        digitalWrite(ma2,HIGH);
        digitalWrite(ma1,LOW);
        delay(100);
        digitalWrite(ma1,LOW);
        digitalWrite(ma2,LOW);
        digitalWrite(led,LOW);
      }
    }

    if(metalv==0){    
        digitalWrite(led,HIGH);
        myservo.write(0);
        Serial.println("metal waste");
        lcd.setCursor(0, 0);
        lcd.print("metal Waste");
        delay(3000);
        digitalWrite(ma1,HIGH);
        digitalWrite(ma2,LOW);
        delay(100);
        digitalWrite(ma1,LOW);
        digitalWrite(ma2,LOW);
        delay(2000);
        digitalWrite(ma2,HIGH);
        digitalWrite(ma1,LOW);
        delay(100);
        digitalWrite(ma1,LOW);
        digitalWrite(ma2,LOW);
        digitalWrite(led,LOW);
      
    }


    else if(moisture>800){
      delay(000);
      if(distance<2){
        digitalWrite(led,HIGH);
        myservo.write(90);
        Serial.println("dry waste");
        lcd.setCursor(0, 0);
        lcd.print("Dry   Waste");
        delay(2000);
        digitalWrite(ma1,HIGH);
        digitalWrite(ma2,LOW);
        delay(100);
        digitalWrite(ma1,LOW);
        digitalWrite(ma2,LOW);
        delay(2000);
        digitalWrite(ma2,HIGH);
        digitalWrite(ma1,LOW);
        delay(100);
        digitalWrite(ma1,LOW);
        digitalWrite(ma2,LOW);
        digitalWrite(led,LOW);
       }
     }

}
