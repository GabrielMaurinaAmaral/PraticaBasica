/*7) Ler um número e utilizando uma estrutura if else if else if... (obrigatoriamente encadeada) informar se ele:
a) É divisível por 5, por 3 ou por 2;
Exemplo: 30 é divisível por 2, 3 e 5.
b) É divisível somente por 5 e por 3; por 5 e por 2; ou por 3 e por 2;
Exemplo: 15 é divisível somente por 3 e por 5.
Exemplo: 10 é divisível somente por 5 e por 2.
Exemplo: 6 é divisível somente por 3 e por 2.
c) É divisível somente por 5, por 3 ou por 2;
Exemplo: 25 é divisível somente por 5
d) Não é divisível por nenhum destes;
Exemplo: 7 não é divisível por 5, por 3 ou por 2;*/

#include<stdio.h>

int main (void)
{
    int x, a, b, c;
    printf("Informe um numero: ");
    scanf("%d",&x);

    a=x%5;
    b=x%3;
    c=x%2;

    if(a==0 && b==0 && c==0)
    {
        printf("%d eh por 2, 3 e 5", x);
    }
    else if((a==0 && b==0) || (a==0 && c==0) || (c==0 && b==0))
    {
        if(a==0 && b==0)
        {
           printf("%d eh divisivel somente por 5 e por 3",x);
        }
        else if(a==0 && c==0)
        {
            printf("%d eh divisivel somente por 5 e por 2",x);
        }

    }
    else
    {
        if(a==0)
        {
            printf("%d eh divisivel somente por 5",x);
        }
        else if(b==0)
        {
            printf("%d eh divisivel somente por 3",x);
        }
        else
        {
            printf("%d eh divisivel somente por 2",x);
        }
    }
    if(a!=0 && b!=0 && c!=0)
    {
       printf("%d nao eh divisivel por 5, por 3, por 2",x);
    }

}
