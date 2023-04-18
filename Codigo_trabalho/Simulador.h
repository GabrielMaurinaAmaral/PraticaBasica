#ifndef SIMULADOR_H
#define SIMULADOR_H
#include "Veiculo.cpp"

class Simulador
{
private:
    int quantidade_veiculos;
    Veiculo veiculos[20];

public:
    Simulador();
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
    void gravar_arquivo();
    void ler_arquivo();
};

#endif