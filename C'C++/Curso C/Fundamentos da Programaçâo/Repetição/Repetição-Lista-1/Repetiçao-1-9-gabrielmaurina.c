/*DO - WHILE
9) Ler um número que indica a quantidade de ímpares iniciando em 1 que deve ser mostrada. O valor
informado para a quantidade deve ser maior que 0. Validar a entrada.
Exemplo:*/

#include<stdio.h>

int main (void)
{
    int x=1, numeImpar, contImpar=1;

    do
    { 

        printf("Informea quantidade de impars: ");
        scanf("%d", &numeImpar);
         if(numeImpar==0)
        {
            printf("informe novamenre");
        }
        while(numeImpar>0)
        {
            printf("%d\n", x);
            x=(2*contImpar)+1;
            contImpar++;

            if(numeImpar+1==contImpar)
            {
                numeImpar=0;
            }
        }

    } while (numeImpar>0);

 return 0;
}
