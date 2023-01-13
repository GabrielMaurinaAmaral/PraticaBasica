
void setup() {
  pinMode(6,OUTPUT);
   pinMode(5,OUTPUT);

}

void loop() {

    if(millis()%200==0)
    {
    digitalWrite(5,HIGH);
    }
    else 
    {
      digitalWrite(5,LOW);
    }
}
