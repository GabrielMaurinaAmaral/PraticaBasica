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
    if (tree == NULL)
        tree = criar(item);
    else if (item < tree->item)
        tree->left = inserir(item, tree->left);
    else if (item > tree->item)
        tree->right = inserir(item, tree->right);

    return tree;
}

void posfix(Node *tree)
{
    if (tree != NULL)
    {
        posfix(tree->left);
        posfix(tree->right);
        if (tree->left == NULL && tree->right == NULL)
            printf(" %d", tree->item);
    }
}

void liberar_arvore(Node *tree)
{
    if (tree != NULL)
    {
        liberar_arvore(tree->left);
        liberar_arvore(tree->right);
        free(tree);
    }
}

int main()
{
    int len, num;
    scanf("%d", &len);

    scanf("%d", &num);
    Node *arvore = criar(num);
    for (int i = 1; i < len; i++)
    {
        scanf("%d", &num);
        inserir(num, arvore);
    }

    posfix(arvore);

    liberar_arvore(arvore);

    return 0;
}