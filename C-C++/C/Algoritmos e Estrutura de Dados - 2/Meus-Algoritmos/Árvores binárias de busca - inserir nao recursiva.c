#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int item;
    struct Node *left;
    struct Node *right;
} Node;

Node *criar(int item)
{
    Node *tree = (Node *)malloc(sizeof(Node));

    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

Node *inserir(int item, Node *tree)
{
    Node *aux, *auxP;

    if (tree == NULL)
        tree = criar(item);
    else
        auxP = aux = tree;

    while (aux != NULL)
    {
        auxP = aux;
        if (item < aux->item)
            aux = aux->left;
        else
            aux = aux->right;
    }

    if (item < aux->item)
        auxP->left = criar(item);
    else
        auxP->right = criar(item);

    return tree;
}
