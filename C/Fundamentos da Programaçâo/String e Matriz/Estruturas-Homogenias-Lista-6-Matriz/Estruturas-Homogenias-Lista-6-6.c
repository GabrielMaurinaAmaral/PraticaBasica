/*6) Gerar uma matriz 3x3 com números randômicos no intervalo de 1 a 100 e a seguir escrever a localização (linha e a coluna) do maior valor.*/

#include <stdio.h>
#include "Funcoes-Matriz-Lista-6.h"

int main(void)
{
    int matriz[3][3], l, c, maior, auxL, auxC;

    gerarMatrizInteiro(3, 3, matriz, 1, 100);
    printf("\n====MATRIZ====\n");
    mostrarMatrizInteiro(3, 3, matriz);

    maior=0;
    auxL=0;
    auxC=0;
    for(l=0; l<3; l++)
    {
        for(c=0; c<3; c++)
        {
            if(matriz[l][c]>maior)
            {
                maior=matriz[l][c];
                auxC=c;
                auxL=l;
            }
        }
    }

    printf(" maior valor da matriz eh %d e esta da linha %d coluna %d", maior, auxL+1, auxC+1);


    return 0;
}