#include "Aula-09-Templates.2.cpp"
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename Vetor>
void print_vetor(Vetor *v, int size)
{
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";
}

int main()
{
    float vetor_f[10];
    int vetor_i[10], i;

    for (i = 0; i < 10; i++)
        vetor_f[i] = float(rand() % 100) / 100.0;
    for (i = 0; i < 10; i++)
        vetor_i[i] = float(rand() % 100);

    cout << "\nVetor float: ";
    print_vetor(vetor_f, 10);
    cout << "\nVetor int: ";
    print_vetor(vetor_i, 10);

    Pilha<int> p{20};
    int num = 0;

    cout << "\nInserir: ";
    while (num != -1)
    {
        cin >> num;
        p.push(num);
    }
    cout << "\nRemovido: ";
    while (!p.pilha_vazia())
    {
        p.pop(num);
        cout << num << " ";
    }

    return 0;
}
