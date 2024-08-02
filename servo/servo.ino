#include <Servo.h>
int servopin1=3;
Servo belbow;

int servopin2=9;
Servo bwrist;

int servopin3=10;
Servo selbow;

int servopin4=11;
Servo swrist;

int i=90;
int j=90;
int k=90;
int l=90;
char val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  belbow.attach(servopin1);
  bwrist.attach(servopin2);
  selbow.attach(servopin3);
  swrist.attach(servopin4);

}

void loop() {
  // put your main code here, to run repeatedly:
  val=Serial.read();
  Serial.println(val);

  belbow.write(i); 
  bwrist.write(j); 
  selbow.write(k); 
  swrist.write(l); 



  if(val=='2' & i<180){
    i=i+10;
  }
  else if(val=='1' & i>0){
    i=i-10;
  }
  else if(val=='3' & j>0){
    j=j-10;
  }
  else if(val=='4' & j<180){
    j=j+10;
  }
    else if(val=='5' & k>0){
    k=k-10;
  }
  else if(val=='6' & k<180){
    k=k+10;
  }
    else if(val=='7' & l>0){
    l=l-10;
  }
  else if(val=='8' & l<180){
    l=l+10;
  }

  delay(00);
}
