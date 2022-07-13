#include <stdio.h>

int main(void)
{
    char string[30];

    printf("Digite uma string: ");
    //scanf("%s", string);
    gets(string);

    printf("String: %s\n", string);

    return 0;
}
