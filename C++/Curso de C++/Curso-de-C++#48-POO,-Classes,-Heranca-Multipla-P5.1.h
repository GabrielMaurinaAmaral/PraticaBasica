#include <iostream>
using namespace std;

#ifndef VEICULO_H
#define VEICULO_H

class Base_1
{
public:
    void print_base_1();
};
void Base_1::print_base_1()
{
    cout << "\nimprimir classe Base_1";
}

class Base_2
{
public:
    void print_base_2();
};
void Base_2::print_base_2()
{
    cout << "\nimprimir classe Base_2";
}

class Principal : public Base_1, public Base_2
{
};

#endif