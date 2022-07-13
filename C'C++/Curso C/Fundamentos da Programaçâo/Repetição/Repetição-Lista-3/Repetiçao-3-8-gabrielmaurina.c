/*8) Apresente os números pares entre 100 e 200. Contar quantos são ímpares e não divisíveis por 3 nesse intervalo.
     Faça a média dos valores pares e divisíveis por 5 do intervalo.*/

#include<stdio.h>

int main (void)
{
    int i, cont1=0, cont2=0, soma=0;

    for(i=100; i<=200; i++)
    {
        if(i%2!=0 && i%3!=0)
        {
            cont1++;
        }
        if(i%2==0 && i%5==0)
        {
            cont2++;
            soma=soma+i;
        }
    }

    printf("Quantos sao impares e nao divisiveis por 3: %d \n", cont1);
    printf("Media dos valores pares e divisiveis por 5: %d ", soma/cont2);

 return 0;   
}