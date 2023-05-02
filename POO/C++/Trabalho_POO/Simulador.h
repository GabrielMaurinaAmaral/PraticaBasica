#ifndef SIMULADOR_H
#define SIMULADOR_H
#include "Veiculo.cpp"

class Simulador
{
private:
    int capacidade_veiculos, quantidade_veiculos;
    Veiculo *garagem;

public:
    Simulador();
    int get_capacidade_veiculos();
    void incluir_veiculo();
    void remover_veiculo(int);
    void abastecer_veiculo(int, float);
    void mover_veiculo(int);
    void mover_todos_veiculos();
    void mostrar_dados_veiculo(int);
    void mostrar_dados_todos_veiculos();
    void veiculo_mexer_pneu(int, int);
    void veiculo_mexer_todos_pneus(int);
    void imprimir_pista();
    int gravar_arquivo();
    int ler_arquivo();
};

#endif