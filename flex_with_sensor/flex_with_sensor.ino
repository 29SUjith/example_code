int flex1=A0;
int flexv1;
int flex2=A1;
int flexv2;
int buzzer=7;
int led1=8;
int led2=9;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(flex1,INPUT);
  pinMode(flex2,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  flexv1=analogRead(flex1);
  Serial.println(flexv1);
  flexv2=analogRead(flex2);
  Serial.println(flexv2);

  if(flexv1>=800){
    digitalWrite(buzzer,HIGH);
    digitalWrite(led1,HIGH);
    delay(50);
    digitalWrite(buzzer,LOW);
    digitalWrite(led1,LOW);
    delay(50);
  }

  else if(flexv1<=715){
    digitalWrite(buzzer,HIGH);
    digitalWrite(led1,HIGH);
    delay(400);
    digitalWrite(buzzer,LOW);
    digitalWrite(led1,LOW);
    delay(400);
  }

  else{
    digitalWrite(led1,LOW);
  }

  if(flexv2>=800){
    digitalWrite(buzzer,HIGH);
    digitalWrite(led2,HIGH);
    delay(50);
    digitalWrite(buzzer,LOW);
    digitalWrite(led2,LOW);
    delay(50);
  }

  else if(flexv2<=715){
    digitalWrite(buzzer,HIGH);
    digitalWrite(led2,HIGH);
    delay(400);
    digitalWrite(buzzer,LOW);
    digitalWrite(led2,LOW);
    delay(400);
  }

  else{
    digitalWrite(led2,LOW);
  }
}
