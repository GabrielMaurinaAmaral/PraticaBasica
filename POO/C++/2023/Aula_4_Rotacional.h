#ifndef fOMPLEXO_H
#define fOMPLEXO_H

#include <iostream>
using namespace std;

class Fracao
{
private:
    int numerador, denominador;
    int MDC(int, int);
    void simplificar();
    
public:
    Fracao(int = 1, int = 1);
    ~Fracao();
    void somar(Fracao f);
    void subtrair(Fracao f);
    void multiplicar(Fracao f);
    void dividir(Fracao f);
    void imprimirFracao();
    void imprimirNumero();
};

#endif