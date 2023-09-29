#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial_estatica.h"

int insereOrdenado(Lista* lista, int elemento) {
    if (lista == NULL) 
        return 0;
    if (!listaCheia(lista)){
        for(int i=0; i <= lista->qtd; i++){
            if (lista->dados[i] > elemento){
                for(int j=lista->qtd; j > i; j--)
                    lista->dados[j] = lista->dados[j-1];
                lista->dados[i] = elemento;
                lista->qtd++;
                return 1;
            }
        }
    }
    return 0;    
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