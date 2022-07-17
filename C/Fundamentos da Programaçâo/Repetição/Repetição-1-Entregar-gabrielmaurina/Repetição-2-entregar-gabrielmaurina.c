/*2) Uma empresa deseja calcular a depreciação de seus bens. Para tanto, desenvolver um programa que
obtenha a taxa de depreciação anual para os bens, o valor do bem a ser depreciado e o período em anos.
Valor depreciado = valor do bem * (taxa de depreciação / 100)
Valor do bem depreciado = valor do bem
valor depreciado
Mostrar os resultados com*/

#include<stdio.h>

int main(void)
{
    float valorBem, depreciacao, valorDep, somaDep;
    int periodo, i;

    printf("Informe o valor do bem a ser depreciado: R$");
    scanf("%f", &valorBem);
    printf("Informeo periodo de depreciamento (em anos): ");
    scanf("%d", &periodo);

    printf(" ANO      VALOR DOS BEM        DEPRECIACAO        VALOR DEPRECIADO\n");
    printf("==================================================================\n");
    for(i=1; i<=periodo; i++)
    {
        valorDep=valorBem*0.985;
        depreciacao=valorBem-valorDep;
        somaDep=somaDep+depreciacao;
        printf(" %d       %5.2f               %5.2f                %5.2f \n", i, valorBem, depreciacao, valorDep);
        valorBem=valorDep;
      
    }
    printf("==================================================================\n");
    printf("Depreciacao acumulada: %0.2f", somaDep);


  return 0;  
}