/*
  Arduino FS-I6X Demo
  fsi6x-arduino-uno.ino
  Read output ports from FS-IA6B receiver module
  Display values on Serial Monitor
  
  Channel functions by Ricardo Paiva - https://gist.github.com/werneckpaiva/
  
  DroneBot Workshop 2021
  https://dronebotworkshop.com
*/
#include <Wire.h>

// Include Adafruit PWM Library
#include <Adafruit_PWMServoDriver.h>

#define MIN_PULSE_WIDTH       650
#define MAX_PULSE_WIDTH       2350
#define FREQUENCY             50

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Define Input Connections
#define CH1 3
#define CH2 5
#define CH3 6
#define CH4 9
#define CH5 13
#define CH6 10
 
// Integers to represent values from sticks and pots
int ch1Value;
int ch2Value;
int ch3Value;
int ch4Value; 
int ch5Value;
int speed1=11;
int ma1=12;
int ma2=8;
int mb1=7;
int mb2=2;
int light=13;

int controlA = ch1Value ;
int controlB = ch2Value;
int controlC = ch3Value;
int controlD = ch4Value;

int motorA = 0;
int motorB = 4;
int motorC = 8;
int motorD = 12;
 
// Boolean to represent switch value
bool ch6Value;
 
// Read the number of a specified channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}
 
// Read the switch channel and return a boolean value
bool readSwitch(byte channelInput, bool defaultValue){
  int intDefaultValue = (defaultValue)? 100: 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}
 
void setup(){
  // Set up serial monitor
  Serial.begin(115200);
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  
  // Set all pins as inputs
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
  pinMode(CH3, INPUT);
  pinMode(CH4, INPUT);
  pinMode(CH5, INPUT);
  pinMode(CH6, INPUT);

  pinMode(speed1,OUTPUT);
  pinMode(ma1,OUTPUT);
  pinMode(ma2,OUTPUT);
  pinMode(mb1,OUTPUT);
  pinMode(mb2,OUTPUT);
  pinMode(light,OUTPUT);
}
 
 
void loop() {
  ch6Value = readSwitch(CH6, false);
  Serial.print(" | Ch6: ");
  Serial.print(ch6Value);
  if(ch6Value==0){ 
    // Get values for each channel
    ch1Value = readChannel(CH1, -100, 100, 0);
    ch2Value = readChannel(CH2, -100, 100, 0);
    ch3Value = readChannel(CH3, 0, 257, 0);
    ch4Value = readChannel(CH4, -100, 100, 0);
    

    
    // Print to Serial Monitor
    Serial.print("Ch1: ");
    Serial.print(ch1Value);
    Serial.print(" | Ch2: ");
    Serial.print(ch2Value);
    Serial.print(" | Ch3: ");
    Serial.print(ch3Value);
    Serial.print(" | Ch4: ");
    Serial.println(ch4Value);

    

      if(ch1Value>20){
        analogWrite(speed1,255);
      
        digitalWrite(ma1,HIGH);
        digitalWrite(mb1,HIGH);
        digitalWrite(ma2,LOW);
        digitalWrite(mb2,LOW);
        Serial.println("Right");
      }
      else if(ch1Value<-20){
        analogWrite(speed1,255);
      
        digitalWrite(ma2,HIGH);
        digitalWrite(mb2,HIGH);
        digitalWrite(ma1,LOW);
        digitalWrite(mb1,LOW);
        Serial.println("Left");
      }

      else if(ch2Value<-20){
        analogWrite(speed1,ch3Value);
        
        digitalWrite(ma1,HIGH);
        digitalWrite(mb2,HIGH);
        digitalWrite(ma2,LOW);
        digitalWrite(mb1,LOW);
        Serial.println("Back");
      }

      else if(ch2Value>20){
        analogWrite(speed1,ch3Value);
        digitalWrite(light,HIGH);
        digitalWrite(ma2,HIGH);
        digitalWrite(mb1,HIGH);
        digitalWrite(ma1,LOW);
        digitalWrite(mb2,LOW);
        Serial.println("Front");
      }

      else if(ch2Value<20 && ch2Value>-20){
        analogWrite(speed1,0);
      
        digitalWrite(ma2,LOW);
        digitalWrite(mb1,LOW);
        digitalWrite(ma1,LOW);
        digitalWrite(mb2,LOW);
        Serial.println("off");
        digitalWrite(light,LOW);
      }      

      else if(ch4Value>20){
        digitalWrite(light,HIGH);
        Serial.println("hi");
      }

      else if(ch4Value<20){
        digitalWrite(light,LOW);
      }


    
    }

  if(ch6Value==1){
    ch1Value = readChannel(CH1, 500, 900, 600);
    ch2Value = readChannel(CH2, 700, 50, 512);
    ch3Value = readChannel(CH3, 900, 380, 702);
    ch4Value = readChannel(CH4, 0, 1023, 512);
    

    
    // Print to Serial Monitor
    Serial.print("Ch1: ");
    Serial.print(ch1Value);
    Serial.print(" | Ch2: ");
    Serial.print(ch2Value);
    Serial.print(" | Ch3: ");
    Serial.print(ch3Value);
    Serial.print(" | Ch4: ");
    Serial.println(ch4Value);









    //Control Motor A
    moveMotor(controlA, motorA, ch1Value);
    
    //Control Motor B
    moveMotor(controlB, motorB, ch2Value);
      
    //Control Motor C
    moveMotor(controlC, motorC, ch3Value);
    
    //Control Motor D
    moveMotor(controlD, motorD, ch4Value);


  }

  delay(100);
}

void moveMotor(int controlIn, int motorOut, int ch)
{
  int pulse_wide, pulse_width, potVal;
  
  // Read values from potentiometer

  
  // Convert to pulse width
  pulse_wide = map(ch, 0, 1023, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  
  //Control Motor
  pwm.setPWM(motorOut, 0, pulse_width);

}