#include <stdio.h>
#include <stdlib.h>
#include "lista_simplesmente_encadeada.h"

int tamanhoLista(Lista* lista){
    int tamanho = 0;
    No* atual = *lista;
    while (atual != NULL){
        tamanho++;
        atual = atual->prox;
    }
    return tamanho;    
}

int procura(Lista* lista, int elemento){
    No* atual = *lista;
    while (atual != NULL){
        if (atual->info == elemento){
            printf ("Elemento %d presente na lista.\n", elemento);
            return 0;
        }
        atual = atual->prox;
    }    
    return -1;
}

int main(){
    Lista* lista = criarLista();

    insereFim(lista, 13);
    insereFim(lista, 29);
    insereFim(lista, 4);
    insereFim(lista, 68);
    insereFim(lista, 51);

    imprimeLista(lista);
    printf ("Tamanho da Lista: %d\n", tamanhoLista(lista));
    procura(lista, 29);

    destroiLista(lista);
    return 0;
}