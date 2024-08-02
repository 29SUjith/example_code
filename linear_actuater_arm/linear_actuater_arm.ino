#include "I2Cdev.h"
#include "MPU6050.h"
#include <Adafruit_PWMServoDriver.h>
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <Adafruit_GFX.h>

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;

#define OUTPUT_READABLE_ACCELGYRO

#define MIN_PULSE_WIDTH       650
#define MAX_PULSE_WIDTH       2350
#define FREQUENCY             50
#define i               1000
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_I2C_ADDR 0x3C // or 0x3C

#define OLED_RST_PIN -1   
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_I2C_ADDR 0x3C // or 0x3C

#define OLED_RST_PIN -1   

Adafruit_SSD1306 display(128, 64, &Wire, OLED_RST_PIN);

int led1=11; //RED
int led2=10; //GREEN
int led3=9;  //BLUE

int fae1 = A0;
int fae2 = A1;
int fa1 = A2;
int fa2 = A3;
int gp = A7;

int fae1v;
int fae2v;
int fa1v;
int fa2v;
int gpv;

int motorA = 12;
int motorB = 1;
int motorC = 2;
int motorD = 11;
int motorE = 14;
int motorF = 5;

int s1=2;
int s2=3;
int s3=4;
int s4=5;
int s5=6;
int s6=7;
int s1s;
int s2s;
int s3s;
int s4s;
int s5s;
int s6s;


void setup() {
    pwm.begin();
    pwm.setPWMFreq(FREQUENCY);

    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

  Serial.begin(9600);

   pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);
   pinMode(led3,OUTPUT);
   pinMode(fae1,INPUT);
   pinMode(fae2,INPUT); 
   pinMode(fa1,INPUT);
   pinMode(fa2,INPUT);
   pinMode(s1,INPUT_PULLUP);
   pinMode(s2,INPUT_PULLUP);
   pinMode(s3,INPUT_PULLUP);
   pinMode(s4,INPUT_PULLUP);
   pinMode(s5,INPUT_PULLUP);
   pinMode(s6,INPUT_PULLUP);

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    // initialize device
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

}

void moveMotor(int potvalue, int motorOut)
{
  int pulse_wide, pulse_width, potVal;
  pulse_wide = map(potvalue, 0, 1023, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096); 
  //Control Motor
  pwm.setPWM(motorOut, 0, pulse_width);
}

void moveMotors(int motorOut)
{
  int pulse_wide, pulse_width, potVal1;
  potVal1 = 508;  
  pulse_wide = map(potVal1,0,1023, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096); 
  //Control Motor
  pwm.setPWM(motorOut, 0, pulse_width);
}

void moveMotor180(int motorOut)
{
  int pulse_wide, pulse_width, potVala;
  // Read values from potentiometer
  gpv = analogRead(gp);
  pulse_wide = map(gpv,0,1023, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  pulse_width = int(float(pulse_wide) / 1000000 * 50 * 4096);
  pwm.setPWM(motorOut, 0, pulse_width);
}

void loop() {
    // read raw accel/gyro measurements from device
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);


    #ifdef OUTPUT_READABLE_ACCELGYRO
        // display tab-separated accel/gyro x/y/z values
        Serial.print("a/g:\t");
        Serial.print(ax); Serial.print("\t");
        Serial.print(ay); Serial.println("\t");
    #endif

   moveMotor180(motorA);

  s1s=digitalRead(s1);
  Serial.print("s1s=");
  Serial.println(s1s);

  s2s=digitalRead(s2);
  Serial.print("s2s=");
  Serial.println(s2s);

  s3s=digitalRead(s3);
  Serial.print("s3s=");
  Serial.println(s3s);

  s4s=digitalRead(s4);
  Serial.print("s4s=");
  Serial.println(s4s);

  s5s=digitalRead(s5);
  Serial.print("s5s=");
  Serial.println(s5s);//right

  s6s=digitalRead(s6);
  Serial.print("s6s=");
  Serial.println(s6s);//left

  fae1v=analogRead(fae1);
  Serial.print("fae1v=");
  Serial.println(fae1v);

  fae2v=analogRead(fae2);
  Serial.print("fae2v=");
  Serial.println(fae2v);

  fa1v=analogRead(fa1);
  Serial.print("fa1v=");
  Serial.println(fa1v);

  fa2v=analogRead(fa2);
  Serial.print("fa2v=");
  Serial.println(fa2v);

  gpv=analogRead(gp);
  Serial.print("gpv=");
  Serial.println(gpv);


  if(ay<-10000 && fa1v<842){
    moveMotor(0,motorB);
    analogWrite(led3,253);
    analogWrite(led2,0);
    analogWrite(led1,0);
  }
  else if(ay>10000 && fa1v>250){
    moveMotor(1023,motorB);
    analogWrite(led3,0);
    analogWrite(led2,255);
    analogWrite(led1,0);
  }
  else if(10000>ax>-10000 && 10000>ay>-10000  ){
    moveMotors(motorB);
    moveMotors(motorC);
    analogWrite(led3,0);
    analogWrite(led2,0);
    analogWrite(led1,250);
  }


  if(ax>10000 && fa2v>40){
    moveMotor(0,motorC);
    analogWrite(led3,243);
    analogWrite(led2,32);
    analogWrite(led1,130);//pink
  }
  else if(ax<-10000 && fa2v<970 ){
    moveMotor(1023,motorC);
    analogWrite(led3,20);
    analogWrite(led2,255);
    analogWrite(led1,203);//yellow
  }

  if(s1s==0 && fae2v<1023){
    moveMotor(0,motorD);
  }

  else if(s2s==0 && fae2v>12){
    moveMotor(1023,motorD);
  }

  else if(s3s==0 && fae1v<1023){
    moveMotor(0,motorE);//exp2

  }

  else if(s4s==0 && fae1v>5){
    moveMotor(1023,motorE);
  }

  else if(s6s==0){
    moveMotor(380,motorF);//left
  }

  else if(s5s==0){
    moveMotor(600,motorF);//right
  }

  else{
    moveMotors(motorF);
    moveMotors(motorD);
    moveMotors(motorE);

  } 



  
  delay(300);
}
