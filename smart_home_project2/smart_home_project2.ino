#include <Servo.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <Wire.h>
#include <Adafruit_GFX.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);

int servopin=9;
Servo myservo;
int motionpin=A0;
int motion;
int mledpin=3;
int buzzer=11;
int gas=10;
int gass;
char value;
int motorpin=4;
int motorpin2=5;
int ledpin=13;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP180 sensor, check wiring!");
  }
  Wire.begin();
  myservo.attach(servopin);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  display.clearDisplay();
  pinMode(motionpin,INPUT);
  pinMode(mledpin,OUTPUT);
  pinMode(gas,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(motorpin,OUTPUT);
  pinMode(motorpin2,OUTPUT);
  pinMode(ledpin,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  value=Serial.read();
  motion=analogRead(motionpin);

  float temperature = bmp.readTemperature();
  Serial.println(temperature);

  gass=digitalRead(gas);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(temperature);
  display.display();

  if(value=='A'){
    digitalWrite(ledpin,HIGH);
  }
  else if(value=='B'){
    digitalWrite(ledpin,LOW);
  }
  else if(value=='C' || temperature>28){
    digitalWrite(motorpin,HIGH);
    digitalWrite(motorpin2,LOW);
  }
  else if(value=='D'){
    digitalWrite(motorpin,LOW);
    digitalWrite(motorpin2,LOW);
  }

  if(motion>300){
    myservo.write(90);
    digitalWrite(mledpin,HIGH);
  }
  else if(motion<100){
    myservo.write(0);
    digitalWrite(mledpin,LOW);
  }
  else if(gass==1){
    for(int i=1;i<=10;i++)
    {
    digitalWrite(buzzer, HIGH);
    delay(250);
    digitalWrite(buzzer, LOW);
    delay(250);
    }
  }
  else if(gass==0){
    digitalWrite(buzzer,LOW);
  }

  delay(200);

}
