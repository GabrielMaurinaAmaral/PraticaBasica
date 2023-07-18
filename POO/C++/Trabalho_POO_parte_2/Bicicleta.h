#ifndef BICICLETA_H
#define BICICLETA_H

#include "Veiculo.cpp"

class Bicicleta : public Veiculo
{
private:
    char tipo;

public:
    Bicicleta(int, int);
    char get_tipo();
    void mover() override;
    void desenhar() override;
};

#endif // BICICLETA_H
