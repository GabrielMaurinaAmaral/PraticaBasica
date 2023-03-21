#include <iostream>
using namespace std;

class Pessoa
{
private:
    string nome, cpf;
    int anoNascimento, idade;
    float peso, altura;

public:
    Pessoa();
    Pessoa(string, string, int, int, float, float);
    ~Pessoa();
    void set_nome(string);
    void set_cpf(string);
    void set_ano(int);
    void set_idade(int);
    void set_peso(float);
    void set_altura(float);
    void imprimir_dados();
};