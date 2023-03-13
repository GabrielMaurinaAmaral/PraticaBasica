#include <iostream>
using namespace std;

class Carro
{
private:
    int velocidade, velMax;
    string marca;

public:
    // construtor
    Carro();
    Carro(int, int, string);
    ~Carro();
    // metodos
    void set_carro(int, int, string);
    void get_carro();
};