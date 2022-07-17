/*7) Elaborar um programa que lê dois valores, verifica se o primeiro é múltiplo do segundo e escreve a mensagem "São múltiplos" ou "Não são múltiplos" dependendo da condição. Verificar para que não seja realizada uma divisão por zero. Nesse caso, informar que não é possível realizar uma divisão por zero.*/

#include<stdio.h>

int main(void)
{
    int x, y, z;
    printf("Informe o primeiro numero:");
    scanf("%d",&x);
    printf("Informe o segundo numero:");
    scanf("%d",&y);

    z=x%y;

    if(z==0)
    {
       printf("Sao multiplos");
    }
    else if(z!=0)
    {
       printf("nao sao multiplos");
    }

 return 0;
}
