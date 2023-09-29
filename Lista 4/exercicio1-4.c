#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial_estatica.h"

int removePrimeiro(Lista* lista, int elemento){
    if (lista == NULL)
        return 0;
    if (listaVazia(lista))
        return 0;
    
    int i;
    for (i=0; i < lista->qtd; i++){
        if (lista->dados[i] == elemento){
            break;
        }
    }

    if (i < lista->qtd){
        for (int j=i; j < lista->qtd-1; j++){
            lista->dados[j] = lista->dados[j+1];
        }
        lista->qtd--;
    }

    return 1;
}

int main(){
    Lista* lista = criaLista();

    insereFim(lista, 10);
    insereFim(lista, 4);
    insereFim(lista, 27);
    insereFim(lista, 19);
    insereFim(lista, 41);
    insereFim(lista, 27);

    imprimeLista(lista);
    removePrimeiro(lista, 27);
    imprimeLista(lista);

    destroiLista(lista);
    return 0;
}