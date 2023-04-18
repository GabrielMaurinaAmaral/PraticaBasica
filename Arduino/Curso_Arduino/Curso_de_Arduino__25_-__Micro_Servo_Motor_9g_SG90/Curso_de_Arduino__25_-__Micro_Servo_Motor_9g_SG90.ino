#include <Servo.h>
#define pot A0
Servo s1;
int angS1;

void setup(){
    s1.attach(2); 
    angS1=0;
    s1.write(angS1);
}
void loop() {
  angS1=map(analogRead(pot),0,1023,0,180);
  s1.write(angS1);
  Serial.print(angS1);
  delay(100);
}
