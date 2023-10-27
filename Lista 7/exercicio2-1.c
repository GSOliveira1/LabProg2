#include <stdio.h>
#include <stdlib.h>
#include "matriz_de_faixa.h"

int main() {
    MatrizFaixa *matriz = NULL;
    int tamanho, option;
    do{
        printf("1. Criar matriz faixa\n");
        printf("2. Inserir Elemento.\n");
        printf("3. Consultar Elemento.\n");
        printf("4. Imprimir Matriz Faixa\n");
        printf("5. Destruir Matriz Faixa\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                if(matriz != NULL){
                    printf("A matriz faixa ja foi criada!\n");
                }else{
                    printf("Informe o tamanho da matriz faixa: ");
                    scanf("%d", &tamanho);
                    matriz = criaMatriz(tamanho);
                    if(matriz == NULL){
                        printf("Nao foi possivel criar a matriz faixa!\n");
                    }else{
                        printf("Matriz faixa criada com sucesso!\n");
                    }
                }
                break;
            case 2:
                if(matriz == NULL){
                    printf("Matriz nao foi criada.\n");
                }else{
                    int elemento, i, j;
                    printf("Informe o elemento a ser inserido: ");
                    scanf("%d", &elemento);
                    printf("Informe a linha e a coluna: ");
                    scanf("%d %d", &i, &j);
                    int resultado = insereElemento(matriz, elemento, i, j);
                    if(resultado == -1){
                        printf("Matriz faixa nao foi criada!\n");
                    }else if(resultado == 0){
                        printf("Falha na insercao do elemento!\n");
                    }else{
                        printf("Elemento inserido.\n");
                    }
                }
                break;
            case 3:
                if(matriz == NULL){
                    printf("Erro: Matriz faixa nao foi criada!\n");
                }else{
                    int linha, coluna;
                    printf("Informe a linha e a coluna: ");
                    scanf("%d %d", &linha, &coluna);
                    int valor = consultaElemento(matriz, linha, coluna);
                    if(valor == 0){
                        printf("Falha ao procurar elemento!\n");
                    }else{
                        printf("Elemento consultado: %d\n", valor);
                    }
                }
                break;
            case 4:
                if(matriz == NULL){
                    printf("Matriz faixa nao foi criada!\n");
                }else{
                    imprimeFaixa(matriz);
                }
                break;
            case 5:
                if(matriz == NULL){
                    printf("Matriz faixa nao foi criada!\n");
                }else{
                    destroiMatriz(matriz);
                    matriz = NULL;
                    printf("Matriz faixa destruida!\n");
                }
                break;
            case 6:
                printf("Saindo.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(option != 6);
    return 0;
}