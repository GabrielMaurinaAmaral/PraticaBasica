//Invertendo uma string

#include <stdio.h>

int main(void)
{
    char string1[20] = "Linguagem C";
    int i=0, j;
    char string2[20];

    while(string1[i] != '\0') //percorre a string at� chegar no final de string
    {
        i++;
    }

    i = i-1; //o i vai estar na posi��o que est� o '\0', ao voltar uma posi��o, fica no �ltimo caractere

    j=0;
    while(i >= 0) //percorre as posi��es da string de tr�s para frente
    {
        string2[j] = string1[i];
        j++;
        i--;
    }

    string2[j] = '\0';

    printf("\nString invertida: %s\n", string2); //imprime a string 2
    return 0;
}
