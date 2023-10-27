#include <stdio.h>
#include <stdlib.h>
#include "matriz_sequencial_estatica.h"
//#include "matriz_sequencial_dinamica.h"
//Esse arquivo funciona tanto para a Matriz Sequencial Estática, quanto para a Matriz Sequencial Dinâmica, basta escolher qual biblioteca importar. 

int main() {
    Matriz *matriz = NULL;
    int option, linhas, colunas, elemento, valor;
    do{
        printf("1. Criar Matriz\n");
        printf("2. Destruir Matriz\n");
        printf("3. Inserir Elemento\n");
        printf("4. Consultar Elemento\n");
        printf("5. Imprimir Matriz\n");
        printf("6. Criar Transposta da Matriz\n");
        printf("7. Verificar se a matriz e quadrada\n");
        printf("8. Verificar se a matriz e simetrica\n");
        printf("9. Criar Matriz Triangular Superior\n");
        printf("10. Criar Matriz Triangular Inferior\n");
        printf("11. Criar Matriz Diagonal\n");
        printf("12. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Informe o numero de linhas: ");
                scanf("%d", &linhas);
                printf("Informe o numero de colunas: ");
                scanf("%d", &colunas);
                matriz = criaMatriz(linhas, colunas);
                if(matriz == NULL)
                    printf("Falha na criacao da matriz!\n");
                else
                    printf("Matriz criada!\n");
                break;
            case 2:
                destroiMatriz(matriz);
                matriz = NULL;
                printf("Matriz destruida!\n");
                break;
            case 3:
                if(matriz == NULL){
                    printf("Matriz nao foi criada!\n");
                }else{
                    printf("Informe o elemento: ");
                    scanf("%d", &elemento);
                    printf("Informe a linha e coluna (linha coluna): ");
                    scanf("%d %d", &linhas, &colunas);
                    if(insereElemento(matriz, elemento, linhas, colunas))
                        printf("Elemento inserido!\n");
                    else
                        printf("Nao foi possivel inserir o elemento!\n");
                }
                break;
            case 4:
                if(matriz == NULL){
                    printf("Erro: Matriz nao foi criada!\n");
                }else{
                    printf("Informe a linha e coluna (linha coluna): ");
                    scanf("%d %d", &linhas, &colunas);
                    if(consultaElemento(matriz, &valor, linhas, colunas))
                        printf("Elemento consultado: %d\n", valor);
                    else
                        printf("Erro: Falha na consulta do elemento!\n");
                }
                break;
            case 5:
                if(matriz == NULL){
                    printf("Matriz nao foi criada!\n");
                }else{
                    imprime(matriz);
                }
                break;
            case 6:
                if(matriz == NULL){
                    printf("Matriz nao foi criada!\n");
                }else{
                    Matriz *transposta = criaTransposta(matriz);
                    if(transposta == NULL){
                        printf("Nao foi possivel criar a matriz transposta!\n");
                    }else{
                        printf("Matriz transposta:\n");
                        imprime(transposta);
                        destroiMatriz(transposta);
                    }
                }
                break;
            case 7:
                if(matriz == NULL){
                    printf("Matriz nao foi criada!\n");
                }else{
                    if(e_matrizQuadrada(matriz))
                        printf("A matriz e' quadrada!\n");
                    else
                        printf("A matriz nao e' quadrada!\n");
                }
                break;
            case 8:
                if(matriz == NULL){
                    printf("Matriz nao foi criada!\n");
                }else{
                    if(e_Simetrica(matriz))
                        printf("A matriz e' simetrica!\n");
                    else
                        printf("A matriz nao e' simetrica!\n");
                }
                break;
            case 9:
                if(matriz == NULL){
                    printf("Matriz nao foi criada!\n");
                }else{
                    Matriz *triangularSuperior = criaTriangularSuperior(matriz);
                    if(triangularSuperior == NULL) {
                        printf("Nao foi possivel criar a matriz triangular superior!\n");
                    }else{
                        printf("Matriz triangular superior:\n");
                        imprime(triangularSuperior);
                        destroiMatriz(triangularSuperior);
                    }
                }
                break;
            case 10:
                if(matriz == NULL){
                    printf("Erro: Matriz nao foi criada!\n");
                }else{
                    Matriz *triangularInferior = criaTriangularInferior(matriz);
                    if(triangularInferior == NULL){
                        printf("Erro: Falha na criacao da matriz triangular inferior!\n");
                    }else{
                        printf("Matriz triangular inferior:\n");
                        imprime(triangularInferior);
                        destroiMatriz(triangularInferior);
                    }
                }
                break;
            case 11:
                if(matriz == NULL){
                    printf("Matriz nao foi criada!\n");
                }else{
                    Matriz *diagonal = criaDiagonal(matriz);
                    if(diagonal == NULL){
                        printf("Nao foi possivel criar a matriz diagonal!\n");
                    }else{
                        printf("Matriz diagonal:\n");
                        imprime(diagonal);
                        destroiMatriz(diagonal);
                    }
                }
                break;
            case 12:
                printf("Saindo.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(option != 12);
    return 0;
}