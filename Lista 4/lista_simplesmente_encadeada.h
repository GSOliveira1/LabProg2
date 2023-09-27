#ifndef LSEC_H
#define LSEC_H
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int info;
    struct No *prox;
} No;
typedef No *Lista;

Lista* criarLista(){
    Lista *lista;
    lista = (Lista*)malloc(sizeof(Lista));
    if (lista != NULL)
        *lista = NULL;
    return lista;
}

int listaVazia(Lista* lista){
    if (lista == NULL)  // Erro ao alocar inicialmente
        return 1;
    if (*lista == NULL)
        return 1;   // Lista Vazia = True
    return 0;       // Lista Vazia = False
}

No* alocarNo(){
    return (No*)malloc(sizeof(No));
}

void liberarNo(No* q){
    free(q);
}

int insereInicio(Lista* lista, int elemento){
    if (lista == NULL)
        return 0;
    No* novo = alocarNo();
    if (novo == NULL)
        return 0;
    novo->info = elemento;
    novo->prox = *lista;
    *lista = novo;
    return 1;
}

#endif // LSEC_H