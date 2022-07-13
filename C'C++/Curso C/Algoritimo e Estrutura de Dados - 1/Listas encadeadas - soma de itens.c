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

int somar_listaE(ListaE *l)
{
    int soma = 0;
    No *aux1, *aux2;
    aux1 = l->inicio;

    if (l != NULL)
    {
        while (!listaE_vazia(l))
        {
            soma += aux1->valor;
            aux2 = aux1->prox;
            remover(aux1->valor, l);
            aux1 = aux2;
        }
    }

    return soma;
}

int main()
{
    ListaE *l = criar_listaE();
    int num;

    do
    {
        scanf("%d", &num);
        if (num != -1)
        {
            inserir_primeiro(num, l);
        }
    } while (num != -1);

    num = somar_listaE(l);
    printf("%d", num);

    return 0;
}