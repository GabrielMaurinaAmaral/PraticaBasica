#include <stdio.h>

int main(void)
{
    char string[10];
    int i=0, j=0, cont;

    printf("Informe texto: ");
    gets(string);

    while (string[i] != '\0')
    {
        printf(" %d ", string[i]);
        i++;
    }

     i=0;
     while (string[i] != '\0')
    {
        while(string[j]!='\0')
        {
            if(string[i]==string[j])
            {
                cont++;
            }
            j++;
        }
        
        printf("\n %d repete %d \n", string[i], cont);
        i++;
        cont=0;
        j=0;
    }
}