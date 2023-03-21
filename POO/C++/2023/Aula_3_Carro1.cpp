#include "Aula_4_Carro.h"

Carro::Carro()
{
    velocidade = 0, velMax = 0, marca = "";
    cout << "objeto criado" << "\n";
}

Carro::Carro(int v, int vMax, string m)
{
    set_carro(v, vMax, m);
    cout << "objeto criado"<< "\n";
}

Carro::~Carro()
{
    cout << "objeto destruido" << "\n";
}

void Carro::set_carro(int v, int vMax, string m)
{
    velocidade = v, velMax = vMax, marca = m;
}

void Carro::get_carro()
{
    cout << "velocidade: " << velocidade << "\n";
    cout << "velocidade maxima: " << velMax << "\n";
    cout << "marca:  " << marca << "\n";
}