int leds[6]={10,9,8,7,6,5};

void setup() {
    for(int i=0; i<6; i++)
    {
      pinMode(leds[i],OUTPUT);
    }
}

void loop() {
  for(int i=0; i<6; i++)
    {
      digitalWrite(leds[i],HIGH);
      delay(100);
    }
    
    for(int i=0; i<6; i++)
    {
      digitalWrite(leds[i],LOW);
      delay(100);
    }
    

}
