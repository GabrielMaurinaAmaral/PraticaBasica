#define potenciometro A5

void setup() {
   pinMode(potenciometro,INPUT);
   Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(p));
  delay(10);

}
