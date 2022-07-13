#include <stdio.h>

int main(void)
{
    char palavra1[20] = {'T','e','s','t','e','\0'}; //como vimos na inialização de vetores
    char palavra2[20] = "Teste"; //a Linguagem permite esse outro tipo de inicialização na qual o '\0' já está incluído automaticamente

    printf("String1: %s\n", palavra1);//imprime a string nome1
    printf("String2: %s\n\n", palavra2);//imprime a string nome2

    palavra1[0] = 'L';
    palavra2[0] = 'L';

    printf("String1: %s\n", palavra1);
    printf("String2: %s\n", palavra2);

    return 0;
}
