//Examplo de matriz com três dimensões

#include <stdio.h>

int main(void)
{
    int i, j, k, matriz[3][2][2];

    matriz[0][0][0]=10; //inserindo 10 na primeira matriz na linha 0 e coluna 0
    matriz[0][0][1]=15; //inserindo 15 na primeira matriz na linha 0 e coluna 1
    matriz[0][1][0]=20; //inserindo 20 na primeira matriz na linha 1 e coluna 0
    matriz[0][1][1]=25; //inserindo 25 na primeira matriz na linha 1 e coluna 1

    matriz[1][0][0]=30; //inserindo 30 na segunda matriz na linha 0 e coluna 0
    matriz[1][0][1]=35; //inserindo 35 na segunda matriz na linha 0 e coluna 1
    matriz[1][1][0]=40; //inserindo 40 na segunda matriz na linha 1 e coluna 0
    matriz[1][1][1]=45; //inserindo 45 na segunda matriz na linha 1 e coluna 1

    matriz[2][0][0]=50; //inserindo 50 na terceira matriz na linha 0 e coluna 0
    matriz[2][0][1]=55; //inserindo 55 na terceira matriz na linha 0 e coluna 1
    matriz[2][1][0]=60; //inserindo 60 na terceira matriz na linha 1 e coluna 0
    matriz[2][1][1]=65; //inserindo 65 na terceira matriz na linha 1 e coluna 1

    //Usando estrutura de repetição para imprimir os elementos que estão na matriz de três dimensão
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
        {
            for(k=0; k<2; k++)
            {
                printf("%d   ", matriz[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
