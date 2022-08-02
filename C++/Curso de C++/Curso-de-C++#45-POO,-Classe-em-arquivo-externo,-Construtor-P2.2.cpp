#include "Curso-de-C++#45-POO,-Classe-em-arquivo-externo,-Construtor-P2.1.h"
#include <iostream>
using namespace std;

int main()
{
    Pessoa *p1 = new Pessoa(1);
    Pessoa *p2 = new Pessoa(2);

    p1->imprimir();
    p2->imprimir();

    return 0;
}