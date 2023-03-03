#include <iostream>
using namespace std;

class Pessoa
{
private:
    int idade;
    string nome;

public:
    int peso;
    float altura;
    bool vivo;

    int get_idade() { return idade; }
    string get_nome() { return nome; }

    // sobrecarga de metodos
    Pessoa(int i, string n, int p, float a, bool v) : idade{i}, nome{n}, peso{p}, altura{a}, vivo{v} {}
    Pessoa()
    {
        idade = 18;
        nome = "jovem adulto";
        vivo = true;
        peso = 0;
        altura = 0.0;
    }
    Pessoa(int i) : idade{i}
    {
        if (i >= 18)
        {
            nome = "adulto";
            vivo = true;
            peso = 0;
            altura = 0.0;
        }
        else
        {
            nome = "crianca";
            vivo = true;
            peso = 0;
            altura = 0.0;
        }
    }

    void prinf()
    {
        cout << endl << get_nome() << endl;
        cout << get_idade() << endl;
        cout << vivo << endl;
        cout << peso << endl;
    }
};

int main()
{
    Pessoa p1{};
    Pessoa p2{15};
    Pessoa p3{20, "brenda", 65, 1.71, true};

    p1.prinf();
    p2.prinf();
    p3.prinf();

    return 0;
}