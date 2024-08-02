#include <LiquidCrystal_I2C.h>





#include <DHT.h>
#include <DHT_U.h>

int sencePin=7;
DHT HT(sencePin,DHT11);
float humidity;
float tempC;
float tempF;
LiquidCrystal_I2C lcd(0x27,16,2);

int trigPin=6;
int echoPin=5;
int pingTravelTime;
float pingTravelDistance;
float distanceToTarget;


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
 HT.begin();
lcd.begin();
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
humidity=HT.readHumidity();
tempC=HT.readTemperature();
tempF=HT.readTemperature(true);

lcd.setCursor(0,0);
lcd.print("T=");
lcd.print(tempC);
lcd.setCursor(0,1);
lcd.print("H=");
lcd.print(humidity);
delay(1000);

digitalWrite(trigPin,LOW);
delayMicroseconds(10);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
pingTravelTime=pulseIn(echoPin,HIGH);
delay(25);
pingTravelDistance=(pingTravelTime*765.*5280.*12)/(3600.*1000000);
distanceToTarget=pingTravelDistance/2;
Serial.println(distanceToTarget); 

lcd.setCursor(9,0);
lcd.print(distanceToTarget);
delay(100);


Serial.print("h=");
Serial.println(humidity);
Serial.print("Temperature=");
Serial.println(tempC);
delay(100);
}
