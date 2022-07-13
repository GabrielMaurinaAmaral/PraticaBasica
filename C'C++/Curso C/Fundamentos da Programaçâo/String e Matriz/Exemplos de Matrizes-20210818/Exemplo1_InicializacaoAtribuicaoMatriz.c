#include <stdio.h>

int main(void)
{
    //Matriz - forma geral
    //tipo nomeMatriz[nro_linhas][nro_colunas];

    //Exemplo
    int i, j, matriz[3][2] = {{1,2},{3,4},{5,6}};//declaração e inicialização de matriz

    printf("Informe o elemento da primeira posicao da matriz: ");
    scanf("%d", &matriz[0][0]); //comando de leitura
    matriz[0][1] = 10; //comando de atribuição
    matriz[1][0] = matriz[0][0] + matriz[0][1]; //expressão

    printf("Primeiro elemento da matriz: %d\n", matriz[0][0]); //impressão do primeiro elemento da matriz
    printf("Ultimo elemento da matriz: %d\n\n", matriz[2][1]); //impressão do último elemento da matriz

    //grava elementos na matriz usando repetição
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Informe o elemento que vai na linha %d e na coluna %d da matriz: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    //imprime elementos da matriz usando repetição
    printf("\n=== MATRIZ ===\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d   ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
