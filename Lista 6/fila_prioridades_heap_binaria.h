#ifndef FPHEAP_H
#define FPHEAP_H
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct NO{
    int info, prioridade;
}NO;
typedef struct{
    int qtd;
    NO dados[MAX];
}FilaPrioridade;

FilaPrioridade* criaFila(){
    FilaPrioridade* filaP;
    filaP = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    if (filaP != NULL)
        filaP->qtd = 0;
    return filaP;
}

void destroiFila(FilaPrioridade* filaP){
    if (filaP != NULL)
        free(filaP);
}

int tamanho(FilaPrioridade* filaP){
    if (filaP == NULL)
        return -1;
    return filaP->qtd;
}

int estaCheia(FilaPrioridade* filaP){
    if (filaP == NULL)
        return -1;
    return (filaP->qtd == MAX);
}

int estaVazia(FilaPrioridade* filaP){
    if (filaP == NULL)
        return -1;
    return (filaP->qtd = 0);
}

void imprime(FilaPrioridade* filaP){
    if (filaP == NULL)
        return;
    if (estaVazia(filaP)){
        printf ("Fila vazia!\n");
        return;
    }
    printf ("Elementos: \n");
    int i;
    for (i = 0; i < filaP->qtd; i++)
        printf ("[%d, %d] (%d) -- ", filaP->dados[i].prioridade, filaP->dados[i].info, i);
    printf ("\n");
}

void trocaNO(NO* a, NO* b){
    NO temp;
    temp.info = a->info;
    temp.prioridade = a->prioridade;
    a->info = b->info;
    a->prioridade = b->prioridade;
    b->info = temp.info;
    b->prioridade = temp.prioridade;
}

void ajustaHeapInsere(FilaPrioridade* filaP, int filho){
    int pai = (filho-1)/2;
    int prioPai = filaP->dados[pai].prioridade;
    int prioFilho = filaP->dados[filho].prioridade;
    while(filho > 0 && prioPai < prioFilho){
        trocaNO(&filaP->dados[filho], &filaP->dados[pai]);
        filho = pai;
        pai = (pai-1)/2;
        prioPai = filaP->dados[pai].prioridade;
        prioFilho = filaP->dados[filho].prioridade;
    }
}

int inserirPrio(FilaPrioridade* filaP, int elem, int pri){
    if(filaP == NULL) return 0;
    if(estaCheia(filaP)) return 0;
    filaP->dados[filaP->qtd].info = elem;
    filaP->dados[filaP->qtd].prioridade = pri;
    ajustaHeapInsere(filaP, filaP->qtd);
    filaP->qtd++;
    return 1;
}

void ajustaHeapRemove(FilaPrioridade* filaP, int pai){
    int filho = 2*pai + 1;
    while(filho < filaP->qtd){ 
        if(filho < filaP->qtd-1)
            if(filaP->dados[filho].prioridade < filaP->dados[filho+1].prioridade)
                filho++;
        
        if(filaP->dados[pai].prioridade > filaP->dados[filho].prioridade)
            break;
        
        trocaNO(&filaP->dados[pai], &filaP->dados[filho]);
        pai = filho;
        filho = 2*pai + 1;
    }
}

int removeInicio(FilaPrioridade* filaP){
    if(filaP == NULL) return 0;
    if(estaVazia(filaP)) return 0;

    filaP->qtd--;
    filaP->dados[0].info = filaP->dados[filaP->qtd].info;
    filaP->dados[0].prioridade = filaP->dados[filaP->qtd].prioridade;
    ajustaHeapRemove(filaP, 0);
    return 1;
}

int verInicio(FilaPrioridade* filaP, int* valor, int* pri){
  if(filaP == NULL) 
    return 0;
  if(estaVazia(filaP)) 
    return 0;
  *valor = filaP->dados[0].info;
  *pri = filaP->dados[0].prioridade;
  return 1;
}
#endif  //FPHEAP_H