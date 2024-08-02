#include <LiquidCrystal_I2C.h>


#include <DHT.h>
#include <DHT_U.h>

int sencePin=4;
DHT HT(sencePin,DHT11);
float humidity;
float tempC;
float tempF;
int trigpin=45;
int echopin=44;
int pingtraveltime;

long duration;
int distance;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
 HT.begin();
lcd.begin();
lcd.backlight();
Serial.begin(9600);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
humidity=HT.readHumidity();
tempC=HT.readTemperature();


analogRead(sencePin);
lcd.setCursor(0,0);
lcd.print("T=");
lcd.print(tempC);
lcd.setCursor(0,1);
lcd.print("Humidity=");
lcd.print(humidity);

digitalWrite(trigpin,LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
duration=pulseIn(echopin,HIGH);
distance=duration*0.034/2;

Serial.print("distance=");
Serial.println(distance);
lcd.setCursor(10,0);
lcd.print(distance);
delay(1000);
}
