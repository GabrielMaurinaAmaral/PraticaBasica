#ifndef BIBLIOTECA_TESTE_H_INCLUDED
#define BIBLIOTECA_TESTE_H_INCLUDED

class Biblioteca_teste
{
public:
    biblioteca_teste(int pt, int pe);
    double distancia_cm();
    double distancia_m();

private:
    int pino_trigger;
    int pino_echo;


};

#endif // BIBLIOTECA_TESTE_H_INCLUDED