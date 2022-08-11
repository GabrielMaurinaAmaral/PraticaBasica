#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pilha.c"

int main(void)
{
    Pilha *p=criar_pilha();

    empilhar(p, 5);
    empilhar(p, 4);
    empilhar(p, 3);
    empilhar(p, 2);
    empilhar(p, 1);
    empilhar(p, 6);

    imprimir_pilha(p);

    return 0;
}