#define pinBot 2
#define pinG 12
#define pinF 11
#define pinA 10
#define pinB 9
#define pinE 8
#define pinD 7
#define pinC 6
#define pinPD 5

int num=10;

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

    switch(num)
    {
      case 0:
      digitalWrite(pinA,HIGH);    
      digitalWrite(pinB,HIGH);    
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,HIGH);    
      digitalWrite(pinE,HIGH);    
      digitalWrite(pinF,HIGH);    
      digitalWrite(pinG,LOW);    
      digitalWrite(pinPD,LOW); 
      break; 
      case 1:
      digitalWrite(pinA,LOW);    
      digitalWrite(pinB,HIGH);    
      digitalWrite(pinC,LOW);
      digitalWrite(pinD,LOW);    
      digitalWrite(pinE,LOW);    
      digitalWrite(pinF,LOW);    
      digitalWrite(pinG,LOW);    
      digitalWrite(pinPD,LOW); 
      break; 
      case 2:
      digitalWrite(pinA,HIGH);    
      digitalWrite(pinB,HIGH);    
      digitalWrite(pinC,LOW);
      digitalWrite(pinD,HIGH);    
      digitalWrite(pinE,HIGH);    
      digitalWrite(pinF,LOW);    
      digitalWrite(pinG,HIGH);    
      digitalWrite(pinPD,LOW); 
      break; 
      case 3:
      digitalWrite(pinA,HIGH);    
      digitalWrite(pinB,HIGH);    
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,HIGH);    
      digitalWrite(pinE,LOW);    
      digitalWrite(pinF,LOW);    
      digitalWrite(pinG,HIGH);    
      digitalWrite(pinPD,LOW); 
      break;  
      case 4:
      digitalWrite(pinA,LOW);    
      digitalWrite(pinB,HIGH);    
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,LOW);    
      digitalWrite(pinE,LOW);    
      digitalWrite(pinF,HIGH);    
      digitalWrite(pinG,HIGH);    
      digitalWrite(pinPD,LOW); 
      break; 
      case 5:
      digitalWrite(pinA,HIGH);    
      digitalWrite(pinB,LOW);    
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,HIGH);    
      digitalWrite(pinE,LOW);    
      digitalWrite(pinF,HIGH);    
      digitalWrite(pinG,HIGH);    
      digitalWrite(pinPD,LOW); 
      break; 
      case 6:
      digitalWrite(pinA,HIGH);    
      digitalWrite(pinB,LOW);    
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,HIGH);    
      digitalWrite(pinE,HIGH);    
      digitalWrite(pinF,HIGH);    
      digitalWrite(pinG,HIGH);    
      digitalWrite(pinPD,LOW); 
      break; 
      case 7:
      digitalWrite(pinA,HIGH);    
      digitalWrite(pinB,HIGH);    
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,LOW);    
      digitalWrite(pinE,LOW);    
      digitalWrite(pinF,LOW);    
      digitalWrite(pinG,LOW);    
      digitalWrite(pinPD,LOW); 
      break; 
      case 8:
      digitalWrite(pinA,HIGH);    
      digitalWrite(pinB,HIGH);    
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,HIGH);    
      digitalWrite(pinE,HIGH);    
      digitalWrite(pinF,HIGH);    
      digitalWrite(pinG,HIGH);    
      digitalWrite(pinPD,LOW); 
      break; 
      case 9:
      digitalWrite(pinA,HIGH);    
      digitalWrite(pinB,HIGH);    
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,LOW);    
      digitalWrite(pinE,LOW);    
      digitalWrite(pinF,HIGH);    
      digitalWrite(pinG,HIGH);    
      digitalWrite(pinPD,LOW); 
      break;    
    }

    delay(200);
}
