#include <AccelStepper.h>

AccelStepper stepper(AccelStepper::DRIVER, 2, 3);  //StepPin D2 and DirPin D3

void setup()
{  
  stepper.setMaxSpeed(4000);
  stepper.moveTo(-2);   
  stepper.setSpeed(1000);    
}

void loop()
{ 
  if (stepper.distanceToGo() == 0)
  {
    stepper.moveTo(-(stepper.currentPosition()));
    stepper.setSpeed(1000);    
  }
  
  while (stepper.distanceToGo() != 0)
  {
    stepper.runSpeedToPosition();    
  }
  delay(000);
}