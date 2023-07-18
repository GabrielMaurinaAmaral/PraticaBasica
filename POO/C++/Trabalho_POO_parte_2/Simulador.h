#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "Veiculo.cpp"
#include "Veiculo_Motorizado.cpp"
#include "Bicicleta.cpp"
#include "Motocicleta.cpp"
#include "Carro_Passeio.cpp"
#include "Carro_Esportivo.cpp"

class Simulador
{
private:
    int capacidade_veiculos;
    int quantidade_veiculos;
    vector<Veiculo *> garagem;

    bool verificar_id_existe(int);

public:
    Simulador(int);

    void incluir_veiculo(char);
    void remover_veiculo(int);
    void abastecer_veiculo(int);
    void mover_veiculo(int);
    void mover_veiculos_tipo(char);
    void mover_todos_veiculos();
    void mostrar_dados_veiculos_tipo(char);
    void mostrar_dados_todos_veiculos();
    void veiculo_mexer_pneu(int);
    void calibrar_veiculos_tipo(char);
    void imprimir_pista();
    void gravar_arquivo();
    void ler_arquivo();
};

#endif // SIMULADOR_H
