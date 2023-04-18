#include "Veiculo.h"

Veiculo::Veiculo()
{
}

Veiculo::Veiculo(int ID) : id{ID}
{
    quantidade_rodas = 4;
    distancia_percorrida = 0;
    combustivel = 0;
    valor_venda = 100;
    ipva = rand() % 2;
    for (int i = 0; i < quantidade_rodas; i++)
        rodas[i] = Rodas();

    cout << "veiculo com ID " << id << " foi criado" << endl;
}

int Veiculo::get_quantidade_rodas()
{
    if (ligado == true)
    {
        return this->quantidade_rodas;
    }
}

void Veiculo::mover()
{
    if (ligado == true)
    {
        if (this->combustivel >= 0.55 && this->ipva == true && verificar_todos_pneus() == true)
            this->distancia_percorrida++;
        else
            cout << "veiculo não possui todos os requisitos para moverse";
    }
}

void Veiculo::abastecer(float abastecer)
{
    if (ligado == true)
    {
        this->combustivel += abastecer;
    }
}

void Veiculo::consumir(float consumir)
{
    if (ligado == true)
    {
        this->combustivel -= consumir;
    }
}

bool Veiculo::verificar_todos_pneus()
{
    bool result;
    if (ligado == true)
    {
        for (int i = 0; i < this->quantidade_rodas; i++)
            result = this->rodas[i].get_calibragem();
        return result;
    }
}
void Veiculo::calibrar(int id_pneu)
{
    if (ligado == true)
    {
        this->rodas[id_pneu].set_calibragem(true);
    }
}

void Veiculo::esvaziar(int id_pneu)
{
    if (ligado == true)
    {
        this->rodas[id_pneu].set_calibragem(false);
    }
}

void Veiculo::imprimir_veiculo()
{
    if (ligado == true)
    {
        int i;
        for (i = 0; i < quantidade_rodas; i++)
            cout << "     ";
        cout << "    ____" << endl;
        for (i = 0; i < quantidade_rodas; i++)
            cout << "     ";
        cout << " __/ |_ \\._" << endl;
        for (i = 0; i < quantidade_rodas; i++)
            cout << "     ";
        cout << "|  _     _``-." << endl;
        for (i = 0; i < quantidade_rodas; i++)
            cout << "     ";
        for (i = 0; i < quantidade_rodas; i++)
            cout << "     ";
        cout << "'-(_)---(_)--'" << endl;
        for (i = 0; i < quantidade_rodas; i++)
            cout << '---------------------' << endl;
    }
}

void Veiculo::mostrar_dados()
{
    if (ligado = true)
    {
        cout << "id: " << this->id << endl;
        cout << "valor de venda: " << this->valor_venda << endl;
        cout << "distancia percorrida: " << this->distancia_percorrida << endl;
        cout << "combustivel: " << this->combustivel << endl;
        cout << "ipva: " << this->ipva << endl;
        cout << "quantidade de rodas: " << this->quantidade_rodas << endl;
        cout << "Rodas: " << this->rodas << endl;
        for (int i = 0; i < this->quantidade_rodas; i++)
        {
            cout << "Roda " << i << ": " << this->rodas[i].get_calibragem() << endl;
        }
    }
}
