#ifndef FPSE_H
#define FPSE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info, prioridade;
    struct NO* proximo;
}NO;
typedef struct NO* FilaPrioridade;

FilaPrioridade* criaFila(){
    FilaPrioridade* filaP;
    filaP = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    if (filaP != NULL)
        *filaP = NULL;
    return filaP;
}

NO *alocarNO(){
    return (NO *)malloc(sizeof(NO));
}

void liberarNO(NO *q){
    free(q);
}

int estaVazia(FilaPrioridade *filaP){
    if (filaP == NULL)
        return -1;
    return ((*filaP)==NULL);
}

int tamanho(FilaPrioridade *filaP){
    if (filaP == NULL)
        return -1;
    if (estaVazia(filaP))
        return 0;
    int tamanho = 0;
    NO* auxiliar = *filaP;
    while (auxiliar != NULL){
        auxiliar = auxiliar->proximo;
        tamanho++;
    }
    return tamanho;
}

int inserirPrio(FilaPrioridade* filaP, int elemento, int prioridade){
    if (filaP == NULL)
        return 0;
    NO* novo = alocarNO();
    if (novo == NULL)
        return 0;
    novo->info = elemento;
    novo->prioridade = prioridade;
    if (estaVazia(filaP)){
        novo->proximo = *filaP;
        *filaP = novo;
    } else {
        NO* auxiliar, *anterior;
        auxiliar = *filaP;
        anterior = NULL;
        while (auxiliar != NULL && auxiliar->prioridade >= novo->prioridade){
            anterior = auxiliar;
            auxiliar = auxiliar->proximo;
        }
        if (anterior == NULL){
            novo->proximo = *filaP;
            *filaP = novo;
        } else {
            novo->proximo = anterior->proximo;
            anterior->proximo = novo;
        }
    }
    return 1;
}

int removeInicio(FilaPrioridade* filaP){
    if (filaP == NULL)
        return 0;
    if (estaVazia(filaP))
        return 0;
    NO* auxiliar = *filaP;
    *filaP = auxiliar->proximo;
    liberarNO(auxiliar);
    return 1;
}

int verInicio(FilaPrioridade* filaP, int* elemento, int* prioridade){
    if (filaP == NULL)
        return 0;
    if (estaVazia(filaP))
        return 0;
    *elemento = (*filaP)->info;
    *prioridade = (*filaP).prioridade;
    return 1;
}

void imprime (FilaPrioridade* filaP){
    if (filaP == NULL)
        return;
    if (estaVazia(filaP)){
        printf ("Fila de Prioridades Vazia!\n");
        return;
    }
    NO* auxiliar = *filaP;
    while (auxiliar != NULL){
        printf ("[%d, %d] ", auxiliar->prioridade, auxiliar->info);
        auxiliar = auxiliar->proximo;
    }
    printf ("\n");
}

void destroiFila(FilaPrioridade* filaP){
    if (filaP != NULL){
        NO* auxiliar;
        while ((*filaP) != NULL){
            auxiliar = *filaP;
            *filaP = (*filaP)->proximo;
            liberarNO(auxiliar);
        }
        free(filaP);
    }
}
#endif  //FPSE_H