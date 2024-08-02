#include <LiquidCrystal_I2C.h>


#include <DHT.h>
#include <DHT_U.h>

int sencePin=4;
DHT HT(sencePin,DHT11);
float humidity;
float tempC;
float tempF;
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
 HT.begin();
lcd.begin();
Serial.begin(9600);
//pinMode(sencePin,INPUT);
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
Serial.println(humidity);

}
