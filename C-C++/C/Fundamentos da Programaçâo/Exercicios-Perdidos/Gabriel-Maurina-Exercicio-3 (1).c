#include <stdio.h>

int strPalavras(char str1[])
{
    int i = 0, result = 0, cont = 0;

    while (str1[i] != '\0')
    {

        if (result == 0)/*pegar a primera letra*/
        {
            if (str1[i] != ' ')
            {
                result = 1;
                cont++;
            }
        }

        else if ((str1[i] != ' ' && str1[i - 1] == ' '))/*as depmais palavras com parametros no meior de espaços*/
        {
            cont++;
        }

        i++;
    }

    return cont;
}

void vetorContCarac(int vetor[], char str[])/*conta quantas levra tem cada palavra*/
{
    int i = 0, contC = 0, j = 0;

    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            contC++;
        }
        if (str[i + 1] == ' ' || str[i + 1] == '\0')
        {
            vetor[j] = contC;
            j++;
            contC = 0;
        }

        i++;
    }
}

int mostrarVetor(int vetor[], int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf(" %d\t", vetor[i]);
    }
}

void strPrimo(char str1[], char str2[])/*grava string em outra apenas primos na tabela esqueci o nome*/
{
    int i, j, k, contDiv;

    i = 0;
    k = 0;
    j = 0;
    while (str1[i] != '\0')
    {
        contDiv = 0;

        for (j = 1; j <= str1[i]; j++)
        {
            if (str1[i] % j == 0)
            {
                contDiv++;
            }
        }
        if (contDiv == 2)
        {
            str2[k] = str1[i];
            k++;
        }
         
        i++;
    }

    str2[k]='\0';/**/
}

int main(void)/*função principal*/
{
    char str1[100], str2[100];
    int tam, i;

    printf("Informe string: ");
    gets(str1);

    printf(" %d ", strPalavras(str1));
    tam = strPalavras(str1);

    int vetor[tam];

    vetorContCarac(vetor, str1);
    printf("\n==== caractres por palavras ====\n");
    mostrarVetor(vetor, tam);

    strPrimo(str1, str2);/*chamdo a função*/
    printf("\n=====String Primo======\n");
    i=0;
    while (str2[i]!='\0')
    {
        printf(" %c", str2[i]);
        i++;
    }
    
    return 0;
}