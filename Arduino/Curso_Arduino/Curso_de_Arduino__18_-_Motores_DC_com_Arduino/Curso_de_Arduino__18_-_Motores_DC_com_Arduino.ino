#define motor 2
int tempo=200;

void setup() {
  pinMode(motor,OUTPUT);
}

void loop() {
   digitalWrite(motor,HIGH);
   delay(tempo);
   digitalWrite(motor,LOW);
   delay(tempo);
}
