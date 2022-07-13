int leds[6]={7,6,5,4,3,2};
#define pot A5
int val;

void setup() {
   for(int i=0; i<6; i++)
   {
    pinMode(leds[i],OUTPUT);
   }
   pinMode(pot,INPUT);
}

void acender(int x)
{
  for(int i=0; i<x; i++)
  {
    digitalWrite(leds[i],HIGH);
  }
  for(int i=x; i<6; i++)
  {
    digitalWrite(leds[i],LOW);
  }
}

void loop() {

  val=analogRead(pot);
  acender(map(val,0,1023,0,6));

}
