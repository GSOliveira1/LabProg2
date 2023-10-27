#ifndef MSD_H
#define MSD_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int **dados;
    int linhas, colunas;
}Matriz;

void zeraMatriz(Matriz* matriz){
    int i, j;
    if (matriz != NULL){
        for (i=0; i<matriz->linhas;i++)
            for (j=0; j<matriz->colunas;j++)
                matriz->dados[i][j] = 0;
    }
}

Matriz* criaMatriz(int linhas, int colunas){
    Matriz* matriz;
    matriz = (Matriz*) malloc (sizeof(Matriz));
    if (matriz != NULL){
        if (linhas <= 0 || colunas <= 0){
            printf ("Valores invalidos!");
            return NULL;
        }
        int i;
        matriz->linhas = linhas;
        matriz->colunas = colunas;
        matriz->dados = (int**) malloc (linhas * sizeof(int*));
        for (i=0; i < linhas; i++)
            matriz->dados[i] = (int*) malloc (colunas * sizeof(int));
        zeraMatriz(matriz);
    }
}

void destroiMatriz(Matriz* matriz){
    if (matriz != NULL){
        int i;
        for (i=0; i < matriz->linhas; i++)
            free(matriz->dados[i]);
        free(matriz->dados);
        free(matriz);
    }
}

int insereElemento(Matriz* matriz, int elemento, int linha, int coluna){
    if (matriz == NULL)
        return 0;
    if (linha < 0 || coluna < 0 || linha >= matriz->linhas || coluna >= matriz->colunas){
        printf ("Valores invalidos, elemento nao foi inserido.\n");
        return 0;
    }
    matriz->dados[linha][coluna] = elemento;
    return 1;
}

int consultaElemento(Matriz* matriz, int *elemento, int linha, int coluna){
    if (matriz == NULL)
        return 0;
    if (linha < 0 || coluna < 0 || linha >= matriz->linhas || coluna >= matriz->colunas){
        printf ("Valores invalidos, elemento nao existe na matriz!\n");
        return 0;
    }
    *elemento = matriz->dados[linha][coluna];
    return 1;
}

void imprime (Matriz* matriz){
    if (matriz == NULL)
        return;
    int i, j;
    printf ("Matriz %d x %d: \n", matriz->linhas, matriz->colunas);
    for (i=0; i<matriz->linhas; i++){
        for (j=0; j<matriz->colunas; j++)
            printf ("%d ", matriz->dados[i][j]);
        printf ("\n");
    }
    printf ("\n");
}

Matriz* criaTransposta (Matriz* matriz){
    if (matriz == NULL)
        return NULL;
    Matriz* transposta = criaMatriz(matriz->colunas, matriz->linhas);
    int i, j;
    for (i=0; i< matriz->linhas; i++){
        for (j=0; j<matriz->colunas; j++)
            transposta->dados[j][i] = matriz->dados[i][j];
    }
    return transposta;
}

int e_matrizQuadrada(Matriz *matriz){
    if (matriz == NULL)
        return 0;
    return (matriz->linhas == matriz->colunas);
}

int e_Simetrica(Matriz* matriz){
    if (matriz == NULL)
        return 0;
    if (!e_matrizQuadrada(matriz)){
        printf ("Matriz nao quadrada!\n");
        return 0;
    }
    int i, j;
    for (i=0; i<matriz->linhas; i++){
        for (j=0; j<matriz->colunas; j++)
            if (matriz->dados[i][j] != matriz->dados[j][i])
                return 0;
    }
    return 1;
}

Matriz* criaTriangularSuperior(Matriz* matriz){
    if (matriz == NULL)
        return 0;
    if (!e_matrizQuadrada(matriz)){
        printf ("Matriz nao quadrada!\n");
        return NULL;
    }
    int i, j;
    Matriz* triangularSuperior = criaMatriz(matriz->linhas, matriz->colunas);
    for (i=0; i<matriz->linhas; i++){
        for (j=0; j<matriz->colunas; j++)
            if (i <= j)
                triangularSuperior->dados[i][j] = matriz->dados[i][j];
    }
    return triangularSuperior;
}

Matriz* criaTriangularInferior(Matriz* matriz){
    if (matriz == NULL)
        return 0;
    if (!e_matrizQuadrada(matriz)){
        printf ("Matriz nao quadrada!\n");
        return NULL;
    }
    int i, j;
    Matriz* triangularInferior = criaMatriz(matriz->linhas, matriz->colunas);
    for (i=0; i<matriz->linhas; i++){
        for (j=0; j<matriz->colunas; j++)
            if (i >= j)
                triangularInferior->dados[i][j] = matriz->dados[i][j];
    }
    return triangularInferior;
}

Matriz* criaDiagonal(Matriz* matriz){
    if (matriz == NULL)
        return 0;
    if (!e_matrizQuadrada(matriz)){
        printf ("Matriz nao quadrada!\n");
        return NULL;
    }
    int i, j;
    Matriz* diagonal = criaMatriz(matriz->linhas, matriz->colunas);
    for (i=0; i < matriz->linhas; i++)
        diagonal->dados[i][i] = matriz->dados[i][i];
    return diagonal;
}
#endif  //MSD_H