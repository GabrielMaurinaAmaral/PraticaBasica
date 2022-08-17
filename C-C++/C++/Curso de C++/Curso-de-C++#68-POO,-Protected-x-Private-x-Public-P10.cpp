#include <iostream>
using namespace std;

class Veiculo
{
private:
    int velmax, potencia;

public:
    int rodas;
    const char *nome;

protected:
    int portas;
    const char *cor;
};

class Carro : public Veiculo
{
public:
    Carro()
    {
        // velmax=180
        // potencia=500
        rodas = 4;
        nome = "Carro";
        portas = 4;
        cor = "Preto";
        // cout << velmax() << endl;
        // cout << potencia() << endl;
        cout << rodas << endl;
        cout << nome << endl;
        cout << portas << endl;
        cout << cor << endl
             << endl;
    }
};
class Moto
{
public:
    Carro c;

    Moto()
    {
        // velmax=180
        // potencia=500
        c.rodas = 2;
        c.nome = "Moto";
        // portas = 0;
        // cor = "Vermelho";
        cout << c.nome << endl;
        cout << c.rodas << endl;
        // cout << portas << endl;
        // cout << cor << endl
    }
};

int main()
{
    Carro v1;
    Moto v2;

    return 0;
}