#include "Veiculo.h"

Veiculo::Veiculo()
{
    existe = false;
    // cout << "Veiculo foi construido na garagem" << endl;
}

Veiculo::Veiculo(int ID) : id{ID}
{
    existe = true;
    static int quantidade_rodas = 4;
    distancia_percorrida = 0;
    desenho = "    ____\n __/ |_ \\._\n|  _     _``-.\n-(_)---(_)--\n";
    combustivel = 1;
    valor_venda = 100;
    ipva = rand() % 2;
    for (int i = 0; i < quantidade_rodas; i++)
        rodas[i] = Rodas();
    cout << "Veiculo com ID " << id << " foi inicializado na pista" << endl;
}

bool Veiculo::get_existe()
{
    return existe;
}

int Veiculo::get_quantidade_rodas()
{
    return quantidade_rodas;
}

void Veiculo::mover()
{
    if (combustivel >= 0.55 && ipva == true && verificar_todos_pneus() == true)
    {
        consumir(0.55);
        distancia_percorrida++;
    }
    else
    {
        if (combustivel < 0.55)
            cout << "Veiculo ID " << id << " nao possui combustivel suficiente" << endl;
        if (ipva == false)
            cout << "Veiculo ID " << id << " nao possui o ipva pago" << endl;
        if (verificar_todos_pneus() == false)
            cout << "Veiculo ID " << id << " nao possui todos os pneus calibrados" << endl;
    }
}

void Veiculo::abastecer(float abastecer)
{
    combustivel += abastecer;
    cout << "Tanque de combustivel esta agora com " << combustivel << " de combustivel" << endl;
}

void Veiculo::consumir(float consumir)
{
    if (combustivel > 0)
    {
        combustivel -= consumir;
        cout << "Tanque de combustivel esta agora com " << combustivel << " de combustivel" << endl;
    }
    else
        cout << "Sem gosolina para consumir" << endl;
    if (combustivel < 0)
        combustivel = 0;
}

bool Veiculo::verificar_todos_pneus()
{
    bool result;
    for (int i = 0; i < quantidade_rodas; i++)
        result = rodas[i].get_calibragem();
    if (result == false)
        return result;
    return result;
}

void Veiculo::calibrar(int id_pneu)
{
    rodas[id_pneu].set_calibragem(true);
    cout << "Pneu: " << id_pneu << " -> calibrado" << endl;
}

void Veiculo::esvaziar(int id_pneu)
{
    rodas[id_pneu].set_calibragem(false);
    cout << "Pneu: " << id_pneu << " -> esvaziado" << endl;
}

void Veiculo::imprimir_veiculo()
{
    int i;
    for (i = 0; i < distancia_percorrida; i++)
        cout << "     ";
    cout << "    ____" << endl;
    for (i = 0; i < distancia_percorrida; i++)
        cout << "     ";
    cout << " __/ |_ \\._" << endl;
    for (i = 0; i < distancia_percorrida; i++)
        cout << "     ";
    cout << "|  _     _``-." << endl;
    for (i = 0; i < distancia_percorrida; i++)
        cout << "     ";
    cout << "-(_)---(_)--\n"
         << endl;
}

void Veiculo::mostrar_dados()
{
    cout << "\nID: " << id << endl;
    cout << "IPVA: ";
    if (ipva == true)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;
    cout << "Combustivel: " << combustivel << endl;
    cout << "Valor de venda: " << valor_venda << endl;
    cout << "Distancia percorrida: " << distancia_percorrida << endl;
    cout << "Quantidade de rodas: " << quantidade_rodas << endl;
    for (int i = 0; i < quantidade_rodas; i++)
    {
        cout << "Roda " << i << ": ";
        if (rodas[i].get_calibragem() == true)
            cout << "calibrada" << endl;
        else
            cout << "decalibrada" << endl;
    }
}