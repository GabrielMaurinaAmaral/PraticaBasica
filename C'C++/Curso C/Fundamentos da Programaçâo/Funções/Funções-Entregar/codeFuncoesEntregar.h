int triangular(int num1)
{
    int i, produtoTrian = 0, result = 0;

    for (i = 1; i <= num1; i++)
    {
        produtoTrian = i * (i + 1) * (i + 2);
        if (produtoTrian == num1)
        {

            result = 1;
            printf("\n %d eh triangula ==> %d * %d * %d = %d\t", num1, i, i + 1, i + 2, produtoTrian);
            i = num1 + 1;
        }
    }
    return (result);
}

int retangular(int num1)
{
    int i, somaRetan = 0, result = 0, aux;

    for (i = 2; i <= num1; i = i + 2)
    {
        somaRetan = somaRetan + i;

        if (somaRetan == num1)
        {
            result = 1;
            aux = i;

            printf("\n%d eh retangular ==> ", num1);
            for (i = 2; i <= aux; i = i + 2)
            {
                if (i < aux)
                {
                    printf("%d + ", i);
                }
                else if (i == aux)
                {
                    printf("%d ", i);
                }
            }
            printf("= %d\n", somaRetan);
        }
    }
    return (result);
}

#include <math.h>
int quadrado(int num1)
{
    int result = 0, raiz;

    raiz = sqrt(num1);
    if (raiz * raiz == num1)
    {
        result = 1;
        printf("\n %d eh quadrado perfeito ==> raiz quadrada de %d eh %d \n", num1, num1, raiz);
    }

    return (result);
}

int palindromo(int num1)
{
    int auxPalin, soma = 0, i, result = 0;

    auxPalin = num1;
    while (auxPalin > 0)
    {
        i = auxPalin % 10;
        soma = (soma * 10) + i;
        auxPalin = auxPalin / 10;
    }

    if (num1 == soma)
    {
        result = 1;
        printf("\n %d eh um palindromo\n ", num1);
    }

    return (result);
}

void quadroCaract(int coluna, int linha, char caract)
{
    int i, contColuna=0, result;

    result=coluna*linha;

    for(i=1; i<=result; i++)
    {
        printf("%c\t", caract);
        contColuna++;

        if(contColuna==coluna)
        {
            printf("\n");
            contColuna=0;
        }    
    }
}