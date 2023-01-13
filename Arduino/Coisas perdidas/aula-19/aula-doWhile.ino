#define pinBot 2
#define pinG 12
#define pinF 11
#define pinA 10
#define pinB 9
#define pinE 8
#define pinD 7
#define pinC 6
#define pinPD 5

int portas[8]={10,9,6,7,8,11,12,5};
int num=10;
int displayConfig[11][8]={{1,1,1,1,1,1,0,0}, //Digito 0
                             {0,1,1,0,0,0,0,0}, //Digito 1
                             {1,1,0,1,1,0,1,0}, //Digito 2
                             {1,1,1,1,0,0,1,0}, //Digito 3
                             {0,1,1,0,0,1,1,0}, //Digito 4
                             {1,0,1,1,0,1,1,0}, //Digito 5
                             {1,0,1,1,1,1,1,0}, //Digito 6
                             {1,1,1,0,0,0,0,0}, //Digito 7
                             {1,1,1,1,1,1,1,0}, //Digito 8
                             {1,1,1,1,0,1,1,0}, //Digito 9
                             {0,0,0,0,0,0,0,0}}; //Tudo apagado

void setup() 
{
  pinMode(pinBot,INPUT);
  
  for(int i=5; i<13; i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop() 
{  
    if(digitalRead(pinBot)==HIGH)
    {
      num++;

      if(num>9)
      {
        num=0;
      }
    }
   for (int nD = 0; nD <= 7; nD++) {
     digitalWrite(portas[nD], displayConfig[num][nD]);
  }
    delay(200);
}
