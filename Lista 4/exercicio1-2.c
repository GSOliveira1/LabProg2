#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial_estatica.h"

int procura(Lista *lista, int elemento){
    for (int i=0; i < lista->qtd; i++){
        if (lista->dados[i] == elemento)
            return i;
    }
    return -1;
}

int main(){
    Lista* lista = criaLista();

    insereFim(lista, 13);
    insereFim(lista, 85);
    insereFim(lista, 25);
    insereFim(lista, 48);
    insereFim(lista, 8);

    imprimeLista(lista);
    printf ("Indice de 48: %d\n", procura(lista, 48));

    destroiLista(lista);
    return 0;
}