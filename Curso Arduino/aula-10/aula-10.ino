#define p A0

void setup() {
   pinMode(p,INPUT);
   Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(p));
  delay(10);

}
