int leds[9] = {12, 11, 10, 9, 8, 7, 6, 5, 4};
float ldr;
float minimo = 85;
float maximo = 1020;
float luz;
int i;

void setup()
{
  for (i = 0; i < 9; i++)
  {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(A0, INPUT);
}

void loop()
{
  ldr = analogRead(A0);
  luz = ((ldr - minimo) / (maximo - minimo)) * 10;
  luz = (luz - 10) * -1;

  for (i = 0; i < 9; i++)
  {
    if (i < luz)
    {
      digitalWrite(leds[i], HIGH);
    }
    else
    {
      digitalWrite(leds[i], LOW);
    }
  }

  delay(100);
}
