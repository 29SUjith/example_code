#include "I2Cdev.h"
#include "MPU6050.h"
#include <Servo.h>

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

#define OUTPUT_READABLE_ACCELGYRO

int motorpin1=7;
int motorpin2=6;
int motorpin3=5;
int motorpin4=4;
int motorpin5=8;
int motorpin6=12;
int speedpin=11;
int switch1=A0;
int switch2=A1;
int switch3=A2;
int switch4=A3;
int buttonstate1;
int buttonstate2;
int buttonstate3;
int buttonstate4;
int buttonstate5;
int speed1=255;
int speed2=100;
int servopin=9;
int servoposition=90;
int switch5=3;
Servo myservo;
int joystickpin=A6;
int joyvalue;

void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    Serial.begin(9600);

    // initialize device
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

    pinMode(motorpin1,OUTPUT);
    pinMode(motorpin2,OUTPUT);
    pinMode(motorpin3,OUTPUT);
    pinMode(motorpin4,OUTPUT);
    pinMode(motorpin5,OUTPUT);
    pinMode(motorpin6,OUTPUT);
    pinMode(switch1,INPUT_PULLUP);
    pinMode(switch2,INPUT_PULLUP);
    pinMode(switch3,INPUT_PULLUP);
    pinMode(switch4,INPUT_PULLUP);
    pinMode(switch5,INPUT_PULLUP);
    pinMode(joystickpin,INPUT_PULLUP);
    pinMode(speedpin,OUTPUT);
    myservo.attach(servopin);
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

  if((ax<18000 && ax>5000) || (ax>-18000 && ax<-5000)){
     buttonstate1=digitalRead(switch1);
     Serial.println(buttonstate1);
     if(buttonstate1==LOW){
       digitalWrite(motorpin1,LOW);     
     }
     else if(ax>12000){
       digitalWrite(motorpin1,HIGH);
       digitalWrite(motorpin2,LOW);
     }
     else{
        digitalWrite(motorpin1,LOW);
     } 


     buttonstate4=digitalRead(switch4);
     Serial.println(buttonstate4);
     if(buttonstate4==LOW){
       digitalWrite(motorpin4,LOW);
     }
     else if(ax>12000){
       digitalWrite(motorpin3,LOW);
       digitalWrite(motorpin4,HIGH);
       analogWrite(speedpin,speed1);
     }
    else{ 
       digitalWrite(motorpin4,LOW);
     }

     



   buttonstate2=digitalRead(switch2);
     Serial.println(buttonstate2);
     if(buttonstate2==LOW){
       digitalWrite(motorpin2,LOW);
     }
     else if(ax<-12000){
       digitalWrite(motorpin1,LOW);
       digitalWrite(motorpin2,HIGH);
     }
    else{ 
       digitalWrite(motorpin2,LOW);
     }
     

   buttonstate3=digitalRead(switch3);
     Serial.println(buttonstate3);
     if(buttonstate3==LOW){
       digitalWrite(motorpin3,LOW);
     }
     else if(ax<-12000){
       digitalWrite(motorpin4,LOW);
       digitalWrite(motorpin3,HIGH);
       analogWrite(speedpin,speed1);
     }
    else{ 
       digitalWrite(motorpin3,LOW);
     }
     }
     
     




else if((ay<18000 && ay>5000) || (ay>-18000 && ay<-5000)){
buttonstate1=digitalRead(switch1);
     Serial.println(buttonstate1);
     if(buttonstate1==LOW){
       digitalWrite(motorpin1,LOW);     
     }
     else if(ay>12000){
       digitalWrite(motorpin1,HIGH);
       digitalWrite(motorpin2,LOW);
     }
     else{
        digitalWrite(motorpin1,LOW);
     } 

     buttonstate4=digitalRead(switch4);
     Serial.println(buttonstate4);
     if(buttonstate4==LOW){
       digitalWrite(motorpin4,LOW);
     }
     else if(ay>12000){
       digitalWrite(motorpin3,LOW);
       digitalWrite(motorpin4,HIGH);
       analogWrite(speedpin,speed2);
     }
    else{ 
       digitalWrite(motorpin4,LOW);
     }
     



   buttonstate2=digitalRead(switch2);
     Serial.println(buttonstate2);
     if(buttonstate2==LOW){
       digitalWrite(motorpin2,LOW);
     }
     else if(ay<-12000){
       digitalWrite(motorpin1,LOW);
       digitalWrite(motorpin2,HIGH);
     }
    else{ 
       digitalWrite(motorpin2,LOW);
     }
     

   buttonstate3=digitalRead(switch3);
     Serial.println(buttonstate3);
     if(buttonstate3==LOW){
       digitalWrite(motorpin3,LOW);
     }
     else if(ay<-12000){
       digitalWrite(motorpin4,LOW);
       digitalWrite(motorpin3,HIGH);
       analogWrite(speedpin,speed2);
     }
    else{ 
       digitalWrite(motorpin3,LOW);
     }}


     else{
       digitalWrite(motorpin1,LOW);
       digitalWrite(motorpin2,LOW);
       digitalWrite(motorpin3,LOW);
       digitalWrite(motorpin4,LOW);
     }


     buttonstate5=digitalRead(switch5);
     Serial.println(buttonstate5);
      if(buttonstate5==LOW){
       myservo.write(90);
      }
      else if(buttonstate5==HIGH){
        myservo.write(0);
      }

      joyvalue=analogRead(joystickpin);
      Serial.println(joyvalue);

      if(joyvalue<500 && joyvalue>200){
        digitalWrite(motorpin5,HIGH);
        digitalWrite(motorpin6,LOW);
        
      }
      else if(joyvalue>700 && joyvalue<970){
        digitalWrite(motorpin5,LOW);
        digitalWrite(motorpin6,HIGH);
      }
      else{
        digitalWrite(motorpin5,LOW);
        digitalWrite(motorpin6,LOW);
      }
      
     
    delay(300);
}

