#include <stdio.h>
#include <stdlib.h>

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
            while (j > h-1 && atual >= vetor[j-h]){
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
        if (vetor[i] > vetor[j]){ //Decrescente
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

void QuickSort(int *vetor, int inicio, int fim){
    if (inicio < fim){
        int q = particao(vetor, inicio, fim);
        QuickSort(vetor, inicio, q);
        QuickSort(vetor, q+1, fim);
    }
}

int particao(int *vetor, int inicio, int fim){
    int esq, dir, pivo;
    esq = inicio; dir = fim;
    pivo = vetor[inicio];
    while(esq < dir){
        while(esq <= fim && vetor[esq] >= pivo) esq++;
        while(dir >= 0 && vetor[dir] < pivo) dir--;
        if(esq < dir) troca(&vetor[esq], &vetor[dir]);
    }
    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;
    return dir;
}

void criaHeap(int *vetor, int pai, int fim){
    int aux = vetor[pai];
    int filho = 2*pai + 1;
    while(filho <= fim){
        if(filho < fim)
            if(vetor[filho] > vetor[filho+1])
                filho++;
        if(aux > vetor[filho]){
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
    printf ("1 - Shell Sort\n");
    printf ("2 - Merge Sort\n");
    printf ("3 - Quick Sort\n");
    printf ("4 - Heap Sort\n");
    int opcao;
    scanf ("%d", &opcao);

    if (opcao == 1){
        ShellSort(vetor, N);
        printf ("Vetor Ordenado: \n");
        for (int i = 0; i < N; i++){
            printf ("vetor[%d] = %d\n", i, vetor[i]);
        }
    }
    else if (opcao == 2){
        MergeSort(vetor, 0, N);
        printf ("Vetor Ordenado: \n");
        for (int i = 0; i < N; i++){
            printf ("vetor[%d] = %d\n", i, vetor[i]);
        }
    }
    else if (opcao == 3){
        QuickSort(vetor, 0, N);
        printf ("Vetor Ordenado: \n");
        for (int i = 0; i < N; i++){
            printf ("vetor[%d] = %d\n", i, vetor[i]);
        }
    }
    else if (opcao == 4){
        HeapSort(vetor, N);
        printf ("Vetor Ordenado: \n");
        for (int i=0; i < N; i++){
            printf ("vetor[%d] = %d\n", i, vetor[i]);
        }
    }
}