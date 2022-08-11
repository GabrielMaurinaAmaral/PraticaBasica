#include <stdio.h>
#include <stdlib.h>

typedef struct Celula Celula;
typedef struct ListaEncadeada ListaEncadeada;
typedef struct Matriz_Esparsa Matriz_Esparsa;

struct Celula
{
    int item;
    int coluna;
    Celula *proximo;
};

struct ListaEncadeada
{
    Celula *head;
};

struct Matriz_Esparsa
{
    int numero_linha;
    int numero_coluna;
    ListaEncadeada **linha;
};

Matriz_Esparsa *criar(int l, int c)
{
    Matriz_Esparsa *mat = (Matriz_Esparsa *)malloc(sizeof(Matriz_Esparsa));
    int i;

    mat->numero_coluna = c;
    mat->numero_linha = l;
    mat->linha = (ListaEncadeada **)malloc(sizeof(ListaEncadeada *) * l);

    for (i = 0; i < l; i++)
    {
        mat->linha[i] = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));
        mat->linha[i]->head = NULL;
    }

    return mat;
}

Celula *criar_celula(int item, int coluna)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->item = item;
    nova->coluna = coluna;
    nova->proximo = NULL;

    return nova;
}

static int validar_pos_matriz(int linha, int coluna, Matriz_Esparsa *mat)
{
    return (mat != NULL) && (linha >= 0) && (linha < mat->numero_linha) && (coluna >= 0) && (coluna < mat->numero_coluna);
}

static void trocar_inserir_na_lista(int item, int coluna, ListaEncadeada *l)
{
    Celula *auxA, *auxP, *novo;

    if ((l->head == NULL) || (coluna < l->head->coluna))
    {
        novo = criar_celula(item, coluna);
        novo->proximo = l->head;
        l->head = novo;
    }
    else if (coluna == l->head->coluna)
    {
        l->head->item = item;
    }
    else
    {
        auxA = l->head;
        auxP = auxA;

        while ((auxP != NULL) && (auxP->coluna < coluna))
        {
            auxA = auxP;
            auxP = auxP->proximo;
        }

        if ((auxP != NULL) && (coluna == auxP->coluna))
            auxP->item = item;
        else
        {
            novo = criar_celula(item, coluna);
            novo->proximo = auxA->proximo;
            auxA->proximo = novo;
        }
    }
}

static void remover_na_lista(int coluna, ListaEncadeada *l)
{
    Celula *auxA, *auxP = NULL;

    if (l->head != NULL)
    {
        if (coluna == l->head->coluna)
        {
            auxP = l->head;
            l->head = l->head->proximo;
            free(auxP);
        }
        else
        {
            auxA = l->head;
            auxP = auxA;

            while ((auxP != NULL) && (auxP->coluna < coluna))
            {
                auxA = auxP;
                auxP = auxP->proximo;
            }

            if ((auxP != NULL) && (coluna == auxP->coluna))
            {
                auxA->proximo = auxP->proximo;

                free(auxP);
            }
        }
    }
}

void trocar(int item, int l, int c, Matriz_Esparsa *mat)
{
    if (validar_pos_matriz(l, c, mat))
    {
        if (item > 0)
            trocar_inserir_na_lista(item, c, mat->linha[l]);
        else
            remover_na_lista(c, mat->linha[l]);
    }
}

void cont_nulo_Matriz_Esparsa(Matriz_Esparsa *mat)
{
    int nul, cont;
    Celula *aux;

    for (int i = 0; i < mat->numero_linha; i++)
    {
        aux = mat->linha[i]->head;
        cont = 0;

        while (aux != NULL)
        {
            cont++;
            aux = aux->proximo;
        }
        nul += mat->numero_coluna - cont;
    }

    printf("%d", nul);
}

int main()
{
    int l, c, item;
    scanf("%d %d", &l, &c);
    Matriz_Esparsa *m = criar(l, c);

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &item);
            trocar(item, i, j, m);
        }
    }

    cont_nulo_Matriz_Esparsa(m);

    return 0;
}