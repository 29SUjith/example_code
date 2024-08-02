int ms1=10;
int ma1=11;
int ma2=12;
int ms2=9;
int mb2=8;
int mb1=7;
int speed1=255;
int speed2=255;

void setup() {
  // put your setup code here, to run once:
pinMode(ms1,INPUT);
pinMode(ma1,INPUT);
pinMode(ma2,INPUT);
pinMode(ms2,INPUT);
pinMode(mb1,INPUT);
pinMode(mb2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(ms1,speed1);
analogWrite(ms2,speed2);
digitalWrite(ma1,HIGH);
digitalWrite(ma2,LOW);
digitalWrite(mb1,HIGH);
digitalWrite(mb2,LOW);

}
