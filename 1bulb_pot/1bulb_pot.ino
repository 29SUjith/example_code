int value;
int bulb=9;
int v1;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(bulb,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
value=analogRead(A0);
v1=(5./1023.)*value;
Serial.println(v1);
analogWrite(bulb,value);



}
