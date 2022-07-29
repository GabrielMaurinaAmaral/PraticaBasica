#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int tam;
    cin >> tam;
    int v[tam];
    for (int i = 0; i < tam; i++)
        cin >> v[i];
    for (int j = tam - 1; j > -1; j--)
        cout << v[j] << " ";

    return 0;
}
