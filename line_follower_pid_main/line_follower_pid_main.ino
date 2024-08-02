
int a0 = A0;
int a1 = A1;
int a2 = A2;
int a3 = A3;
int a4 = A4;
int ENA=10;
int ENB=11;
int INA1=4;
int INA2=3;
int INB1=5;
int INB2=6;

void setup()
{
  Serial.begin(9600);
    pinMode(a0, INPUT);
   pinMode(a1, INPUT);
    pinMode(a2, INPUT);
     pinMode(a3, INPUT);
      pinMode(a4, INPUT);
      pinMode(ENA, OUTPUT);
       pinMode(ENB, OUTPUT);
        pinMode(INA1, OUTPUT);
         pinMode(INA2, OUTPUT);
         pinMode(INB1, OUTPUT);
         pinMode(INB2, OUTPUT);
       
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);

}

void loop()
{
  int o4 = digitalRead(a0);
  int o3 = digitalRead(a1);
  int o2 = digitalRead(a2);
  int o1 = digitalRead(a3);
  int o0 = digitalRead(a4);

if (o0==1&&o2==0&&o3==1)
{
  digitalWrite(INA1,HIGH);
  digitalWrite(INA2,LOW);
  digitalWrite(INB1,HIGH);
  digitalWrite(INB2,LOW);
}
if((o0==0&&o2==0&&o3==1)||(o0==0&&o2==1&&o3==1))
{
  digitalWrite(INA1,HIGH);
  digitalWrite(INA2,LOW);
  digitalWrite(INB1,LOW);
  digitalWrite(INB2,LOW);
}
if((o0==1&&o2==0&&o3==0)||(o0==1&&o2==1&&o3==0))
{
  digitalWrite(INA1,LOW);
  digitalWrite(INA2,LOW);
  digitalWrite(INB1,HIGH);
  digitalWrite(INB2,LOW);
}
if (o0==0&&o2==0&&o3==0)
{
  digitalWrite(INA1,LOW);
  digitalWrite(INA2,LOW);
  digitalWrite(INB1,LOW);
  digitalWrite(INB2,LOW);
}
}