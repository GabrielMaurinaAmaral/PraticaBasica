#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main(void)
{
    Lista *l = criar_lista();

    inserir(l, 7);
    inserir(l, 6);
    inserir(l, 5);
    inserir(l, 4);
    inserir(l, 3);
    inserir(l, 2);
    inserir(l, 1);

    imprimir_lista(l);

    remover(l, 6);

    imprimir_lista(l);

    inserir(l, 8);

    imprimir_lista(l);

    printf("%d", buscar(l, 2));
}