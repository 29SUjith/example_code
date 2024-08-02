#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
char val;
String input = "";
int total=0;

const int sp = 13; // LED connected to digital pin 13
int sps;
int ledPin=12;
const String rfidTag1 = "550018B553AB";
const String rfidTag2 = "3A00C3F88786"; // RFID tag to detect 
const String rfidTag3 = "550019237B14";

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  
  pinMode(sp, INPUT_PULLUP);
  pinMode(ledPin,OUTPUT);
  
  
  lcd.setCursor(0, 0);
  lcd.print("RFID Reader");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan a Tag");
}

void loop() {
  sps=digitalRead(sp);
  Serial.println(sps);
  if(sps==1){
    total=0000;
  }

  if (Serial.available()) {
    val = Serial.read();
    if (val != '\n' && val != '\r') {
      input += val;
    }
    
    // Once a full RFID string is received
    if (input.length() >= 12) {
      lcd.clear();

      if (input == rfidTag1) {
        digitalWrite(ledPin, HIGH); // Turn on the LED
        lcd.setCursor(0, 0);
        lcd.print("TEA");
        total=total+100;
        lcd.setCursor(0,1);
        lcd.print("Amount=");
        lcd.setCursor(8,1);
        lcd.print("100");

      } 

      else if (input == rfidTag2) {
        digitalWrite(ledPin, HIGH); // Turn on the LED
        lcd.setCursor(0, 0);
        lcd.print("MILK");
        total=total+50;
        lcd.setCursor(0,1);
        lcd.print("Amount=");
        lcd.setCursor(8,1);
        lcd.print("50");

      } 

      else if (input == rfidTag3) {
        digitalWrite(ledPin, HIGH); // Turn on the LED
        lcd.setCursor(0, 0);
        lcd.print("BREAD");
        total=total+150;
        lcd.setCursor(0,1);
        lcd.print("Amount=");
        lcd.setCursor(8,1);
        lcd.print("150");

      } 

      else {
        digitalWrite(ledPin, LOW); // Turn off the LED
        lcd.setCursor(0, 1);
        lcd.print("Unknown Tag");
      }
      
      delay(1000); // Display the message for 2 seconds
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Scan a Tag");

      
      input = ""; // Clear the input for the next reading
    }
  }
      lcd.setCursor(0,1);
      lcd.print("TOTAL=");
      lcd.setCursor(7,1);
      lcd.print(total);
}
