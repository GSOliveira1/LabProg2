#ifndef MF_H
#define MF_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *diagonal;
    int *superior;
    int *inferior;
    int tamanho;
}MatrizFaixa;

void zeraMatriz(MatrizFaixa *matrizFaixa) {
    if(matrizFaixa == NULL)
        return;
    for(int i = 0; i < matrizFaixa->tamanho; i++)
        matrizFaixa->diagonal[i] = 0;
    for(int i = 0; i < matrizFaixa->tamanho - 1; i++) 
        matrizFaixa->superior[i] = 0;
    for(int i = 0; i < matrizFaixa->tamanho - 1; i++)
        matrizFaixa->inferior[i] = 0;
}

MatrizFaixa* criaMatriz(int t){
    MatrizFaixa *matrizFaixa = (MatrizFaixa*) malloc(sizeof(MatrizFaixa));
    if(matrizFaixa != NULL){
        if(t <= 1)
            return NULL;
        matrizFaixa->tamanho = t;
        matrizFaixa->diagonal = (int*) malloc(t * sizeof(int));
        matrizFaixa->superior = (int*) malloc((t-1) * sizeof(int));
        matrizFaixa->inferior = (int*) malloc((t-1) * sizeof(int));
        if(matrizFaixa->diagonal == NULL || matrizFaixa->superior == NULL || matrizFaixa->inferior == NULL){
            return NULL;
        }
        zeraMatriz(matrizFaixa);
    }
    return matrizFaixa;
}

void destroiMatriz(MatrizFaixa *matrizFaixa){
    if(matrizFaixa != NULL){
        free(matrizFaixa->diagonal);
        free(matrizFaixa->superior);
        free(matrizFaixa->inferior);
        free(matrizFaixa);
    }
}

int insereElemento(MatrizFaixa *matrizFaixa, int elemento, int i, int j){
    if(matrizFaixa == NULL)  
        return -1;
    if(i < 0 || j < 0 || i >= matrizFaixa->tamanho || j >= matrizFaixa->tamanho)
        return 0;
    if(i == j)
        matrizFaixa->diagonal[i] = elemento;
    else if(i + 1 == j)
        matrizFaixa->superior[i] = elemento;
    else if(i == j + 1)
        matrizFaixa->inferior[j] = elemento;
    else
        return 0;
    return 1;
}

int consultaElemento(MatrizFaixa *matrizFaixa, int i, int j){
    if(matrizFaixa == NULL)
        return 0;
    if(i < 0 || j < 0 || i >= matrizFaixa->tamanho || j >= matrizFaixa->tamanho)
        return 0;
    if(i == j)
        return matrizFaixa->diagonal[i];
    else if(i + 1 == j)
        return matrizFaixa->superior[i];
    else if(i == j + 1)
        return matrizFaixa->inferior[j];
    else
        return 0;
}

void imprimeFaixaVetores(MatrizFaixa *matrizFaixa){   
    if(matrizFaixa == NULL)
        return;
    int i;
    printf("Matriz Faixa, Tam: %d x %d:\n", matrizFaixa->tamanho, matrizFaixa->tamanho);
    printf("Diagonal = [");
    for(i = 0; i < matrizFaixa->tamanho; i++)
        printf("%d ", matrizFaixa->diagonal[i]) ;
    printf("]\n");
    printf("Superior = [");
    for (i = 0; i < matrizFaixa->tamanho - 1; i++)
        printf("%d ", matrizFaixa->superior[i]);
    printf("]\n");
    printf("Inferior = [");
    for(i = 0; i < matrizFaixa->tamanho - 1; i++)
        printf("%d ", matrizFaixa->inferior[i]);
    printf("]\n\n");
}

void imprimeFaixa(MatrizFaixa *matrizFaixa){
    if(matrizFaixa == NULL)
        return;
    imprimeFaixaVetores(matrizFaixa);
    printf("Matriz original: \n");
    for(int i = 0; i < matrizFaixa->tamanho; i++){
        for(int j = 0; j < matrizFaixa->tamanho; j++){
            printf("%d\t", consultaElemento(matrizFaixa, i, j));
        }
        printf("\n");
    }
    printf("\n");
}

#endif  //MF_H