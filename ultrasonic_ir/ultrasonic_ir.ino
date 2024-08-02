

int trigpin2=9;
int echopin2=10;
int distance2;
long duration2;
int led=12;
int ir=13;
int read;
//int pingtraveltime;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(trigpin2,OUTPUT);
pinMode(echopin2,INPUT);
pinMode(ir,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:




digitalWrite(trigpin2,LOW);
delayMicroseconds(2);
digitalWrite(trigpin2,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin2,LOW);
duration2=pulseIn(echopin2,HIGH);
distance2=(duration2/2)*0.0343;
Serial.print("distance2=");
Serial.println(distance2);
delay(1000);

read=digitalRead(ir);
Serial.println(read);


if(read==0){
  if(distance2<30){
    digitalWrite(led,HIGH);
  }
}


else if(distance2<30){
  digitalWrite(led,LOW);
}

else{
  Serial.println("ntg");
}
}
