#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 100

typedef struct Pilha
{
    int item[MAX_SIZE];
    int topo;

} Pilha;

Pilha *criar_pilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}

int pilha_cheia(Pilha *p)
{
    if (p == NULL)
    {
        return -1;
    }
    else if (p->topo == (MAX_SIZE - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pilha_vazia(Pilha *p)
{
    if (p == NULL)
    {
        return -1;
    }
    else if (p->topo == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int empilhar_pilha(Pilha *p, int item)
{
    if (p == NULL)
    {
        p = criar_pilha();
    }
    if (!pilha_cheia(p))
    {
        p->topo++;

        p->item[p->topo] = item;

        return 1;
    }

    return 0;
}

int desempilhar_pilha(Pilha *p)
{
    int item = INT_MIN;

    if (!pilha_vazia(p))
    {
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}

void imprimir_pilha(Pilha *p)
{
    Pilha aux = *p;
    int item;

    while (!pilha_vazia(&aux))
    {
        item = desempilhar_pilha(&aux);

        printf("%d", item);
    }
}

int decimal_para_binario(Pilha *p1, Pilha *p2)
{
    int i;
    int num = p1->item[p1->topo];

    while (num > 0)
    {
        empilhar_pilha(p2, num % 2);
        i++;
        num = num / 2;
    }

    return 0;
}

int main()
{
    Pilha *p1 = criar_pilha();
    Pilha *p2 = criar_pilha();
    int num;

    scanf("%d", &num);
    empilhar_pilha(p1, num);

    decimal_para_binario(p1, p2);
    imprimir_pilha(p2);

    return 0;
}