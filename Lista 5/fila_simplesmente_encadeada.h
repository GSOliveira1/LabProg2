#ifndef FSE_H
#define FSE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;
}NO;

typedef struct{
    int qtd;
    struct NO* inicio;
    struct NO* fim;
}Fila;

Fila* criaFila(){
    Fila* fila;
    fila = (Fila*)malloc(sizeof(Fila));
    if (fila != NULL){
        fila->qtd = 0;
        fila->inicio = NULL;
        fila->fim = NULL;
    }
    return fila;
}

void destroiFila(Fila* fila){
    if (fila != NULL){
        NO* auxiliar;
        while (fila->inicio != NULL){
            auxiliar = fila->inicio;
            fila->inicio = fila->inicio->prox;
            free(auxiliar);
        }
        free(fila);
    }
}

NO* criaNo(){
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->info = 0;
    novo->prox = NULL;
    return novo;
}

void destroiNo(NO* no){
    free(no);
}

int tamanhoFila (Fila *fila){
    if (fila == NULL)
        return 0;
    return fila->qtd;
}

int estaVazia(Fila* fila){
    if (fila == NULL)
        return 0;
    return fila->inicio == NULL;
}

int enfileirar(Fila* fila, int elemento){
    if (fila == NULL)
        return 0;
    NO* auxiliar = criaNo();
    auxiliar->info = elemento;

    if (estaVazia(fila)){
        fila->inicio = auxiliar;
        fila->fim = auxiliar;
    } else{
        fila->fim->prox = auxiliar; // Se a fila não estiver vazia, adicione após o último elemento;
        fila->fim = auxiliar;   // Atualize o último elemento
    }
    fila->qtd++;
    return 1;    
}

int desenfileirar(Fila* fila){
    if (fila == NULL)
        return 0;
    if (estaVazia(fila))
        return 0;
    NO* auxiliar = fila->inicio;
    fila->inicio = fila->inicio->prox;

    destroiNo(auxiliar);
    fila->qtd--;
    return 1;
}

int verInicio(Fila* fila, int* elemento){
    if (fila == NULL)
        return 0;
    if (estaVazia(fila))
        return 0;
    *elemento = fila->inicio->info;
    return 1;
}

void imprime(Fila* fila){
    if (fila == NULL)
        return;
    if (estaVazia(fila)){
        printf ("Fila Vazia!\n");
        return;
    }

    printf ("Elementos:\n");
    NO* auxiliar = fila->inicio;
    do {
        printf ("%d ", auxiliar->info);
        auxiliar = auxiliar->prox;
    } while (auxiliar != NULL);
    printf ("\n");
}

#endif  //FSE_H