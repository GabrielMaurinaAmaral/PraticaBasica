#include "Aula_4_Complexo.h"

Complexo::Complexo(int r, int i)
{
    real = r, imaginario = i;
    cout << "\nComplexo criado";
}

Complexo::~Complexo()
{
}

void Complexo::inicializarNumero(int r, int i)
{
    real = r, imaginario = i;
}

void Complexo::imprimirNumero()
{
    if (imaginario > 0)
        cout << "\nNumero complexo: " << real << " + " << imaginario << "i";
    else if (imaginario == 0)
        cout << "\nNumero complexo: " << real;
    else
        cout << "\nNumero complexo: " << real << " " << imaginario << "i";
}

bool Complexo::elgual(Complexo c)
{
    if (c.real == this->real && c.imaginario == this->imaginario)
        return true;
    else
        return false;
}
void Complexo::somar(Complexo c)
{
    this->real += c.real;
    this->imaginario += c.imaginario;
}

void Complexo::subtrair(Complexo c)
{
    this->real -= c.real;
    this->imaginario -= c.imaginario;
}

void Complexo::multiplicar(Complexo c)
{
    int aux_r = (this->real * c.real) - (this->imaginario * c.imaginario);
    int aux_i = (this->real * c.imaginario) + (this->imaginario * c.real);
    this->real = aux_r;
    this->imaginario = aux_i;
}

void Complexo::dividir(Complexo c)
{
    int aux_r = ((this->real * c.real) + (this->imaginario * c.imaginario)) / ((c.real * c.real) + (c.imaginario * c.imaginario));
    int aux_i = ((this->imaginario * c.real) - (this->real * c.imaginario)) / ((c.real * c.real) + (c.imaginario * c.imaginario));
    this->real = aux_r;
    this->imaginario = aux_i;
}