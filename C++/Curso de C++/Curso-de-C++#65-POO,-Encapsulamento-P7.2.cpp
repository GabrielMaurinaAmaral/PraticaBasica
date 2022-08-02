#include "Curso-de-C++#65-POO,-Encapsulamento-P7.1.h"
#include <iostream>
using namespace std;

int main()
{
    Pessoa p1{true, "Gabriel", 16, 1.80};

    p1.set_idade(19);

    cout << p1.nome << endl;
    cout << p1.get_idade() << endl;
    cout << p1.get_vivo() << endl;
    cout << p1.get_altura() << endl;

    return 0;
}