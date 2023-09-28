#ifndef LSEC_H
#define LSEC_H
#include <stdlib.h>
#include <stdio.h>

typedef struct No{
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

int insereFim(Lista* lista, int elemento){
    if (lista == NULL)
        return 0;
    No* novo = alocarNo();
    if (novo == NULL)
        return 0;
    novo->info = elemento;
    novo->prox = NULL;
    if (listaVazia(lista)){
        *lista = novo;
    } else{
        No* auxiliar = *lista;
        while (auxiliar->prox != NULL)
            auxiliar = auxiliar->prox;
        auxiliar->prox = novo;
    }
    return 1;
}

int removeInicio(Lista* lista){
    if (lista == NULL)
        return 0;
    if (listaVazia(lista))
        return 0;
    No* auxiliar = *lista;
    *lista = auxiliar->prox;
    liberarNo(auxiliar);
    return 1;
}

int removeFim (Lista* lista){
    if (lista == NULL)
        return 0;
    if (listaVazia(lista))
        return 0;
    No* anterior, *auxiliar = *lista;
    while (auxiliar->prox != NULL){
        anterior = auxiliar;
        auxiliar = auxiliar->prox;
    }
    if (auxiliar == *lista)
        *lista = auxiliar->prox;
    else
        anterior->prox = auxiliar->prox;
    liberarNo(auxiliar);
    return 1;
}

void imprimeLista(Lista* lista){
    if (lista == NULL)
        return;
    if (listaVazia(lista)){
        printf ("Lista vazia!\n");
        return;
    }
    printf ("Elementos:\n");
    No* auxiliar = *lista;
    while (auxiliar != NULL){
        printf ("%d ", auxiliar->info);
        auxiliar = auxiliar->prox;
    }
    printf ("\n");
}

void destroiLista (Lista* lista){
    if (lista != NULL){
        No* auxiliar;
        while ((*lista) != NULL){
            auxiliar = *lista;
            *lista = (*lista)->prox;
            liberarNo(auxiliar);
        }
        free(lista);
    }
}

#endif // LSEC_H