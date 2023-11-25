#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
} Pessoa;

void selectionSortCrescente(Pessoa *vetor, int N){
    int i, j, menor;
    for (i=0; i<N-1; i++){
        menor = i;
        for (j=i+1; j<N; j++){
            if (strcmp(vetor[j].nome, vetor[menor].nome) < 0 || strcmp(vetor[j].nome, vetor[menor].nome) == 0 && vetor[j].idade < vetor[menor].idade)
                menor = j;
        }

        if (i != menor){
            Pessoa aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}

void selectionSortDecrescente(Pessoa *vetor, int N){
    int i, j, menor;
    for (i=0; i<N-1; i++){
        menor = i;
        for (j=i+1; j<N; j++){
            if (strcmp(vetor[j].nome, vetor[menor].nome) > 0 || strcmp(vetor[j].nome, vetor[menor].nome) == 0 && vetor[j].idade > vetor[menor].idade)
                menor = j;
        }

        if (i != menor){
            Pessoa aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}

void insertionSortCrescente(Pessoa *vetor, int N){
    int i, j;
    Pessoa atual;
    for (i=1; i<N; i++){
        atual = vetor[i];
        j = i;
        while ((j > 0) && (strcmp(vetor[j-1].nome, atual.nome) < 0 || strcmp(vetor[j-1].nome, atual.nome) == 0 && vetor[j-1].idade < atual.idade)){
            vetor[j] = vetor[j-1];
            j--;
        }
        vetor[j] = atual;
    }
}

void insertionSortDecrescente(Pessoa *vetor, int N){
    int i, j;
    Pessoa atual;
    for (i=1; i<N; i++){
        atual = vetor[i];
        j = i;
        while ((j > 0) && (strcmp(vetor[j-1].nome, atual.nome) > 0 || strcmp(vetor[j-1].nome, atual.nome) == 0 && vetor[j-1].idade > atual.idade)){
            vetor[j] = vetor[j-1];
            j--;
        }
        vetor[j] = atual;
    }
}

int main(){
    int N;
    printf ("Quantas pessoas serão informadas? ");
    scanf ("%d", &N);
    Pessoa vetor[N];
    for (int i = 0; i < N; i++){
        printf ("Nome: ");
        scanf (" %s", &vetor[i].nome);
        printf ("Idade: ");
        scanf ("%d", &vetor[i].idade);
    }

    printf ("Qual algoritmo deseja usar?\n");
    printf ("1 - Selection Sort\n");
    printf ("2 - Insertion Sort\n");
    int opcao;
    scanf ("%d", &opcao);

    if (opcao == 1){
        selectionSortCrescente(vetor, N);
        for (int i = 0; i < N; i++){
            printf ("Nome: %s, Idade: %d\n", vetor[i].nome, vetor[i].idade);
        }

        selectionSortDecrescente(vetor, N);
        printf ("Vetor Ordenado: \n");
        for (int i = 0; i < N; i++){
            printf ("Nome: %s, Idade: %d\n", vetor[i].nome, vetor[i].idade);
        }
    }
    else if (opcao == 2){
        insertionSortCrescente(vetor, N);
        for (int i = 0; i < N; i++){
            printf ("Nome: %s, Idade: %d\n", vetor[i].nome, vetor[i].idade);
        }

        insertionSortDecrescente(vetor, N);
        printf ("Vetor Ordenado: \n");
        for (int i = 0; i < N; i++){
            printf ("Nome: %s, Idade: %d\n", vetor[i].nome, vetor[i].idade);
        }
    }
}