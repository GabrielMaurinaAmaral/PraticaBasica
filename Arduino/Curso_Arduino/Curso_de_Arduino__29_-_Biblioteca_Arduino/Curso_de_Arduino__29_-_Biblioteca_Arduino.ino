#include <biblioteca_teste.h>

#define p_trigger 4
#define p_echo 5

Biblioteca_teste biblioteca_teste(p_trigger, p_echo);

int dist_cm, dist_m;

void setup() {
  Serial.begin(9600);
}

void loop() {
  dist_cm=biblioteca_teste.distancia_cm();
  dist_m=dist_cm/100;
  Serial.print("Distancia: ");
  Serial.print(dist_cm);
  Serial.print("cm | ");
  Serial.print(dist_m);
  Serial.print("m");
  Serial.print("-------------------------------");
  delay(1000);
}
