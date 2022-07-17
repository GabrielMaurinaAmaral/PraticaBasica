//Criar um vetor de caracteres e outro vetor de inteiros que conta as vogais do vetor de caracteres

#include <stdio.h>

int main(void)
{
    char caracteres[10];
    int i, vogais[5];

    for(i=0; i<10; i++)
    {
        printf("Digite o caractere %d: ", i);
        setbuf(stdin, NULL);
        scanf("%c", &caracteres[i]);//Adiciona elementos no vetor de caracteres
    }

    printf("\n\n==== VETOR DE CARACTERES ====\n");
    for(i=0; i<10; i++)
    {
        printf("%c\t", caracteres[i]); //Imprime o vetor de caracteres
    }

    printf("\n\n==== VETOR DE INTEIROS COM LIXO DE MEMORIA ====\n");
    for(i=0; i<5; i++)
    {
        printf("%d\t", vogais[i]);//Imprime o vetor de inteiros
    }

    //Inicializa o vetor de inteiros com 0
    for(i=0; i<5; i++)
    {
        vogais[i] = 0;
    }

    printf("\n\n==== VETOR DE INTEIROS INICIALIZADO COM 0 ====\n");
    for(i=0; i<5; i++)
    {
        printf("%d\t", vogais[i]);//Imprime o vetor de inteiros
    }

    //Percorre o vetor de caracteres e conta as vogais no vetor de inteiros
    for(i=0; i<10; i++)
    {
        if(caracteres[i] == 'a' || caracteres[i] == 'A')
        {
            vogais[0]++;
        }
        else if(caracteres[i] == 'e'|| caracteres[i] == 'E')
        {
            vogais[1]++;
        }
        else if(caracteres[i] == 'i'|| caracteres[i] == 'I')
        {
            vogais[2]++;
        }
        else if(caracteres[i] == 'o'|| caracteres[i] == 'O')
        {
            vogais[3]++;
        }
        else if(caracteres[i] == 'u'|| caracteres[i] == 'U')
        {
            vogais[4]++;
        }
    }

    printf("\n\n==== VETOR DE INTEIROS  ====\n");
    printf("A/a\tE/e\tI/i\tO/o\tU/u\n");
    for(i=0; i<5; i++)
    {
        printf("%d\t", vogais[i]);//Imprime o vetor de inteiros
    }

    return 0;
}
