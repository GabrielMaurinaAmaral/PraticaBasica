#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(void)
{ 
    float salariobase, gratificacao, salariobruto, salarioliquido, ir;

    printf("Insira o salario base: R$");
    scanf("%f", &salariobase);
    printf("Insira a gratificacao: R$");
    scanf("%f", &gratificacao);

    salariobruto = salariobase + gratificacao;

    if (salariobruto<1000)
    {
        ir = salariobruto*(15/100);
    }

    else
    {
        ir = salariobruto*(20/100);
    }

    salarioliquido = salariobruto - ir;

    printf("Seu salario liquido e R$%.2f\n", salarioliquido);

    system("pause");

    return 0;

}