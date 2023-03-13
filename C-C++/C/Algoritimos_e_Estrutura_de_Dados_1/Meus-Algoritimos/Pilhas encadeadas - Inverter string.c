#include <stdio.h>
#include <stdlib.h>

typedef struct No No;
typedef struct PilhaE PilhaE;

struct No
{
    char valor;
    No *prox;
};

struct PilhaE
{
    No *topo;
};

No *criar_No(char valor)
{
    No *no = (No *)malloc(sizeof(No));

    no->valor = valor;
    no->prox = NULL;

    return no;
}

PilhaE *criar_PilhaE()
{
    PilhaE *p = (PilhaE *)malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}

int PilhaE_vazia(PilhaE *p)
{
    return (p == NULL || p->topo == NULL);
}

void empilhar(char valor, PilhaE *p)
{
    No *aux;

    if (p == NULL)
    {
        p = criar_PilhaE();
    }

    aux = criar_No(valor);
    aux->prox = p->topo;
    p->topo = aux;
}

char desempilhar(PilhaE *p)
{
    No *aux;
    char valor;

    if (!PilhaE_vazia(p))
    {
        aux = p->topo;
        valor = aux->valor;
        p->topo = aux->prox;

        free(aux);
    }

    return valor;
}

void imprimir_PilhaE(PilhaE *p)
{
    No *aux;

    if (!PilhaE_vazia(p))
    {
        aux = p->topo;

        while (aux != NULL)
        {
            printf("%c", aux->valor);
            aux = aux->prox;
        }
    }
}

int liberar_pilha(PilhaE *p)
{
    if (p != NULL)
    {
        while (!PilhaE_vazia(p))
        {
            desempilhar(p);
        }

        free(p);

        return 1;
    }

    return 0;
}

void inverterString(char str[])
{
    PilhaE *p = criar_PilhaE();
    int i = 0;

    while (str[i] != '\0')
    {
        empilhar(str[i], p);
        i++;
    }
    i=0;
    while (str[i] != '\0')
    {
        str[i] = desempilhar(p);
        i++;
    }

    liberar_pilha(p);
}

int main()
{
    char str[100];

    scanf("%s", str);
    inverterString(str);

    printf(str);

    return 0;
}