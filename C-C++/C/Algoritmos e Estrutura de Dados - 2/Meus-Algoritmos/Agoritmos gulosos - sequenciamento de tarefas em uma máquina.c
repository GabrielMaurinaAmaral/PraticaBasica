#include <iostream>
using namespace std;

typedef struct Atividade
{
    int id;
    int e;
    int d;
} Atividade;

void bubblesort(Atividade *a, int n)
{
    int i, j;
    Atividade aux;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if ((a[j].d - a[j].e) < a[j + 1].d - a[j + 1].e)
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
}

void execucao(Atividade *a, int n)
{
    int atraso = 0;

    bubblesort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i].id);
        atraso += a[i].d - a[i].e;
    }

    if (atraso >= 0)
        printf("\n0");
    else
        printf("\n%d", atraso * -1);
}

int main()
{
    int n;
    scanf("%d", &n);
    Atividade atividades[n];
    for (int i = 0; i < n; i++)
    {
        atividades[i].id = i;
        scanf("%d %d", &atividades[i].e, &atividades[i].d);
    }

    execucao(atividades, n);

    return 0;
}