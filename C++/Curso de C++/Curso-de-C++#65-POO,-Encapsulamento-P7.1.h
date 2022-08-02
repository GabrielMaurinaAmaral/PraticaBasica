#include <iostream>
using namespace std;

class Pessoa
{
private:
    int idade;
    float altura;
    bool vivo;
    void set_vivo(bool v) { this->vivo = v; }

public:
    string nome;
    // construtor
    Pessoa(bool v, string n, int i, float a) : nome{n}, vivo{v}, idade{i}, altura{a} {}
    
    void set_idade(int i) { this->idade = i; }
    void set_altura(float a) { this->altura = a; }

    int get_idade() { return this->idade; }
    float get_altura() { return this->altura; }
    bool get_vivo() { return this->vivo; }
};