#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Simulador.cpp"

int main()
{
    Simulador menu(20);
    int opcao = 0;
    int dado_int_1 = 0;
    int dado_int_2 = 0;
    float dado_float = 0.0;
    char dado_char = 'a';

    while (opcao != 15)
    {
        std::cout << "\nMENU - Escolha uma das opcoes abaixo" << std::endl;
        std::cout << "1  - Incluir veiculo na pista" << std::endl;
        std::cout << "2  - Remover veiculo na pista" << std::endl;
        std::cout << "3  - Abastecer veiculo" << std::endl;
        std::cout << "4  - Movimentar veiculo" << std::endl;
        std::cout << "5  - Movimentar veiculos por tipo" << std::endl;
        std::cout << "6  - Movimentar todos os veiculos" << std::endl;
        std::cout << "7  - Imprimir todos os dados de todos os veiculos" << std::endl;
        std::cout << "8  - Imprimir todos os dados de veiculos por tipo" << std::endl;
        std::cout << "9  - Calibrar um pneu especifico" << std::endl;
        std::cout << "10 - Calibrar todos os pneus de um veiculo especifico" << std::endl;
        std::cout << "11 - Esvaziar todos os pneus de um veiculo especifico" << std::endl;
        std::cout << "12 - Imprimir pista de corrida" << std::endl;
        std::cout << "13 - Gravar veiculos em arquivo" << std::endl;
        std::cout << "14 - Ler veiculos do arquivo" << std::endl;
        std::cout << "15 - Sair da aplicacao" << std::endl;
        std::cout << std::endl;

        try
        {
            std::cout << "Digite sua opcao: ";
            std::cin >> opcao;

            if (opcao == 1)
            {
                std::cout << "\tB - Bicicleta" << std::endl;
                std::cout << "\tM - Motocicleta" << std::endl;
                std::cout << "\tC - Carro Passeio" << std::endl;
                std::cout << "\tE - Carro esportivo" << std::endl;
                std::cout << "Que tipo de veiculo você quer incluir? ";
                std::cin >> dado_char;

                if (dado_char == 'E' || dado_char == 'B' || dado_char == 'M' || dado_char == 'C')
                {
                    try
                    {
                        menu.incluir_veiculo(dado_char);
                    }
                    catch (const std::invalid_argument &e)
                    {
                        std::cout << "Opção não existente" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Opção inválida" << std::endl;
                }
            }
            else if (opcao == 2)
            {
                std::cout << "Em qual veiculo você quer remover? Informe o ID: ";
                std::cin >> dado_int_1;
                menu.remover_veiculo(dado_int_1);
            }
            else if (opcao == 3)
            {
                std::cout << "Em qual veiculo você quer abastecer? Informe o ID: ";
                std::cin >> dado_int_1;
                menu.abastecer_veiculo(dado_int_1);
            }
            else if (opcao == 4)
            {
                std::cout << "Em qual veiculo você quer mover? Informe o ID: ";
                std::cin >> dado_int_1;
                menu.mover_veiculo(dado_int_1);
            }
            else if (opcao == 5)
            {
                std::cout << "\tB - Bicicleta" << std::endl;
                std::cout << "\tM - Motocicleta" << std::endl;
                std::cout << "\tC - Carro Passeio" << std::endl;
                std::cout << "\tE - Carro esportivo" << std::endl;
                std::cout << "Que tipo de veiculo você quer mover? ";
                std::cin >> dado_char;
                menu.mover_veiculos_tipo(dado_char);
            }
            else if (opcao == 6)
            {
                menu.mover_todos_veiculos();
            }
            else if (opcao == 7)
            {
                menu.mostrar_dados_todos_veiculos();
            }
            else if (opcao == 8)
            {
                std::cout << "Mostrar dados dos veiculos de qual tipo: ";
                std::cin >> dado_char;
                menu.mostrar_dados_veiculos_tipo(dado_char);
            }
            else if (opcao == 9)
            {
                std::cout << "Qual veiculo você quer mexer nos pneus? Informe o ID: ";
                std::cin >> dado_int_1;
                menu.veiculo_mexer_pneu(dado_int_1);
            }
            else if (opcao == 10)
            {
                std::cout << "Mostrar dados dos veiculos de qual tipo: ";
                std::cin >> dado_char;
                menu.calibrar_veiculos_tipo(dado_char);
            }
            else if (opcao == 12)
                menu.imprimir_pista();
            else if (opcao == 13)
                menu.gravar_arquivo();
            else if (opcao == 14)
                menu.ler_arquivo();
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Opcao não existente, tente novamente" << std::endl;
        }
    }
    std::cout << "Encerrando a aplicacao." << std::endl;

    return 0;
}
