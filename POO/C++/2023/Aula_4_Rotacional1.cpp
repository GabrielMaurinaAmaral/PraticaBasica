#include "Aula_4_Rotacional.h"

Fracao::Fracao(int n, int d)
{
    numerador = n;
    denominador = d;
    this->simplificar();
}

Fracao::~Fracao()
{
}

int Fracao::MDC(int a, int b)
{
    while (b != 0)
    {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a; // mdc sai no a pra reutilizar variavel
}

void Fracao::simplificar()
{
    int mdc = MDC(numerador, denominador);
    this->numerador = numerador / mdc;
    this->denominador = denominador / mdc;
}

void Fracao::somar(Fracao f)
{
    if (this->denominador == f.denominador)
        this->numerador += f.numerador;
    else
    {
        int aux_1 = this->numerador;
        int aux_2 = this->denominador;
        int aux_3 = f.numerador;
        int aux_4 = f.denominador;

        this->numerador = aux_1 * aux_4;

        this->numerador += aux_3 * aux_2;
        this->denominador = aux_2 * aux_4;
        this->simplificar();
    }
}

void Fracao::subtrair(Fracao f)
{
    if (this->denominador == f.denominador)
    {
        this->numerador -= f.numerador;
    }
    else
    {
        int aux_1 = this->numerador;
        int aux_2 = this->denominador;
        int aux_3 = f.numerador;
        int aux_4 = f.denominador;

        this->numerador = aux_1 * aux_4;
        f.numerador = aux_3 * aux_2;

        this->numerador -= f.numerador;
        this->denominador = aux_2 * aux_4;
        this->simplificar();
    }
}

void Fracao::multiplicar(Fracao f)
{
    int aux_1 = this->numerador;
    int aux_2 = this->denominador;

    this->numerador = aux_1 * f.numerador;
    this->denominador = aux_2 * f.denominador;
    this->simplificar();
}

void Fracao::dividir(Fracao f)
{
    int aux_1 = this->numerador;
    int aux_2 = this->denominador;

    this->numerador = aux_1 * f.denominador;
    this->denominador = aux_2 * f.numerador;
    this->simplificar();
}

void Fracao::imprimirFracao()
{
    cout << "\nNumero em Fração"
         << numerador << "/" << denominador;
}

void Fracao::imprimirNumero()
{
    cout << "\nNumero em Float:"
         << float(numerador / denominador);
}
