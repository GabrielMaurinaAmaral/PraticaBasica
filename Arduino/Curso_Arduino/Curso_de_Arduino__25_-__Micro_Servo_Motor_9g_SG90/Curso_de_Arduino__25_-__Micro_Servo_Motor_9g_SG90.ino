#include <Servo.h>
#define pot A0
Servo s1;
Servo s2;
int angS1;
int angS2;

void setup(){
    s1.attach(2);
    s2.attach(3);
    angS1=0;
    s1.write(angS1);
    s2.write(angS1);
}

void loop() {
  angS1=map(analogRead(pot),0,1023,0,180);
  s1.write(angS1);
  s2.write(angS1);
  Serial.println(s1.read(angS1));
  delay(100);
}
