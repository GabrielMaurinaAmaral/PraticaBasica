#define led_r 3
#define maximo 32
#define minimo 0
#define temp 100

void setup() 
{
  pinMode(led_r,OUTPUT);
}

void loop()
{  
   for(int i=minimo; i<maximo; i++)
   {
      analogWrite(led_r,i);
      delay(temp);
   }

   for(int i=maximo; i>minimo; i--)
   {
      analogWrite(led_r,i);
      delay(temp);
   }
}
