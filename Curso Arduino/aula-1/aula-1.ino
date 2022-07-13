void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(7,INPUT);
}

void loop() {

  digitalWrite(8,digitalRead(7));
  digitalWrite(9,digitalRead(7));

}
