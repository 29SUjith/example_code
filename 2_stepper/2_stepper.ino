#include <AccelStepper.h>
#include "I2Cdev.h"
#include "MPU6050.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

#define OUTPUT_READABLE_ACCELGYRO

AccelStepper stepper1(AccelStepper::DRIVER, 3, 2);  //StepPin D2 and DirPin D3
AccelStepper stepper2(AccelStepper::DRIVER, 5, 4);  //StepPin D4 and DirPin D5

void setup()
{  
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
      Wire.begin();
  #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
      Fastwire::setup(400, true);
  #endif

  Serial.begin(9600);

  // initialize device
  Serial.println("Initializing I2C devices...");
  //accelgyro.initialize();

  // verify connection
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");


  stepper1.setMaxSpeed(400);
  stepper1.setSpeed(0);    
  stepper2.setMaxSpeed(400);
  stepper2.setSpeed(0);

}

void loop()
{  
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

  if(ay<-4000){
    //stepper1.setMaxSpeed(400);
    stepper1.setSpeed(-200);   
    //stepper2.setMaxSpeed(400);
    stepper2.setSpeed(-200);
  }
  else if(ay>1000){
    //stepper1.setMaxSpeed(400);
    stepper1.setSpeed(300);   
    //stepper2.setMaxSpeed(400);
    stepper2.setSpeed(300);
  }
  else{
    stepper1.setMaxSpeed(400);
    stepper1.setSpeed(0);    
    stepper2.setMaxSpeed(400);
    stepper2.setSpeed(0);

  }
  stepper1.runSpeed();
  stepper2.runSpeed();
  delay(00);
}