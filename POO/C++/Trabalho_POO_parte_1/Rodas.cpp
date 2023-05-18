#include "Rodas.h"
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;


Rodas::Rodas()
{
    this->calibragem_pneu = rand() % 2;
}

void Rodas::set_calibragem(bool c_p)
{
    this->calibragem_pneu = c_p;
}

bool Rodas::get_calibragem()
{
    return this->calibragem_pneu;
}

void Rodas::imprimir()
{
    cout << "\n Calibragem do Pneu: " << this->calibragem_pneu << endl;
}