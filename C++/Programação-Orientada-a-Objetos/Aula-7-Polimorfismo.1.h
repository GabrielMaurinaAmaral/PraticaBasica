#include <iostream>
using namespace std;

#ifndef FORMA_H
#define FORMA_H

class Forma
{
protected:
    double x, y;

public:
    Forma(double = 0, double = 0);
    ~Forma(){}
    // virtual é usado para ativar o polimorfismo
    virtual void print_dados();
    virtual double area() { return 0; }
};

#ifndef RETANGULO_H
#define RETANGULO_H

class Retangulo : public Forma
{
private:
    double base, altura;

public:
    Retangulo(double = 0, double = 0, double = 0, double = 0);
    ~Retangulo(){}
    void print_dados();
    double area();
};

#ifndef CIRCULO_H
#define CIRCULO_H

class Circulo : public Forma
{
private:
    double raio;

public:
    Circulo(double = 0, double = 0, double = 0);
    ~Circulo(){}
    void print_dados();
    double area();
};

#endif
#endif
#endif