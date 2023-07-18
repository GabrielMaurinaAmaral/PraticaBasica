#include "Roda.h"
using namespace std;

Roda::Roda()
{
    calibragem_pneu = (rand() % 2 == 0);
}

void Roda::set_calibragem(bool c_p)
{
    calibragem_pneu = c_p;
}

bool Roda::get_calibragem()
{
    return calibragem_pneu;
}

string Roda::to_string()
{
    return "Calibragem do Pneu: " + string(calibragem_pneu ? "True" : "False");
}