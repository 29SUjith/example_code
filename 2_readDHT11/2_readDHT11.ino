#include <LiquidCrystal_I2C.h>

/*!
 * @file readDHT11.ino
 * @brief DHT11 is used to read the temperature and humidity of the current environment. 
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [Wuxiao](xiao.wu@dfrobot.com)
 * @version  V1.0
 * @date  2018-09-14
 * @url https://github.com/DFRobot/DFRobot_DHT11
 */

#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 10
//#include <LiquidCrystal_I2C.h>

 LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
  Serial.begin(9600);
 // lcd.begin();
 lcd.begin();
 
  lcd.backlight();
}

void loop(){
  DHT.read(DHT11_PIN);
  Serial.print("temp:");
  Serial.print(DHT.temperature);
  Serial.print("  humi:");
  Serial.println(DHT.humidity);
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("temp:");
  lcd.print(DHT.temperature);
  lcd.setCursor(0,1);
  lcd.print("humi:");
  lcd.print(DHT.humidity);
}
