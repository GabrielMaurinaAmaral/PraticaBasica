#include "Veiculo_Motorizado.h"
#include <random>

Veiculo_Motorizado::Veiculo_Motorizado(int id, int rodas) : Veiculo{id, rodas}
{
    combustivel = 0;
    ipva = (rand() % 2 == 0);
}

float Veiculo_Motorizado::get_combustivel()  
{
    return combustivel;
}

bool Veiculo_Motorizado::get_ipva() 
{
    return ipva;
}

void Veiculo_Motorizado::abastecer(float quantidade)
{
    combustivel += quantidade;
    std::cout << "Tanque de combustivel esta agora com " << combustivel << " de combustivel" << endl;
}

void Veiculo_Motorizado::consumir(float quantidade)
{
    combustivel -= quantidade;
    std::cout << "Tanque de combustivel esta agora com " << combustivel << " de combustivel" << endl;
}

string Veiculo_Motorizado::to_string() 
{
    ostringstream oss;
    oss << this->to_string();
    oss << "Combustivel no tanque: " << combustivel << endl;
    oss << "IPVA: " << (ipva ? "True" : "False") << endl;
    return oss.str();
}
