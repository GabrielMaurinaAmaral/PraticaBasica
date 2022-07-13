int soma(int num1, int num2)
{
    return num1 + num2;
}

int subtracao(int num1, int num2)
{
    return num1 - num2;
}

int produto(int num1, int num2)
{
    return num1 * num2;
}

int divisao(int num1, int num2)
{
    return num1 / num2;
}

int resto(int num1, int num2)
{
    return num1 % num2;
}

int primo(int num1)
{
    int i, contDiv = 0;

    for (i = 1; i <= num1; i++)
    {
        if (num1 % i == 0)
        {
            contDiv++;
        }
    }
    if (contDiv == 2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void primoLimitado(int inf, int sup)
{
    int i, contDiv, k;

    printf("Primos entre %d e %d:", inf, sup);
    for (i = inf; i <= sup; i++)
    {
        contDiv = 0;
        for (k = 1; k <= i; k++)
        {
            if (i % k == 0)
            {
                contDiv++;
            }
        }
        if (contDiv == 2)
        {
            printf("%d\t", i);
        }
    }
}

void primoMedia(int inf, int sup)
{
    int i, contDiv, k, contPrimo = 0;
    float soma = 0;

    for (i = inf; i <= sup; i++)
    {
        contDiv = 0;
        for (k = 1; k <= i; k++)
        {
            if (i % k == 0)
            {
                contDiv++;
            }
        }
        if (contDiv == 2)
        {
            soma = soma + i;
            contPrimo++;
        }
    }
    printf("Media dos primos entre %d e %d: %f", inf, sup, soma / contPrimo);
}

void fatorialMostrar(int num1)
{
    int i;

    printf("\n%d!= ", num1);
    for (i = num1; i >= 2; i--)
    {
        printf(" %d *", i);
    }
    printf(" 1 = ");
}

void fatorialCalculo(int num1)
{
    int i;
    long long int produtoFat = 1;

    for (i = num1; i >= 2; i--)
    {
        produtoFat = produtoFat * i;
    }
    printf("%lld\n", produtoFat);
}


