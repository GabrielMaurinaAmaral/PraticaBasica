#include <iostream>
using namespace std;

class Conta
{
private:
    string nomeCorrentista;
    float saldo;

public:
    Conta();
    Conta(string, float);
    ~Conta();
    void setNome(string);
    void setSaldo(float);
    string getNome();
    float getSaldo();
    void depositar(float);
    void retirar(float);
    void mostrarConta();
};