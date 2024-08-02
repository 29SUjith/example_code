int speedpin=5;
int dir1=4;
int dir2=7;
int mspeed;
int jpin=A1;
int jval;

void setup() {
  // put your setup code here, to run once:
pinMode(speedpin,OUTPUT);
pinMode(dir1,OUTPUT);
pinMode(dir2,OUTPUT);
pinMode(jpin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
jval=analogRead(jpin);
 if (jval<496){
digitalWrite(dir1,HIGH);
digitalWrite(dir2,LOW);
mspeed=(-255./497.*jval+255);
analogWrite(speedpin,mspeed);
 }
if (jval>=496){
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
mspeed=(255./497.*jval-255);
analogWrite(speedpin,mspeed);
}
}
