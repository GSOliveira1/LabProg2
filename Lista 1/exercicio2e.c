/*
a) Faça um algoritmo recursivo para preencher as posições de um vetor de inteiros de tamanho N.
b) Faça um algoritmo recursivo para imprimir de forma crescente, do primeiro até o último, (e decrescente do último até o primeiro) os elementos desse vetor.
c) Faça um algoritmo recursivo para encontrar e retornar o maior elemento desse vetor.
*/

#include <stdio.h>

void preenche_recursivo(int i, int n, int* vetor){
    if (i >= n)
        return;    
    
    vetor[i] = i;
    preenche_recursivo(i+1, n, vetor);
}

void imprime_crescente(int i, int n, int* vetor){
    if (i >=n)
        return;
    
    printf("%d ", vetor[i]);
    imprime_crescente(i+1, n, vetor);
}

void imprime_decrescente(int i, int n, int* vetor){
    if (i >= n)
        return;
    
    printf("%d ", vetor[n-1-i]);
    imprime_decrescente(i+1, n, vetor);
}

int maiorElemento_recursivo(int i, int n, int* vetor){
    int proximo;
    
    if (i < n-1){
        proximo = maiorElemento_recursivo(i+1, n, vetor);
    } else {
        proximo = vetor[i];
    }

    if (vetor[i] > proximo){
        return vetor[i];
    } else {
        return proximo;
    }
}

int main(){
    int N = 10;
    int vetor[N];
    preenche_recursivo(0, N, vetor);
    imprime_crescente(0, N, vetor);
    printf ("\n");
    imprime_decrescente(0, N, vetor);
    printf ("\n");
    printf ("Maior Elemento: %d\n", maiorElemento_recursivo(0, N, vetor));
}