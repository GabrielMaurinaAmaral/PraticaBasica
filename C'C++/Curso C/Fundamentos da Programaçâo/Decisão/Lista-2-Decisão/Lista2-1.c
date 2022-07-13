/*1) Ler três valores inteiros diferentes, encontrar e mostrar o menor deles. Deve ser criada uma variável para armazenar o menor número.*/

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

    if(y>z && x>z)
    {
       a=z;
       printf("%d numero entre os tres", z);
    }
    else if(x>y && z>y)
    {
       a=y;
       printf("%d numero entre os tres", y);
    }
    else
    {
       a=x;
       printf("%d numero entre os tres", x);
    }
}

