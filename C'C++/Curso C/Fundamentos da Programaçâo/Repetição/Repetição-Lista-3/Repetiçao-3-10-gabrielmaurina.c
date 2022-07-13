/*10) Escreva um algoritmo que gere a série de Fibonacci até o termo n que é informado pelo usuário. 
      A série de Fibonacci é formada pela sequência: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ... , etc*/

#include<stdio.h>

int main (void)
{
    int i, num, antes=1, depois, meio=1;

    do
    {
        printf("Quantos termos mostar: ");
        scanf("%d", &num); 

    } while(num<=0);
    
    printf("A série de Fibonacci é formada pela sequência: 1, ");
    for(i=1; i<=num; i++)
    {
        printf("%d, ", meio);
        depois=antes+meio;
        antes=meio;
        meio=depois;
   
        
    }

 return 0;
}
