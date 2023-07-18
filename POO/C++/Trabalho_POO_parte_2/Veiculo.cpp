#include "Veiculo.h"


Veiculo::Veiculo(int ID, int q_rodas) : id(ID), quantidade_rodas(q_rodas), distancia_percorrida(0)
{
    for (int i = 0; i < quantidade_rodas; i++)
        rodas.push_back(Roda());
}

int Veiculo::get_id()
{
    return id;
}

int Veiculo::get_distancia_percorrida()
{
    return distancia_percorrida;
}

int Veiculo::get_quantidade_rodas()
{
    return quantidade_rodas;
}

vector<Roda> Veiculo::get_rodas()
{
    return rodas;
}

void Veiculo::set_distancia_percorrida(int new_distancia)
{
    distancia_percorrida = new_distancia;
}

bool Veiculo::verificar_pneu()
{
    for (Roda roda : rodas)
        if (!roda.get_calibragem())
            return false;
    return true;
}

void Veiculo::calibrar_pneu(int id_pneu)
{
    rodas[id_pneu].set_calibragem(true);
    std::cout << "Pneu: " << id_pneu << " -> calibrado" << endl;
}

void Veiculo::esvaziar_pneu(int id_pneu)
{
    rodas[id_pneu].set_calibragem(false);
    std::cout << "Pneu: " << id_pneu << " -> esvaziado" << endl;
}

string Veiculo::to_string()
{
    ostringstream oss;
    oss << "\nID: " << id << endl;
    oss << "Distancia percorrida: " << distancia_percorrida << endl;
    oss << "Quantidade de rodas: " << quantidade_rodas << endl;
    for (Roda roda : rodas)
        oss << roda.to_string();
    return oss.str();
}
