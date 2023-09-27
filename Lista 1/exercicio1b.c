#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maior_elemento(int *vet, int tamanho){
    int maior = vet[0];
    for (int i = 0; i < tamanho; i++){
        if (vet[i] > maior)
            maior = vet[i];
    }
    return maior;
}

int menor_elemento(int *vet, int tamanho){
    int menor = vet[0];
    for (int i = 0; i < tamanho; i++){
        if (vet[i] < menor)
            menor = vet[i];
    }
    return menor;
}

float media(int *vet, int tamanho){
    float media = 0;
    for (int i = 0; i < tamanho; i++){
        media += vet[i];
    }
    return media / tamanho;
}

int main(){
    srand(time(NULL));
    int vetor1[10];
    int vetor2[20];

    for (int i = 0; i < 10; i++){
        vetor1[i] = rand() % 100;
    }

    for (int i = 0; i < 20; i++){
        vetor2[i] = rand() % 100;
    }

    printf("Vetor 1:");
    for (int i = 0; i < 10; i++){
        printf("%d ", vetor1[i]);
    }

    printf("\nVetor 2:");
    for (int i = 0; i < 20; i++){
        printf("%d ", vetor2[i]);
    }
    printf("\n");

    printf("Maior Elemento Vetor 1: %d\n", maior_elemento(vetor1, 10));
    printf("Menor Elemento Vetor 1: %d\n", menor_elemento(vetor1, 10));
    printf("Media Elementos Vetor 1: %f\n", media(vetor1, 10));

    printf("Maior Elemento Vetor 2: %d\n", maior_elemento(vetor2, 20));
    printf("Menor Elemento Vetor 2: %d\n", menor_elemento(vetor2, 20));
    printf("Media Elementos Vetor 2: %f\n", media(vetor2, 20));
}