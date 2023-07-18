#ifndef VEICULO_MOTORIZADO_H
#define VEICULO_MOTORIZADO_H

#include "Veiculo.cpp"

class Veiculo_Motorizado : public Veiculo {
private:
    float combustivel;
    bool ipva;

public:
    Veiculo_Motorizado(int, int);

    float get_combustivel();
    bool get_ipva();
    void abastecer(float);
    void consumir(float);
    string to_string();
};

#endif // VEICULO_MOTORIZADO_H
