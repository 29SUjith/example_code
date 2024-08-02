int led=12;
int s1;
int s2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,LOW);
  s1=analogRead(A0);
  s2=analogRead(A1);
  Serial.print("s1");
  Serial.println(s1);
  Serial.print("s2");
  Serial.println(s2);
  delay(400);
}
