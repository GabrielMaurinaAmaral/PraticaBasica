/*DO - WHILE e FOR
5) Ler um número maior que 2 e imprimir todos os pares entre 2 e o número lido. Imprimir a somaP dos pares, o produtoI dos ímpares que são divisíveis por 9 e a média de todos os números do intervalo.*/

#include<stdio.h>
int main(void)
{
    int i, x, k, j, somaP=0, somaT=0, produtoI=1, mediaT, cont;
    printf("Infome um numero: ");
    scanf("%d",&x);
 
    printf("Numeros pares: ");
    for(i=2; 2<=i && i<=x; i++)
    {
        if(i%2==0)
        {
            printf("%d,", i);
           somaP=somaP+i;
        }
    }

    printf("\nNumeros impar:");
    for(j=2; 2<=j && j<=x; j++)
    {
        if(j%9==0)
        {
            printf("%d,", j);
            produtoI=produtoI*j;
        }
    }
    
    for(k=2; 2<=k && k<=x; k++)
    {
        somaT=somaT+k;
        cont++
    }
     mediaT=somaT/cont;

    printf("\nSoma dos par: %d \n", somaP);
    printf("Produtos dos impar: %d\n", produtoI);
    printf("Media dos intervalo: %d",mediaT);
    return 0;   
}