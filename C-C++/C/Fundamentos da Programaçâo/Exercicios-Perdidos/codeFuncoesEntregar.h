void triangular(int num1)
{
    int i, produtoTrian = 0, aux = 0;

    for (i = 1; i <= num1; i++)
    {
        produtoTrian = i * (i + 1) * (i + 2);
        if (produtoTrian == num1)
        {
            aux = 1;
            printf("\n %d eh triangula ==> %d * %d * %d = %d\t", num1, i, i + 1, i + 2, produtoTrian);
            i = num1 + 1;
        }
    }
    if (aux == 0)
    {
        printf("\n%d nao eh triangular\t", num1);
    }
}

int retangular(int num1)
{
    int i, somaRetan=0, result=0, aux;

    for (i = 2; i <= num1; i=i+2)
    {
        somaRetan = somaRetan + i;

        if (somaRetan == num1)
        {
            result=1;
            aux=i;

            printf("\n%d eh retangular ==> ", num1);
            for(i=2; i<=aux; i=i+2)
            {
                if(i < aux)
                {
                    printf("%d + ", i);
                }
                else if(i == aux)
                {
                    printf("%d ", i);
                }
            }
            printf("= %d\n", somaRetan);
        }
    }
    return(result);

}
