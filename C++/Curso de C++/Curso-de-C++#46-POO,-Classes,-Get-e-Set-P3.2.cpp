#include <iostream>
#include "Curso-de-C++#46-POO,-Classes,-Get-e-Set-P3.1.h"

using namespace std;

int main()
{
    Pessoa *p1 = new Pessoa();
    Pessoa *p2 = new Pessoa();

    p1->get_dados();
    p2->set_dados(27, "Breno", "Rico", 1.54, 54);

    p1->imprimir();
    p2->imprimir();

    return 0;
}