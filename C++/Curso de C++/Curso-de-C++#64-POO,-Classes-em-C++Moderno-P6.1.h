#include <iostream>
using namespace std;

class Pessoa
{
public:
    int idade;
    float altura;
    string nome;
    bool vivo;

    // construtor (lista de inicialização)
    Pessoa(bool v, string n, int i, float a) : nome{n}, vivo{v}, idade{i}, altura{a} {}
};