

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