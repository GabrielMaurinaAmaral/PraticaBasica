#define ldr A0
#define led 2
int val=0;

void setup() {
    pinMode(ldr,INPUT);
    pinMode(led,OUTPUT);
    Serial.begin(9600);
}

void loop() {
   val=analogRead(ldr);

   if(val<800)
   {
    digitalWrite(led, HIGH);
   }
   else
   {
    digitalWrite(led, LOW);
   }
   Serial.println(val);
   delay(100);
}
