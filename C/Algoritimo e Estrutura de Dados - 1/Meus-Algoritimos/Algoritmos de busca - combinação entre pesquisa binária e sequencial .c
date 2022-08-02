#include <stdio.h>
#include <stdlib.h>

int pesquisa_bin(int v[], int num, int m, int tam)
{
    int ini = 0, fim = tam - 1, meio, aux;

    while (fim - ini + 1 > m)
    {
        if ((ini == fim) && (num == v[ini]))
        {
            return ini;
        }
        else if (ini < fim)
        {
            meio = (ini + fim) / 2;

            if (num == v[meio])
            {
                return meio;
            }
            else if (num < v[meio])
            {
                fim = meio - 1;
            }
            else
            {
                ini = meio + 1;
            }
        }
        else
        {
            return -1;
        }
    }
    for (int i = ini; i <= fim; i++)
    {
        printf("%d ", v[i]);
    }
    for (aux = 0; aux < tam && num != v[aux]; aux++);

    printf("\n");
    if (num > v[tam - 1])
    {
        return -1;
    }
    else if (aux < num)
    {
        return aux;
    }
    else
    {
        return -1;
    }

    return -1;
}

int main()
{
    int num, fim, m, *v;

    scanf("%d %d", &num, &fim);
    v = (int *)malloc(fim * sizeof(int));

    for (int i = 0; i < fim; i++)
    {
        scanf("%d", &v[i]);
    }

    scanf("%d", &m);
    printf("%d", pesquisa_bin(v, num, m, fim));

    return 0;
}