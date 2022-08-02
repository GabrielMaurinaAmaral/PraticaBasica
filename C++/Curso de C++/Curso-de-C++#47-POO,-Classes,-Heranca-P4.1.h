#include <iostream>
using namespace std;

#ifndef VEICULO_H
#define VEICULO_H

class Veiculo // class pai
{
private:
    int tipo;
    int velmax;
    bool arma;

public:
    int vel;
    int blind;
    int rodas;
    void set_tipo(int t);
    void set_velmax(int v);
    void set_arma(bool a);
    void print();
};

void Veiculo::set_tipo(int t)
{
    tipo = t;
}
void Veiculo::set_velmax(int v)
{
    velmax = v;
}
void Veiculo::set_arma(bool a)
{
    arma = a;
}
void Veiculo::print()
{
    cout << "\nTipo: " << tipo;
    cout << "\nVelmax: " << velmax;
    cout << "\nArma: " << arma;
    cout << "\nVel: " << vel;
    cout << "\nBlind: " << blind;
    cout << "\nRodas: " << rodas << endl;
}

class Moto : public Veiculo // criando uma nova class que erda os dados da class Veiculo
{
public:
    Moto();
};

Moto::Moto() // METODO CONSTRUTOR
{
    vel = 0;
    blind = 0;
    rodas = 2;
    set_tipo(1);
    set_velmax(120);
    set_arma(false);
}

class Carro : public Veiculo
{
public:
    Carro();

};

Carro::Carro() // METODO CONSTRUTOR
{
    vel = 0;
    blind = 0;
    rodas = 4;
    set_tipo(2);
    set_velmax(180);
    set_arma(false);
}

#endif