#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pilhaC.c"

int main(void)
{
    Pilha *p = criar_pilha();

    empilhar(p, "g");
    empilhar(p, "a");
    empilhar(p, "b");
    empilhar(p, "r");
    empilhar(p, "i");
    empilhar(p, "e");

    imprimir_pilha(p);

    return 0;
}