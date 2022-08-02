#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pilhaE.h"

struct Cell
{
    int valor; 
    Cell *prox;
};

struct PilhaE
{
    Cell *topo;
};

Cell *criar_celula(int valor)
{
    Cell *c = (Cell *)malloc(sizeof(Cell));

    c->valor = valor;
    c->prox = NULL;

    return c;
}

PilhaE *criar_pilhaE()
{
    PilhaE *p = (PilhaE *)malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}

int pilhaE_vazia(PilhaE *p)
{
    return (p == NULL) || (p->topo == NULL);
}

void empilhar(int valor, PilhaE *p)
{
    Cell *aux; 

    if (p == NULL)
    {
        p = criar_pilhaE();

    }

    aux = criar_celula(valor);
    aux->prox = p->topo;
    p->topo = aux;
}

int desempilhar(PilhaE *p)
{
    Cell *aux;           
    int valor = -INT_MAX; 

    if (!pilhaE_vazia(p))
    {
        aux = p->topo;
        valor = aux->valor;
        p->topo = aux->prox;

        free(aux);
    }

    return valor;
}

void imprimir_pilha(PilhaE *p)
{
    Cell *aux; 

    if (!pilhaE_vazia(p))
    {
        aux = p->topo;

        while (aux != NULL)
        {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }
}

int liberar_pilha(PilhaE *p)
{
    if (p != NULL)
    {
        while (!pilhaE_vazia(p))
        {
            desempilhar(p);
        }

        free(p);

        return 1;
    }

    return 0;
}
