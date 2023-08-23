#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Horario
{
    int id, ini, fim;
} Horario;

void bubblesort(Horario *h, int n)
{
    int i, j;
    Horario aux;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (h[j].fim > h[j + 1].fim)
            {
                aux = h[j];
                h[j] = h[j + 1];
                h[j + 1] = aux;
            }
}

void ordem_horarios(Horario *horarios, int len)
{
    bubblesort(horarios, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d %d %d\n", horarios[i].id, horarios[i].ini, horarios[i].fim);
    }

    int aux = horarios[0].fim;
    printf("\n%d ", horarios[0].id);

    for (int i = 1; i < len; i++)
    {
        if (aux < horarios[i].ini)
        {
            aux = horarios[i].fim;
            printf("%d ", horarios[i].id);
        }
    }
}

int main()
{
    int len;
    scanf("%d", &len);
    Horario horarios[len];

    for (int i = 0; i < len; i++)
    {
        scanf("%d %d %d", &horarios[i].id, &horarios[i].ini, &horarios[i].fim);
    }

    ordem_horarios(horarios, len);

    return 0;
}