#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *vetor, int N){
    int i, j, menor;
    for (i=0; i < N-1; i++){
        menor = i;
        for (j=i+1; j < N; j++){
            if (vetor[j] < vetor[menor])
                menor = j;
        }

        if (i != menor){
            int aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}

void insertionSort(int *vetor, int N){
    int i, j, atual;
    for (i=1; i<N; i++){
        atual = vetor[i];
        for (j=i; (j>0) && (atual < vetor[j-1]); j--){
            vetor[j] = vetor[j-1];
        }
        vetor[j] = atual;
    }
}

void bubbleSort(int *vetor, int N){
    int i, j;
    for (i=0; i < N-1; i++){
        for(j=0; j < N-i-1; j++){
            if (vetor[j] > vetor[j+1]){
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

int main(){
    int N;
    printf ("Informe o tamanho do vetor: ");
    scanf ("%d", &N);
    int vetor[N];
    for (int i = 0; i < N; i++){
        printf ("vetor[%d] = ", i);
        scanf ("%d", &vetor[i]);
    }
    printf ("Vetor Desordenado: ");
    for (int i = 0; i < N; i++){
        printf ("vetor[%d] = %d\n", i, vetor[i]);
    }

    printf ("Qual algoritmo deseja usar?\n");
    printf ("1 - Selection Sort\n");
    printf ("2 - Insertion Sort\n");
    printf ("3 - Bubble Sort\n");
    int opcao;
    scanf ("%d", &opcao);

    if (opcao == 1){
        selectionSort(vetor, N);
        printf ("Vetor Ordenado: \n");
        for (int i = 0; i < N; i++){
            printf ("vetor[%d] = %d\n", i, vetor[i]);
        }
    }
    else if (opcao == 2){
        insertionSort(vetor, N);
        printf ("Vetor Ordenado: \n");
        for (int i = 0; i < N; i++){
            printf ("vetor[%d] = %d\n", i, vetor[i]);
        }
    }
    else if (opcao == 3){
        bubbleSort(vetor, N);
        printf ("Vetor Ordenado: \n");
        for (int i = 0; i < N; i++){
            printf ("vetor[%d] = %d\n", i, vetor[i]);
        }
    }
}