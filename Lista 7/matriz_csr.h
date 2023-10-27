#ifndef CSR_H
#define CSR_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *A;  //Valores
    int *IA;
    int *JA;
    int lin, col, QNN, QI;
}MEsparsaCSR;

MEsparsaCSR* criaMatrizEsparsa(int l, int c, int qnn){
    MEsparsaCSR *ms;
    ms = (MEsparsaCSR*) malloc (sizeof(MEsparsaCSR));
    if(ms != NULL){
        if(l <= 0 || c <= 0 || qnn < 0){
            printf("Valores invalidos, matriz nao criada!\n");
            return NULL;
        }
        ms->lin = l; ms->col = c;
        ms->QI = 0; ms->QNN = qnn;
        ms->A = ms->IA = ms->JA = NULL;
        if(qnn != 0){
            ms->A = (int*) malloc (qnn*sizeof(int));
            ms->JA = (int*) malloc (qnn*sizeof(int));
            if(ms->A == NULL || ms->JA == NULL) return NULL;
        }
        ms->IA = (int*) malloc ((ms->lin+1)*sizeof(int));
        if(ms->IA == NULL) return NULL;
        int i; for(i=0; i<l+1; i++) ms->IA[i] = 0;
    }
    return ms;
}

void destroiMatrizEsparsa(MEsparsaCSR *ms){
    if(ms != NULL){
        free(ms->A);
        free(ms->IA);
        free(ms->JA);
        free(ms);
    }
}

int* meuRealloc(int* v, int tam){
    int* aux = (int*) malloc ((tam+1)*sizeof(int));
    if(aux != NULL){
        if(v != NULL){
            int i;
            for(i=0; i<tam; i++)
                aux[i] = v[i];
            free(v);
        }
    }
    return aux;
}

int insereElemEsparsa( MEsparsaCSR *ms , int elem , int i, int j){
    if(ms == NULL) 
        return 0;
    if(i < 0 || j < 0 || i >= ms->lin || j >= ms->col){
        printf("Valores invalidos, elem nao inserido!\n"); 
        return 0;
    }
    int k; int index = -1;
    int ini = ms->IA[i]; 
    int fim = ms->IA[i +1];
    for(k = ini; k < fim; k++)
        if(ms->JA[k] >= j){ 
            index = k;
            break; 
        }
    if(index == -1){
        if(ms->QI == ms->QNN){
            ms->A = meuRealloc(ms->A, ms->QNN );
            ms->JA = meuRealloc(ms->JA , ms->QNN );
            ms->QNN++;
        }
        for(k = ms->QNN -1; k >= fim; k--){
            ms->A[k] = ms->A[k -1];
            ms->JA[k] = ms->JA[k -1];
        }
        ms->A[fim] = elem;
        ms->JA[fim] = j;
        ms->QI++;
        for(int k = i +1; k <=ms->lin; k++) 
            ms->IA[k]++;
    }else 
        ms->A[index] = elem;
    return 1;
}

int removeElemEsparsa(MEsparsaCSR *ms , int i, int j){
    if(ms == NULL) 
        return 0;
    if(i < 0 || j < 0 || i >= ms->lin || j >= ms->col){
        printf("Valores invalidos , elem nao removido!\n");
        return 0;
    }
    int k;
    int index = -1;
    int ini = ms->IA[i];
    int fim = ms->IA[i +1];
    for(k = ini; k<fim ; k++)
        if(ms->JA[k] == j){
            index = k;
            break;
        }
    if(index != -1){
        for(k = index; k < ms->QNN - 1; k++){
        ms->A[k] = ms->A[k +1];
        ms->JA[k] = ms->JA[k +1];
        }
        ms->QNN --;
        ms->QI --;
        for(int k = i + 1; k <=ms->lin; k++)
            ms->IA[k] --;
    }else{
        printf("Elemento nao existente\n");
        return 0;
    }
    return 1;
}

int consultaElemEsparsa(MEsparsaCSR *ms, int i, int j){
    if(ms == NULL )
        return 0;
    if(i < 0 || j < 0 || i >= ms->lin || j >= ms->col){
        printf("Valores invalidos, elem inexistente!\n");
        return 0;
    }
    int k;
    for(k = ms->IA[i]; k < ms->IA[i + 1]; k++)
        if(ms->JA[k] == j)
            return ms->A[k];
    return 0;
}

void imprimeEsparsaVetores (MEsparsaCSR * ms){
    if(ms == NULL)
        return ;
    int i;
    printf("Matriz Esparsa , Tam: %d x %d:\n", ms->lin, ms->col);
    printf("%d elementos nao nulos .\n", ms->QNN);
    printf("A = [");
    for(i = 0; i < ms->QNN; i++)
        printf("%d ", ms->A[i]);
    printf("]\n");
    printf("IA = [");
    for(i = 0; i < ms->lin + 1; i++)
        printf("%d ", ms->IA[i]);
    printf("]\n");
    printf("JA = [");
    for(i = 0; i < ms->QNN; i++)
        printf("%d ", ms->JA[i]);
    printf("]\n\n");
}

#endif  //CSR_H