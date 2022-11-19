#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define N 5

typedef struct NodeB NodeB;

struct NodeB
{
    int nro_chaves;
    int chaves[N - 1];
    NodeB *filhos[N];
    int eh_no_folha;
};

NodeB *criar_ArvoreB()
{
    NodeB *tree = malloc(sizeof(NodeB));
    int i;

    tree->eh_no_folha = 1;
    tree->nro_chaves = 0;

    for (i = 0; i < N; i++)
        tree->filhos[i] = NULL;

    return tree;
}

int liberar(NodeB *tree)
{
    if (tree != NULL)
    {
        free(tree);

        return 1;
    }

    return 0;
}
static int busca_binaria(int key, NodeB *tree)
{
    int ini, fim, meio;

    if (tree != NULL)
    {
        ini = 0;
        fim = tree->nro_chaves - 1;

        while (ini <= fim)
        {
            meio = (ini + fim) / 2;

            if (tree->chaves[meio] == key)
                return meio;
            else if (tree->chaves[meio] > key)
                fim = meio - 1;
            else
                ini = meio + 1;
        }

        return ini;
    }

    return -1;
}

int pesquisar(int key, NodeB *tree)
{
    int pos = busca_binaria(key, tree);

    if (pos >= 0)
    {
        if (tree->chaves[pos] == key)
            return 1;
        else
            return pesquisar(key, tree->filhos[pos]);
    }

    return 0;
}

static NodeB *split_pag(NodeB *pai, int posF_cheio)
{
    int i;
    NodeB *pag_esq = pai->filhos[posF_cheio];
    NodeB *pag_dir;

    pag_dir = criar_ArvoreB();
    pag_dir->eh_no_folha = pag_esq->eh_no_folha;
    pag_dir->nro_chaves = round((N - 1) / 2);

    for (i = 0; i < pag_dir->nro_chaves; i++)
        pag_dir->chaves[i] = pag_esq->chaves[i + pag_dir->nro_chaves];

    if (!pag_esq->eh_no_folha)
        for (i = 0; i < pag_dir->nro_chaves; i++)
            pag_dir->filhos[i] = pag_esq->filhos[i + pag_dir->nro_chaves];

    pag_esq->nro_chaves = (N - 1) / 2;

    for (i = pai->nro_chaves + 1; i > posF_cheio + 1; i--)
        pai->filhos[i + 1] = pai->filhos[i];

    pai->filhos[posF_cheio + 1] = pag_dir;
    pai->filhos[posF_cheio] = pag_esq;
    pai->chaves[posF_cheio] = pag_dir->chaves[0];
    pai->nro_chaves++;

    for (i = 0; i < pag_dir->nro_chaves; i++)
        pag_dir->chaves[i] = pag_dir->chaves[i + 1];

    pag_dir->nro_chaves--;

    return pai;
}

static NodeB *inserir_pagina_nao_cheia(NodeB *tree, int key)
{
    int i;
    int pos = busca_binaria(key, tree);

    if (tree->eh_no_folha)
    {
        for (i = tree->nro_chaves; i > pos; i--)
            tree->chaves[i] = tree->chaves[i - 1];

        tree->chaves[i] = key;
        tree->nro_chaves++;
    }
    else
    {
        if (tree->filhos[pos]->nro_chaves == N - 1)
        {
            tree = split_pag(tree, pos);

            if (key > tree->chaves[pos])
                pos++;
        }

        tree->filhos[pos] = inserir_pagina_nao_cheia(tree->filhos[pos], key);
    }

    return tree;
}

NodeB *inserir(NodeB *tree, int key)
{
    NodeB *aux = tree;
    NodeB *nova_pag;

    if (aux->nro_chaves == N - 1)
    {
        nova_pag = criar_ArvoreB();

        tree = nova_pag;

        nova_pag->eh_no_folha = 0;
        nova_pag->filhos[0] = aux;
        nova_pag = split_pag(nova_pag, 0);
        nova_pag = inserir_pagina_nao_cheia(nova_pag, key);

        tree = nova_pag;
    }
    else
        tree = inserir_pagina_nao_cheia(aux, key);

    return tree;
}

void media_todal(NodeB *tree, int *soma, int *cont_chaves)
{
    if (tree != NULL)
    {
        if (tree->eh_no_folha)
        {
            for (int i = 0; i < tree->nro_chaves; i++)
                *soma += tree->chaves[i];
            *cont_chaves += tree->nro_chaves;
        }
        else
            for (int i = 0; i < tree->nro_chaves; i++)
                media_todal(tree->filhos[i], soma, cont_chaves);
    }
}

int main()
{
    NodeB *arvoreB = criar_ArvoreB();
    int len, num, *soma = 0, *cont = 0;

    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &num);
        arvoreB = inserir(arvoreB, num);
    }

    media_todal(arvoreB, &soma, &cont);
    printf("%d %d", soma, cont);

    return 0;
}