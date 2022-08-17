#include <stdio.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct ListaE ListaE;
typedef struct HashT HashT;

struct Cell
{
    int item;
    Cell *next;
};

struct ListaE
{
    Cell *head;
};

struct HashT
{
    unsigned int tam;
    ListaE *buckets;
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

HashT *criar_Hash(unsigned int tam)
{
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->tam = tam;
    t->buckets = malloc(tam * sizeof(ListaE));

    for (i = 0; i < tam; i++)
        t->buckets[i].head = NULL;

    return t;
}

int listaE_vazia(ListaE *l)
{
    return (l == NULL) || (l->head == NULL);
}

void inserir_primeiro(int key, ListaE *l)
{
    Cell *aux;

    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(key);
    aux->next = l->head;
    l->head = aux;
}

void inserir_ultimo(int key, ListaE *l)
{
    Cell *aux, *novo;

    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(key, l);

    else
    {
        aux = l->head;

        while (aux->next != NULL)
            aux = aux->next;

        novo = criar_celula(key);
        aux->next = novo;
    }
}

static int h1(int key, int tam)
{
    return key % tam;
}

int inserir_Hash(int key, HashT *t)
{
    int x;

    if (t != NULL)
    {
        x = h1(key, t->tam);
        inserir_ultimo(key, &t->buckets[x]);
        printf("%d\n", x);
    }

    return 0;
}

void imprimir_Hash(HashT *t)
{
    int i;
    Cell *aux;

    if (t != NULL)
    {
        for (i = 0; i < t->tam; i++)
        {
            printf("%d: ->", i);
            aux = t->buckets[i].head;

            if (t->buckets[i].head != NULL)
                while (aux != NULL)
                {

                    if (aux->item >= 0)
                        printf("%d ", aux->item);
                    if (aux->next != NULL)
                        printf("-> ");
                    aux = aux->next;
                }
            printf("\n");
        }
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

int liberar_Hash(HashT *t)
{
    if (t != NULL)
    {
        for (int i = 0; i < t->tam; i++)
            liberar_LE(&t->buckets[i]);
        free(t->buckets);
        free(t);

        return 1;
    }

    return 0;
}

int main()
{
    int n, tam, key;
    scanf("%d", &tam);
    HashT *t = criar_Hash(tam);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        inserir_Hash(key, t);
    }

    printf("\n");
    imprimir_Hash(t);

    return 0;
}