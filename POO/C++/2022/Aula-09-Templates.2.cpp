#include "Aula-09-Templates.1.h"
#include <iostream>
using namespace std;

template <typename T>
Pilha<T>::Pilha(int s)
{
    size = (s > 0 ? s : 10);
    topo = -1;
    pilha = new T[size];
}
template <typename T>
bool Pilha<T>::push(T &valor)
{
    if (pilha_cheia())
        return false;
    topo++;
    pilha[topo] = valor;

    return true;
}
template <typename T>
bool Pilha<T>::pop(T &valor)
{
    if (pilha_vazia())
        return false;
    valor = pilha[topo];
    topo--;

    return true;
}