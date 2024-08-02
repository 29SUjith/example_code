#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int servopin=9;
int i=90;
int servoposition=i;
int sw1=13;
int sw1s;
int moisturev;
Servo myservo;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sw1,INPUT_PULLUP);
  myservo.attach(servopin);
  lcd.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  sw1s=digitalRead(sw1);
  Serial.println(sw1s);
  moisturev=analogRead(A0);
  Serial.print("moisture=");
  Serial.println(moisturev);
  lcd.setCursor(0,0);
  lcd.print("Smart Bin");
  lcd.setCursor(0,1);
  lcd.print("Type=");
  myservo.write(i);

  if(sw1s==0){
    i=0;
    
    lcd.setCursor(5,1);
    lcd.print("metal Waste");
    delay(2000);
  }

  else if(moisturev<=990){
    i=180;
    
    lcd.setCursor(5,1);
    lcd.print("Wet   Waste");
    delay(2000);
  }
  else{
    i=90;
    lcd.setCursor(5,1);
    lcd.print("Dry   Waste");
  }

  //delay(100);
  
}
