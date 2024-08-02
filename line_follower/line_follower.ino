int m1a=2;
int m1b=3;
int m2a=4;
int m2b=5;
int ir1;//right
int ir2;
int ir3;//left
int ir4;
int sp1=9;
int sp2=10;
int speed=220;
int speed2=210;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(m1a,OUTPUT);
  pinMode(m1b,OUTPUT);
  pinMode(m2a,OUTPUT);
  pinMode(m2b,OUTPUT);
  pinMode(sp1,OUTPUT);
  pinMode(sp2,OUTPUT);
  pinMode(12,INPUT_PULLUP);
}

void front(){
  //front
  digitalWrite(m1a,HIGH);//left motor
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,LOW);//right motor
  digitalWrite(m2b,HIGH);
  analogWrite(sp1,speed);
  analogWrite(sp2,speed);
}
void stop(){
  //back
  digitalWrite(m1b,LOW);
  digitalWrite(m1a,LOW);
  digitalWrite(m2b,LOW);
  digitalWrite(m2a,LOW);
}
void right(){
  //right
  digitalWrite(m1a,HIGH);
  digitalWrite(m1b,LOW);
  digitalWrite(m2b,LOW);
  digitalWrite(m2a,HIGH);
  analogWrite(sp1,speed2);
  analogWrite(sp2,speed2);
}
void left(){
  //left
  digitalWrite(m1a,LOW);
  digitalWrite(m1b,HIGH);
  digitalWrite(m2b,HIGH);
  digitalWrite(m2a,LOW);
  analogWrite(sp1,speed2);
  analogWrite(sp2,speed2);
}


void loop() {
  // put your main code here, to run repeatedly:
  
  ir1=digitalRead(A0);
  ir2=digitalRead(A1);
  ir3=digitalRead(A2);
  ir4=digitalRead(A3);

  

  Serial.print("ir1= ");
  Serial.println(ir1);
  Serial.print("ir2= ");
  Serial.println(ir2);
  Serial.print("ir3= ");
  Serial.println(ir3);
  Serial.print("ir4= ");
  Serial.println(ir4);

  left();


  if(ir1==0 & ir2==0 & ir3==0 & ir4==0){
    front();
  }
  else if(ir4==1 | ir3==1){
    left();
  }

  else if(ir1==0 | ir2==1){
    right();
  }

  else {
    stop();
  }
  delay(30);
}
