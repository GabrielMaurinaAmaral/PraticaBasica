#include <stdio.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct ListaE ListaE;

struct Cell
{
    int item;
    Cell *next;
};

struct ListaE
{
    Cell *head;
};

Cell *criar_celula(int key)
{
    Cell *c = (Cell *)malloc(sizeof(Cell));

    c->item = key;
    c->next = NULL;

    return c;
}

ListaE *criar_listaE()
{
    ListaE *l = (ListaE *)malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}

int listaE_vazia(ListaE *l)
{
    return (l == NULL) || (l->head == NULL);
}

void inserir_primeiro(int key, ListaE *l)
{
    Cell *aux;

    if (l == NULL)
    {
        l = criar_listaE();
    }

    aux = criar_celula(key);

    aux->next = l->head;
    l->head = aux;
}

void inserir_ultimo(int key, ListaE *l)
{
    Cell *aux, *novo;

    if (l == NULL)
    {
        l = criar_listaE();
    }

    if (listaE_vazia(l))
    {
        inserir_primeiro(key, l);
    }
    else
    {
        aux = l->head;

        while (aux->next != NULL)
        {
            aux = aux->next;
        }

        novo = criar_celula(key);

        aux->next = novo;
    }
}

void imprimir(ListaE *l)
{
    Cell *aux;

    if (!listaE_vazia(l))
    {
        aux = l->head;

        while (aux != NULL)
        {
            printf("%d ", aux->item);
            aux = aux->next;
        }

        printf("\n");
    }
}

int liberar_LE(ListaE *l)
{
    Cell *aux = NULL;

    if (l != NULL)
    {
        while (l->head != NULL)
        {
            aux = l->head;
            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }
    return 0;
}

void bubllesort_listaE(ListaE *l, int tam)
{
    Cell *aux1, *aux2;
    int troca = 1;

    if (!listaE_vazia(l))
    {
        aux1 = l->head;
        for (int i = 0; (i < tam - 1) && (troca); i++)
        {
            for (int j = 0; j < tam - i - 1; j++)
            {
                if (aux1->item > aux1->next)
                {
                    aux2->item = aux1->item;
                    aux1->item = aux1->next;
                    aux1->next = aux2->item;
                    aux1 = aux1->next;
                }
            }
        }
    }
}

int main()
{
    int num, tam = 0;
    ListaE *l = criar_listaE;

    do
    {
        scanf("%d", &num);
        if (num != -1)
        {
            inserir_ultimo(num, l);
            tam++;
        }
    } while (num != -1);

    bubllesort_listaE(l, tam);
    imprimir(l);
    liberar_LE(l);
    return 0;
}