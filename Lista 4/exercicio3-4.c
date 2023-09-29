#include <stdio.h>
#include <stdlib.h>
#include "lista_duplamente_encadeada.h"

int removePrimeiro(Lista* lista, int elemento){
    if (lista == NULL)
        return 0;
    if (listaVazia(lista))
        return 0;

    NO* auxiliar = *lista;
    while (auxiliar->proximo != NULL){
        if (auxiliar->proximo->info == elemento){
            NO* auxiliar2 = auxiliar->proximo;
            auxiliar->proximo = auxiliar2->proximo;
            auxiliar->proximo->anterior = auxiliar2->anterior;
            liberarNo(auxiliar2);
            break;
        }
        auxiliar = auxiliar->proximo;
    }
    return 1;   
}

int main(){
    Lista *lista = criarLista();

    insereFim(lista, 13);
    insereFim(lista, 28);
    insereFim(lista, 65);
    insereFim(lista, 5);
    insereFim(lista, 14);
    insereFim(lista, 65);
    
    imprimeLista(lista);
    removePrimeiro(lista, 65);
    imprimeLista(lista);

    destroiLista(lista);
    return 0;
}