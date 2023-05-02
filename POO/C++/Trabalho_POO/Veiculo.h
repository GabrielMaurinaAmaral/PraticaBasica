#ifndef VEICULO_H
#define VEICULO_H
#include "Rodas.cpp"

class Veiculo
{
private:
    int id, distancia_percorrida; 
    //static int quantidade_rodas = 4;   -> não roda isso prof, tentei de tudo que é jeito, em teoria é pq eu fiz uma .h pra declara a variavel e a static teve ser iniciaizado com uma valor na mesma linha.
    //static int quantidade_rodas;
    string desenho;
    float combustivel, valor_venda;
    bool ipva, existe;
    Rodas rodas[4];

public:
    Veiculo();
    Veiculo(int);
    bool get_existe();
    int get_quantidade_rodas();
    void mover();
    void imprimir_veiculo();
    bool verificar_todos_pneus();
    void abastecer(float);
    void consumir(float);
    void mostrar_dados();
    void calibrar(int);
    void esvaziar(int);
};

#endif