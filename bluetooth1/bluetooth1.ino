int relay=7;
char recieved_value;
char A;
char B;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(relay,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
recieved_value = Serial.read();
Serial.println(recieved_value);
if(recieved_value==A){
  digitalWrite(relay,HIGH);
}
else if(recieved_value==B){
  digitalWrite(relay,LOW);
}
else{
  digitalWrite(relay,LOW);
}

delay(1000);
}
