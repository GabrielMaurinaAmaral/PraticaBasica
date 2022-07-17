#define pot A5
int val;

void setup() {
    pinMode(pot,INPUT);
    Serial.begin(9600);
}

void loop() {
   
   val=analogRead(pot);
   Serial.println(constrain(val,0,1000));
   delay(100);
}
