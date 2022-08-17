/*12) Faça um programa que imprima os n (indicado pelo usuário) primeiros números pares (começa em 0). Apresente 5 valores por linha.*/

#include<stdio.h>

int main(void)
{
    int i, num, j, soma=0;
    printf("Informe quantos pares apresentar: ");
    scanf("%d", &num);

    for(j=1; j<=num; j)
    {
        for(i=1; i<=5; i++)
        {
            printf("%2d    ", soma);
            soma=soma+2;    
        }
        printf("\n");
        j=j+2;
        
    }

 return 0;    
}