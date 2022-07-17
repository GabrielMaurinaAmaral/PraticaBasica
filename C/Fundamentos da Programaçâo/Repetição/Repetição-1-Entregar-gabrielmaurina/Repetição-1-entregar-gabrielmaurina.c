/*1) Ler um número e ler um dígito. Contar quantos dígitos o número possui. Exemplo:
É informado 5 como dígito:
55
possui 2 dígitos cinco;
10
possui nenhum dígito cinco;
1550
possui dois dígitos cinco;
50050
possui dois dígitos cinco.
Repetir o
programa enquanto informados valores positivos.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num, i, dig, aux;
    char opc;

    do
    {
        int qtd_digito = 0;

        do
        {
            printf("Informe um numero: ");
            scanf("%d", &num);
            if (num < 0)
            {
                printf("Numero invalido, ele dever ser positivo\n");
            }
        } while (num < 0);

        do
        {
            printf("Inforem um digito: ");
            scanf("%d", &dig);
            if (dig < 0 && dig > 9)
            {
                printf("digito invalido ele dever ser positivo e menor que 10\n");
            }
        } while (num < 0 && (dig < 0 || dig > 9));

        while (num > 0)
        {
            aux = num % 10;
            num = (num / 10);
            if (aux == dig)
            {
                qtd_digito++;
            }
        }
        printf("\nO numero tem %d digitos iguais a %d \n", qtd_digito, dig);

        do
        {
            setbuf(stdin, NULL);
            printf("Deseja repetir o programa: ");
            scanf("%c", &opc);

            if (opc != 'N' || opc != 'n' || opc != 'S' || opc != 's')
            {
                printf("Caracter errado\n");
            }

        } while (opc != 'N' || opc != 'n' || opc != 'S' || opc != 's');

    } while (opc == 'S' || opc == 's');

    system("pause");
    return 0;
}
