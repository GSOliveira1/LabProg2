#include <stdio.h>
#include <stdlib.h>
#include "lista_simplesmente_encadeada.h"

int insereOrdenado(Lista* lista, int elemento){
    if (lista == NULL)
        return 0;
    
    No* novo = alocarNo();
    novo->info = elemento;
    novo->prox = NULL;

    if (listaVazia(lista)){
        *lista = novo;
    } 
    else {
        No atual;
        atual.prox = *lista;

        No* auxiliar = &atual;
        while (auxiliar->prox != NULL && auxiliar->prox->info < elemento)
            auxiliar = auxiliar->prox;
        
        if (auxiliar->prox == *lista){
            novo->prox = *lista;
            *lista = novo;
        }

        novo->prox = auxiliar->prox;
        auxiliar->prox = novo;
    }

    return 1;
}

int main(){
    Lista* lista = criarLista();

    insereOrdenado(lista, 13);
    imprimeLista(lista);
    insereOrdenado(lista, 28);
    imprimeLista(lista);
    insereOrdenado(lista, 50);
    imprimeLista(lista);
    insereOrdenado(lista, 5);
    imprimeLista(lista);
    insereOrdenado(lista, 10);
    imprimeLista(lista);
    insereOrdenado(lista, 45);
    imprimeLista(lista);

    destroiLista(lista);
    return 0;
}