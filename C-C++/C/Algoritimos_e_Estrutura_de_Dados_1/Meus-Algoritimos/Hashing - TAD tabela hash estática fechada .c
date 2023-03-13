#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned int tam;
    int *buckets;
} HashT;

HashT *criar(unsigned int tam)
{
    HashT *t = malloc(sizeof(HashT));

    t->tam = tam;
    t->buckets = malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}

static int h1(int key, int tam, float c)
{
    return (int)(((key * c) - (int)(key * c)) * tam);
}

static int h2(int key, int tam)
{
    return 1 + key % (tam - 1);
}

static int rhash(int key, int tam, int i, float c)
{
    return (int)((h1(key, tam, c) + (i * h2(key, tam))) % tam);
}

int inserir(int key, HashT *t, float c)
{
    int x;
    int i, rh;

    if ((t != NULL) && (key > 0))
    {
        x = h1(key, t->tam, c);

        if (t->buckets[x] <= 0)
        {
            t->buckets[x] = key;
            printf("%d\n", x);

            return 1;
        }
        else
        {
            i = 1;
            rh = x;

            while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] > 0))
            {
                rh = rhash(key, t->tam, i, c);

                i++;
            }

            if ((i < t->tam) && (t->buckets[rh] <= 0))
            {
                t->buckets[rh] = key;
                printf("%d\n", rh);

                return 1;
            }
        }
    }

    return 0;
}

int liberar(HashT *t)
{
    if (t != NULL)
    {
        free(t->buckets);
        free(t);

        return 1;
    }

    return 0;
}

int main()
{
    float c;
    int n, tam, key;

    scanf("%f %d", &c, &n);
    HashT *h = criar(n);
    scanf("%d", &tam);

    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &key);
        inserir(key, h, c);
    }

    liberar(h);

    return 0;
}