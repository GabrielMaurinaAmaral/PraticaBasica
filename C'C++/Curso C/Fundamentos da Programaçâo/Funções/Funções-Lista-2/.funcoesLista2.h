void fatorial(int num1)
{
    int i;
    long long int produtoFat = 1;

    printf("\n%d!= ", num1);
    for (i = num1; i >= 2; i--)
    {
        printf(" %d *", i);
        produtoFat = produtoFat * i;
    }
    printf(" 1 = %lld\n", produtoFat);
}

int divisorQuant(int num1)
{
    int contDiv = 0, i;

    for (i = 1; i <= num1; i++)
    {
        if (num1 % i == 0)
        {
            contDiv++;
        }
    }

    return (contDiv);
}

int divisorMostrar(int num1)
{
    int i;

    for (i = 1; i <= num1; i++)
    {
        if (num1 % i == 0)
        {
            printf("%d\t", i);
        }
    }
}

int divisorSoma(int num1)
{
    int i, contDiv = 0, soma = 0;

    for (i = 1; i <= num1; i++)
    {
        if (num1 % i == 0)
        {
            printf("%d  ", i);
            contDiv++;
            soma = soma + i;
        }
    }
    printf(" ==> Quantidade: %d", contDiv);
    printf(" ==> Soma: %d", soma);
}

int mdc(int num1, int num2)
{
    int mdc;

    do
    {
        mdc = num1 % num2;
        num1 = num2;
        num2 = mdc;

    } while (mdc != 0);

    return num1;
}