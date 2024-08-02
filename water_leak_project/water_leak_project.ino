#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int flowSensorPin1 = 2;
const int flowSensorPin2 = 3;
const int ledPin = 13;

volatile int pulseCount1 = 0;
volatile int pulseCount2 = 0;

float flowRate1 = 0;
float flowRate2 = 0;

unsigned long oldTime1 = 0;
unsigned long oldTime2 = 0;

int i;

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  Serial.begin(9600);

  pinMode(flowSensorPin1, INPUT);
  pinMode(flowSensorPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(flowSensorPin1, HIGH);
  digitalWrite(flowSensorPin2, HIGH);

  attachInterrupt(digitalPinToInterrupt(flowSensorPin1), pulseCounter1, FALLING);
  attachInterrupt(digitalPinToInterrupt(flowSensorPin2), pulseCounter2, FALLING);

  oldTime1 = millis();
  oldTime2 = millis();

  lcd.begin();
  
}

void loop() {
  if (millis() - oldTime1 > 1000) {
    detachInterrupt(digitalPinToInterrupt(flowSensorPin1));

    flowRate1 = (pulseCount1 / 7.5);

    pulseCount1 = 0;

    attachInterrupt(digitalPinToInterrupt(flowSensorPin1), pulseCounter1, FALLING);

    oldTime1 = millis();

    Serial.print("Flow Rate Sensor 1: ");
    Serial.print(flowRate1);
    Serial.println(" L/min");
  }

  if (millis() - oldTime2 > 1000) {
    detachInterrupt(digitalPinToInterrupt(flowSensorPin2));

    flowRate2 = (pulseCount2 / 7.5);

    pulseCount2 = 0;

    attachInterrupt(digitalPinToInterrupt(flowSensorPin2), pulseCounter2, FALLING);

    oldTime2 = millis();

    Serial.print("Flow Rate Sensor 2: ");
    Serial.print(flowRate2);
    Serial.println(" L/min");
  }

  i = flowRate2 - flowRate1;
  if (i > 2) {
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Leak Detected");
  } else {
    digitalWrite(ledPin, LOW);    
    lcd.setCursor(0, 0);
    lcd.print("    Normal   ");
  }
}

void pulseCounter1() {
  pulseCount1++;
}

void pulseCounter2() {
  pulseCount2++;
}
