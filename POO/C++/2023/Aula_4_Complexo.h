#ifndef COMPLEXO_H
#define COMPLEXO_H

#include <iostream>
using namespace std;

class Complexo
{
private:
    int real, imaginario;

public:
    Complexo(int = 1, int = 1);
    ~Complexo();
    void inicializarNumero(int = 1, int = 1);
    void imprimirNumero();
    bool elgual(Complexo);
    void somar(Complexo);
    void subtrair(Complexo);
    void multiplicar(Complexo);
    void dividir(Complexo);
};

#endif