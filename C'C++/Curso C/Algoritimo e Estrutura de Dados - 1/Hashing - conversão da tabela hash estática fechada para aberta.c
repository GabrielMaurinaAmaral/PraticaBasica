#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Cell
{
    int item;
    struct Cell *next;
} Cell;

typedef struct ListaE
{
    Cell *head;
} ListaE;

typedef struct HashA
{
    unsigned int size;
    ListaE *buckets;
} HashA;

typedef struct HashF
{
    unsigned int tam;
    int *buckets;
} HashF;

HashF *chF(unsigned int tam)
{
    HashF *t = malloc(sizeof(HashF));
    t->tam = tam, t->buckets = malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}

static int hashingF(int k, int B)
{
    return k % B;
}

static int overflow_prog(int hashC, int B, int tentativa)
{
    return (hashC + tentativa) % B;
}

int buscarF(int key, HashF *t)
{
    int x = hashingF(key, t->tam);
    int i, rh;
    if (t->buckets[x] == key)
        return x;
    else if (t->buckets[x] >= 0)
    {
        i = 1;
        rh = x;
        while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] >= 0))
        {
            rh = overflow_prog(x, t->tam, i);
            i++;
        }
        if ((i < t->tam) && (t->buckets[rh] == key))
            return rh;
    }

    return -1;
}

int inserirF(int key, HashF *t)
{
    int x;
    int i, rh;

    if ((t != NULL) && (key > 0))
    {
        x = hashingF(key, t->tam);
        if (t->buckets[x] <= 0)
        {
            t->buckets[x] = key;
            return 1;
        }
        else
        {
            i = 1;
            rh = x;
            while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] > 0))
            {
                rh = overflow_prog(x, t->tam, i);
                i++;
            }
            if ((i < t->tam) && (t->buckets[rh] <= 0))
            {
                t->buckets[rh] = key;
                return 1;
            }
        }
    }

    return 0;
}

int removerF(int key, HashF *hf)
{
    if (hf != NULL)
    {
        if (buscarF(key, hf) >= 0)
        {
            hf->buckets[buscarF(key, hf)] = 0;
            return 1;
        }
    }

    return 0;
}

void imprimirF(HashF *t)
{
    if (t != NULL)
        for (int i = 0; i < t->tam; i++)
            if (t->buckets[i] > 0)
                printf("%d\n", t->buckets[i]);
}

int liberarF(HashF *t)
{
    if (t != NULL)
    {
        free(t->buckets), free(t);
        return 1;
    }

    return 0;
}

Cell *criar_Cell(int key)
{
    Cell *c = (Cell *)malloc(sizeof(Cell));
    c->item = key, c->next = NULL;

    return c;
}

HashA *chA(unsigned int n)
{
    HashA *h = malloc(sizeof(HashA));
    h->size = n;
    h->buckets = malloc(n * sizeof(L));

    for (int i = 0; i < n; i++)
        h->buckets[i].head = criar_Cell(-1);

    return h;
}

static int fh(int k, int B)]
{
    return k % B;
}

void inserirA(HashF *hf, HashA *ha)
{
    for (int i = 0; i < ha->size; i++)
    {
        if (ha != NULL)
        {
            Cell *aux1 = ha->buckets[fh(hf->buckets[i], ha->size)].head;
            Cell *aux2 = criar_Cell(hf->buckets[i]);

            while (aux1 != NULL)
            {
                while (aux1->item > 0)
                {
                    if (aux1->next == NULL)
                        aux1->next = criar_Cell(-1);
                    aux1 = aux1->next;
                }
                if (aux1->item <= 0)
                    aux1->item = aux2->item, aux1 = aux1->next;
            }
        }
    }
}

void imprimirA(HashA *h)
{
    if (h != NULL)
    {
        for (int i = 0; i < h->size; i++)
        {
            Cell *aux = h->buckets[i].head;
            printf("%d: -> ", i);
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

void liberarA(HashA *h)
{
    if (h != NULL)
        free(h->buckets), free(h);
}

void converter(HashF *hf, HashA *ha)
{
    inserirA(hf, ha);
    liberarF(hf);
}

int main()
{
    int n, tam, key;
    scanf("%d%d", &n, &qtd);
    HashF *hf = chF(n);
    HashA *ha = chA(n);

    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &key);
        inserirF(key, hf);
    }

    converter(hf, ha);
    imprimirA(ha);
    liberarA(ha);

    return 0;
}