#include "Aula-7-Polimorfismo.1.h"
#include <iostream>
using namespace std;

// FORMA
Forma::Forma(double xx, double yy) : x{xx}, y{yy} {}
void Forma::print_dados()
{
    cout << "\nOrigem: (" << x << "," << y << ")";
}

// RETANGULO
Retangulo::Retangulo(double xx, double yy, double bb, double aa) : Forma{xx, yy}, base{bb}, altura{aa} {}
double Retangulo::area()
{
    return base * altura;
}
void Retangulo::print_dados()
{
    Forma::print_dados();
    cout << "\nBase..: " << base
         << "\nAltura: " << altura
         << "\nArea: " << area()<<endl;
}

// CIRCULO
Circulo::Circulo(double xx, double yy, double rr) : Forma{xx, yy}, raio{rr} {}
double Circulo::area()
{
    return 3.141592 * raio * raio;
}
void Circulo::print_dados()
{
    Forma::print_dados();
    cout << "\nRaio: " << raio
         << "\nArea: " << area()<<endl;
}
