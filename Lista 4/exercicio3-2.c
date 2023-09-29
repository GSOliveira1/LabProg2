#include <stdio.h>
#include <stdlib.h>
#include "lista_duplamente_encadeada.h"

int procura(Lista* lista, int elemento){
    NO* atual = *lista;
    while (atual != NULL){
        if (atual->info == elemento){
            printf ("Elemento %d presente na lista.\n", elemento);
            return 0;
        }
        atual = atual->proximo;
    }    
    return -1;
}

int tamanhoLista(Lista* lista){
    int tamanho = 0;
    NO* atual = *lista;
    while (atual != NULL){
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;    
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