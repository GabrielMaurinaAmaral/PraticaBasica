#include <stdio.h>

int main(void)
{
    char string1[20]="Linguagem C";
    char string2[20];
    int i;
    //string1 = string2; //errado

    printf("String1 = %s\n", string1);

    for(i=0; string1[i]!='\0'; i++)
    {
        string2[i] = string1[i];
    }
    string2[i]='\0';

    printf("String2 = %s\n", string2);

    return 0;

}
