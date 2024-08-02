

char value;
int i=120;
int speed1=11;
int speed2=10;
int ma1=12;
int ma2=8;
int mb1=7;
int mb2=2;
int light=13;



void setup(){
Serial.begin(9600);
pinMode(speed1,OUTPUT);
pinMode(speed2,OUTPUT);
pinMode(ma1,OUTPUT);
pinMode(ma2,OUTPUT);
pinMode(mb1,OUTPUT);
pinMode(mb2,OUTPUT);
pinMode(light,OUTPUT);
digitalWrite(light,LOW);
}

void loop(){
value=Serial.read();
Serial.println(value);

if(value=='1'){
  i=120;
}
else if(value=='2'){
  i=180;
}
else if(value=='3'){
  i=210;
}
else if(value=='0'){
  i=0;
}
else if(value=='4'){
  i=255;
}
Serial.println(i);

if(value=='R'){
  analogWrite(speed1,255);
  analogWrite(speed2,255);
  digitalWrite(ma1,HIGH);
  digitalWrite(mb1,HIGH);
  digitalWrite(ma2,LOW);
  digitalWrite(mb2,LOW);
  Serial.println("Right");
}
else if(value=='L'){
  analogWrite(speed1,255);
  analogWrite(speed2,255);
  digitalWrite(ma2,HIGH);
  digitalWrite(mb2,HIGH);
  digitalWrite(ma1,LOW);
  digitalWrite(mb1,LOW);
  Serial.println("Left");
}

else if(value=='B'){
  analogWrite(speed1,i);
  analogWrite(speed2,i);
  digitalWrite(ma1,HIGH);
  digitalWrite(mb2,HIGH);
  digitalWrite(ma2,LOW);
  digitalWrite(mb1,LOW);
  Serial.println("Back");
}

else if(value=='F'){
  analogWrite(speed1,i);
  analogWrite(speed2,i);
  digitalWrite(ma2,HIGH);
  digitalWrite(mb1,HIGH);
  digitalWrite(ma1,LOW);
  digitalWrite(mb2,LOW);
  Serial.println("Front");
}

else if(value=='W'){
  digitalWrite(light,HIGH);
}
else if(value=='A'){
  digitalWrite(light,LOW);
}


else if(value=='S'){
  analogWrite(speed1,i);
  analogWrite(speed2,i);
  digitalWrite(ma2,LOW);
  digitalWrite(mb1,LOW);
  digitalWrite(ma1,LOW);
  digitalWrite(mb2,LOW);
  Serial.println("off");
}


delay(500);
}