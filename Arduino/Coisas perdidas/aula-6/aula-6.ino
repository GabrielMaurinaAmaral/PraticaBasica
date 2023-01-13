#define led 4
#define btn 3
int btnC=0;
int btnL=0;

void trocaLed()
{
  if(digitalRead(led)==HIGH)
  {
    digitalWrite(led,LOW);
  }
  else
  {
    digitalWrite(led,HIGH);
  }
}

void key()
{
    if((btnC==1)and(btnL==1))
    {
      btnC=0;
      btnL=0;
      trocaLed();
    }
}
void setup() 
{
 pinMode(led, OUTPUT);
 pinMode(btn,INPUT);
}
void loop() 
{
  if(digitalRead(btn)==HIGH)
  {
    btnC=1;
    btnL=0;
  }
  else
  {
    btnL=1;
  }
  key();
}
