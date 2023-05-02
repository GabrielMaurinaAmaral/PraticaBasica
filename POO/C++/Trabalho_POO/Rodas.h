#ifndef RODAS_H
#define RODAS_H

class Rodas
{
private:
    bool calibragem_pneu;
public:
    Rodas();
    void set_calibragem(bool);
    bool get_calibragem();
    void imprimir();
};

#endif