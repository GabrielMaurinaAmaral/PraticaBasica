/*Uma pessoa resolveu fazer uma aplicação em uma poupança programada1. Para calcular seu rendimento,
ela deverá fornecer o valor constante da aplicação mensal, a taxa de juros (%) e o prazo da aplicação (em
meses). Sabendose que a fórmula usada para este cálculo é:*/

#include<stdio.h>
#include<math.h>

int main (void)
{

    int n;
    float i, vm, va;

    printf("Informe o valor da aplicação mensal:");
    scanf("%f",&vm);
    printf("Infome a taxa de juros(entre 1 a 0):");
    scanf("%f",&i);
    printf("quantas mensalidades:");
    scanf("%i",&n);

    va=(vm*(pow(1+i,n)-1))/i;

    printf("Valor final eh R$%.2f",va);

    return 0;

}
