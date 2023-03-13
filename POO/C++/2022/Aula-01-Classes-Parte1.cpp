#include <iostream>
using namespace std;

class Carro
{
private:
    float velocidade;

public:
    // costrutor
    Carro(float v) : velocidade{v} {}
    Carro()
    {
        velocidade = 0;
    }
    // destruidor
    ~Carro() {}

    void definir_velocidade(float v)
    {
        if (v <= 200 && v > 0)
            velocidade = v;
        else
            velocidade = 0;
    }
    void acelerar(float v)
    {
        if ((velocidade + v) <= 200)
            velocidade += v;
        else
            velocidade = 200;
    }
};

class Pessoa
{
private:
    string nome, cpf;
    int ano_nascimeto;

public:
    Pessoa(string n, string c, int a) : nome{n}, cpf{c}, ano_nascimeto{a} {}
    Pessoa()
    {
        nome = "";
        cpf = "";
        ano_nascimeto = 0;
    }
    ~Pessoa() {}

    void imprimir_dados()
    {
        cout << "Nome: " << nome << endl;
        cout << "CPF: " << cpf << endl;
        cout << "Ano de Nascimento: " << ano_nascimeto << endl << endl;
    }
};

int main()
{
    Carro c1{};
    Carro c2{100};

    c1.definir_velocidade(150);
    c1.acelerar(400);
    c1.definir_velocidade(300);

    Pessoa p1{};
    Pessoa p2{"gabreil", "whg24g", 2000};
    p1.imprimir_dados();
    p2.imprimir_dados();

    return 0;
}