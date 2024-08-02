#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

Adafruit_BMP085 bmp;
RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int counter;
const int buzzer = 13;//13

void setup() {
  Serial.begin(9600);
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP180 sensor, check wiring!");
  }
  lcd.begin();
  lcd.backlight();
  Wire.begin();
  rtc.begin();
  pinMode(2, INPUT); // Assuming gas sensor connected to pin 2
  pinMode(buzzer, OUTPUT); // Set buzzer pin as OUTPUT
}

void loop() {
  if (counter <= 2) {
    // Reading from BMP180 sensor
    float temperature = bmp.readTemperature();
    float pressure = bmp.readPressure() / 100.0F;

    lcd.clear();
    lcd.print("T: ");
    lcd.print(temperature);
    lcd.print(" *C");

    Serial.print("C");
    Serial.print(temperature);
    Serial.print(",");

    lcd.setCursor(0, 1);
    lcd.print("P: ");
    lcd.print(pressure);
    lcd.print(" hPa");

    Serial.print("P");
    Serial.println(pressure);

    delay(1000); // Delay between readings
  }/* else if (counter < 5) {
    // Reading from RTC
    DateTime now = rtc.now();

    lcd.clear();
    lcd.print(now.day());
    lcd.print('/');
    lcd.print(now.month());
    lcd.print('/');
    lcd.print(now.year());

    lcd.setCursor(0, 1);

    lcd.print(now.hour());
    lcd.print(':');
    lcd.print(now.minute());
    lcd.print(':');
    lcd.print(now.second());

   /* Serial.print("T");
    Serial.print(now.hour());
    Serial.print(":");
    Serial.print(now.minute());
    Serial.print(":");
    Serial.println(now.second());

    delay(1000);
  } */else {
    counter = 0;
  }
  counter++;

  if (!digitalRead(0)) {
    // Gas detected
    Serial.println("G");
    lcd.clear();
    lcd.print("Gas Detected");

    Serial.println("Gas Detected");
    for(int i=1;i<=10;i++)
    {
    digitalWrite(buzzer, HIGH);
    delay(250);
    digitalWrite(buzzer, LOW);
    delay(250);
    }
  }
}