#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial_estatica.h"

int insereOrdenado(Lista* lista, int elemento){
    if (lista == NULL || listaCheia(lista))
        return 0;

    int i;
    for (i=0; i < tamanhoLista(lista) && lista->dados[i] < elemento; i++){
        for (int j=lista->qtd; j >= i+1; j--){
            lista->dados[j] = lista->dados[j-1];
        }
    }
    lista->dados[i] = elemento;
    lista->qtd++;

    return 1;
}

int main(){
    Lista* lista = criaLista();

    insereOrdenado(lista, 5);
    imprimeLista(lista);
    insereOrdenado(lista, 2);
    imprimeLista(lista);
    insereOrdenado(lista, 27);
    imprimeLista(lista);
    insereOrdenado(lista, 30);
    imprimeLista(lista);
    insereOrdenado(lista, 50);
    imprimeLista(lista);
    insereOrdenado(lista, 15);
    imprimeLista(lista);

    destroiLista(lista);
    return 0;
}