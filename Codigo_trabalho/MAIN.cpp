#include "Simulador.cpp"

int main()
{
    Simulador menu = Simulador();
    int opcao;
    int x, z;
    float y;

    do
    {
        cout << "\n     MENU" << endl;
        cout << "     Escolha uma das opoes" << endl;
        cout << "1  - Incluir veiculo" << endl;
        cout << "2  - Remover veiculo" << endl;
        cout << "3  - Abastecer veiculo" << endl;
        cout << "4  - Movimentar veiculo" << endl;
        cout << "5  - Movimentar todos os veiculos" << endl;
        cout << "6  - Imprimir todos os dados de um veiculo" << endl;
        cout << "7  - Imprimir todos os dados de todos os veiculos" << endl;
        cout << "8  - Esvaziar/calibrar um pneu especifico," << endl;
        cout << "9  - Esvaziar/calibrar todos os pneus de um veiculo especifico" << endl;
        cout << "10 - Imprimir pista de corrida" << endl;
        cout << "11 - Gravar veiculos em arquivo" << endl;
        cout << "12 - Ler veiculos do arquivo" << endl;
        cout << "13 - Sair da aplicacao\n"
             << endl;

        cin >> opcao;

        switch (opcao)
        {
        case 1:
            menu.incluir_veiculo();
            break;
        case 2:
            cout << "Em qual veiculo vc quer remover o veiculo? " << endl;
            cin >> x;
            menu.remover_veiculo(x);
            break;
        case 3:
            cout << "Em qual veiculo vc quer abastecer? " << endl;
            cin >> x;
            cout << "Quando de gasosa vc quer colocar no tanque consagrado? " << endl;
            cin >> y;
            menu.abastecer_veiculo(x, y);
            break;
        case 4:
            cout << "Em qual veiculo vc quer mover? " << endl;
            cin >> x;
            menu.mover_veiculo(x);
            break;
        case 5:
            menu.mover_todos_veiculos();
            break;
        case 6:
            cout << "Mostra dados de qual veiculo? " << endl;
            cin >> x;
            menu.mostrar_dados_veiculo(x);
            break;
        case 7:
            menu.mostrar_dados_todos_veiculos();
            break;
        case 8:
            cout << "Qual veiculo vc quer mexer nos pneus? " << endl;
            cin >> x;
            cout << "qual pneus vc quer encher 1,2,3 ou 4: " << endl;
            cin >> z;
            menu.veiculo_mexer_pneu(x, z);
        case 9:
            cout << "Qual veiculo vc quer mexer nos pneus? " << endl;
            cin >> x;
            menu.veiculo_mexer_todos_pneus(x);
            break;
        case 10:
            menu.imprimir_pista();
            break;
        case 11:
            break;
        case 12:
            break;
        default:
            break;
        }

    } while (opcao != 13);

    return 0;
}