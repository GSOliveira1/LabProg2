#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct{
    int topo;
    int dados[MAX];
}Pilha;

Pilha* criaPilha(){
    Pilha* pilha;
    pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha != NULL)
        pilha->topo = 0;
    return pilha;
}

void destroiPilha (Pilha *pilha){
    if(pilha != NULL )
        free (pilha);
}

int tamanhoPilha ( Pilha *pilha){
    if(pilha == NULL)
        return -1;
    return pilha -> topo ;
}

 int estaCheia ( Pilha *pilha){
    if(pilha == NULL )
        return -1;
    return (pilha -> topo == MAX );
 }

int estaVazia ( Pilha *pilha){
    if(pilha == NULL )
        return -1;
    return (pilha -> topo == 0);
}

int empilhar(Pilha* pilha, int elemento){
    if (pilha == NULL)
        return 0;
    if (estaCheia(pilha))
        return 0;
    pilha->dados[pilha->topo] = elemento;
    pilha->topo++;
    return 1;
}

int desempilhar (Pilha* pilha){
    if (pilha == NULL)
        return 0;
    if (estaVazia(pilha))
        return 0;
    pilha->topo--;
    return 1;
}

int verTopo (Pilha* pilha, int* elemento){
    if (pilha == NULL)
        return 0;
    if (estaVazia(pilha))
        return 0;
    *elemento = pilha->dados[pilha->topo-1];
    return 1;
}

void imprime(Pilha *pilha){
    if (pilha == NULL)
        return;
    if (estaVazia(pilha)){
        printf ("Pilha Vazia!\n");
        return;
    }
    printf ("Elementos: \n");
    int i;
    for (i = pilha->topo-1; i >= 0; i--){
        printf ("%d ", pilha->dados[i]);
    }
    printf ("\n");
}

#endif  //PILHA_H