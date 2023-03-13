#include <iostream>
using namespace std;

class Veiculo
{
private:
    string cor;
    string nome;

public:
    int rodas;
    float velmax;
    bool ligado;

    string get_cor() { return cor; }
    string get_nome() { return nome; }
    void set_cor(string c) { cor = c; }
    void set_nome(string n) { nome = n; }

    // sobrecarga de metodos
    // Veiculo(string n, string c, int r, float v, bool l) : cor{c}, nome{n}, rodas{r}, velmax{v}, ligado{l} {}

    virtual void print()
    {
        cout << get_nome() << endl;
        cout << get_cor() << endl;
        cout << velmax << endl;
        cout << ligado << endl;
        cout << rodas << endl
             << endl;
    }
};

class Carro : public Veiculo
{
public:
    Carro()
    {
        set_nome("Carro");
        set_cor("Preto");
        velmax = 180;
        rodas = 4;
        ligado = true;
    }
};

class Moto : public Veiculo
{
public:
    Moto()
    {
        set_nome("Moto");
        set_cor("Vermelho");
        velmax = 200;
        rodas = 2;
        ligado = true;
    }
};

class Caminhao : public Veiculo
{
public:
    int carga_max;
    bool cargueiro;

    Caminhao(int cm, bool c) : carga_max{cm}, cargueiro{c}
    {
        set_nome("Caminhao");
        set_cor("Verde");
        velmax = 140;
        rodas = 8;
        ligado = true;
        if (c)
            carga_max = cm;
        else
            carga_max = 0;
    }
    void print() override
    {
        cout << get_nome() << endl;
        cout << get_cor() << endl;
        cout << velmax << endl;
        cout << ligado << endl;
        cout << rodas << endl;
        cout << cargueiro << endl;
        cout << carga_max << endl
             << endl;
    }
};