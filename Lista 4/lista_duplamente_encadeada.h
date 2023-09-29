#ifndef LDE_H
#define LDE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* anterior;
    struct NO* proximo;
}NO;
typedef struct NO* Lista;

Lista* criarLista(){
    Lista* lista;
    lista = (Lista*)malloc(sizeof(Lista));
    if (lista != NULL)
        *lista = NULL;
    return lista;
}

int listaVazia(Lista* lista){
    if (lista == NULL)
        return 0;
    if (*lista == NULL)
        return 1;
    return 0;
}

NO* alocarNo(){
    return (NO*)malloc(sizeof(NO));
}

void liberarNo(NO* q){
    free(q);
}

int insereInicio(Lista* lista, int elemento){
    if (lista == NULL)
        return 0;
    NO* novo = alocarNo();
    if (novo == NULL)
        return 0;
    novo->info = elemento;
    novo->proximo = *lista;
    novo->anterior = NULL;
    if (!listaVazia(lista))
        (*lista)->anterior = novo;
    *lista = novo;
    return 1;
}

int insereFim(Lista *lista, int elemento){
    if (lista == NULL)
        return 0;
    NO* novo = alocarNo();
    if (novo == NULL)
        return 0;
    novo->info = elemento;
    novo->proximo = NULL;
    if (listaVazia(lista)){
        novo->anterior = NULL;
        *lista = novo;
    } else{
        NO* auxiliar = *lista;
        while (auxiliar->proximo != NULL)
            auxiliar = auxiliar->proximo;
        auxiliar->proximo = novo;
        novo->anterior = auxiliar;
    }
    return 1;
}

int removeInicio(Lista* lista){
    if (lista == NULL)
        return 0;
    if (listaVazia(lista))
        return 0;
    NO* auxiliar = *lista;
    *lista = auxiliar->proximo;
    if (auxiliar->proximo != NULL)
        auxiliar->proximo->anterior = NULL;
    liberarNo(auxiliar);
    return 1;
}

int removeFim(Lista* lista){
    if (lista == NULL)
        return 0;
    if (listaVazia(lista))
        return 0;
    NO* auxiliar = *lista;
    while (auxiliar->proximo != NULL)
        auxiliar = auxiliar->proximo;
    if (auxiliar->anterior == NULL)
        *lista = auxiliar->proximo;
    else
        auxiliar->anterior->proximo = NULL;
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
    NO* auxiliar = *lista;
    while (auxiliar != NULL){
        printf ("%d ", auxiliar->info);
        auxiliar = auxiliar->proximo;
    }
    printf("\n");
}

void destroiLista(Lista* lista){
    if (lista != NULL){
        NO *auxiliar;
        while ((*lista)!=NULL){
            auxiliar = *lista;
            *lista = (*lista)->proximo;
            liberarNo(auxiliar);
        }
        free(lista);
    }
}

#endif  //LDE_H