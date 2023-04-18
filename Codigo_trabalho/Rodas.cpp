#include "Rodas.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Rodas::Rodas()
{
    calibragem_pneu = rand() % 2;
}

void Rodas::set_calibragem(bool c_p)
{
    calibragem_pneu = c_p;
}

bool Rodas::get_calibragem()
{
    return calibragem_pneu;
}

void Rodas::imprimir()
{
    cout << "\n Calibragem do Pneu: " << calibragem_pneu << endl;
}