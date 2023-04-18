#include "Simulador.h"
#include <fstream>

Simulador::Simulador()
{
    quantidade_veiculos = 0;
}

void Simulador::incluir_veiculo()
{
    int id = rand() % 20; // - quantidade_veiculos
    veiculos[id] = Veiculo(id);
}

void Simulador::remover_veiculo(int id)
{
    veiculos[id].~Veiculo();
}

void Simulador::abastecer_veiculo(int id, float quantidade_gasosa)
{
    veiculos[id].abastecer(quantidade_gasosa);
}

void Simulador::mover_veiculo(int id)
{
    veiculos[id].mover();
}

void Simulador::mover_todos_veiculos()
{
    for (int i = 0; i < 20; i++)
        veiculos[i].mover();
}

void Simulador::mostrar_dados_veiculo(int id)
{
    veiculos[id].mostrar_dados();
}

void Simulador::mostrar_dados_todos_veiculos()
{
    for (int i = 0; i < 20; i++)
        veiculos[i].mostrar_dados();
}

void Simulador::veiculo_mexer_pneu(int id, int id_pneu)
{
    int opcao;
    cout << "esvaziar(1) ou encher(2)" << endl;
    cin >> opcao;
    if (opcao == 1)
        veiculos[id].esvaziar(id_pneu);
    else
        veiculos[id].calibrar(id_pneu);
}

void Simulador::veiculo_mexer_todos_pneus(int id)
{
    int opcao;
    cout << "esvaziar(1) ou encher(2) todos os penus" << endl;
        cin >> opcao;
    if (opcao == 1)
        for (int i = 0; i < veiculos[id].get_quantidade_rodas(); i++)
            veiculos[id].esvaziar(i);

    else
        for (int i = 0; i < veiculos[id].get_quantidade_rodas(); i++)
            veiculos[id].calibrar(i);
}

void Simulador::imprimir_pista()
{
    for (int i = 0; i < 20; i++)
        veiculos[i].imprimir_veiculo();
}

void Simulador::gravar_arquivo()
{
    ifstream arquivo;
    arquivo.open("Aquivo_Corrida_Carrinhos.txt");

    arquivo.close();
}