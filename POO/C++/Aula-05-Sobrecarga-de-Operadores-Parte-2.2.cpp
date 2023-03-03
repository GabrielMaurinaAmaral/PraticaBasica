#include "Aula-05-Sobrecarga-de-Operadores-Parte-2.1.h"
#include <iostream>
using namespace std;

Complexo::Complexo(float r, float i)
{
    real = r, imaginario = i;
}
Complexo::~Complexo()
{
}

void Complexo::print() const
{
    cout << real << "+ (" << imaginario << ")i";
}

Complexo Complexo::add(Complexo &parametro)
{
    float x = this->real + parametro.real;
    float y = this->imaginario + parametro.imaginario;
    return Complexo{x, y};
}
Complexo Complexo::sub(Complexo &parametro)
{
    float x = this->real - parametro.real;
    float y = this->imaginario - parametro.imaginario;
    return Complexo{x, y};
}

Complexo Complexo::operator+(Complexo &parametro) // a = b + c
{
    float x = this->real + parametro.real;
    float y = this->imaginario + parametro.imaginario;
    return Complexo{x, y};
}
Complexo Complexo::operator-(Complexo &parametro) // a = b - c
{
    float x = this->real - parametro.real;
    float y = this->imaginario - parametro.imaginario;
    return Complexo{x, y};
}

bool Complexo::operator!()
{
    return (real == 0 && imaginario == 0) ? true : false;
}

Complexo &Complexo::operator++() // ++a
{
    this->real += 1;
    this->imaginario += 1;
    return *this;
}
Complexo Complexo::operator++(int value) // a++
{
    Complexo temp = *this;
    this->real += 1;
    this->imaginario += 1;
    return temp;
}
