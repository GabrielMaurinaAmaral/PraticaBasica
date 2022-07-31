#include <iostream>
using namespace std;

class Pessoa
{
private:
    int idade;
    string nome, sobrenome;
    float altura, peso;

public:
    void iniciar(int tipo);
    void imprimir();

};

void Pessoa::iniciar(int tipo)
{
    if (tipo == 1)
    {
        this->idade = 0;
        this->nome = this->sobrenome = "";
        this->altura = this->peso = 0.0;
    }
    else if (tipo == 2)
    {
        cout << "\nIdade: ", cin >> this->idade;
        cout << "Nome: ", cin >> this->nome;
        cout << "Sobrenome: ", cin >> this->sobrenome;
        cout << "Altura: ", cin >> this->altura;
        cout << "Peso: ", cin >> this->peso;
    }
}

void Pessoa::imprimir()
{
    cout << "\nIdade: " << this->idade;
    cout << "\nNome: " << this->nome;
    cout << "\nSobrenome: " << this->sobrenome;
    cout << "\nAltura: " << this->altura;
    cout << "\nPeso: " << this->peso << endl;
}