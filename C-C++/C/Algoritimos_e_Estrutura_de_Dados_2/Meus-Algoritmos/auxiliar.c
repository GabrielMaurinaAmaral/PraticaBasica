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

FilaE *criar_filaE();

void enfileirar(int key, FilaE *f);

int liberar_filaE(FilaE *f);

void imprimir_fila(FilaE *f);

int desenfileirar(FilaE *f);

int filaE_vazia(FilaE *f);

void imprimir_lista(Lista *l);

void inserir_na_lista(int key, int peso, Lista *l);

Cell *criar_celula(int key, int peso);

int procurar(int key, Lista *l);

Lista *criar_lista();

static Lista **iniciar_LA(int n);

GrafoLA *iniciar_grafoLA(int v);

int aresta_existeLA(GrafoLA *G, int v1, int v2);

void inserir_arestaLA(GrafoLA *G, int v1, int v2, int peso);

void imprimir_arestasLA(GrafoLA *G);

void liberarGLA(GrafoLA *G);

int liberar_lista(Lista *l);

int lista_vazia(Lista *l);

void print_LA(GrafoLA *g_LA);

void prim_algorithm(GrafoLA *g_LA);

Cell *criar_celula_2(int key);

int extrai_minimo(FilaE *f, GrafoLA *g_LA);

int main()
{
    GrafoLA *g_LA = NULL;
    int quant, v1, v2, peso, arestas;
    scanf("%d", &quant);
    scanf("%d", &arestas);
    g_LA = iniciar_grafoLA(quant);

    for (int i = 0; i < arestas; i++)
    {
        scanf("%d", &v1);
        scanf("%d", &v2);
        scanf("%d", &peso);

        inserir_arestaLA(g_LA, v1, v2, peso);
    }

    printf("\n");

    // print_LA(g_LA);

    prim_algorithm(g_LA);

    return 0;
}

static void conta_par(NodeB *tree, int *contador)
{
    int i;
    if (tree != NULL)
    {
        for (i = 0; i < tree->nro_chaves; i++)
        {
            if (tree->chaves[i] % 2 == 0)
                (*contador)++;
            if (!tree->eh_no_folha)
                contar_par(tree->filhos[i], contador);
        }
        if (!tree->eh_no_folha) // após o laço acima, i será a posição da última página folha
            contar_par(tree->filhos[i], contador);
    }
}
int npar(NodeB *tree)
{
    int contador = 0;
    conta_par(tree, &contador);
    return contador;
}
