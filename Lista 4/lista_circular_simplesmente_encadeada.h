#ifndef LCSE_H
#define LCSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;
} NO;
typedef struct NO* Lista;

Lista* criarLista(){
    Lista *lista;
    lista = (Lista*) malloc (sizeof(Lista));
    if (lista != NULL)
        *lista = NULL;
    return lista;
}

int listaVazia(Lista* lista){
    if (lista == NULL)
        return 1;
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

int insereInicio(Lista* lista, int elem){
    if(lista == NULL) return 0;
    NO* novo = alocarNo();
    if(novo == NULL) return 0;
    novo->info = elem;
    if(listaVazia(lista)){
        novo->prox = novo;
        *lista = novo;
    }else{
        NO* aux = *lista;
        while(aux->prox != (*lista))
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = *lista;
        *lista = novo;        
    }
    return 1;
}

int insereFim(Lista* lista, int elem){
    if(lista == NULL) return 0;
    NO* novo = alocarNo();
    if(novo == NULL) return 0;
    novo->info = elem;
    if(listaVazia(lista)){
        novo->prox = novo;
        *lista = novo;
    }else{
        NO* aux = *lista;
        while(aux->prox != (*lista))
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = *lista;       
    }
    return 1;
}

int removeInicio(Lista *lista){
    if(lista == NULL) return 0;
    if(listaVazia(lista)) return 0;
    NO* prim = *lista;
    if(prim == prim->prox){
        //apenas 1 elemento
        *lista = NULL;
    }else{
        NO* aux = *lista;
        while(aux->prox != (*lista))
            aux = aux->prox;
        aux->prox = (*lista)->prox;
        *lista = (*lista)->prox;
    }
    liberarNo(prim);
    return 1;
}

int removeFim(Lista *lista){
    if(lista == NULL) return 0;
    if(listaVazia(lista)) return 0;
    NO* aux = *lista;
    if(aux == aux->prox){
        //apenas 1 elemento
        *lista = NULL;
    }else{
        NO* ant;
        while(aux->prox != (*lista)){
            ant = aux;//anterior
            aux = aux->prox;
        }  
        ant->prox = *lista;
    }
    liberarNo(aux);
    return 1;
}

void imprimeLista(Lista* lista){
    if(lista == NULL) return;
    if(listaVazia(lista)){
        printf("Lista Vazia!\n");
        return;
    }
    printf("Elementos:\n");
    NO* aux = *lista;
    while(aux->prox != *lista){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("%d ", aux->info);
    printf("\n");
}

void destroiLista(Lista *lista){
    if(lista != NULL && (*lista) != NULL){
        NO* prim, *aux;
        prim = *lista;
        *lista = (*lista)->prox;
        while((*lista) != prim){
            aux = *lista;
            *lista = (*lista)->prox;
            printf("Destruindo.. %d\n", aux->info);
            liberarNo(aux);
        }
        printf("Destruindo.. %d\n", prim->info);
        liberarNo(prim);
        free(lista);
    }
}

#endif  //LCSE_H