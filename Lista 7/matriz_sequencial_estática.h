#ifndef MSE_H
#define MSE_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct{
    int dados[MAX][MAX];
    int linha, coluna;
}Matriz;

void zeraMatriz(Matriz* matriz){
    int i, j;
    if (matriz != NULL){
        for (i=0; i<matriz->linha;i++)
            for (j=0; j<matriz->coluna;j++)
                matriz->dados[i][j] = 0;
    }
}

Matriz* criaMatriz(int linha, int coluna){
    Matriz* matriz;
    matriz = (Matriz*) malloc(sizeof(Matriz));
    if (matriz != NULL){
        if (linha <= 0 || coluna <=0 || linha > MAX || coluna > MAX){
            printf ("Valores invalidos, matriz nao criada!\n");
            return NULL;
        }
        matriz->linha = linha;
        matriz->coluna = coluna;
        zeraMatriz(matriz);
    }
    return matriz;
}

void destroiMatriz(Matriz* matriz){
    if (matriz != NULL)
        free(matriz);
}

int insereElemento(Matriz* matriz, int elemento, int linha, int coluna){
    if (matriz == NULL)
        return 0;
    if (linha < 0 || coluna < 0 || linha >= matriz->linha || coluna >= matriz->coluna){
        printf ("Valores invalidos, elemento nao foi inserido.\n");
        return 0;
    }
    matriz->dados[linha][coluna] = elemento;
    return 1;
}

int consultaElemento(Matriz* matriz, int *elemento, int linha, int coluna){
    if (matriz == NULL)
        return 0;
    if (linha < 0 || coluna < 0 || linha >= matriz->linha || coluna >= matriz->coluna){
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
    printf ("Matriz %d x %d: \n", matriz->linha, matriz->coluna);
    for (i=0; i<matriz->linha; i++){
        for (j=0; j<matriz->coluna; j++)
            printf ("%d ", matriz->dados[i][j]);
        printf ("\n");
    }
    printf ("\n");
}

Matriz* criaTransposta (Matriz* matriz){
    if (matriz == NULL)
        return NULL;
    Matriz* transposta = criaMatriz(matriz->coluna, matriz->linha);
    int i, j;
    for (i=0; i< matriz->linha; i++){
        for (j=0; j<matriz->coluna; j++)
            transposta->dados[j][i] = matriz->dados[i][j];
    }
    return transposta;
}

int e_matrizQuadrada(Matriz *matriz){
    if (matriz == NULL)
        return 0;
    return (matriz->linha == matriz->coluna);
}

int e_Simetrica(Matriz* matriz){
    if (matriz == NULL)
        return 0;
    if (!e_matrizQuadrada(matriz)){
        printf ("Matriz nao quadrada!\n");
        return 0;
    }
    int i, j;
    for (i=0; i<matriz->linha; i++){
        for (j=0; j<matriz->coluna; j++)
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
    Matriz* triangularSuperior = criaMatriz(matriz->linha, matriz->coluna);
    for (i=0; i<matriz->linha; i++){
        for (j=0; j<matriz->coluna; j++)
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
    Matriz* triangularInferior = criaMatriz(matriz->linha, matriz->coluna);
    for (i=0; i<matriz->linha; i++){
        for (j=0; j<matriz->coluna; j++)
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
    Matriz* diagonal = criaMatriz(matriz->linha, matriz->coluna);
    for (i=0; i < matriz->linha; i++)
        diagonal->dados[i][i] = matriz->dados[i][i];
    return diagonal;
}

#endif  //MSE_H