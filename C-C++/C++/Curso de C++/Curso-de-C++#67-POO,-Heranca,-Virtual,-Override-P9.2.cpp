#include "Curso-de-C++#67-POO,-Heranca,-Virtual,-Override-P9.1.h"
#include <iostream>
using namespace std;

int main()
{
    Carro v1{};
    Moto v2{};
    Caminhao v3{500, true};
    Caminhao v4{400, false};

    v1.print();
    v2.print();
    v3.print();
    v4.print();

    return 0;
}