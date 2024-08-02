char val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  val=Serial.read();
  Serial.println(val);
  if(val=='F'){
      //front
    digitalWrite(3,LOW);//L
    digitalWrite(4,HIGH); 
    digitalWrite(5,LOW);//R
    digitalWrite(6,HIGH);
  }

  else if(val=='B'){
      //back
    digitalWrite(4,LOW);
    digitalWrite(3,HIGH); 
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
  }

  else if(val=='L'){
      //left
    digitalWrite(4,LOW);
    digitalWrite(3,HIGH); 
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
  }

  else if(val=='R'){
    //right
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH); 
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
  }

  else if(val=='S'){
    //stop
    digitalWrite(3,LOW);
    digitalWrite(4,LOW); 
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
  } 
}

