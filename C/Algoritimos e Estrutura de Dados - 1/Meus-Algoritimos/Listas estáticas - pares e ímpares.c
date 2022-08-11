#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define TAMANHO_MAX 100

typedef struct Lista{
    int item[TAMANHO_MAX];
    int tam;
} Lista;

Lista *criar_lista(){
    Lista *l=(Lista *)malloc(sizeof(Lista));
    l->tam = 0;
    return l;
}

int lista_vazia(Lista *l){
    return (l == NULL) || (l->tam == 0);
}

int lista_cheia(Lista *l){
    return (l != NULL) && (l->tam == TAMANHO_MAX);
}

int buscar(Lista *l, int chave){
    int i;
    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++){
            if (l->item[i] == chave){
                return i;
            }
        }
    }
    return -1;
}

int inserir(Lista *l, int chave){
    if (!lista_cheia(l)){
        l->item[l->tam] = chave;
        l->tam++;
        return 1;
    }
    return 0;
}

int remover(Lista *l, int chave){
    int i, p = buscar(l, chave);
    if (p > -1){
        for (i = p; i < l->tam - 1; i++){
            l->item[i] = l->item[i + 1];
        }
        l->tam--;
        return 1;
    }
    return 0;
}

void imprimir_par_impar(Lista *l2, Lista *l3){
    if (!lista_vazia(l2)){
        printf("par: ");
        imprimir_lista(l2);
    }
    else{
        printf("par: -1\n");
    }
    if (!lista_vazia(l3)){
        printf("impar: ");
        imprimir_lista(l3);
    }
    else{
        printf("impar: -1\n");
    }
}

void imprimir_lista(Lista *l){
    int i;
    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++){
            printf("%d ", l->item[i]);
        }
        printf("\n");
    }
}

int main(){
    Lista *l1 = criar_lista();
    Lista *l2 = criar_lista();
    Lista *l3 = criar_lista();
    int i, num, tam = -1;
    do{
        scanf("%d", &num);
        inserir(l1, num);
        tam++;
    } while (l1->item[tam] != -1);
    remover(l1, -1);
    for (i = 0; i < l1->tam; i++){
        if (l1->item[i] % 2 == 0){
            inserir(l2, l1->item[i]);
        }
        else{
            inserir(l3, l1->item[i]);
        }
    }
    imprimir_par_impar(l2, l3);
    return 0;
}
