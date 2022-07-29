#include "Aula02-Classes-Parte1.1.h"
#include <iostream>
using namespace std;

Tempo::Tempo() // maneira de inicializar
{
    hora = 0;
    minuto = 0;
    segundo = 0;
}
Tempo::Tempo(int h, int m, int s) // outra maneira de se inicializar
{
    // hora = h;
    // minuto = m;
    // segundo = s;
    set_Tempo(h, m, s);
}
void Tempo::set_Tempo(int h, int m, int s)
{
    hora = (h >= 0 && s <= 23) ? h : 0;
    minuto = (m >= 0 && m <= 60) ? m : 0;
    segundo = (s >= 0 && s <= 60) ? s : 0;
}
void Tempo::imprimir()
{
    cout << hora << ":" << minuto << ":" << segundo << "\n";
}
// Tempo::~Tempo();

Circle::Circle()
{
    radius = 0.0, x = y = 0;
}
Circle::Circle(float rr, int xx, int yy)
{
    radius = rr, x = xx, y = yy;
}
float Circle::area()
{
    return radius * radius * 3.141592;
}
float Circle::diameter()
{
    return radius * 2;
}
void Circle::set_radius(float rr)
{
    radius = rr > 0 ? rr : 0;
}
void Circle::set_origin(int xx, int yy)
{
    x = xx, y = yy;
}
float Circle::get_radius()
{
    return radius;
}
void Circle::imprimir()
{
    cout << "radius=" << radius << ", x=" << x << ", y=" << y << "\n";
}