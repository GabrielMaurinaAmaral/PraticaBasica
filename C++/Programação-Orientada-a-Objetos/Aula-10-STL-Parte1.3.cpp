#include <vector>
#include <algorithm>
#include <iostream>
#include
using namespace std;

int main()
{
    int i;
    vector<int> idades;
    vector<int>::iterator it;

    for (i = 0; i < 10; i++)
        idades.push_back(int(rand() % 100));

    cout << "\nVetor desordenado: ";
    for (i = 0; i < idades.size(); i++)
        cout << idades[i] << " ";

    sort(idades.begin(), idades.end());

    cout << "\nVetor ordenado: ";
    // for (i = 0; i < idades.size(); i++)
    //     cout << idades[i] << " ";
    for (it = idades.begin(); it != idades.end(); ++it)
        cout << (*it) << " ";

///////////////////////
   
    
}