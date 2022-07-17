/*9) Leia dois valores que representam os limites de um intervalo. O usuário pode informar os valores em ordem crescente ou decrescente.
     Para os limites do intervalo validar para que:
    a) O programa não aceite valores iguais, ou seja, que o limite inferior seja igual ao superior e vice-versa;
    b) Em cada limite não seja informado valor menor ou igual a zero.
Apresente os valores separados por tabulação. Faça a média dos valores que são divisíveis por 11 e por 7, desse intervalo.*/
 
#include<stdio.h>

int main (void)
{
    int    inf, sup, i, cont7=0, soma7=0, cont11=0, soma11=0;

    do
    {
    printf("Informe o limite inferior: ");
    scanf("%d", &inf);
    printf("Informe o limite superior: ");
    scanf("%d", &sup);
    } while(inf==sup && (inf<=0 || sup<=0));

    for(i=inf; inf<=i && i<=sup; i++ )
    {
        printf(" %d\t", i);

        if(i%7==0)
        {
            soma7=soma7+i;
            cont7++;
        }
        if(i%11==0)
         {
            soma11=soma11+i;
            cont11++;
        }

    }

    printf("\nMedia 7: %d", soma7/cont7);
    printf("\nMedia 11: %d", soma11/cont11);

 return 0;
}