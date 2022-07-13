#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

No *criar_No(int valor)
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

    aux = criar_No(valor);

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

int desenfileirar(FilaE *f)
{
    No *aux;
    int item = -INT_MAX;

    if (!filaE_vazia(f))
    {
        aux = f->inicio;
        f->inicio = aux->next;
        item = aux->item;

        free(aux);
    }

    return item;
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

FilaE *semafaro(FilaE *f1, FilaE *f2, FilaE *f3)
{
    FilaE *f4 = criar_filaE(), *aux1 = criar_filaE(), *aux2 = criar_filaE(), *aux3 = criar_filaE();
    int cont = 0;
    *aux1 = *f1;
    *aux2 = *f2;
    *aux3 = *f3;

    do
    {
        while (cont != 3)
        {
            if (!filaE_vazia(aux1))
            {
                enfileirar(desenfileirar(aux1), f4);
                cont++;
            }
            else
            {
                cont = 3;
            }
        }
        cont = 0;

        while (cont != 3)
        {
            if (!filaE_vazia(aux2))
            {
                enfileirar(desenfileirar(aux2), f4);
                cont++;
            }
            else
            {
                cont = 3;
            }
        }
        cont = 0;

        while (cont != 3)
        {
            if (!filaE_vazia(aux3))
            {
                enfileirar(desenfileirar(aux3), f4);
                cont++;
            }
            else
            {
                cont = 3;
            }
        }
        cont = 0;

    } while (!(filaE_vazia(aux1)) || !(filaE_vazia(aux2)) || !(filaE_vazia(aux3)));

    return f4;
}

int main()
{
    FilaE *f1 = criar_filaE(), *f2 = criar_filaE(), *f3 = criar_filaE();
    int num;
    do
    {
        scanf("%d", &num);
        if (num != -1)
        {
            enfileirar(num, f1);
        }
    } while (num != -1);
    do
    {
        scanf("%d", &num);
        if (num != -1)
        {
            enfileirar(num, f2);
        }
    } while (num != -1);
    do
    {
        scanf("%d", &num);
        if (num != -1)
        {
            enfileirar(num, f3);
        }
    } while (num != -1);

    FilaE *f4 = semafaro(f1, f2, f3);
    imprimir_fila(f4);

    return 0;
}