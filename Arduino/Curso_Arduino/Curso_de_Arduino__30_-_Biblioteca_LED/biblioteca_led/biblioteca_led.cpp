#include <biblioteca_led.h>

Biblioteca_LED::Biblioteca_LED(int pin)
{
    this->pino_led = pin;
    pinMode(this->pino_led, OUTPUT);
}
void Biblioteca_LED::acender()
{
    digitalWrite(this->pino_led, HIGH);
}
void Biblioteca_LED::apagar()
{
    digitalWrite(this->pino_led, LOW);
}
void Biblioteca_LED::acender_t(int tmp)
{
    acender();
    delay(tmp);
    apagar()
}
void Biblioteca_LED::apagar_t(int tmp)
{
    apagar();
    delay(tmp);
    acender();
}
void Biblioteca_LED::piscar(int tmp, int loop);
{
    for(int i=0; i<loop; i++)
        acender_t(tmp);
        delay(tmp);
}