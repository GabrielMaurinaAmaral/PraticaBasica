/*2) Ler tr�s valores inteiros diferentes, encontrar e mostrar o n�mero do meio. Deve ser criada uma vari�vel para armazenar o n�mero do meio.*/

#include<stdio.h>

int main(void)
{
    int x,y,z,a;
    printf("Informe um numero:");
    scanf("%d",&x);
    printf("Informe um numero:");
    scanf("%d",&y);
    printf("Informe um numero:");
    scanf("%d",&z);

    if(z<y && z>x || z>y && z<x)
    {
       a=z;
       printf("%d eh o numero do meio", z);
    }
    else if(y<z && y>x || y>z && y<x)
    {
       a=y;
       printf("%d eh o numero do meio", y);
    }
    else
    {
       a=x;
       printf("%d eh o numero do meio", x);
    }

 return 0;
}
