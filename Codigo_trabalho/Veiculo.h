#ifndef VEICULO_H
#define VEICULO_H
#include "Rodas.cpp"

class Veiculo
{
private:
    int id, quantidade_rodas, distancia_percorrida;
    float combustivel, valor_venda;
    bool ipva, ligado;
    Rodas rodas[4]; // Declarando array de rodas(objetos)

public:
    Veiculo();
    Veiculo(int);
    int get_quantidade_rodas();
    void mover();
    void imprimir_veiculo();
    bool verificar_todos_pneus();
    void abastecer(float);
    void consumir(float);
    void mostrar_dados();
    void calibrar(int);
    void esvaziar(int);
};

#endif