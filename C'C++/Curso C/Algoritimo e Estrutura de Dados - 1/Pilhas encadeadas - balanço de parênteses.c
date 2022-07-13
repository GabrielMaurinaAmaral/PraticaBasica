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

int parenteses(PilhaE *p, char stg[])
{
    for (int i = 0; stg[i] != '\0'; i++)
    {
        if (stg[i] == '(')
            empilhar(stg[i], p);
        else if (stg[i] == ')')
        {
            if (!pilhaE_vazia(p))
                desempilhar(p);
            else
                return 0;
        }
    }
    if (pilhaE_vazia(p))
        return 1;
    else
        return 0;
}

int main()
{
    int n, i, j;
    char c[100];
    PilhaE *p = criar_PilhaE();

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", c);
        for (j = 0; j < 100; j++)
        {
            if (c[j] == '\0' || c[j] == '\32')
            {
                break;
            }
            else
            {
                empilhar(c[j], p);
            }
        }

        balance(p);
    }

    liberar_pilha(p);
}