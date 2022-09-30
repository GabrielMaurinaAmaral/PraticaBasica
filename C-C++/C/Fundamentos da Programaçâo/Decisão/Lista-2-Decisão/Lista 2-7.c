/*7) Ler um n�mero e utilizando uma estrutura if else if else if... (obrigatoriamente encadeada) informar se ele:
a) � divis�vel por 5, por 3 ou por 2;
Exemplo: 30 � divis�vel por 2, 3 e 5.
b) � divis�vel somente por 5 e por 3; por 5 e por 2; ou por 3 e por 2;
Exemplo: 15 � divis�vel somente por 3 e por 5.
Exemplo: 10 � divis�vel somente por 5 e por 2.
Exemplo: 6 � divis�vel somente por 3 e por 2.
c) � divis�vel somente por 5, por 3 ou por 2;
Exemplo: 25 � divis�vel somente por 5
d) N�o � divis�vel por nenhum destes;
Exemplo: 7 n�o � divis�vel por 5, por 3 ou por 2;*/

#include <stdio.h>

int main(void)
{
    int x, a, b, c;
    printf("Informe um numero: ");
    scanf("%d", &x);

    a = x % 5;
    b = x % 3;
    c = x % 2;

    if (a == 0 && b == 0 && c == 0)
    {
        printf("%d eh por 2, 3 e 5", x);
    }
    else if ((a == 0 && b == 0) || (a == 0 && c == 0) || (c == 0 && b == 0))
    {
        if (a == 0 && b == 0)
        {
            printf("%d eh divisivel somente por 5 e por 3", x);
        }
        else if (a == 0 && c == 0)
        {
            printf("%d eh divisivel somente por 5 e por 2", x);
        }
    }
    else
    {
        if (a == 0)
        {
            printf("%d eh divisivel somente por 5", x);
        }
        else if (b == 0)
        {
            printf("%d eh divisivel somente por 3", x);
        }
        else
        {
            printf("%d eh divisivel somente por 2", x);
        }
    }
    if (a != 0 && b != 0 && c != 0)
    {
        printf("%d nao eh divisivel por 5, por 3, por 2", x);
    }
}
