#ifndef PSE_H
#define PSE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;
}NO;

typedef struct{
    int qtd;
    struct NO* topo;
}Pilha;

Pilha* criaPilha(){
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha != NULL){
        pilha->qtd = 0;
        pilha->topo = NULL;
    }
    return pilha;
}

void destroiPilha(Pilha** pilha){
    if (*pilha != NULL){
        free (*pilha);
        *pilha = NULL;
    }
}

int tamanhoPilha(Pilha* pilha){
    if (pilha == NULL)
        return 0;
    return pilha->qtd;
}

int estaVazia(Pilha* pilha){
    if (pilha == NULL)
        return 0;
    return pilha->topo == NULL;
}

NO* criaNo(){
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->info = 0;
    novo->prox = NULL;
    return novo;
}

int empilhar(Pilha* pilha, int elemento){
    if (pilha == NULL)
        return 0;
    NO* auxiliar = criaNo();
    auxiliar->info = elemento;
    auxiliar->prox = pilha->topo;
    pilha->topo = auxiliar;
    pilha->qtd++;
    return 1;
}

void destroiNO(NO* no){
    free(no);
}

int desempilhar(Pilha* pilha){
    if (pilha == NULL)
        return 0;
    if (estaVazia(pilha))
        return 0;
    NO* auxiliar = pilha->topo;
    pilha->topo = pilha->topo->prox;
    destroiNO(auxiliar);
    pilha->qtd--;
    return 1;
}

int verTopo(Pilha* pilha, int* elemento){
    if (pilha == NULL)
        return 0;
    if (estaVazia(pilha))
        return 0;
    *elemento = pilha->topo->info;
    return 1;
}

void imprime(Pilha* pilha){
    if (pilha == NULL)
        return;
    if (estaVazia(pilha)){
        printf ("Pilha Vazia!\n");
        return;
    }
    printf ("Elementos da Pilha:\n");
    NO* auxiliar = pilha->topo;
    do {
        printf ("%d ", auxiliar->info);
        auxiliar = auxiliar->prox;
    } while (auxiliar != NULL);
    printf ("\n");
}
#endif  //PSE_H