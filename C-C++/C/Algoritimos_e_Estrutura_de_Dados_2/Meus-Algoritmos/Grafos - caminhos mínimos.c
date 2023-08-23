#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Cell Cell;
typedef struct Lista Lista;
typedef struct FilaE FilaE;
typedef struct GrafoLA GrafoLA;

struct Cell
{
    int item, peso;
    Cell *next;
};

struct Lista
{
    Cell *head;
};

struct FilaE
{
    Cell *inicio, *fim;
};

struct GrafoLA
{
    int V, A, *nafila, *pai, *key;
    Lista **adj;
};
/***************************************************************/
// Celula
Cell *criar_celula(int key, int peso)
{
    Cell *c = (Cell *)malloc(sizeof(Cell));
    c->item = key;
    c->peso = peso;
    c->next = NULL;

    return c;
}

Cell *criar_celula_2(int key)
{
    Cell *c = (Cell *)malloc(sizeof(Cell));
    c->item = key;
    c->next = NULL;

    return c;
}
/***************************************************************/
// Lista encadeada
Lista *criar_lista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->head = NULL;

    return l;
}

int lista_vazia(Lista *l)
{
    return (l == NULL) || (l->head == NULL);
}

int procurar(int key, Lista *l)
{
    Cell *aux = NULL;

    if (l != NULL)
    {
        aux = l->head;

        while ((aux != NULL) && (key != aux->item))
            aux = aux->next;
    }

    if ((aux != NULL) && (key == aux->item))
        return 1;
    else
        return 0;
}

void inserir_na_lista(int key, int peso, Lista *l)
{
    Cell *auxA, *auxP, *c;

    if (lista_vazia(l))
    {
        if (l == NULL)
            l = criar_lista();
        l->head = criar_celula(key, peso);
    }
    else
    {
        c = criar_celula(key, peso);

        if (l->head->item >= key)
        {
            c->next = l->head;
            l->head = c;
        }
        else
        {
            auxA = l->head;
            auxP = auxA;

            while ((auxP != NULL) && (auxP->item < key))
            {
                auxA = auxP;
                auxP = auxP->next;
            }

            auxA->next = c;
            c->next = auxP;
        }
    }
}

int liberar_lista(Lista *l)
{
    Cell *aux = NULL;

    if ((l != NULL) && !lista_vazia(l))
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
/***************************************************************/
// Fila encadeada
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

void enfileirar(int key, FilaE *f)
{
    Cell *aux;

    if (f == NULL)
        f = criar_filaE();

    aux = criar_celula_2(key);

    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else
    {
        f->fim->next = aux;
        f->fim = f->fim->next;
    }
}

int desenfileirar(FilaE *f)
{
    Cell *aux;
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
int liberar_filaE(FilaE *f)
{
    if (!filaE_vazia(f))
    {
        while (f->inicio != NULL)
            desenfileirar(f);
        free(f);

        return 1;
    }

    return 0;
}
/***************************************************************/
// GrafoLA
static Lista **iniciar_LA(int n)
{
    Lista **adj = (Lista **)malloc(n * sizeof(Lista));

    for (int i = 0; i < n; i++)
        adj[i] = criar_lista();

    return adj;
}

GrafoLA *iniciar_grafoLA(int v)
{
    GrafoLA *G = (GrafoLA *)malloc(sizeof(GrafoLA));

    G->pai = (int *)malloc(sizeof(int) * v);
    G->nafila = (int *)malloc(sizeof(int) * v);
    G->key = (int *)malloc(sizeof(int) * v);

    G->V = v;
    G->A = 0;
    G->adj = iniciar_LA(G->V);

    return G;
}

int aresta_existeLA(GrafoLA *G, int v1, int v2)
{
    if ((G != NULL) && (G->adj[v1]->head != NULL))
        return procurar(v2, G->adj[v1]);

    return 0;
}

void inserir_arestaLA(GrafoLA *G, int v1, int v2, int peso)
{
    if (!aresta_existeLA(G, v1, v2))
    {
        inserir_na_lista(v2, peso, G->adj[v1]);
        G->A++;
    }
}

void liberarGLA(GrafoLA *G)
{
    if (G != NULL)
    {
        for (int i = 0; i < G->V; i++)
            liberar_lista(G->adj[i]);
        free(G);
    }
}
/***************************************************************/
// main
int extrai_minimo(FilaE *f, GrafoLA *G)
{
    int vM;
    Cell *aux, *auxM;

    auxM = f->inicio;
    aux = auxM->next;

    while (aux != NULL)
    {
        if (G->key[aux->item] < G->key[auxM->item])
            auxM = aux;
        aux = aux->next;
    }

    if (auxM != f->inicio)
    {
        vM = f->inicio->item;
        f->inicio->item = auxM->item;
        auxM->item = vM;
    }

    return desenfileirar(f);
}

void caminhos_minima(GrafoLA *G)
{
    int u, v;
    Cell *aux;
    FilaE *f = NULL;

    f = criar_filaE();

    for (v = 0; v < G->V; v++)
    {
        G->nafila[v] = 1;
        G->pai[v] = -1;
        G->key[v] = INT_MAX;
        enfileirar(v, f);
    }

    G->key[0] = 0;

    while (!filaE_vazia(f))
    {
        u = extrai_minimo(f, G);
        G->nafila[u] = 0;
        
        aux = G->adj[u]->head;
        while (aux != NULL)
        {
            if ((aux->peso != 0) && (G->nafila[aux->item]) && (aux->peso < G->key[aux->item]))
            {
                G->key[aux->item] = aux->peso;
                G->pai[aux->item] = u;
            }
            aux = aux->next;
        }
    }

    for (v = 0; v < G->V; v++)
    {
        printf("%d: ", v);

        if (G->pai[v] >= 0)
            printf("%d\n", G->pai[v]);
        else
            printf("-\n");
    }

    liberar_filaE(f);
}

int main()
{
    int V, A, v1, v2, peso;
    scanf("%d %d", &V, &A);
    GrafoLA *G = iniciar_grafoLA(V);

    for (int i = 0; i < A; i++)
    {
        scanf("%d %d %d", &v1, &v2, &peso);
        inserir_arestaLA(G, v1, v2, peso);
    }
    caminhos_minima(G);

    return 0;
}
