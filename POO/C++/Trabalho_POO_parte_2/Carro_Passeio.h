#ifndef CARRO_PASSEIO_H
#define CARRO_PASSEIO_H

#include "Veiculo_Motorizado.cpp"
#include "Interface_IPVA.h"

class Carro_Passeio : public Veiculo_Motorizado, public Interface_IPVA
{
private:
    static constexpr float gasto_carro_passeio = 0.75;
    char tipo;

public:
    Carro_Passeio(int, int);
    char get_tipo();
    void mover() override;
    void desenhar() override;
};

#endif // CARRO_PASSEIO_H
