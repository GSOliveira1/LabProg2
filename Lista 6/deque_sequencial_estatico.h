#ifndef DSE_H
#define DSE_H
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    int dados[MAX];
    int qtd, inicio, fim;
}Deque;

Deque* criaDeque(){
    Deque* deque;
    deque = (Deque*)malloc(sizeof(Deque));
    if (deque != NULL){
        deque->fim = 0;
        deque->inicio = 0;
        deque->qtd = 0;
    }
    return deque;
}

void destroiDeque(Deque* deque){
    if (deque != NULL)
        free(deque);
}

int tamanhoDeque(Deque* deque){
    if (deque == NULL)
        return -1;
    return deque->qtd;
}

int estaCheio(Deque* deque){
    if (deque == NULL)
        return -1;
    return (deque->qtd == MAX);
}

int estaVazio(Deque* deque){
    if (deque == NULL)
        return -1;
    return (deque->qtd == 0);
}

int insereFim(Deque* deque, int elemento){
    if (deque == NULL)
        return 0;
    if (estaCheio(deque))
        return 0;
    deque->dados[deque->fim] = elemento;
    deque->fim = (deque->fim+1) % MAX;
    deque->qtd++;
    return 1;
}

int insereInicio(Deque* deque, int elemento){
    if (deque == NULL)
        return 0;
    if (estaCheio(deque))
        return 0;
    deque->inicio = (deque->inicio - 1 < 0 ? MAX -1 : deque->inicio-1);
    deque->dados[deque->inicio] = elemento;
    deque->qtd++;
    return 1;
}

int removeFim(Deque* deque){
    if (deque == NULL)
        return 0;
    if (estaVazio(deque))
        return 0;
    deque->fim = (deque->fim-1 < 0 ? MAX-1 : deque->fim-1);
    deque->qtd--;
    return 1;
}

int removeInicio(Deque* deque){
    if (deque == NULL)
        return 0;
    if (estaVazio(deque))
        return 0;
    deque->inicio = (deque->inicio+1)%MAX;
    deque->qtd--;
    return 1;
}

int verInicio (Deque* deque, int* elemento){
    if (deque == NULL)
        return 0;
    if (estaVazio(deque))
        return 0;
    *elemento = deque->dados[deque->inicio];
    return 1;
}

int verFim(Deque* deque, int* elemento){
    if (deque == NULL)
        return 0;
    if (estaVazio(deque))
        return 0;
    int i = (deque->fim-1 < 0 ? MAX-1 : deque->fim-1);
    *elemento = deque->dados[i];
    return 1;
}

void imprime(Deque* deque){
    if (deque == NULL)
        return;
    if (estaVazio(deque)){
        printf ("Deque vazio!\n");
        return;
    }
    int i = deque->inicio;
    printf ("Elementos: \n");
    do{
        printf ("%d ", deque->dados[i]);
        i = (i+1)%MAX;
    } while (i != deque->fim);
    printf ("\n");
}
#endif // DSE_H