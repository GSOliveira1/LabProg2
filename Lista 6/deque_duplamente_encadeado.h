#ifndef DDE_H
#define DDE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO *proximo;
    struct NO *anterior;
} NO;
typedef struct{
    int qtd;
    struct NO *inicio;
    struct NO *fim;
} Deque;

NO *alocarNO()
{
    return (NO *)malloc(sizeof(NO));
}

void liberarNO(NO *q){
    free(q);
}

Deque *criaDeque(){
    Deque *deque;
    deque = (Deque *)malloc(sizeof(Deque));
    if (deque != NULL){
        deque->qtd = 0;
        deque->inicio = NULL;
        deque->fim = NULL;
    }
    return deque;
}

void destroiDeque(Deque *deque){
    if (deque != NULL){
        NO *auxiliar;
        while (deque->inicio != NULL)
        {
            auxiliar = deque->inicio;
            deque->inicio = deque->inicio->proximo;
            liberarNO(auxiliar);
        }
        free(deque);
    }
}

int tamanhoDeque(Deque *deque){
    if (deque == NULL)
        return -1;
    return deque->qtd;
}

int estaVazio(Deque *deque){
    if (deque == NULL)
        return -1;
    return (deque->qtd == 0);
}

int insereInicio(Deque *deque, int elem){
    if (deque == NULL)
        return 0;
    NO *novo = alocarNO();
    if (novo == NULL)
        return 0;
    novo->info = elem;
    novo->anterior = NULL;
    if (estaVazio(deque)){
        novo->proximo = NULL;
        deque->fim = novo;
    }
    else{
        deque->inicio->anterior = novo;
        novo->proximo = deque->inicio;
    }
    deque->inicio = novo;
    deque->qtd++;
    return 1;
}

int insereFim(Deque *deque, int elem){
    if (deque == NULL)
        return 0;
    NO *novo = alocarNO();
    if (novo == NULL)
        return 0;
    novo->info = elem;
    novo->proximo = NULL;
    if (estaVazio(deque)){
        novo->anterior = NULL;
        deque->inicio = novo;
    }
    else{
        deque->fim->proximo = novo;
        novo->anterior = deque->fim;
    }
    deque->fim = novo;
    deque->qtd++;
    return 1;
}

int removeInicio(Deque *deque){
    if (deque == NULL)
        return 0;
    if (estaVazio(deque))
        return 0;
    NO *auxiliar = deque->inicio;
    if (deque->inicio == deque->fim){
        deque->inicio = deque->fim = NULL;
    }
    else{
        deque->inicio = deque->inicio->proximo;
        deque->inicio->anterior = NULL;
    }
    liberarNO(auxiliar);
    deque->qtd--;
    return 1;
}

int removeFim(Deque *deque){
    if (deque == NULL)
        return 0;
    if (estaVazio(deque))
        return 0;
    NO *auxiliar = deque->fim;
    if (deque->inicio == deque->fim){
        deque->inicio = deque->fim = NULL;
    }
    else{
        deque->fim = deque->fim->anterior;
        deque->inicio->proximo = NULL;
    }
    liberarNO(auxiliar);
    deque->qtd--;
    return 1;
}

int verInicio(Deque *deque, int *p){
    if (deque == NULL)
        return 0;
    if (estaVazio(deque))
        return 0;
    *p = deque->inicio->info;
    return 1;
}

int verFim(Deque *deque, int *p){
    if (deque == NULL)
        return 0;
    if (estaVazio(deque))
        return 0;
    *p = deque->fim->info;
    return 1;
}

void imprime(Deque *deque){
    if (deque == NULL)
        return;
    if (estaVazio(deque)){
        printf("Deque Vazio!\n");
        return;
    }
    NO *auxiliar = deque->inicio;
    printf("Elementos:\n");
    while (auxiliar != NULL){
        printf("%d ", auxiliar->info);
        auxiliar = auxiliar->proximo;
    }
    printf("\n");
}

#endif // DDE_H