#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

float voltage;
int sensorvalue;
int led=2;

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorvalue=analogRead(A0);
  voltage=sensorvalue*(5.0/1023.00);
  Serial.println(sensorvalue);

  lcd.setCursor(0,0);
  lcd.print("voltage=");
  lcd.setCursor(9,0);
  lcd.print(voltage);
  lcd.setCursor(13,0);
  lcd.print("V");

  if(voltage>=3){
    digitalWrite(led,HIGH);
    delay(1000);
  }
  else{
    digitalWrite(led,LOW);
  }
  delay(100);
}
