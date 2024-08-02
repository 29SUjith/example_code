int servo=A0;
int read;
int blue=2;
int green=3;
int red=4;
int led=12;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(servo,INPUT);
pinMode(blue,OUTPUT);
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
read=analogRead(servo);
Serial.println(read);






digitalWrite(led,HIGH);

if(read>600){

  digitalWrite(green,LOW);
  digitalWrite(blue,HIGH);
}

else if(read<490){
  digitalWrite(red,LOW);
   digitalWrite(blue,HIGH);
}

else{
  digitalWrite(blue,LOW);
  digitalWrite(red,HIGH);
  digitalWrite(green,HIGH);
}
}
