#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct{
    int qtd, inicio, fim;
    int dados[MAX];
}Fila;

Fila* criarFila(){
    Fila* fila;
    fila = (Fila*)malloc(sizeof(Fila));
    if (fila != NULL){
        fila->qtd = 0;
        fila->inicio = 0;
        fila->fim = 0;
    }
    return fila;
}

void destroiFila(Fila *fila){
    if (fila != NULL)
        free(fila);    
}

int tamanhoFila (Fila *fila){
    if (fila == NULL)
        return -1;
    return fila->qtd;
}

int filaCheia(Fila *fila){
    if (fila == NULL)
        return -1;
    return (fila->qtd == MAX);
}

int filaVazia(Fila *fila){
    if (fila == NULL)
        return -1;
    return (fila->qtd == 0);
}

int enfileirar (Fila *fila, int elemento){
    if (fila == NULL)
        return 0;
    if (filaCheia(fila))
        return 0;
    fila->dados[fila->fim] = elemento;
    fila->fim = (fila->fim+1)%MAX;
    fila->qtd++;
    return 1;
}

int desenfileirar(Fila *fila){
    if (fila == NULL)
        return 0;
    if (filaVazia(fila))
        return 0;
    fila->inicio = (fila->inicio+1)%MAX;
    fila->qtd--;
    return 1;
}

int verInicio(Fila* fila, int* elemento){
    if (fila == NULL)
        return 0;
    if (filaVazia(fila))
        return 0;
    *elemento = fila->dados[fila->inicio];
    return 1;
}

void imprime(Fila* fila){
    if (fila == NULL)
        return;
    if (filaVazia(fila)){
        printf ("Fila vazia!\n");
        return;
    }
    int i = fila->inicio;
    printf ("Elementos: \n");
    do{
        printf ("%d ", fila->dados[i]);
        i = (i+1)%MAX;
    } while (i != fila->fim);
    printf ("\n");
}

#endif  //FILA_H