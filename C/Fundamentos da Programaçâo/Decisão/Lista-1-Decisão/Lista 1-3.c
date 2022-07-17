/*3) Elaborar um programa que leia um caractere. Se o caractere informado for �F� ou �f� mostrar a mensagem �pessoa f�sica�, se informado �J� ou �j� mostrar a mensagem �pessoa jur�dica� ou mostrar "caractere inv�lido" para qualquer outro caractere.*/

#include<stdio.h>

int main(void)
{
    char x;
    printf("Informe um caractere: ");
    scanf("%c", &x);

    if(x=='F' || x=='f')
    {
       printf("Pessoa fisica");
    }
    else
    {
        if(x=='J' || x=='j')
        {
           printf("Pessoa juridica");
        }
        else
        {
            printf("caractere invalido");
        }
    }
    return 0;
}
