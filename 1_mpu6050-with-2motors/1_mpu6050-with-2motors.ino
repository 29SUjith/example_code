#include "I2Cdev.h"
#include "MPU6050.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

#define OUTPUT_READABLE_ACCELGYRO

int motorpin1=5;
int motorpin2=6;
int motorpin3=7;
int motorpin4=8;


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
   
}

void loop() {
    // read raw accel/gyro measurements from device
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    #ifdef OUTPUT_READABLE_ACCELGYRO
        // display tab-separated accel/gyro x/y/z values
        Serial.print("a/g:\t");
        Serial.print(ax); Serial.print("\t");
        Serial.print(ay); Serial.println("\t");
        /*Serial.print(az); Serial.print("\t");
        Serial.print(gx); Serial.print("\t");
        Serial.print(gy); Serial.print("\t");
        Serial.println(gz);*/
    #endif

    if(ax>12000){
      digitalWrite(motorpin1,HIGH);
      digitalWrite(motorpin2,LOW);
      digitalWrite(motorpin3,LOW); 
      digitalWrite(motorpin4,LOW);
    }
    else if(ax<12000 && ax>-12000){
      digitalWrite(motorpin1,LOW);
      digitalWrite(motorpin2,LOW);
    }

      if(ax<-12000){
      digitalWrite(motorpin1,LOW);
      digitalWrite(motorpin2,HIGH);
      digitalWrite(motorpin3,LOW); 
      digitalWrite(motorpin4,LOW);
    }

    
     if(ay>12000){
      digitalWrite(motorpin1,LOW);
      digitalWrite(motorpin2,LOW);
      digitalWrite(motorpin3,HIGH); 
      digitalWrite(motorpin4,LOW);
    }
    else if(ay<12000 && ay>-12000){
      digitalWrite(motorpin3,LOW); 
      digitalWrite(motorpin4,LOW);
    }

      if(ay<-12000){
      digitalWrite(motorpin1,LOW);
      digitalWrite(motorpin2,LOW);
      digitalWrite(motorpin3,LOW); 
      digitalWrite(motorpin4,HIGH);
    }
}