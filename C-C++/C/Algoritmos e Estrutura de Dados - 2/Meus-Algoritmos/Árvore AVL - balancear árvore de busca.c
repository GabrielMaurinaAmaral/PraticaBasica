#include <stdio.h>
#include <stdlib.h>
typedef struct NodeAVL NodeAVL;
typedef struct Node Node;

struct Node
{
    int item;
    struct Node *left;
    struct Node *right;
};

struct NodeAVL
{
    int item;
    int fb;
    struct NodeAVL *left;
    struct NodeAVL *right;
};

Node *criar(int item)
{
    Node *tree = (Node *)malloc(sizeof(Node));

    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

NodeAVL *criar_AVL(int item)
{
    NodeAVL *tree = (NodeAVL *)malloc(sizeof(NodeAVL));

    tree->item = item;
    tree->fb = 0;
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

static NodeAVL *rotateL(NodeAVL *tree)
{
    NodeAVL *auxA = tree->left, *auxB;

    if (auxA->fb == +1)
    {
        tree->left = auxA->right;
        auxA->right = tree;
        tree->fb = 0;
        tree = auxA;
    }
    else
    {
        auxB = auxA->right;
        auxA->right = auxB->left;
        auxB->left = auxA;
        tree->left = auxB->right;
        auxB->right = tree;

        if (auxB->fb == +1)
            tree->fb = -1;
        else
            tree->fb = 0;

        if (auxB->fb == -1)
            auxA->fb = +1;
        else
            auxA->fb = 0;

        tree = auxB;
    }

    return tree;
}

static NodeAVL *rotateR(NodeAVL *tree)
{
    NodeAVL *auxA = tree->right, *auxB;

    if (auxA->fb == -1)
    {
        tree->right = auxA->left;
        auxA->left = tree;
        tree->fb = 0;
        tree = auxA;
    }
    else
    {
        auxB = auxA->left;
        auxA->left = auxB->right;
        auxB->right = auxA;
        tree->right = auxB->left;
        auxB->left = tree;

        if (auxB->fb == -1)
            tree->fb = +1;
        else
            tree->fb = 0;

        if (auxB->fb == +1)
            auxA->fb = -1;
        else
            auxA->fb = 0;

        tree = auxB;
    }

    return tree;
}

NodeAVL *inserirAVL(NodeAVL *tree, int value, int *grown)
{
    NodeAVL *auxA, *auxB;

    if (tree == NULL)
    {
        tree = criar_AVL(value);

        *grown = 1;
    }
    else if (value < tree->item)
    {
        tree->left = inserirAVL(tree->left, value, grown);

        if (*grown)
        {
            switch (tree->fb)
            {
            case -1:
                tree->fb = 0;
                *grown = 0;
                break;
            case 0:
                tree->fb = +1;
                break;
            case +1:
                tree = rotateL(tree);
                tree->fb = 0;
                *grown = 0;
            }
        }
    }
    else if (value > tree->item)
    {
        tree->right = inserirAVL(tree->right, value, grown);

        if (*grown)
        {
            switch (tree->fb)
            {
            case +1:
                tree->fb = 0;
                *grown = 0;
                break;
            case 0:
                tree->fb = -1;
                break;
            case -1:
                tree = rotateR(tree);
                tree->fb = 0;
                *grown = 0;
            }
        }
    }

    return tree;
}

NodeAVL *abb_2_avl(Node *tree, NodeAVL *avl)
{
    int g = 0;
    if (tree != NULL)
    {
        avl = inserirAVL(avl, tree->item, &g);
        avl = abb_2_avl(tree->left, avl);
        avl = abb_2_avl(tree->right, avl);
    }

    return avl;
}

void imprimirPrefix(NodeAVL *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->item);
        imprimirPrefix(tree->left);
        imprimirPrefix(tree->right);
    }
}

int main()
{
    NodeAVL *arv;
    Node *arvore;
    int size, n;

    scanf("%d", &size);
    for (int i = 1; i < size; i++)
    {
        scanf("%d", &n);
        arvore = inserir(n, arvore);
    }

    arv = abb_2_avl(arvore, arv);
    imprimirPrefix(arv);

    return 0;
}