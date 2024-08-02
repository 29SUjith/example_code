#include "Arduino.h"
#include "uRTCLib.h"
#include <LiquidCrystal_I2C.h>

// uRTCLib rtc;
uRTCLib rtc(0x68);
LiquidCrystal_I2C lcd(0x27,16,2);
int ldr1=A0;
int ldr2=A1;
int ldr3=A2;
int read1;
int read2;
int read3;
int ledpin1=11;
int ledpin2=10;
int ledpin3=9;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {
  Serial.begin(9600);
  lcd.begin();
  
  delay(3000); // wait for console opening

  URTCLIB_WIRE.begin();

  // Comment out below line once you set the date & time.
  // Following line sets the RTC with an explicit date & time
  // for example to set January 13 2022 at 12:56 you would call:
   rtc.set(0, 25, 15, 4, 11, 10, 23);
  // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // set day of week (1=Sunday, 7=Saturday)
  Serial.begin(9600);
pinMode(ledpin1,OUTPUT);
pinMode(A0,INPUT);
pinMode(ledpin2,OUTPUT);
pinMode(A1,INPUT);
pinMode(ledpin3,OUTPUT);
pinMode(A2,INPUT);
}

void loop() {

lcd.setCursor(0,0);
lcd.print(rtc.hour());
lcd.setCursor(2,0);
lcd.print(":");
lcd.setCursor(3,0);
lcd.print(rtc.minute());
lcd.setCursor(5,0);
lcd.print(":");
lcd.setCursor(6,0);
lcd.print(rtc.second());

lcd.setCursor(0,1);
lcd.print(rtc.day());
lcd.setCursor(2,1);
lcd.print("/");
lcd.setCursor(3,1);
lcd.print(rtc.month());
lcd.setCursor(5,1);
lcd.print("/");
lcd.setCursor(6,1);
lcd.print(rtc.year());



  rtc.refresh();

  Serial.print("Current Date & Time: ");
  Serial.print(rtc.year());
  Serial.print('/');
  Serial.print(rtc.month());
  Serial.print('/');
  Serial.print(rtc.day());

  Serial.print(" (");
  Serial.print(daysOfTheWeek[rtc.dayOfWeek()-1]);
  Serial.print(") ");

  Serial.print(rtc.hour());
  Serial.print(':');
  Serial.print(rtc.minute());
  Serial.print(':');
  Serial.println(rtc.second());

  Serial.print("Temperature: ");
  Serial.print(rtc.temp()  / 100);
  Serial.print("\xC2\xB0");   //shows degrees character
  Serial.println("C");

  Serial.println();
  delay(500);



  read1=analogRead(ldr1);
Serial.println(read1);

read2=analogRead(ldr2);
Serial.println(read2);

read3=analogRead(ldr3);
Serial.println(read3);
delay(500);

if(read1>800){
 analogWrite(ledpin1,255);
}
else if(read1>600){
  analogWrite(ledpin1,190);
}
else if(read1>500){
  analogWrite(ledpin1,150);
}
else{
  digitalWrite(ledpin1,LOW);

}


if(read2>800){
 analogWrite(ledpin2,255);
}
else if(read2>600){
  analogWrite(ledpin1,190);
}
else if(read2>500){
  analogWrite(ledpin2,150);
}
else{
  digitalWrite(ledpin2,LOW);

}



if(read3>800){
 analogWrite(ledpin3,255);
}
else if(read3>600){
  analogWrite(ledpin3,190);
}
else if(read3>500){
  analogWrite(ledpin3,150);
}
else{
  digitalWrite(ledpin3,LOW);

}
}