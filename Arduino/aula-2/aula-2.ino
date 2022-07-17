void setup() {
    pinMode(13,OUTPUT);// OUTPUT = saida  e INPUT = entrada
    
}

void loop() {
  digitalWrite(13,HIGH);// HIGH = ligada(5V)  e LOW = desligada(0v)
  delay(100);
  digitalWrite(13,LOW);
  delay(100);
}
