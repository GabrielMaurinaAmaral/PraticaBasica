#define pin_1 6
#define pin_2 7

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_1, OUTPUT);
  pinMode(pin_2, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin_1,LOW);
  digitalWrite(pin_2,HIGH);
  delay(1000);
  digitalWrite(pin_1,HIGH);
  digitalWrite(pin_2,LOW);
  delay(500);
}
