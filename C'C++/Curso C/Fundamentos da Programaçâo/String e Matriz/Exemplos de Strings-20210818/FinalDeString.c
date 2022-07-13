#include <stdio.h>

int main(void)
{
    char palavra[20] = "Oitenta";

    printf("String: %s\n", palavra);


    palavra[2] = '\0';

    printf("String: %s\n", palavra);

    return 0;
}
