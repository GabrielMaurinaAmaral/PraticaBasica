#include "Aula-03-Classes-Parte2.1.h"
#include <iostream>
using namespace std;

int Date::howmany=0;

// construtor
Date::Date(int dd, int mm, int yy) : d{dd}, m{mm}, y{yy}
{
    count = 0;
    howmany ++;
    cout << "\nobjeto inicializado";
}
Date::~Date()
{
    howmany--;
    cout << "\nobjeto destruido";
}
void Date::print() const
{
    cout << d << "/" << m << "/" << y;
    count++;
}
Date Date::set_day(int dd)
{
    d = (dd > 0 && dd <= 31) ? dd : 1;

    return *this;
}
Date Date::set_month(int mm)
{
    m = (mm > 0 && mm <= 12) ? mm : 1;
    return *this;
}
Date Date::set_year(int yy)
{
    y = (yy > 0) ? yy : 2000;
    return *this;
}