#include "Aula_4_Conta.h"

Conta::Conta()
{
    nomeCorrentista = "-", saldo = 0;
    cout << "objeto criado\n";
}

Conta::Conta(string n, float s) : nomeCorrentista{n}, saldo{s}
{
    cout << "objeto criado\n";
}

Conta::~Conta()
{
    cout << "objeto destruido\n";
}

void Conta::setNome(string n)
{
    nomeCorrentista = n;
}

void Conta::setSaldo(float s)
{
    saldo = s;
}

string Conta::getNome()
{
    return nomeCorrentista;
}

float Conta::getSaldo()
{
    return saldo;
}

void Conta::depositar(float quantia)
{
    saldo += quantia;
}

void Conta::retirar(float quantia)
{
    if (quantia <= saldo)
        saldo -= quantia;
    else
        cout << "não é possivel\n";
}

void Conta::mostrarConta()
{
    cout << "\nNome: " << nomeCorrentista;
    cout << "\nSaldo: " << saldo << endl;
}