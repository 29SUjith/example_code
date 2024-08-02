#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int buzzer=13;
int ma1=12;
int ma2=11;
int mb1=9;
int mb2=10;
char v1;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin();
lcd.backlight();
pinMode(buzzer,OUTPUT);
pinMode(ma1,OUTPUT);
pinMode(ma2,OUTPUT);
pinMode(mb1,OUTPUT);
pinMode(mb2,OUTPUT);
lcd.setCursor(0,0);
lcd.print("HI");
lcd.setCursor(0,1);
lcd.print("STORM HERE");
}

void loop() {
 // put your main code here, to run repeatedly:
v1=Serial.read();
Serial.println(v1);
delay(300);
if(v1=='1'){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("READY");
}


//back
if(v1=='B'){
  digitalWrite(ma1,HIGH);
  digitalWrite(mb1,HIGH);
  digitalWrite(ma2,LOW);
  digitalWrite(mb2,LOW);
  lcd.clear();
  lcd.print("BACK");
}


//Front
else if(v1=='F'){
  digitalWrite(ma2,HIGH);
  digitalWrite(mb2,HIGH);
  digitalWrite(ma1,LOW);
  digitalWrite(mb1,LOW);
  lcd.clear();
  lcd.print("FRONT");
}

//Right
else if(v1=='R'){
  digitalWrite(ma2,HIGH);
  digitalWrite(mb1,HIGH);
  digitalWrite(ma1,LOW);
  digitalWrite(mb2,LOW);
  lcd.clear();
  lcd.print("RIGHT");
}

//Left
else if(v1=='L'){
  digitalWrite(ma1,HIGH);
  digitalWrite(mb2,HIGH);
  digitalWrite(ma2,LOW);
  digitalWrite(mb1,LOW);
  lcd.clear();
  lcd.print("LEFT");
}

else if(v1=='S'){
  digitalWrite(ma1,LOW);
  digitalWrite(mb2,LOW);
  digitalWrite(ma2,LOW);
  digitalWrite(mb1,LOW);
  lcd.clear();
  lcd.print("STOP");

}
else if(v1=='2'){
  digitalWrite(buzzer,HIGH);
}

else if(v1=='3'){
  digitalWrite(buzzer,LOW);
}
}
