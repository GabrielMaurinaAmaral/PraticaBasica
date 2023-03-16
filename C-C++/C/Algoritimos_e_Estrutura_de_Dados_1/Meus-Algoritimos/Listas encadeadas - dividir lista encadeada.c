#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct No No;
typedef struct ListaE ListaE;

struct No
{
    int valor;
    No *prox;
};

struct ListaE
{
    No *inicio;
};

No *criar_No(int num)
{
    No *no = (No *)malloc(sizeof(No));

    no->valor = num;
    no->prox = NULL;

    return no;
}

ListaE *criar_listaE()
{
    ListaE *l = (ListaE *)malloc(sizeof(ListaE));

    l->inicio = NULL;

    return l;
}

int listaE_vazia(ListaE *l)
{
    return (l == NULL) || (l->inicio == NULL);
}

void inserir_primeiro(int valor, ListaE *l)
{
    No *aux;

    if (l == NULL)
    {
        l = criar_listaE();
    }

    aux = criar_No(valor);
    aux->prox = l->inicio;
    l->inicio = aux;
}

void inserir_ultimo(int valor, ListaE *l)
{
    No *aux, *novo;

    if (l == NULL)
    {
        l = criar_listaE();
    }

    if (listaE_vazia(l))
    {
        inserir_primeiro(valor, l);
    }
    else
    {
        aux = l->inicio;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        novo = criar_No(valor);
        aux->prox = novo;
    }
}

int remover(int valor, ListaE *l)
{
    No *auxA, *auxP = NULL;

    if (!listaE_vazia(l))
    {
        auxA = l->inicio;

        if (auxA->valor == valor)
        {
            l->inicio = l->inicio->prox;
        }
        else
        {
            auxP = auxA;

            while ((auxA != NULL) && (auxA->valor != valor))
            {
                auxP = auxA;
                auxA = auxA->prox;
            }
        }

        if (auxA != NULL)
        {
            if (auxP != NULL)
            {
                auxP->prox = auxA->prox;
            }

            free(auxA);

            return 1;
        }
    }

    return 0;
}

int tamanho_LE(ListaE *l)
{
    No *aux;
    int tam = 0;

    if (!listaE_vazia(l))
    {
        aux = l->inicio;

        while (aux != NULL)
        {
            aux = aux->prox;
            tam++;
        }
    }

    return tam;
}

void imprimir(ListaE *l)
{
    No *aux;

    if (!listaE_vazia(l))
    {
        aux = l->inicio;

        while (aux != NULL)
        {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }
}

int dividir_listaE(ListaE *l1, ListaE *l2)
{
    int tam;
    No *aux1, *aux2;

    if (!listaE_vazia(l1))
    {
        aux1 = l1->inicio;
        tam = (tamanho_LE(l1) / 2);
    }

    if (tamanho_LE(l1) % 2 != 0)
    {
        tam += 1;
    }

    if (l1 != NULL)
    {
        for (int i = 0; i < tam; i++)
        {
            inserir_ultimo(aux1->valor, l2);
            aux2 = aux1->prox;
            remover(aux1->valor, l1);
            aux1 = aux2;
        }
    }

    ListaE *auxL;
    auxL->inicio = l1->inicio;
    l1->inicio = l2->inicio;
    l2->inicio = auxL->inicio;

    return 0;
}

int main()
{
    ListaE *l1 = criar_listaE(), *l2 = criar_listaE();
    int num;

    do
    {
        scanf("%d", &num);
        if (num != -1)
        {
            inserir_ultimo(num, l1);
        }
    } while (num != -1);

    dividir_listaE(l1, l2);
    imprimir(l1);
    imprimir(l2);

    return 0;
}