#include <Stepper.h>
#define e1 8
#define e2 9
#define e3 10
#define e4 11
#define led 13

const int passosPorGiro=64;
Stepper mp(passosPorGiro, e1, e3, e2, e4);

void setup() 
{
  pinMode(led, OUTPUT); //mp.setSpeed(500); RPM
}

void loop() 
{
  digitalWrite(led, LOW);
  motor(500,1,1,500,5);
  digitalWrite(led, HIGH);
  delay(3000);

  digitalWrite(led, LOW);
  motor(500,-1,1,500,5);
  digitalWrite(led, HIGH);
  delay(3000);  
}

void motor(int val, int sentido, int loop, int tmp)
{
  mp.setSpeed(vel); // RPM
  for(int i=0; i<(32*voltas); i++)
  {
    mp.step(passosPorGiro*sentido); 
    delay(tmp);
  }
  delay(tmp*4);
}
