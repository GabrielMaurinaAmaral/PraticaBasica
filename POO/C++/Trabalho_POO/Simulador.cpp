#include "Simulador.h"
#include <iostream>
#include <fstream>

Simulador::Simulador()
{
    capacidade_veiculos = 20;
    quantidade_veiculos = 0;
    garagem = new Veiculo[capacidade_veiculos];
}

int Simulador::get_capacidade_veiculos()
{
    return capacidade_veiculos;
}

void Simulador::incluir_veiculo()
{
    if (capacidade_veiculos == quantidade_veiculos)
        cout << "Capacidade de veiculo está cheia" << endl;

    else if (quantidade_veiculos == 0)
    {
        int id = rand() % 20;
        garagem[id] = Veiculo(id);
        quantidade_veiculos++;
    }
    
    else
    {
        int id;
        do
        {
            id = rand() % capacidade_veiculos;
        } while (garagem[id].get_existe() == true);
        
        garagem[id] = Veiculo(id);
        quantidade_veiculos++;
        cout << "Quantdade de garagem na pista agora e " << quantidade_veiculos << endl;
    }
}

void Simulador::remover_veiculo(int id)
{
    if (garagem[id].get_existe() == true)
    {
        garagem[id] = Veiculo();
        quantidade_veiculos--;
        cout << "Veiculo com id " << id << "foi exluido da" << endl;
        cout << "Quantdade de garagem na pista agora é " << quantidade_veiculos << endl;
    }
    else
        cout << "Não existe nenhum vaiculo co ID " << id << "na pista para que seja excluido" << endl;
}

void Simulador::abastecer_veiculo(int id, float quantidade_gasosa)
{
    if (garagem[id].get_existe() == true)
        garagem[id].abastecer(quantidade_gasosa);
    else
        cout << "Não existe nenhum vaiculo co ID " << id << " na pista para que possa abastecer" << endl;
}

void Simulador::mover_veiculo(int id)
{
    if (garagem[id].get_existe() == true)
        garagem[id].mover();
    else
        cout << "Não existe nenhum vaiculo co ID " << id << " na pista para que possa movelo" << endl;
}

void Simulador::mover_todos_veiculos()
{
    for (int i = 0; i < 20; i++)
        if (garagem[i].get_existe() == true)
            garagem[i].mover();
}

void Simulador::mostrar_dados_veiculo(int id)
{
    if (garagem[id].get_existe() == true)
        garagem[id].mostrar_dados();
    else
        cout << "Não existe nenhum vaiculo co ID " << id << " na pista para que possa mostrar as informacoes" << endl;
}

void Simulador::mostrar_dados_todos_veiculos()
{
    for (int i = 0; i < 20; i++)
        if (garagem[i].get_existe() == true)
            garagem[i].mostrar_dados();
}

void Simulador::veiculo_mexer_pneu(int id, int id_pneu)
{
    if (garagem[id].get_existe() == true)
    {
        int opcao;
        cout << "esvaziar(1) ou encher(2)" << endl;
        cin >> opcao;

        if (id_pneu < quantidade_veiculos && quantidade_veiculos < id_pneu)
        {
            if (opcao == 1)
                garagem[id].esvaziar(id_pneu);
            else
                garagem[id].calibrar(id_pneu);
        }
        else
            cout << "Não existe esse pneu no veiculo com ID " << id << endl;
    }
    else
        cout << "Não existe nenhum vaiculo co ID " << id << " na pista para que possa mexer no pneu dele" << endl;
}

void Simulador::veiculo_mexer_todos_pneus(int id)
{
    if (garagem[id].get_existe() == true)
    {
        int opcao;
        cout << "esvaziar(1) ou encher(2) todos os penus" << endl;
        cin >> opcao;

        if (opcao == 1)
            for (int i = 0; i < garagem[id].get_quantidade_rodas(); i++)
                garagem[id].esvaziar(i);
        else
            for (int i = 0; i < garagem[id].get_quantidade_rodas(); i++)
                garagem[id].calibrar(i);
    }
    else
        cout << "Não existe nenhum vaiculo co ID " << id << " na pista para que possa mexer nos pneus dele" << endl;
}

void Simulador::imprimir_pista()
{
    cout << endl;
    for (int i = 0; i < 20; i++)
        if (garagem[i].get_existe() == true)
            garagem[i].imprimir_veiculo();
    cout << endl;
}

int Simulador::gravar_arquivo()
{
    ofstream arquivo_gravar("veiculos.dat", ios::binary);

    if (!arquivo_gravar.is_open())
    {
        cerr << "Erro ao abrir o arquivo_gravar!" << endl;
        return 1;
    }

    for (int i = 0; i < 20; i++)
        arquivo_gravar.write(reinterpret_cast<const char *>(&garagem[i]), sizeof(garagem[i]));
    arquivo_gravar.close();

    return 0;
}

int Simulador::ler_arquivo()
{
    ifstream arquivo_leitura("veiculos.dat", ios::binary);

    if (!arquivo_leitura.is_open())
    {
        cerr << "Erro ao abrir o arquivo_gravar!" << endl;
        return 1;
    }
    for (int i = 0; i < 20; i++)
        arquivo_leitura.read(reinterpret_cast<char*>(&garagem[i]), sizeof(garagem[i]));
    arquivo_leitura.close();
    
    return 0;
}
