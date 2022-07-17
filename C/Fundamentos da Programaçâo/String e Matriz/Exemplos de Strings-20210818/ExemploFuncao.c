/*Fazer uma função para contar a quantidade de caracteres de uma string, incluindo espaços, e outra função não incluindo espaços. */

#include <stdio.h>

int contarCaracteres(char texto[]);
int contarCaracteresSemEspaco(char texto[]);

int main(void)
{
    char opcao, texto[150];
    int i;

    do
    {
        printf("Informe um texto com ate 150 caracteres: ");
        setbuf(stdin, NULL);
        gets(texto);

        printf("\nNumero de caracteres com espaco: %d", contarCaracteres(texto)); //chama a função e imprime o seu retorno
        printf("\nNumero de caracteres sem espaco: %d", contarCaracteresSemEspaco(texto));//chama a função e imprime o seu retorno

        printf("\n\nDeseja repetir o programa (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c",&opcao);

    }while(opcao =='S' || opcao =='s');

    return 0;
}

int contarCaracteres(char texto[])
{
    int i=0;

    while(texto[i] != '\0')//enquanto não é final de string
    {
        i++; //conta os caracteres
    }
    return(i);
}

int contarCaracteresSemEspaco(char texto[])
{
    int i=0, cont=0;

    while(texto[i] != '\0')//enquanto não é final de string
    {
        if(texto[i] != ' ') //se caracter for diferente de espaço em branco
        {
            cont++;
        }
        i++;
    }
    return(cont);
}
