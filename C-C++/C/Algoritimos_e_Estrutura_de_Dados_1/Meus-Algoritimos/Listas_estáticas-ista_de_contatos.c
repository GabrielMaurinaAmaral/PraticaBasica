#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define TAMANHO_MAX 100

typedef struct Lista
{
    char item[TAMANHO_MAX][255];
    int tam;
} Lista;

Lista *criar_LISTA()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->tam = 0;
    return l;
}

int LISTA_vazia(Lista *l)
{
    return (l == NULL) || (l->tam == 0);
}

int LISTA_cheia(Lista *l)
{
    return (l != NULL) && (l->tam == TAMANHO_MAX);
}

int substr(char str[], char substr[])
{
    int i, j, aux;
    if (strlen(substr) > strlen(str))
    {
        return 0;
    }
    else
    {
        for (i = 0; i < (strlen(str) - strlen(substr) + 1); i++)
        {
            aux = 0;
            for (j = i; ((j < (i + strlen(substr))) && (substr[j - i] == str[j])); j++)
            {
                aux++;
            }
            if (aux == strlen(substr))
            {
                return 1;
            }
        }
        return 0;
    }
}

int inserir(Lista *l, char chave[])
{
    if (!LISTA_cheia(l))
    {
        strcpy(l->item[l->tam], chave);

        l->tam++;

        return 1;
    }

    return 0;
}

void imprimir_LISTA(Lista *l)
{
    int i;

    if (!LISTA_vazia(l))
    {
        for (i = 0; i < l->tam; i++)
        {
            printf("%s \n", l->item[i]);
        }
    }
}

int liberar_LISTA(Lista *l)
{
    if (l != NULL)
    {
        free(l);

        return 1;
    }

    return 0;
}

int buscar(Lista *l, char chave[])
{
    int i;

    if (!LISTA_vazia(l))
    {
        for (i = 0; i < l->tam; i++)
        {
            if (l->item[i] == chave)
            {
                return i;
            }
        }
    }

    return -1;
}

int main()
{
    Lista *contatos = criar_Lista();
    char nome[255], chave[255];
    int num, i;

    scanf("%s", chave);
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        scanf("%s", nome);

        if (1 == substr(nome, chave))
        {
            inserir(contatos, nome);
        }
    }

    imprimir_Lista(contatos);

    return 0;
}