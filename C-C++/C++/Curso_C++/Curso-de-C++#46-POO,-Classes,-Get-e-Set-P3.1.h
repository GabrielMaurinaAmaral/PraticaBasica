#include <iostream>
using namespace std;

#ifndef PESSOA_H
#define PESSOA_H

class Pessoa
{
private: // dados privados
    int idade;
    string sobrenome;
    float altura, peso;
    bool vivo;
    void set_dados(int i, string n, string s, float a, float p);

public: //dados publicos
    string nome; 
    Pessoa();
    void get_dados();
    void imprimir();
};

Pessoa::Pessoa() // metodo construtor
{
    idade = 0;
    nome = sobrenome = "";
    altura = peso = 0.0;
    vivo = true;
}
void Pessoa::get_dados() // inseir dados
{
    cout << "\nIdade..: ", cin >> idade;
    cout << "Nome.....: ", cin >> nome;
    cout << "Sobrenome: ", cin >> sobrenome;
    cout << "Altura...: ", cin >> altura;
    cout << "Peso.....: ", cin >> peso;
}

void Pessoa::set_dados(int i, string n, string s, float a, float p) // trocar dados
{
    idade = i;
    nome = n;
    sobrenome = s;
    altura = a;
    peso = p;
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