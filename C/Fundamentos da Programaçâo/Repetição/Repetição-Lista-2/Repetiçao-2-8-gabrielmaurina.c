/*8) Ler números inteiros informados pelo usuário até ser informado um valor negativo. Dentre os números 
informados, exceto o valor negativo que é a condição de saída:

a) Contar a quantidade de números menores que 10 ou maiores que 100.
b) Contar a quantidade de números ímpares.
c) Contar a quantidade de números divisíveis por 10.
d) Contar a quantidade de números entre 10 e 100.
e) Contar quantas vezes é informado o número 30.
f) Contar quantas vezes é informado um número diferente de 10, de 20 e de 30.*/

#include<stdio.h>

int main (void)
{  
    int num, i, contA=0, contB=0, contC=0, contD=0, contE=0, contF=0;

    do
    {
        printf("Informe um numero: ");
        scanf("%d", &num);

        i=num;

        if(num>10 || 100<num)
        {
            contA++;
        }
        else if(num<=10 || 100>=num)
        {
            contD++;
        }
        
        if(num==30)
        {
            contE++;
        }
        if(num=!10 || num!=20 || num!=30) 
        {
            contF++;
        }

        if(num%2!=0)
        {
            contB++;
        }
        if(num%10==0)
        {
            contC++;
        }
        
    }while (0<=i);


    printf("Quantidade de números menores que 10 ou maiores que 100: %d\n", contA);
    printf("Quantidade de números ímpares: %d\n", contB);   
    printf("Quantidade de números divisíveis por 10: %d\n", contC);
    printf("quantidade de números entre 10 e 100; %d\n", contD);
    printf("Quantas vezes é informado o número 30: %d\n", contE);
    printf("Quantas vezes é informado um número diferente de 10, de 20 e de 30: %d", contF);

 return 0;
}