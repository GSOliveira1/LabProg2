#ifndef LSE_H
#define LSE_H
#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 100

typedef struct{
    int dados[MAX_TAM];
    int qtd;
}Lista;

Lista* criaLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if (lista != NULL)
        lista->qtd = 0;
    return lista;
}

void destroiLista(Lista* lista){
    if (lista != NULL)
        free(lista);
}

int tamanhoLista(Lista* lista){
    if (lista == NULL)
        return -1;
    return lista->qtd;
}

int listaCheia (Lista* lista){
    if (lista == NULL)
        return -1;
    return (lista->qtd == MAX_TAM);
}

int listaVazia(Lista* lista){
    if (lista == NULL)
        return -1;
    return (lista->qtd == 0);
}

int insereFim(Lista *lista, int elemento){
    if (lista == NULL)
        return 0;
    if (!listaCheia(lista)){
        lista->dados[lista->qtd] = elemento;
        lista->qtd++;
        printf ("Elemento inserido com sucesso!\n");
        return 1;
    } else {
        printf ("Elemento nao inserido - Lista cheia!\n");
        return 0;
    }
}

int insereInicio(Lista *lista, int elemento){
    if (lista == NULL)
        return 0;
    if (!listaCheia(lista)){
        int i;
        for (i = lista->qtd - 1; i >= 0; i++)
            lista->dados[i+1] = lista->dados[i];
        lista->dados[0] = elemento;
        lista->qtd++;
        printf ("Elemento inserido com sucesso!\n");
        return 1;
    } else{
        printf ("Elemento nao inserido - Lista cheia!\n");
        return 0;
    }
}

int removeFim (Lista *lista){
    if (lista == NULL)
        return 0;
    if (!listaVazia(lista)){
        lista->qtd--;
        printf ("Elemento removido com sucesso!\n");
        return 1;
    } else {
        printf("Nenhum elemento removido - Lista vazia!\n");
        return 0;
    }
}

int removeInicio(Lista *lista){
    if (lista == NULL)
        return 0;
    if (!listaVazia(lista)){
        int i;
        for (i=0; i<lista->qtd; i++)
            lista->dados[i] = lista->dados[i+1];
        lista->qtd--;
        printf ("Elemento removido com sucesso!\n");
        return 1;
    } else {
        printf ("Nenhum elemento removido - Lista vazia!\n");
        return 0;
    }
}

int imprimeLista(Lista *lista){
    if (lista == NULL)
        return 0;
    if (listaVazia(lista)){
        printf ("Lista vazia!\n");
        return 0;
    }
    printf ("Elementos:\n");
    int i;
    for (i=0; i<lista->qtd; i++){
        printf ("%d ", lista->dados[i]);
    }
    printf ("\n");
    return 1;
}

#endif // LSE_H