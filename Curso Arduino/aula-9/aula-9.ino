#define ledB 2
#define ledG 3
#define ledR 4

class BOT
{
  public:
  int bot, botAnt, botAtu, pino;
  
  bot(int p)
  {
    pino=p;
    botAnt=0;
    botAtu=0;
  }
  bool press()
  {
    botAtu=digitalRead(bot);
    if(botAtu && !botAnt)
    {
      return true;
    }
    else
    {
      return false;
    }
     botAnt=botAtu;
  }
}

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(bot, INPUT);
}

void loop() {

  BOT bot1(7);
}
