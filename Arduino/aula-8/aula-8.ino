#define ledB 2
#define ledG 3
#define ledR 4
#define bot 7

int num=0;
int botAnt=0;
int botAtu=0;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(bot, INPUT);
}

void loop() {

  botAtu=digitalRead(bot);
  if(botAtu && !botAnt)
  {
    num++;
    if(num==3)
    {
      num=0;
    }
  }
  botAnt=botAtu;
  
  if(num==0)
  {
  digitalWrite(ledR,HIGH);
  digitalWrite(ledG,LOW);
  digitalWrite(ledB,LOW);
  }
  if(num==1)
  {
  digitalWrite(ledR,LOW);
  digitalWrite(ledG,HIGH);
  digitalWrite(ledB,LOW);
  }
  if(num==2)
  {
  digitalWrite(ledR,LOW);
  digitalWrite(ledG,LOW);
  digitalWrite(ledB,HIGH);
  }
  delay(10);

}
