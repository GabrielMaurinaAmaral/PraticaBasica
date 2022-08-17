#include <stdio.h>

int main(void)
{
    int vetor[10] = {17, 33, 21, 67, 81, 10, 45, 29, 79, 98};
    int i;

    for(i=0; i<10; i++)
    {
        printf("%d\t", vetor[i]);
    }

    return 0;
}
