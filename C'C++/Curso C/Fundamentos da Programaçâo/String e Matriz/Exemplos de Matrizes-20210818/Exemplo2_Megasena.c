//Imprime 50 combina��es de jogos para a megasena

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i, j, matriz[50][6]; //declara��o da matriz

    srand(time(NULL));

    //Grava elementos na matriz
    for(i=0; i<50; i++) //50 linhas
    {
        for(j=0; j<6; j++) //6 colunas
        {
            matriz[i][j] = rand() % 60 + 1; //gera n�mero aleat�rio entre 1 e 60.
        }
    }
        
    //Imprime os elementos da matriz
    for(i=0; i<50; i++)
    {
        printf("Combinacao de %2d: ", i + 1);
        for(j=0; j<6; j++)
        {
            printf("%2d  ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
