#ifndef CARRO_ESPORTIVO_H
#define CARRO_ESPORTIVO_H

#include "Veiculo_Motorizado.cpp"
#include "Interface_IPVA.h"

class Carro_Esportivo : public Veiculo_Motorizado, public Interface_IPVA
{
private:
    static constexpr float gasto_carro_esportivo = 2.3;
    char tipo;

public:
    Carro_Esportivo(int, int);
    char get_tipo();
    void mover() override;
    void desenhar() override;
};

#endif // CARRO_ESPORTIVO_H
