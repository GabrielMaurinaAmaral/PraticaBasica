#include "Curso-de-C++#47-POO,-Classes,-Heranca-P4.1.h"
#include <iostream>
using namespace std;

int main()
{
    Veiculo *v1 = new Moto();
    Veiculo *v2 = new Carro();

    v1->print();
    v2->print();

    return 0;
}