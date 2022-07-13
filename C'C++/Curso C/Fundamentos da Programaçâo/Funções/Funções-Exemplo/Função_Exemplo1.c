#include <stdio.h>

int quadrado(int a)
{
    return a*a;
}

int main(void)
{
    /*Função: conjunto de comandos que recebe um nome e pode ser chamada
    em qualquer parte de um programa, quantas vezes forem necessárias.
    Vantagens: estruturação do programa e reutilização de códigos.

    Forma geral de uma função
    tipo nome_da_função(parâmetros)
    {
        conjunto de declarações e comandos;
    }*/

    int num, i;

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("Quadrado do numero: %d\n", quadrado(num));

    printf("\nNUMERO\tQUADRADO\n");
    for(i=1; i<=15; i++)
    {
        printf("%d\t%d\n", i, quadrado(i));
    }

    return 0;
}
