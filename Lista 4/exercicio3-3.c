#include <stdio.h>
#include <stdlib.h>
#include "lista_duplamente_encadeada.h"

int insereOrdenado(Lista* lista, int elemento){
    if (lista == NULL)
        return 0;
    
    NO* novo = alocarNo();
    novo->info = elemento;
    novo->anterior = NULL;
    novo->proximo = NULL;

    if (listaVazia(lista)){
        *lista = novo;
    } 
    else {
        NO atual;
        atual.proximo = *lista;

        NO* auxiliar = &atual;
        while (auxiliar->proximo != NULL && auxiliar->proximo->info < elemento)
            auxiliar = auxiliar->proximo;
        
        if (auxiliar->proximo == *lista){
            novo->proximo = *lista;
            *lista = novo;
        } else{
            novo->anterior = auxiliar;
        }

        novo->proximo = auxiliar->proximo;
        auxiliar->proximo = novo;
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