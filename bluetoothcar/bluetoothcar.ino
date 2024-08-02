#define trigPin 6
#define echoPin 5
#define M2 12
#define enA 10
#define M1 11
#define enB 9
#define M4 8
#define M3 7
//Servo servo;
//volatile long dis;
bool OD;
unsigned long currentTime,previousTime,delayTime=100;
long dist()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  long distance = (duration / 2) / 29.1;

  if (distance >= 2 && distance <= 400) 
  {
//    Serial.print("Distance: ");
  //  Serial.print(distance);
   // Serial.println(" cm");
    return distance;
  } 
  else
  {
    //Serial.println("Out of range");
    return -1;
  }
}
void front1()
{
    digitalWrite(M1,LOW);
    digitalWrite(M2,HIGH);
  }
  void front2()
  {
    digitalWrite(M3,HIGH);
    digitalWrite(M4,LOW);
  }
void back1()
{
  
    digitalWrite(M1,HIGH);
    digitalWrite(M2,LOW);
}
void back2()
  {
     digitalWrite(M3,LOW);
     digitalWrite(M4,HIGH);
  }
void right()
{
  front1();
  back2();
}
void left()
{
  front2();
  back1();
}
void off()
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
}
void forward()
{
  front1();
  front2();
}
void backward()
{
  back1();
  back2();
}
void speed(int x)
{
  analogWrite(enA,x);
  analogWrite(enB,x);
}
void setup() 
{
  // put your setup code here, to run once:
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  pinMode(M3,OUTPUT);
  pinMode(M4,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  //servo.attach(SP);
  //servo.write(90);
  Serial.begin(9600);
  speed(127);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(currentTime-previousTime>=delayTime)
  {
    if(dist()<=5&&dist()!=-1)
    {
    OD=true;
     Serial.println("Object detected");
    off();
    }
    else
    {
          Serial.print("Distance ");
         Serial.println(dist());
    } 
    OD=false;
    previousTime=currentTime;
  }
  if(Serial.available())
  {
    char data=Serial.read();
    if(!OD)
    {
    if(data=='E')
    {
        forward();
    }
    else if(data=='F')
    {
      left();
    }
    else if(data=='G')
    {
      right();
    }
    else if(data=='H')
    {
      backward();
    }
    else if(data=='0')
    {
      speed(0);
    }
    else if(data=='1')
    {
      speed(64);
    }
    else if(data=='2')
    {
      speed(128);
    }
    else if(data=='3')
    {
      speed(200);
    }
    else if(data=='4')
    {
      speed(255);
    }
    else if(data=='Z')
    {
      off();
    }
  }
  }
delay(10);
}