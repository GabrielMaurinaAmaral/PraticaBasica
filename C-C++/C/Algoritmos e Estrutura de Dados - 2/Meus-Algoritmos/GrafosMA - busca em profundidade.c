#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Cell Cell;
typedef struct FilaE FilaE;
typedef struct GrafoMA GrafoMA;

struct Cell
{
    int item;
    Cell *next;
};

struct FilaE
{
    Cell *inicio, *fim;
};

struct GrafoMA
{
    int V, A, *cor, *pai, *d, *f, **mat;
};

Cell *criar_celula(int key)
{
    Cell *c = (Cell*)malloc(sizeof(Cell));
    c->item = key;
    c->next = NULL;

    return c;
}
/***************************************************************/
// Fila encadeada
FilaE *criar_filaE()
{
    FilaE *f = (FilaE*)malloc(sizeof(FilaE));
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

    aux = criar_celula(key);

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
static int **iniciar_MA(int n)
{
    int **mat = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
        mat[i] = (int *)calloc(n, sizeof(int));

    return mat;
}

static int valida_vertice(GrafoMA *G, int v)
{
    return (v >= 0) && (v < G->V);
}

GrafoMA *iniciar_grafoMA(int v)
{
    GrafoMA *G = (GrafoMA *)malloc(sizeof(GrafoMA));

    G->pai = (int *)malloc(sizeof(int) * v);
    G->cor = (int *)malloc(sizeof(int) * v);
    G->d = (int *)malloc(sizeof(int) * v);
    G->f = (int *)malloc(sizeof(int) * v);

    G->V = v;
    G->A = 0;
    G->mat = iniciar_MA(G->V);

    return G;
}

int aresta_existe(GrafoMA *G, int v1, int v2)
{
    return (G != NULL) && valida_vertice(G, v1) && valida_vertice(G, v2) && (G->mat[v1][v2] != 0);
}

void inserir_aresta(GrafoMA *G, int v1, int v2)
{
    if (!aresta_existe(G, v1, v2))
    {
        G->mat[v1][v2] = G->mat[v2][v1] = 1;
        G->A++;
    }
}

void remover_aresta(GrafoMA *G, int v1, int v2)
{
    if (aresta_existe(G, v1, v2))
    {
        G->mat[v2][v1] = G->mat[v1][v2] = 0;
        G->A--;
    }
}

void liberarGMA(GrafoMA *G)
{
    if (G != NULL)
    {
        free(G->mat);
        free(G);
    }
}

void visitar_vertice(GrafoMA *G, int u, int *tempo)
{
    int v;

    G->cor[u] = 1;
    *tempo = *tempo + 1;
    G->d[u] = *tempo;

    for (v = 0; v < G->V; v++)
    {
        if ((G->mat[u][v] != 0) && (G->cor[v] == 0))
        {
            G->pai[v] = u;
            visitar_vertice(G, v, tempo);
        }
    }

    G->cor[u] = 2;
    *tempo = *tempo + 1;
    G->f[u] = *tempo;
}

void busca_profundidade(GrafoMA *G)
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
    int i, j, V, s;
    GrafoMA *G;

    scanf("%d", &V);

    G = iniciar_grafoMA(V);

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            scanf("%d", &G->mat[i][j]);

    scanf("%d", &s);

    busca_profundidade(G);

    return 0;
}