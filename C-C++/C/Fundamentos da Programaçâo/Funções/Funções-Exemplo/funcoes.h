int quadrado(int numero)
{
    return(numero * numero);
}

int primo(int numero)
{
    int i, contDiv=0;

    for(i=1; i<=numero; i++)
    {
        if(numero%i == 0)
        {
            contDiv++;
        }
    }
    return(contDiv);
}

float media(void)
{
    float nota1, nota2;

    printf("Informe a primeira nota: ");
    scanf("%f", &nota1);
    printf("Informe a segunda nota: ");
    scanf("%f", &nota2);

    return((nota1 + nota2)/2);
}

void multiplica(int numero1, int numero2)
{
    printf("\nMultiplicao: %d\n", numero1 * numero2);
}

void soma(void)
{
    int num, num1;

    printf("\nInforme um numero: ");
    scanf("%d", &num);
    printf("Informe outro numero: ");
    scanf("%d", &num1);

    printf("Soma: %d\n", num + num1);
}

int calculaFatorial(int numero)
{
    int i, fat=1;

    for(i=numero; i>=2; i--)
    {
        fat = fat * i;
    }

    return(fat);
}

void mostraFatorial(int numero, int fat)
{
    int i;

    printf("%d! = ", numero);

    for(i=numero; i>=2; i--)
    {
        printf("%d * ", i);
    }

    printf("1 = %d\n",  fat);

}
