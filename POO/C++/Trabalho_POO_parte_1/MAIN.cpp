#include "Simulador.cpp"

int main()
{
    Simulador menu = Simulador();
    int opcao;
    int id, id_pneu;
    float gasolina;

    do
    {
        cout << "\nMENU - Escolha uma das opcoes a baixo" << endl;
        cout << "1  - Incluir veiculo na pista" << endl;
        cout << "2  - Remover veiculo na pista" << endl;
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
            do
            {
                cout << "Em qual veiculo vc quer remover o veiculo, informe o ID? " << endl;
                cin >> id;
                if (0 > id || id > menu.get_capacidade_veiculos())
                    cout << "So e possivel escolher o invertavo do ID entre 0 a " << menu.get_capacidade_veiculos() << endl
                         << endl;
            } while (0 > id || id > menu.get_capacidade_veiculos());
            menu.remover_veiculo(id);
            break;

        case 3:
            do
            {
                cout << "Em qual veiculo vc quer abastecer, informe o ID? " << endl;
                cin >> id;
                if (0 > id || id > menu.get_capacidade_veiculos())
                    cout << "So e possivel escolher o invertavo do ID entre 0 a " << menu.get_capacidade_veiculos() << endl
                         << endl;
            } while (0 > id || id > menu.get_capacidade_veiculos());
            do
            {
                cout << "Quantos Litros de gasosa vc quer colocar no tanque consagrado? " << endl;
                cin >> gasolina;
                if (gasolina < 0)
                    cout << "Quantidade não possivel, digite apenas numeros positivos" << endl
                         << endl;
            } while (gasolina < 0);
            menu.abastecer_veiculo(id, gasolina);
            break;

        case 4:
            do
            {
                cout << "Em qual veiculo vc quer mover? " << endl;
                cin >> id;
                if (0 > id || id > menu.get_capacidade_veiculos())
                    cout << "Só é possivel escolher o invertavo do ID entre 0 a " << menu.get_capacidade_veiculos() << endl
                         << endl;
            } while (0 > id || id > menu.get_capacidade_veiculos());
            menu.mover_veiculo(id);
            break;

        case 5:
            menu.mover_todos_veiculos();
            break;

        case 6:
            do
            {
                cout << "Mostra dados de qual veiculo? " << endl;
                cin >> id;
                if (0 > id || id > menu.get_capacidade_veiculos())
                    cout << "Só é possivel escolher o invertavo do ID entre 0 a " << menu.get_capacidade_veiculos() << endl
                         << endl;
            } while (0 > id || id > menu.get_capacidade_veiculos());
            menu.mostrar_dados_veiculo(id);
            break;

        case 7:
            menu.mostrar_dados_todos_veiculos();
            break;

        case 8:
            do
            {
                cout << "Qual veiculo vc quer mexer nos pneus, informe o ID? " << endl;
                cin >> id;
                if (0 > id || id > menu.get_capacidade_veiculos())
                    cout << "Só é possivel escolher o invertavo do ID entre 0 a " << menu.get_capacidade_veiculos() << endl
                         << endl;
            } while (0 > id || id > menu.get_capacidade_veiculos());
            do
            {
                cout << "qual pneu vc quer encher 1,2,3 ou 4: " << endl;
                cin >> id_pneu;
                if (0 > id_pneu || id_pneu > 5)
                    cout << "Não é possivel isso, apenas escolha 1,2,3 ou 4 para escolher o pneu" << endl;
            } while (0 > id_pneu || id_pneu > 5);
            menu.veiculo_mexer_pneu(id, id_pneu - 1);

        case 9:
            do
            {
                cout << "Qual veiculo vc quer mexer nos pneus, informe o ID? " << endl;
                cin >> id;
                if (0 > id || id > menu.get_capacidade_veiculos())
                    cout << "Só é possivel escolher o invertavo do ID entre 0 a " << menu.get_capacidade_veiculos() << endl
                         << endl;
            } while (0 > id || id > menu.get_capacidade_veiculos());
            menu.veiculo_mexer_todos_pneus(id);
            break;

        case 10:
            menu.imprimir_pista();
            break;
        case 11:
            menu.gravar_arquivo();
            break;
        case 12:
            menu.ler_arquivo();
            break;
        case 13:
            break;
        default:
            break;
        }
    } while (opcao != 13);

    return 0;
}