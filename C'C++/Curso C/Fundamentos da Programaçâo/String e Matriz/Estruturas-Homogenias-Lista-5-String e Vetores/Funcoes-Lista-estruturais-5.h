void numPerfeito(int vetor[], int i)
{
    int  j, somaDiv;

    somaDiv = 0;

    for (j = 1; j < vetor[i]; j++)
    {
        if (vetor[i] % j == 0)
        {
            somaDiv = somaDiv + j;
        
            if(somaDiv==vetor[i])
            {
                printf(" %d eh perfeito", vetor[i]);
            }
            else
            {
                printf(" %d eh perfeito", vetor[i]);
            }
        }
    }
}

int comparaString(char string1[], char string2[])
{
    int cont1, cont2, m, n;

    cont1 = 0;
    cont2 = 0;
    m = 0;
    n = 0;

    while (string1[m] != '\0')
    {
        cont1++;
        m++;
    }

    while (string2[n] != '\0')
    {
        if (string2[n] == string1[n])
        {
            cont2++;
        }
        n++;
    }

    if (cont1 == cont2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}