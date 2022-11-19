#include <Servo.h>

#define pot A5
#define pinSer 8

Servo ser;


void setup() {
    ser.attach(pinSer);  
    Serial.begin(9600);
}

void loop() {
  int lido=analogRead(pot);
  byte ang=map(lido,0,1023,0,179);

for(int i=0ç 
  
  ser.write(ang);
  
  Serial.print("  A5:");
  Serial.print(lido);
  Serial.print("  Angulo:");
  Serial.print(ang);
  Serial.print("\n");

  delay(10);
    
}
