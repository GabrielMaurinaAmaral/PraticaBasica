#include <biblioteca_teste.h>

Biblioteca_teste::biblioteca_teste(int pt, int pe)
{
    this->pino_trigger = pt;
    this->pino_echo = pe;

    pinMode(pino_trigger, OUTPUT);
    pinMode(pino_echo, INPUT);
}

double Biblioteca_teste::distancia_cm()
{
    digitalWrite(pino_trigger, LOW);
    delayMicroseconds(2); // 1 mic = 1mil/1000
    digitalWrite(pino_trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(pino_trigger, LOW);

    unsigned long microSegundos = pulseIn(pino_echo, HIGH);
    double dsitancia_cm = (microSegundos * 0.0343) / 2.0;

    if (distancia_cm == 0 || distancia_cm > 400)
    {
        return -1.0;
    }
    else
    {
        return distancia_cm;
    }
    // delay(2);  1 mil = 1s/100
}