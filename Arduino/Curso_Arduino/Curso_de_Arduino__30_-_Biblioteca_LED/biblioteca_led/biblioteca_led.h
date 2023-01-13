#ifndef BIBLIOTECA_LED_H_INCLUDED
#define BIBLIOTECA_LED_H_INCLUDED


class Biblioteca_LED
{
public:
    Biblioteca_LED(int pin);
    void acender();
    void apagar();
    void acender_t(int tmp);
    void apagar_t(int tmp);
    void piscar(int tmp, int loop);

private:
    int pino_led;
};

#endif //BIBLIOTECA_LED_H_INCLUDED