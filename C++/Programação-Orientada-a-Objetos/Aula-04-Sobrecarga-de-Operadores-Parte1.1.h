#ifndef COMPLEXO_H
#define COMPLEXO_H

class Complexo
{
private:
    float real, imaginario;

public:
    //contruir e destruir
    Complexo(float = 0.0, float = 0.0);
    ~Complexo();

    //interface
    void print()const;
    Complexo add(Complexo&);
    Complexo sub(Complexo&);

    //sobrecarga de operadores
    Complexo operator+(Complexo&); //+1
    Complexo operator-(Complexo&); //-1
    bool operator!();
    Complexo& operator++();  //invremento
    Complexo operator++(int); //pos-incremento
};


#endif