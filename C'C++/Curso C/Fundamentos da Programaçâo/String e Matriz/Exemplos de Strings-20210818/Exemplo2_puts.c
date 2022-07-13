#include <stdio.h>

int main(void)
{
    char nome[35];

    printf("Digite o seu nome: ");
    gets(nome);
    printf("Nome informado: ");
    puts(nome);

    return 0;
}
