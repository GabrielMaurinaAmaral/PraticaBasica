#define led 3
#define pot A0

void setup() {
   pinMode(led,OUTPUT);
   pinMode(pot,INPUT);
}

void loop() {
  //analogico= 0 a 1023
  //PWN= 0 a 255
  // sintaxe= map(leitura, min_val_entrada, max_val_entrada,min_val_saida, max_val_saida);
  analogWrite(led,analogRead(pot)/4);
  analogWrite(led,map(analogRead(pot),0,1023,0,255));
  
}
