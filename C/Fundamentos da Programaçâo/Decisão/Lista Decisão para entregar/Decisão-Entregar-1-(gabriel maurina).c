/*1) A contribui��o para o INSS � calculada da seguinte forma:
a) Sal�rio bruto at� tr�s sal�rios m�nimos = INSS 8%.
b) Sal�rio bruto acima de tr�s sal�rios m�nimos = INSS 10%.
c) pLara as contribui��es maiores que o sal�rio m�nimo, considerar a import�ncia de um sal�rio m�nimo.
Elaborar um programa que receba como entrada o valor do sal�rio m�nimo e o valor
do sal�rio bruto, calcule o INSS e o sal�rio l�quido restante e informe-os.*/

#include<stdio.h>

int main(void)
{
    float b, m, x, y;
    printf("Informe o salario minimo: R$");
    scanf("%f",&m);
    printf("Informe o salario bruto: R$");
    scanf("%f",&b);

    x=b*0.08;
    y=b*0.1;

    if(b<(m*3))
    {
        if(x>m)
        {
            printf("Salario liquido: R$%0.2f \n", b-m);
            printf("INSS foi de R$%0.2f", m);
        }
        else
        {
            printf("Salario liquido: R$%0.2f \n", b-x);
            printf("INSS foi de R$%0.2f", x);
        }    
    }
    else
    {
        if(y>m)
        {
            printf("Salario liquido: R$%0.2f \n", b-m);
            printf("INSS foi de R$%0.2f", m);
        }
        else
        {
            printf("Salario liquido: R$%0.2f \n", b-y);
            printf("INSS foi de R$%0.2f", y);
        }    
    }


 return 0;
}
