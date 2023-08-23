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
    Cell *inicio;
    Cell *fim;
};

struct GrafoLA
{
    int V, A, *cor, *pai, *d;
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

static int valida_vertice_LA(GrafoLA *G, int v)
{
    return (v >= 0) && (v < G->V);
}

GrafoLA *iniciar_grafoLA(int v)
{
    GrafoLA *G = (GrafoLA *)malloc(sizeof(GrafoLA));

    G->pai = (int *)malloc(sizeof(int) * v);
    G->cor = (int *)malloc(sizeof(int) * v);
    G->d = (int *)malloc(sizeof(int) * v);

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
void busca_largura_LA(GrafoLA *G, int s)
{
    int u = 0, v;
    Cell *aux;
    FilaE *f = NULL;

    if (valida_vertice_LA(G, s))
    {
        for (v = 0; v < G->V; v++)
        {
            G->cor[v] = 0;
            G->d[v] = INT_MAX;
            G->pai[v] = -1;
        }

        G->cor[s] = 1;
        G->d[s] = 0;

        f = criar_filaE();
        enfileirar(s, f);

        while (!filaE_vazia(f))
        {
            u = desenfileirar(f);
            
            aux = G->adj[u]->head;
            while (aux != NULL)
            {
                if (G->cor[aux->item] == 0)
                {
                    G->cor[aux->item] = 1;
                    G->pai[aux->item] = u;
                    G->d[aux->item] = G->d[u] + 1;

                    enfileirar(aux->item, f);
                }
                aux = aux->next;
            }
            G->cor[u] = 2;
        }
    }

    printf("v d p\n");

    for (v = 0; v < G->V; v++)
    {
        printf("%d ", v);

        if (G->d[v] < INT_MAX)
            printf("%d ", G->d[v]);
        else
            printf("- ");
        if (G->pai[v] >= 0)
            printf("%d\n", G->pai[v]);
        else
            printf("-\n");
    }

    liberar_filaE(f);
}

int main()
{
    int V, s, num;
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

    scanf("%d", &s);
    busca_largura_LA(G, s);

    return 0;
}