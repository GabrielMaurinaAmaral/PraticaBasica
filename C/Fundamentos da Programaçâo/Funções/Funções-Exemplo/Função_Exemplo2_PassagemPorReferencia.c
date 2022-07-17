/*Passagem de parâmetro por referência: usa-se o operador "*" na frente do nome do
parâmetro durante a declaração da função.*/

#include <stdio.h>

void somaMaisUm(int *x);

int main(void)
{
    int num;

    printf("Digite um valor para a variavel num: ");
    scanf("%d", &num);

    printf("\nVariavel num antes de passar pela funcao: %d\n", num);

    somaMaisUm(&num);//chamada da função com um ponteiro como parâmetro

    printf("Variavel num depois de passar pela funcao: %d\n", num);

    return 0;
}

void somaMaisUm(int *x) //x = o que está dentro do endereço de x
{
    *x = *x + 1;
    printf("Variavel num dentro da funcao: %d\n", *x);
}
