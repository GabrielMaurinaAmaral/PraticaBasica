#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE_MAX 100

typedef struct Pilha
{
    int v[SIZE_MAX];
    int topo;
    
} Pilha;

Pilha *criar_pilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}

int vazia_pilha(Pilha *p)
{
    return p->topo < 0;
}

int cheia_pilha(Pilha *p)
{
    return p->topo >= (SIZE_MAX - 1);
}

void empilhar(Pilha *p, int key)
{
    if (!cheia_pilha(p))
    {
        p->topo++;
        p->v[p->topo] = key;
    }
}

int desempilhar(Pilha *p)
{
    int item = -SIZE_MAX;

    if (!vazia_pilha(p))
    {
        item = p->v[p->topo];
        p->topo--;
    }
    return item;
}

void imprimir_pilha(Pilha *p)
{
    Pilha aux = *p;
    int item;

    while (!vazia_pilha(&aux))
    {
        item = desempilhar(&aux);
        printf("%d", item);
    }
}

void liberar_pilha(Pilha *p)
{
    if (p != NULL)
    {
        free(p);
    }
}

int operar_pilha(int v2, int v1, char op)
{
    switch (op)
    {
    case '+':
        return v1 + v2;
        break;
    case '-':
        return v1 - v2;
        break;
    case '*':
        return v1 * v2;
        break;
    case '/':
        return v1 / v2;
        break;
    default:
        return -1;
    }
}

int conversor_pilha(char n)
{
    switch (n)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    default:
        return -1;
    }
}

Pilha *posfixa(char straux[])
{
    Pilha *p = criar_pilha();
    int i, v1, v2;

    for (i = 0; i < strlen(straux); i++)
    {
        if (conversor_pilha(straux[i]) != -1)
        {
            empilhar(p, conversor_pilha(straux[i]));
        }
        else
        {
            v2 = desempilhar(p);
            v1 = desempilhar(p);
            empilhar(p, operar_pilha(v2, v1, straux[i]));
        }
    }

    return p;

    liberar_pilha(p);
}

int main()
{
    char straux[SIZE_MAX];
    scanf("%s", straux);

    imprimir_pilha(posfixa(straux));

    return 0;
}