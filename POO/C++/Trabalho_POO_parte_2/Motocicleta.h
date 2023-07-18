#ifndef MOTOCICLETA_H
#define MOTOCICLETA_H

#include "Veiculo_Motorizado.cpp"
#include "Interface_IPVA.h"

class Motocicleta : public Veiculo_Motorizado, public Interface_IPVA
{
private:
    static constexpr float gasto_motocicleta = 0.25;
    string tipo;

public:
    Motocicleta(int id, int rodas);
    string get_tipo() const;
    void mover() override;
    void desenhar() override;
};

#endif // MOTOCICLETA_H
