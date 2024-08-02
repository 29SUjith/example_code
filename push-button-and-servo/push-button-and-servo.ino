#include <Servo.h>

const int buttonPinIncrease = 4; // Pin for increasing angle
const int buttonPinDecrease = 6; // Pin for decreasing angle
const int servoPin = 9;          // Pin for the servo motor
#include <LiquidCrystal_I2C.h>
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 2
LiquidCrystal_I2C lcd(0x27,16,2);

Servo myServo;
int angle = 90; // Initial angle
bool increaseButtonPressed = false;
bool decreaseButtonPressed = false;
int state1;
int state2;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(buttonPinIncrease, INPUT_PULLUP);
  pinMode(buttonPinDecrease, INPUT_PULLUP);
  lcd.begin();
  lcd.print("WELCOME");
}

void loop() {
   DHT.read(DHT11_PIN);
  lcd.setCursor(0,0);
  lcd.print("Temperature=");
  lcd.print(DHT.temperature);

if (DHT.temperature<45){
  if (digitalRead(buttonPinIncrease) == LOW) {
    if (!increaseButtonPressed) {
      increaseButtonPressed = true;
      angle += 20; // Increase angle by 15 degrees
      if (angle > 180) {
        angle = 180;
      }
      myServo.write(angle);
    }
  } else {
    increaseButtonPressed = false;
  }

  // Check if the decrease button is pressed
  if (digitalRead(buttonPinDecrease) == LOW) {
    if (!decreaseButtonPressed) {
      decreaseButtonPressed = true;
      angle -= 20; // Decrease angle by 15 degrees
      if (angle < 0) {
        angle = 0;
      }
      myServo.write(angle);
    }
  } else {
    decreaseButtonPressed = false;
  } 
  }


  Serial.println(DHT.temperature);
  state1=digitalRead(buttonPinIncrease);
  Serial.println(state1);
  state2=digitalRead(buttonPinDecrease);
  Serial.println(state2);
}


