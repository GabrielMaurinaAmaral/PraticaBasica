/*Na matemática, o fatorial de um número é o produto de todos os inteiros positivos menores ou iguais ao número. Exemplo: Fatorial de 5 é 1 * 2 * 3 * 4 * 5 = 120. Elabore um programa que calcule e mostre o fatorial de um número informado pelo usuário. Validar esse número para que esteja em um intervalo de 1 a 20. Lembrando que fatorial de 1 = 1 e fatorial de 0 = 1.
Obs.: Use uma variável de tipo de dado long long int (%lld) para armazenar o fatorial.
*/

#include<stdio.h>

int main(void)
{
    int num, i;
    long long int fat=1;

    printf("Informe um numero: ");
    scanf("%d", &num);

    printf("%d! = ", num);

    for(i=num; i>=2; i--)
    {
        fat=fat*i;
        printf("%d * ", i);
    }
    printf("1 = %lld\n", fat);

    return 0;
}