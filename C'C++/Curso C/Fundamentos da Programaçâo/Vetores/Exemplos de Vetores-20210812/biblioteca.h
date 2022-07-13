char primo(int num)
{
    int i, contDiv=0;
    char resultado = 'n';

    for(i=1; i<=num; i++)
    {
        if(num%i == 0)
        {
            contDiv++;
        }
    }
    if(contDiv == 2)
    {
        resultado = 's';
    }

    return(resultado);
}

void sorteiaNumeros(int qtde, int limite)
{
    int i;

    srand(time(NULL));

    for(i=1; i<=qtde; i++)
    {
        printf("%d\t", rand()%limite + 1);
    }
}

int potencia(void)
{
    int base, expo, i, resultado=1;

    do
    {
        printf("Informe o valor da base: ");
        scanf("%d", &base);

        if(base < 0)
        {
            printf("Valor invalido\n");
        }
    }while(base < 0);

    do
    {
        printf("Informe o valor do expoente: ");
        scanf("%d", &expo);

        if(expo < 0)
        {
            printf("Valor invalido\n");
        }
    }while(expo < 0);

    for(i=1; i<=expo; i++)
    {
        resultado = resultado * base;
        if(i == expo)
        {
            printf("%d ", base);
        }
        else
        {
            printf("%d * ", base);
        }
    }

    return(resultado);
}

void media(void)
{
     int idade, i, soma=0;
     float media;

     for(i=1; i<=3; i++)
     {
        printf("Informe a idade: ");
        scanf("%d", &idade);

        soma = soma + idade;
     }

     media = soma / 3.0;

     printf("Media das idades: %.2f", media);
}
