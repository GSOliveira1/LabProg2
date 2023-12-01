#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TAMANHO_ARQUIVO 100

void troca(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

void ShellSort(int *vetor, int n){
    int i, j, atual;
    int h = 1;
    while (h<n)
        h = 3*h+1;
    
    while (h>0){
        for (i=h; i<n; i++){
            atual = vetor[i];
            j = i;
            while (j > h-1 && atual <= vetor[j-h]){
                vetor[j] = vetor[j-h];
                j = j-h;
            }
            vetor[j] = atual;
        }
        h = h/3;
    }
}

void Merge(int *vetor, int inicio, int meio, int fim){
    int tam = fim-inicio+1;
    //Vetor Auxiliar - A
    int *A = (int*) malloc (tam*sizeof(int));
    int i = inicio, j = meio+1, k = 0;
    while (i<=meio && j<=fim) {
        if (vetor[i] < vetor[j]){ 
            A[k] = vetor[i]; 
            i++; 
        }
        else {
            A[k] = vetor[j]; 
            j++; 
        }
        k++;
    }
    while (i<=meio) { 
        A[k] = vetor[i];  
        i++;  
        k++; 
    }
    while (j<=fim) { 
        A[k] = vetor[j];  
        j++;  
        k++; 
    }
    for(i = inicio, k=0; i<=fim; i++, k++) 
        vetor[i] = A[k];
    free(A);    
}

void MergeSort(int *vetor, int inicio, int fim){
    if (inicio < fim){
        int meio = (inicio + fim)/2;
        MergeSort(vetor, inicio, meio);
        MergeSort(vetor, meio+1, fim);
        Merge(vetor, inicio, meio, fim);
    }
}

int particao(int *vetor, int inicio, int fim){
    int esq, dir, pivo;
    esq = inicio; dir = fim;
    pivo = vetor[inicio];
    while(esq < dir){
        while(esq <= fim && vetor[esq] <= pivo) esq++;
        while(dir >= 0 && vetor[dir] > pivo) dir--;
        if(esq < dir) troca(&vetor[esq], &vetor[dir]);
    }
    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;
    return dir;
}

void QuickSort(int *vetor, int inicio, int fim){
    if (inicio < fim){
        int q = particao(vetor, inicio, fim);
        QuickSort(vetor, inicio, q);
        QuickSort(vetor, q+1, fim);
    }
}

void criaHeap(int *vetor, int pai, int fim){
    int aux = vetor[pai];
    int filho = 2*pai + 1;
    while(filho <= fim){
        if(filho < fim)
            if(vetor[filho] < vetor[filho+1])
                filho++;
        if(aux < vetor[filho]){
            vetor[pai] = vetor[filho];
            pai = filho;
            filho = 2*pai + 1;
        }else filho = fim + 1;
    }
    vetor[pai] = aux;
}

void HeapSort(int *vetor, int n){
    int i;
    for(i=(n-1)/2; i>=0; i--)
        criaHeap(vetor, i, n-1);
    for(i=n-1; i>=1; i--){
        troca(&vetor[0], &vetor[i]);
        criaHeap(vetor, 0, i-1);
    }
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
    int *vet = (int*) malloc(n * sizeof(int));
    int *vetor_ShellSort = (int*) malloc(n * sizeof(int));
    int *vetor_MergeSort = (int*) malloc(n * sizeof(int));
    int *vetor_HeapSort = (int*) malloc(n * sizeof(int));

    if (vet == NULL || vetor_ShellSort == NULL || vetor_MergeSort == NULL || vetor_HeapSort == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    int i = 0;
    while (fscanf(arquivo, "%d", &vet[i]) == 1) {
        vetor_ShellSort[i] = vet[i];
        vetor_MergeSort[i] = vet[i];
        vetor_HeapSort[i] = vet[i];
        i++;
    }
    
    clock_t t1;
    t1 = clock();
    ShellSort(vetor_ShellSort, n);
    t1 = clock() - t1;
    printf ("%f seconds.\n", ((float)t1) / CLOCKS_PER_SEC);
    printf("\n");

    clock_t t2;
    t2 = clock();
    MergeSort(vetor_MergeSort, 0, n);
    t2 = clock() - t2;
    printf ("%f seconds.\n", ((float)t2) / CLOCKS_PER_SEC);
    printf("\n");

    clock_t t4;
    t4 = clock();
    HeapSort(vetor_HeapSort, n);
    t4 = clock() - t4;
    printf ("%f seconds.\n", ((float)t4) / CLOCKS_PER_SEC);
    printf("\n");

    clock_t t3;
    t3 = clock();
    QuickSort(vet, 0, n);
    t3 = clock() - t3;
    printf ("%f seconds.\n", ((float)t3) / CLOCKS_PER_SEC);
    printf("\n");

    free(vet);
    free(vetor_ShellSort);
    free(vetor_MergeSort);
    free(vetor_HeapSort);

    fclose(arquivo);
    return 0;
}