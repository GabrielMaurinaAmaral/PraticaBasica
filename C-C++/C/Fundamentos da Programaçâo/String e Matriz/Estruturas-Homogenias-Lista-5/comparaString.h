int main(char string1[], char string2[])
{
    int cont1, cont2, i, j;

    cont1 = 0;
    cont2 = 0;
    i = 0;
    j = 0;

    while (string1[i] != '\0')
    {
        cont1++;
        i++;
    }

    while (string2[j] != '\0')
    {
        if (string2[j] == string1[j])
        {
            cont2++;
        }
        j++;
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