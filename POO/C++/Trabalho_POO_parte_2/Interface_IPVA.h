#ifndef INTERFACE_IPVA_H
#define INTERFACE_IPVA_H

#include <iostream>

class Interface_IPVA
{
public:
    static constexpr float CARRO_PASSEIO = 1.3;
    static constexpr float MOTOCICLETA = 0.75;
    static constexpr float CARRO_ESPORTIVO = 3.15;
    static constexpr int VALOR_BASE = 500;

    virtual void calcular_Ipva() = 0;
};

#endif // INTERFACE_IPVA_H
