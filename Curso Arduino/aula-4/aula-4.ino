#define led_r 8
#define led_y 9
#define led_g 10

void setup() 
{
  pinMode(led_r,OUTPUT);
  pinMode(led_y,OUTPUT);
  pinMode(led_g,OUTPUT);
}

void semaforo(int temR, int temY, int temG) 
{  
 digitalWrite(led_r,HIGH);
  digitalWrite(led_y,LOW);
  digitalWrite(led_g,LOW);
  delay(temR);

  digitalWrite(led_r,LOW);
  digitalWrite(led_y,LOW);
  digitalWrite(led_g,HIGH);
  delay(temG);

  digitalWrite(led_r,LOW);
  digitalWrite(led_y,HIGH);
  digitalWrite(led_g,LOW);
  delay(temY);
}

void loop() 
{
    semaforo(2000,1000,4000);
}
