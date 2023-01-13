// varia de 0 a 255 com 8 bits de espaço
#define led 3
#define maximo 255
#define minimo 0
#define tempo 100

void setup() {
  pinMode(led,OUTPUT);
}

void loop() {
  for(int i=0; i<maximo; i++){
     //digotalWrite(led,HIGH);
     analogWrite(led,i);
     delay(temp);
  }
  for(int i=255; i>minimo; i--){
     //digotalWrite(led,LOW);
     analogWrite(led,i);
     delay(temp);
  }
}
