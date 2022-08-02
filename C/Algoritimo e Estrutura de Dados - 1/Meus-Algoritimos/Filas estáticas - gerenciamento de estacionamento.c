#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define TAMANHO_MAX 100

typedef struct FILA{
    int item[TAMANHO_MAX];
    int ini;
    int fim;
    int tam;
} FILA;

FILA *criar_FILA(){
    FILA *f = (FILA *)malloc(sizeof(FILA));
    f->ini = -1;
    f->fim = -1;
    f->tam = 0;
    return f;
}

int FILA_cheia(FILA *f){
    if (f == NULL){
        return -1;
    }
    else if (f->tam < TAMANHO_MAX){
        return 0;
    }
    else{
        return 1;
    }
}

int FILA_vazia(FILA *f){
    if (f == NULL){
        return -1;
    }
    else if (f->tam > 0){
        return 0;
    }
    else{
        return 1;
    }
}

int enfileirar(FILA *f, int num){
    if (f == NULL){
        f = criar_FILA();
    }
    if (!FILA_cheia(f)){
        if (f->ini < 0){
            f->ini = 0;
        }
        if (f->fim < TAMANHO_MAX - 1){
            f->fim++;
        }
        else{
            f->fim = 0;
        }
        f->item[f->fim] = num;
        f->tam++;
        return 1;
    }
    return 0;
}

int desenfileirar(FILA *f){
    int item = INT_MIN;
    if (!FILA_cheia(f)){
        item = f->item[f->ini];
        if (f->ini < TAMANHO_MAX - 1){
            f->ini++;
        }
        else{
            f->ini = 0;
        }
        f->tam--;
        if (f->tam == 0){
            f->ini = -1;
            f->fim = -1;
        }
    }
    return item;
}

void imprimir_FILA(FILA *f){
    FILA auxF = *f;
    int item;
    while (!FILA_vazia(&auxF)){
        item = desenfileirar(&auxF);
        printf("%d ", item);
    }
    printf("\n");
}

void liberar_FILA(FILA *f){
    if (f != NULL){
        free(f);
    }
}

void encontrar_numero(FILA *f, int numero){
    int n, j = 0, quantidade = 0;
    do{
        n=f->item[j];
        desenfileirar(f);
        if (n != numero){
            enfileirar(f, n);
            quantidade++;
        }

        j++;
        if (j == f->tam + 1){
            break;
        }
    } while (n != numero);
    if (n == numero){
        imprimir_FILA(f);
        printf("%d\n", quantidade);
        printf("sucesso");
    }
    else{
        printf("falha");
    }
}

int main(){
    FILA *f1 = criar_FILA();
    int n, numero;

    do{
        scanf("%d", &n);
        if (n != -1){
            enfileirar(f1, n);
        }
    } while (n != -1);
    scanf("%d", &numero);
    encontrar_numero(f1, numero);
    return 0;
}
