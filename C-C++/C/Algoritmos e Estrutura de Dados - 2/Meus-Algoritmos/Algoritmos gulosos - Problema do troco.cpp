#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quantidade_moedas(int moedas[], int len, int troco)
{
    int i, quantidade;

    for (i = 0; (i < len) && (troco > 0); i++)
    {
        quantidade = troco / moedas[i];
        troco = troco % moedas[i];

        while (quantidade > 0)
        {
            printf("%d\n", moedas[i]);
            quantidade--;
        }
    }
}

int main()
{
    int i, len, troco, *moedas;
    scanf("%d %d", &troco, &len);
    moedas = (int *)malloc(sizeof(int) * len);

    for (i = 0; i < len; i++)
        scanf("%d", &moedas[i]);

    quantidade_moedas(moedas, len, troco);

    free(moedas);
    return 0;
}
