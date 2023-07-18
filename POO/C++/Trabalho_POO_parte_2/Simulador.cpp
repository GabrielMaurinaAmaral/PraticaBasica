#include "Simulador.h"

bool Simulador::verificar_id_existe(int id)
{
    for (Veiculo *veiculo : garagem)
        if (veiculo->get_id() == id)
            return true;
    return false;
}
Simulador::Simulador(int capacidade)
{
    capacidade_veiculos = capacidade;
    quantidade_veiculos = 0;
    std::cout << "SIMULAÇÃO COMEÇOU" << endl;
}

void Simulador::incluir_veiculo(char tipo)
{
    if (capacidade_veiculos == quantidade_veiculos)
        std::cout << "Capacidade de veículos está cheia" << endl;
    else
    {
        int id = rand() % 1000;
        while (verificar_id_existe(id))
            id = rand() % 1000;

        Veiculo *veiculo;
        if (tipo == 'B')
            veiculo = new Bicicleta(id, 2);
        else if (tipo == 'M')
            veiculo = new Motocicleta(id, 4);
        else if (tipo == 'C')
            veiculo = new Carro_Passeio(id, 4);
        else if (tipo == 'E')
            veiculo = new Carro_Esportivo(id, 4);

        garagem.push_back(veiculo);
        quantidade_veiculos = garagem.size();
        std::cout << veiculo->to_string() << endl;
        std::cout << "Quantidade de veículos na pista agora é " << quantidade_veiculos << endl;
    }
}

void Simulador::remover_veiculo(int id)
{
    for (int i = 0; i < garagem.size(); i++)
        if (garagem[i]->get_id() == id)
        {
            delete garagem[i];
            garagem.erase(garagem.begin() + i);
            quantidade_veiculos--;
            std::cout << "Veículo com ID " << id << " foi excluído da pista" << endl;
            std::cout << "Quantidade de veículos na pista agora é " << quantidade_veiculos << endl;
            break;
        }
    std::cout << "Não existe nenhum veículo com ID " << id << " na pista para ser excluído" << endl;
}

void Simulador::abastecer_veiculo(int id)
{
    for (Veiculo *veiculo : garagem)
        if (veiculo->get_id() == id)
        {
            Veiculo_Motorizado *motorizado = dynamic_cast<Veiculo_Motorizado *>(veiculo);
            if (motorizado != nullptr)
            {
                float quantidade_gasosa;
                std::cout << "Quantos litros de gasolina você quer colocar no tanque: ";
                cin >> quantidade_gasosa;
                motorizado->abastecer(quantidade_gasosa);
                break;
            }
            else
            {
                std::cout << "Bicicleta não pode ser abastecida" << endl;
                break;
            }
        }
    std::cout << "Não existe nenhum veículo com ID " << id << " na pista para ser abastecido" << endl;
}

void Simulador::mover_veiculo(int id)
{
    for (Veiculo *veiculo : garagem)
        if (veiculo->get_id() == id)
        {
            veiculo->mover();
            break;
        }
    std::cout << "Não existe nenhum veículo com ID " << id << " na pista para ser movido" << endl;
}

void Simulador::mover_veiculos_tipo(char tipo)
{
    for (Veiculo *veiculo : garagem)
        if (veiculo->get_tipo() == tipo)
            veiculo->mover();
}

void Simulador::mover_todos_veiculos()
{
    for (Veiculo *veiculo : garagem)
    {
        veiculo->mover();
    }
}

void Simulador::mostrar_dados_veiculos_tipo(char tipo)
{
    for (Veiculo *veiculo : garagem)
    {
        if (veiculo->get_tipo() == tipo)
        {
            std::cout << veiculo->to_string() << endl;
        }
    }
}

void Simulador::mostrar_dados_todos_veiculos()
{
    for (Veiculo *veiculo : garagem)
    {
        std::cout << veiculo->to_string() << endl;
    }
}

void Simulador::veiculo_mexer_pneu(int id)
{
    for (Veiculo *veiculo : garagem)
    {
        if (veiculo->get_id() == id)
        {
            int id_pneu = 0;
            for (string roda : veiculo->get_rodas())
            {
                std::cout << "Pneu " << id_pneu << " está " << roda << endl;
                id_pneu++;
            }

            int pneu_escolhido;
            std::cout << "Qual pneu você quer mexer? ";
            cin >> pneu_escolhido;

            if (pneu_escolhido >= 0 && pneu_escolhido < veiculo->get_quantidade_rodas())
            {
                int opcao;
                std::cout << "Esvaziar(1) ou encher(2)? ";
                cin >> opcao;

                if (opcao == 1)
                {
                    veiculo->esvaziar_pneu(pneu_escolhido);
                }
                else if (opcao == 2)
                {
                    veiculo->calibrar_pneu(pneu_escolhido);
                }
                else
                {
                    std::cout << "Digite 1 para esvaziar ou 2 para encher" << endl;
                }
            }
            else
            {
                std::cout << "Não existe esse pneu no veículo com ID " << id << endl;
            }

            return;
        }
    }
    std::cout << "Não existe nenhum veículo com ID " << id << " na pista para mexer no pneu" << endl;
}

void Simulador::calibrar_veiculos_tipo(char tipo)
{
    for (Veiculo *veiculo : garagem)
    {
        if (veiculo->get_tipo() == tipo)
        {
            for (int i = 0; i < veiculo->get_quantidade_rodas(); i++)
            {
                veiculo->calibrar_pneu(i);
            }
        }
    }
}

void Simulador::imprimir_pista()
{
    for (Veiculo *veiculo : garagem)
    {
        veiculo->desenhar();
    }
}

void Simulador::gravar_arquivo()
{
    if (garagem.size() > 0)
    {
        ofstream file("veiculos.bin", ios::binary);
        int tamanho = garagem.size();
        file.write(reinterpret_cast<char *>(&tamanho), sizeof(tamanho));
        for (Veiculo *veiculo : garagem)
        {
            veiculo->escrever_arquivo(file);
        }
        file.close();
        std::cout << "Veículos gravados com sucesso" << endl;
    }
    else
    {
        std::cout << "Não há veículos para serem gravados" << endl;
    }
}

void Simulador::ler_arquivo()
{
    ifstream file("veiculos.bin", ios::binary);
    if (file)
    {
        int tamanho;
        file.read(reinterpret_cast<char *>(&tamanho), sizeof(tamanho));
        for (int i = 0; i < tamanho; i++)
        {
            Veiculo *veiculo = Veiculo::ler_arquivo(file);
            garagem.push_back(veiculo);
        }
        file.close();
        std::cout << "Veículos lidos com sucesso" << endl;
    }
    else
    {
        std::cout << "Nenhum arquivo encontrado" << endl;
    }
}
