#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Cell Cell;
typedef struct Lista Lista;
typedef struct FilaE FilaE;
typedef struct GrafoLA GrafoLA;

struct Cell
{
    int item;
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
    int V, A, *cor, *pai, *d, *f;
    Lista **adj;
};
/***************************************************************/
// Celula
Cell *criar_celula(int item)
{
    Cell *c = (Cell *)malloc(sizeof(Cell));
    c->item = item;
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

int procurar(int item, Lista *l)
{
    Cell *aux = NULL;

    if (l != NULL)
    {
        aux = l->head;

        while ((aux != NULL) && (item < aux->item))
            aux = aux->next;
    }

    if ((aux != NULL) && (item == aux->item))
        return 1;
    else
        return 0;
}

void inserir_na_lista(int item, Lista *l)
{
    Cell *auxA, *auxP, *c;

    if (lista_vazia(l))
    {
        if (l == NULL)
            l = criar_lista();

        l->head = criar_celula(item);
    }
    else
    {
        c = criar_celula(item);

        if (l->head->item >= item)
        {
            c->next = l->head;
            l->head = c;
        }
        else
        {
            auxA = l->head;
            auxP = auxA;

            while ((auxP != NULL) && (auxP->item < item))
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
    Cell *aux;

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

void enfileirar(int item, FilaE *f)
{
    Cell *aux;

    if (f == NULL)
        f = criar_filaE();

    aux = criar_celula(item);

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
    Lista **adj = (Lista **)malloc(n * sizeof(Lista *));

    for (int i = 0; i < n; i++)
        adj[i] = criar_lista();

    return adj;
}

GrafoLA *iniciar_grafoLA(int v)
{
    GrafoLA *G = (GrafoLA *)malloc(sizeof(GrafoLA));

    G->pai = (int *)malloc(sizeof(int) * v);
    G->cor = (int *)malloc(sizeof(int) * v);
    G->d = (int *)malloc(sizeof(int) * v);
    G->f = (int *)malloc(sizeof(int) * v);

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

void inserir_arestaLA(GrafoLA *G, int v1, int v2)
{
    if (!aresta_existeLA(G, v1, v2))
    {
        inserir_na_lista(v2, G->adj[v1]);
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
void visitar_vertice(GrafoLA *G, int u, int *tempo)
{
    int v;
    Cell *aux;

    G->cor[u] = 1;
    *tempo = *tempo + 1;
    G->d[u] = *tempo;

    for (v = 0; v < G->V; v++)
    {
        aux = G->adj[u]->head;
        while (aux != NULL)
        {
            if ((aux->item != 0) && (G->cor[v] == 0))
            {
                G->pai[v] = u;
                visitar_vertice(G, v, tempo);
            }
            aux = aux->next;
        }
    }

    G->cor[u] = 2;
    *tempo = *tempo + 1;
    G->f[u] = *tempo;
}

void busca_profundidade_LA(GrafoLA *G)
{
    int u, v, tempo = 0;

    for (u = 0; u < G->V; u++)
    {
        G->pai[u] = -1;
        G->cor[u] = 0;
    }

    for (u = 0; u < G->V; u++)
    {
        if (G->cor[u] == 0)
            visitar_vertice(G, u, &tempo);
    }

    printf("v d f p\n");

    for (v = 0; v < G->V; v++)
    {
        printf("%d %d %d ", v, G->d[v], G->f[v]);

        if (G->pai[v] >= 0)
            printf("%d\n", G->pai[v]);
        else
            printf("-\n");
    }
}

int main()
{
    int V, num;
    scanf("%d", &V);
    GrafoLA *G = iniciar_grafoLA(V);

    for (int i = 0; i < V; i++)
    {
        do
        {
            scanf("%d", &num);
            if (num != -1)
                inserir_arestaLA(G, i, num);

        } while (num != -1);
    }

    busca_profundidade_LA(G);

    return 0;
}