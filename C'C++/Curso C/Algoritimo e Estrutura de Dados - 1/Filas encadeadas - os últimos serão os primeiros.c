#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE_MAX 100

typedef struct Pilha
{
    int v[SIZE_MAX];
    int topo;

} Pilha;

Pilha *criar_pilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}

int vazia_pilha(Pilha *p)
{
    return p->topo < 0;
}

int cheia_pilha(Pilha *p)
{
    return p->topo >= (SIZE_MAX - 1);
}

void empilhar(Pilha *p, int key)
{
    if (!cheia_pilha(p))
    {
        p->topo++;
        p->v[p->topo] = key;
    }
}

int desempilhar(Pilha *p)
{
    int item = -SIZE_MAX;

    if (!vazia_pilha(p))
    {
        item = p->v[p->topo];
        p->topo--;
    }
    return item;
}

void liberar_pilha(Pilha *p)
{
    if (p != NULL)
    {
        free(p);
    }
}

typedef struct No No;
typedef struct FilaE FilaE;

struct No
{
    int item;
    No *next;
};

struct FilaE
{
    No *inicio;
    No *fim;
};

No *criar_celula(int valor)
{
    No *c = (No *)malloc(sizeof(No));

    c->item = valor;
    c->next = NULL;

    return c;
}

FilaE *criar_filaE()
{
    FilaE *f = (FilaE *)malloc(sizeof(FilaE));

    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

int filaE_vazia(FilaE *f)
{
    return (f == NULL) || (f->inicio == NULL);
}

void enfileirar(int valor, FilaE *f)
{
    No *aux;

    if (f == NULL)
    {
        f = criar_filaE();
    }

    aux = criar_celula(valor);

    if (f->inicio == NULL)
    {
        f->inicio = f->fim = aux;
    }
    else
    {
        f->fim->next = aux;
        f->fim = f->fim->next;
    }
}

void imprimir_fila(FilaE *f)
{
    No *aux;

    if (!filaE_vazia(f))
    {
        aux = f->inicio;

        while (aux != NULL)
        {
            printf("%d ", aux->item);
            aux = aux->next;
        }
    }
}

int liberar_filaE(FilaE *f)
{
    if (!filaE_vazia(f))
    {
        while (f->inicio != NULL)
        {
            desenfileirar(f);
        }
        free(f);

        return 1;
    }

    return 0;
}

void enfileirar_pilha(Pilha *p, FilaE *f)
{
    Pilha *aux = criar_pilha();
    *aux = *p;

    while (!vazia_pilha(aux))
    {
        enfileirar(desempilhar(aux), f);
    }

    return 0;
}

int main()
{
    int num;
    Pilha *p = criar_pilha();
    FilaE *f = criar_filaE();

    do
    {
        scanf("%d", &num);
        if (num != -1)
        {
            empilhar(p, num);
        }

    } while (num != -1);

    enfileirar_pilha(p, f);
    imprimir_fila(f);

    liberar_pilha(p);
    liberar_filaE(f);

    return 0;
}