#include "Aula_4_Pessoa.h"

Pessoa::Pessoa()
{
    nome = "-";
    cpf = "-";
    anoNascimento = 0;
    idade = 0;
    peso = 0.0;
    altura = 0.0;
    cout << "objeto criado" << "\n";
}

Pessoa::Pessoa(string n, string c, int anoN, int i, float p, float a)
{
    nome = n;
    cpf = c;
    anoNascimento = anoN;
    idade = i;
    peso = p;
    altura = a;
    cout << "objeto criado"
         << "\n";
}

Pessoa::~Pessoa()
{
    cout << "objeto destruido"
         << "\n";
}

void Pessoa::set_nome(string n)
{
    nome = n;
}
void Pessoa::set_cpf(string c)
{
    cpf = c;
}
void Pessoa::set_ano(int ano)
{
    anoNascimento = ano;
}
void Pessoa::set_idade(int i)
{
    idade = i;
}

void Pessoa::set_peso(float p)
{
    peso = p;
}

void Pessoa::set_altura(float a)
{
    altura = a;
}

void Pessoa::imprimir_dados()
{
    cout << nome << "\n";
    cout << cpf << "\n";
    cout << anoNascimento << "\n";
    cout << idade << "\n";
    cout << peso << "\n";
    cout << altura << "\n\n";
}