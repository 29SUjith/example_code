#include "Arduino.h"
#include "uRTCLib.h"
#include <LiquidCrystal_I2C.h>

// uRTCLib rtc;
uRTCLib rtc(0x68);
LiquidCrystal_I2C lcd(0x27,16,2);

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {
  Serial.begin(9600);
  lcd.begin();
  
  delay(3000); // wait for console opening

  URTCLIB_WIRE.begin();

  // Comment out below line once you set the date & time.
  // Following line sets the RTC with an explicit date & time
  // for example to set January 13 2022 at 12:56 you would call:
   rtc.set(0, 13, 12, 3, 29, 8, 23);
  // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // set day of week (1=Sunday, 7=Saturday)
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
  delay(5000);
  
}