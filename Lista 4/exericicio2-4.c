#include <stdio.h>
#include <stdlib.h>
#include "lista_simplesmente_encadeada.h"

int removePrimeiro(Lista* lista, int elemento){
    if (lista == NULL)
        return 0;
    if (listaVazia(lista))
        return 0;

    No* auxiliar = *lista;
    while (auxiliar->prox != NULL){
        if (auxiliar->prox->info == elemento){
            No* auxiliar2 = auxiliar->prox;
            auxiliar->prox = auxiliar2->prox;
            liberarNo(auxiliar2);
            break;
        }

        auxiliar = auxiliar->prox;
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