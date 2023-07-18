#ifndef VEICULO_H
#define VEICULO_H

#include "Roda.cpp"
#include <sstream>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

class Veiculo
{
private:
    int id;
    int distancia_percorrida;
    int quantidade_rodas;
    vector<Roda> rodas;

public:
    Veiculo(int , int);
    int get_id();
    int get_distancia_percorrida();
    int get_quantidade_rodas();
    vector<Roda> get_rodas();
    void set_distancia_percorrida(int);
    virtual void mover() = 0;
    virtual void desenhar() = 0;
    bool verificar_pneu();
    void calibrar_pneu(int);
    void esvaziar_pneu(int);
    string to_string();
};

#endif // VEICULO_H