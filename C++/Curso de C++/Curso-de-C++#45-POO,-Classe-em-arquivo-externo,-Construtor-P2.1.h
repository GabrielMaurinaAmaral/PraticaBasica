#include <iostream>
using namespace std;

#ifndef PESSOA_H
#define PESSOA_H

class Pessoa
{
private:
    int idade;
    string nome, sobrenome;
    float altura, peso;

public:
    Pessoa (int tipo);
    void imprimir();

};

Pessoa::Pessoa(int tipo) //metodo construtor
{
    if (tipo == 1)
    {
        idade = 0;
        nome = sobrenome = "";
        altura = peso = 0.0;
    }
    else if (tipo == 2)
    {
        cout << "\nIdade..: ", cin >> idade;
        cout << "Nome.....: ", cin >> nome;
        cout << "Sobrenome: ", cin >> sobrenome;
        cout << "Altura...: ", cin >> altura;
        cout << "Peso.....: ", cin >> peso;
    }
}

void Pessoa::imprimir()
{
    cout << "\nIdade....: " << idade;
    cout << "\nNome.....: " << nome;
    cout << "\nSobrenome: " << sobrenome;
    cout << "\nAltura...: " << altura;
    cout << "\nPeso.....: " << peso << endl;
}

#endif