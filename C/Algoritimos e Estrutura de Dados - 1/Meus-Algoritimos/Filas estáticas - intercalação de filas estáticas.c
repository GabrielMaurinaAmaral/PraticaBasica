#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 100

typedef struct Fila
{
    int item[MAX_SIZE];
    int ini;
    int fim;
    int tam;

} Fila;

Fila *criar_fila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}

int fila_cheia(Fila *f)
{
    if (f == NULL)
    {
        return -1;
    }
    else if (f->tam < MAX_SIZE)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int fila_vazia(Fila *f)
{
    if (f == NULL)
    {
        return -1;
    }
    else if (f->tam > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int enfileirar(Fila *f, int num)
{
    if (f == NULL)
    {
        f = criar_fila();
    }

    if (!fila_cheia(f))
    {
        if (f->ini < 0)
        {
            f->ini = 0;
        }

        if (f->fim < MAX_SIZE - 1)
        {
            f->fim++;
        }
        else
        {
            f->fim = 0;
        }

        f->item[f->fim] = num;
        f->tam++;

        return 1;
    }

    return 0;
}

int desenfileirar(Fila *f)
{
    int item = INT_MIN;

    if (!fila_cheia(f))
    {
        item = f->item[f->ini];

        if (f->ini < MAX_SIZE - 1)
        {
            f->ini++;
        }
        else
        {
            f->ini = 0;
        }

        f->tam--;

        if (f->tam == 0)
        {
            f->ini = -1;
            f->fim = -1;
        }
    }

    return item;
}

void imprimir_fila(Fila *f)
{
    Fila aux = *f;
    int item;

    while (!fila_vazia(&aux))
    {
        item = desenfileirar(&aux);

        printf("%d ", item);
    }

    printf("\n");
}

void liberar_fila(Fila *f)
{
    if (f != NULL)
    {
        free(f);
    }
}

Fila *intercalar_fila(Fila *f1, Fila *f2, Fila *f3)
{
    int v1, v2;

    while (!fila_vazia(f1) && !fila_vazia(f2))
    {
        v1 = desenfileirar(f1);
        v2 = desenfileirar(f2);

        if (v1 >= v2)
        {
            enfileirar(f3, v1);
            enfileirar(f3, v2);
        }
        else
        {
            enfileirar(f3, v2);
            enfileirar(f3, v1);
        }
    }

    while (!fila_vazia(f1))
    {
        v1 = desenfileirar(f1);
        enfileirar(f3, v1);
    }

    while (!fila_vazia(f2))
    {
        v2 = desenfileirar(f2);
        enfileirar(f3, v2);
    }

    return f3;
}
int main()
{
    Fila *f1 = criar_fila();
    Fila *f2 = criar_fila();
    Fila *f3 = criar_fila();
    int n;

    do
    {
        scanf("%d", &n);

        if (n != -1)
        {
            enfileirar(f1, n);
        }

    } while (n != -1);

    do
    {
        scanf("%d", &n);

        if (n != -1)
        {
            enfileirar(f2, n);
        }

    } while (n != -1);

    intercalar_fila(f1, f2, f3);
    imprimir_fila(f3);

    return 0;
}