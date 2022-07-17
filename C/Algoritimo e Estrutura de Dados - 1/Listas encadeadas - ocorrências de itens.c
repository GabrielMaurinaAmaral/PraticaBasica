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

ListaE *criar_ListaE()
{
    ListaE *l = (ListaE *)malloc(sizeof(ListaE));

    l->inicio = NULL;

    return l;
}

void inserir_primeiro(int valor, ListaE *l)
{
    No *aux;

    if (l == NULL)
    {
        l = criar_ListaE();
    }

    aux = criar_No(valor);
    aux->prox = l->inicio;
    l->inicio = aux;
}

void procurar(int valor, ListaE *l)
{
    No *aux;
    int tam = 0;

    if (l != NULL)
    {
        aux = l->inicio;

        while (aux != NULL)
        {
            if (aux->valor == valor)
            {
                tam++;
            }

            aux = aux->prox;
        }
    }

    printf("o item %d aparece %d vez(es)", valor, tam);
}

int main()
{
    ListaE *l = criar_ListaE();
    int num;

    do
    {
        scanf("%d", &num);
        if (num != -1)
        {
            inserir_primeiro(num, l);
        }
    } while (num != -1);

    scanf("%d", &num);
    procurar(num, l);

    return 0;
}