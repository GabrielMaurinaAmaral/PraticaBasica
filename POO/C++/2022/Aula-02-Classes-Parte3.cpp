#include "Aula-02-Classes-Parte2.cpp"
#include <iostream>
using namespace std;

int main()
{
    Tempo padrao;             // chama o costrutor vazio
    Tempo custom(11, 20, 34); // chama o segundo construtor

    cout << "Hora padrao: ";
    padrao.imprimir();

    cout << "Hora custom: ";
    custom.imprimir();

    Circle c1;      //{0.0, 0, 0}
    Circle c2(7.7); //{7.7, 0, 0}
    Circle c3(15.7, 8.9, -5.1);

    c1.set_radius(10.0);
    c1.set_origin(5, 7);

    cout << "Circle c1: ", c1.imprimir();
    cout << "Circle c2: ", c2.imprimir();
    cout << "Circle c3: ", c3.imprimir();
    cout << "Area de c1: " << c1.area();
    cout << "\ndiametro de c1: " << c1.diameter();

    return 0;
}