#include <iostream>
#include <limits.h>
using namespace std;

#define max(a, b) a > b ? a : b;

int maior_preco(int precos[], int tam_haste)
{
    int q, r[tam_haste + 1];
    r[0] = 0;

    for (int i = 1; i <= tam_haste; i++)
    {
        q = INT_MIN;

        for (int j; j < i; j++)
            q = max(q, precos[j] + r[i - j - 1]);
        r[i] = q;
    }

    return r[tam_haste];
}

int main()
{

    return 0;
}