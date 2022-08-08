#include <iostream>
using namespace std;

#ifndef PILHA_H
#define PILHA_H

template <typename T>
class Pilha
{
private:
    int size;
    int topo;
    T *pilha;

public:
    Pilha(int = 10);
    ~Pilha()
    {
        delete[] pilha;
    }

    bool push(T &);
    bool pop(T &);
    bool pilha_vazia()
    {
        return topo == -1 ? true : false;
    }
    bool pilha_cheia()
    {
        return topo == size - 1 ? true : false;
    }
};
#endif