#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define TAMANHO_ARQUIVO 100

void selectionSort(int *vetor, int N){
    int i, j, menor, mov, comp;
    mov = comp = 0;
    for (i=0; i < N-1; i++){
        menor = i;
        for (j=i+1; j < N; j++){
            comp++;
            if (vetor[j] < vetor[menor])
                menor = j;
        }

        if (i != menor){
            int aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
            mov++;
        }
    }
    printf ("Comparacoes: %d\nMovimentacoes: %d\n", comp, mov);
}

void insertionSort(int *vetor, int N){
    int i, j, atual, comp, mov;
    mov = comp = 0;
    for (i=1; i<N; i++){
        atual = vetor[i];
        comp++;
        for (j=i; (j>0) && (atual < vetor[j-1]); j--){
            vetor[j] = vetor[j-1];
            comp++;
            mov++;
        }
        vetor[j] = atual;
    }
    printf ("Comparacoes: %d\nMovimentacoes: %d\n", comp, mov);
}

void bubbleSort(int *vetor, int N){
    int i, j, comp, mov;
    mov = comp = 0;
    for (i=0; i < N-1; i++){
        for(j=0; j < N-i-1; j++){
            comp++;
            if (vetor[j] > vetor[j+1]){
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                mov++;
            }
        }
    }
    printf ("Comparacoes: %d\nMovimentacoes: %d\n", comp, mov);
}

int main(){
    FILE *arquivo;
    char nomeArquivo[TAMANHO_ARQUIVO];

    printf("Digite o nome do arquivo .txt que esta na pasta 'entradas': ");
    scanf("%s", nomeArquivo);

    char caminhoArquivo[TAMANHO_ARQUIVO];
    GetModuleFileName(NULL, caminhoArquivo, TAMANHO_ARQUIVO);
    char *ultimoBarra = strrchr(caminhoArquivo, '\\');
    if (ultimoBarra != NULL) {
        *ultimoBarra = '\0'; 
    }

    snprintf(caminhoArquivo, TAMANHO_ARQUIVO, "%s\\entradas\\%s.txt", caminhoArquivo, nomeArquivo);

    arquivo = fopen(caminhoArquivo, "r");
    printf("Caminho do arquivo: %s\n", caminhoArquivo);
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int n;
    fscanf(arquivo, "%d", &n);
    int vet[n], vetor_BubbleSort[n], vetor_SelectionSort[n], vetor_InsertionSort[n];
    int i = 0;

    while(!feof(arquivo)){
        fscanf(arquivo, "%d", &vet[i]);
        vetor_BubbleSort[i] = vet[i];
        vetor_SelectionSort[i] = vet[i];
        vetor_InsertionSort[i] = vet[i];
        i++;
    }
    
    clock_t t1;
    t1 = clock();
    bubbleSort(vetor_BubbleSort, n);
    t1 = clock() - t1;
    printf ("%f seconds.\n", ((float)t1) / CLOCKS_PER_SEC);
    printf("\n");

    clock_t t2;
    t2 = clock();
    selectionSort(vetor_SelectionSort, n);
    t2 = clock() - t2;
    printf ("%f seconds.\n", ((float)t2) / CLOCKS_PER_SEC);
    printf("\n");

    clock_t t3;
    t3 = clock();
    insertionSort(vetor_InsertionSort, n);
    t3 = clock() - t3;
    printf ("%f seconds.\n", ((float)t3) / CLOCKS_PER_SEC);
    printf("\n");
    
    fclose(arquivo);
    return 0;
}
