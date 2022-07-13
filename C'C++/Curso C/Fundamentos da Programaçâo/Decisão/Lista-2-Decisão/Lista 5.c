/*5) Calcular o imposto de renda de uma pessoa de acordo com a seguinte tabela:
Renda anual
Alíquota*
Até R$ 10.000,00
0%
> R$ 10.000,00 e <= R$ 25.000,00
10%
Acima de R$ 25.000,00
25%
*Alíquota é o percentual para realizar o cálculo do imposto de renda a ser pago.
Se informado valor negativo, não realizar o cálculo e informar o usuário*/

#include<stdio.h>

int main (void)
{
    float x;
    printf("Informe a renda anual: R$ ");
    scanf("%f", &x);

    if(x>0 && x<=10000)
    {
        printf("A renda eh de R$%0.2f",x);
    }
    if(x>10000 && x<=25000)
    {
        printf("A renda eh de R$%0.2f", x*1.1);
    }
    if(x>25000)
    {
        printf("A renda eh de R$%0.2f", x*1.25);
    }
    else
    {
        printf("dados informados incoretamente");
    }
 return 0;
}
