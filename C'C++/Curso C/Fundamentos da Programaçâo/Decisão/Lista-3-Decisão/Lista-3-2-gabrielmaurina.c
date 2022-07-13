/*2) Ler dois números inteiros e informar:
a) Se ambos são divisíveis por 5.
b) Se pelo menos um deles é divisível por 5.
c) Se ambos são pares.
d) Se pelo menos um deles é ímpar.*/

#include<stdio.h>
#include<math.h>>

int main (void)
{
    int x,y;
    printf("Informe um numero:");
    scanf("%d",&x);
    printf("Informe outro numero:");
    scanf("%d",&y);

    if(x%5==0 && y%5==0)
    {
        printf("Ambos sao divisiveis por 5 \n");
    }
    else if(x%5==0 || y%5==0)
    {
        printf("Pelo menos um deles eh divisivel por 5 \n");
    }
    if(x%2==0 && y%2==0)
    {
        printf("Ambos sao pares \n");
    }
    else if(x%2!=0 || y%2!=0)
    {
        printf("Se pelo menos um deles eh impar \n");        
    }

 return 0;
}



