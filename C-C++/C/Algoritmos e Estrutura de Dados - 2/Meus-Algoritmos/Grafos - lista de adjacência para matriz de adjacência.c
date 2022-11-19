#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/***************************************************************/
typedef struct Cell Cell;
typedef struct Lista Lista;
typedef struct GrafoLA GrafoLA;
typedef struct GrafoMA GrafoMA;

struct Cell
{
    int key;
    struct Cell *next;
};

struct Lista
{
    Cell *head;
};

struct GrafoLA
{
    int V, A;
    Lista **adj;
};
struct GrafoMA
{
    int V, A;
    int **mat;
};
/***************************************************************/
// Lista encadeada

Lista *criar_lista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->head = NULL;

    return l;
}

Cell *criar_celula(int key)
{
    Cell *c = (Cell *)malloc(sizeof(Cell));
    c->key = key;
    c->next = NULL;

    return c;
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

        while ((aux != NULL) && (key < aux->key))
            aux = aux->next;
    }

    if ((aux != NULL) && (key == aux->key))
        return 1;
    else
        return 0;
}

void inserir_na_lista(int key, Lista *l)
{
    Cell *auxA, *auxP, *c;

    if (lista_vazia(l))
    {
        if (l == NULL)
            l = criar_lista();

        l->head = criar_celula(key);
    }
    else
    {
        c = criar_celula(key);

        if (l->head->key >= key)
        {
            c->next = l->head;
            l->head = c;
        }
        else
        {
            auxA = l->head;
            auxP = auxA;

            while ((auxP != NULL) && (auxP->key < key))
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
// GrafoMA

static int **iniciar_MA(int n)
{
    int i, **mat = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
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

    G->V = v;
    G->A = 0;
    G->mat = iniciar_MA(G->V);

    return G;
}

int aresta_existeMA(GrafoMA *G, int v1, int v2)
{
    return (G != NULL) && valida_vertice(G, v1) && valida_vertice(G, v2) && (G->mat[v1][v2] != 0);
}

void inserir_arestaMA(GrafoMA *G, int v1, int v2)
{
    if (!aresta_existeMA(G, v1, v2))
    {
        G->mat[v1][v2] = 1;
        G->A++;
    }
}

void imprimir_arestasMA(GrafoMA *G)
{
    int i, j;

    for (i = 0; i < G->V; i++)
    {
        for (j = 0; j <  G->V; j++)
            if (G->mat[i][j] !=NULL)
                printf("1 ");
            else
                printf("0 ");
        printf("\n");
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

/***************************************************************/

GrafoMA *converter_LA_em_MA(GrafoLA *grafoLA)
{
    int i;
    Cell *aux;
    GrafoMA *grafoMA = iniciar_grafoMA(grafoLA->V);

    if (grafoLA != NULL)
    {
        for (i = 0; i < grafoLA->V; i++)
        {
            aux = grafoLA->adj[i]->head;
            while (aux != NULL)
            {
                inserir_arestaMA(grafoMA, i, aux->key);
                aux = aux->next;
            }
        }
    }

    return grafoMA;
}

int main()
{
    int vertices, vertice;
    scanf("%d", &vertices);
    GrafoLA *grafoLA = iniciar_grafoLA(vertices);

    for (int i = 0; i < vertices; i++)
    {
        do
        {
            scanf("%d", &vertice);
            if (vertice != -1)
                inserir_arestaLA(grafoLA, i, vertice);

        } while (vertice != -1);
    }

    GrafoMA *grafoMA = converter_LA_em_MA(grafoLA);
    imprimir_arestasMA(grafoMA);

    liberarGLA(grafoLA);
    liberarGMA(grafoMA);

    return 0;
}