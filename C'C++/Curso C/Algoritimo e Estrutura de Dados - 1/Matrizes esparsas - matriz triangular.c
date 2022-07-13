#include <stdio.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct ListaE ListaE;
typedef struct Spa_Mat Spa_Mat;

struct Cell
{
    int item;
    int col;
    Cell *next;
};

struct ListaE
{
    Cell *head;
};

struct Spa_Mat
{
    int n_lin;
    int n_col;
    ListaE **lin;
};

Spa_Mat *criar(int l, int c)
{
    Spa_Mat *mat = (Spa_Mat *)malloc(sizeof(Spa_Mat));
    int i;

    mat->n_col = c;
    mat->n_lin = l;
    mat->lin = (ListaE **)malloc(sizeof(ListaE *) * l);

    for (i = 0; i < l; i++)
    {
        mat->lin[i] = (ListaE *)malloc(sizeof(ListaE));
        mat->lin[i]->head = NULL;
    }

    return mat;
}

Cell *criar_celula(int item, int col)
{
    Cell *nova = (Cell *)malloc(sizeof(Cell));
    nova->item = item;
    nova->col = col;
    nova->next = NULL;

    return nova;
}

static int validar_pos_matriz(int lin, int col, Spa_Mat *mat)
{
    return (mat != NULL) && (lin >= 0) && (lin < mat->n_lin) && (col >= 0) && (col < mat->n_col);
}

static void trocar_inserir_na_lista(int item, int col, ListaE *l)
{
    Cell *auxA, *auxP, *novo;

    if ((l->head == NULL) || (col < l->head->col))
    {
        novo = criar_celula(item, col);
        novo->next = l->head;
        l->head = novo;
    }
    else if (col == l->head->col)
    {
        l->head->item = item;
    }
    else
    {
        auxA = l->head;
        auxP = auxA;

        while ((auxP != NULL) && (auxP->col < col))
        {
            auxA = auxP;
            auxP = auxP->next;
        }

        if ((auxP != NULL) && (col == auxP->col))
            auxP->item = item;
        else
        {
            novo = criar_celula(item, col);
            novo->next = auxA->next;
            auxA->next = novo;
        }
    }
}

static void remover_na_lista(int col, ListaE *l)
{
    Cell *auxA, *auxP = NULL;

    if (l->head != NULL)
    {
        if (col == l->head->col)
        {
            auxP = l->head;
            l->head = l->head->next;
            free(auxP);
        }
        else
        {
            auxA = l->head;
            auxP = auxA;

            while ((auxP != NULL) && (auxP->col < col))
            {
                auxA = auxP;
                auxP = auxP->next;
            }

            if ((auxP != NULL) && (col == auxP->col))
            {
                auxA->next = auxP->next;

                free(auxP);
            }
        }
    }
}

void trocar(int item, int l, int c, Spa_Mat *mat)
{
    if (validar_pos_matriz(l, c, mat))
    {
        if (item > 0)
            trocar_inserir_na_lista(item, c, mat->lin[l]);
        else
            remover_na_lista(c, mat->lin[l]);
    }
}

void triangular(Spa_Mat *mat)
{
    int inf = 0, sup = 0;

    for (int i = 0; i < mat->n_lin; i++)
    {
        Cell *aux = mat->lin[i]->head;

        while (aux != NULL)
        {
            if (i < aux->col && aux->item != 0)
                sup = 1;
            else if (i > aux->col && aux->item != 0)
                inf = 1;

            aux = aux->next;
        }
    }

    sup == 0 || inf == 0 || (sup = 0 && inf == 0) ? printf("triangular") : printf("nao triangular");
}

int main()
{
    int n, item;
    scanf("%d", &n);
    Spa_Mat *mat = criar(n, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &item);
            trocar(item, i, j, mat);
        }
    }

    triangular(mat);

    return 0;
}