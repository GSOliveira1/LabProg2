#include <stdio.h>
#include <stdlib.h>
#include "lista_circular_simplesmente_encadeada.h"

int tamanho(Lista* lista){
    int aux = 0;
    NO* aux2 = *lista;

    while (aux2 != *lista || aux == 0){
        aux2 = aux2->prox;
        aux++;
    }
    return aux;
}

int procura(Lista* lista, int elemento){
    int i = 0;
    NO* aux = *lista;

    while (aux != *lista || i == 0){
        if (aux->info == elemento) return i;
        aux = aux->prox;
        i++;
    }
    return -1;       
}

int main(){
    Lista* lista = criarLista();

    insereFim(lista, 13);
    insereFim(lista, 4);
    insereFim(lista, 28);
    insereFim(lista, 43);
    insereFim(lista, 66);

    imprimeLista(lista);
    printf ("Tamanho da Lista = %d\n", tamanho(lista));
    printf ("Indice de 43: %d\n", procura(lista, 43));

    destroiLista(lista);
    return 0;
}