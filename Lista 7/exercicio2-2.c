#include <stdio.h>
#include <stdlib.h>
#include "matriz_csr.h"

int main(){
    MEsparsaCSR* esparsa = NULL;

    int option, linhas, colunas, elemento;
    do{
        printf ("1- Criar Matriz Esparsa.\n");
        printf ("2- Destruir Matriz Esparsa.\n");
        printf ("3- Inserir Elemento.\n");
        printf ("4- Remover Elemento.\n");
        printf ("5- Consultar Elemento.\n");
        printf ("6- Imprimir Matriz Esparsa.\n");
        printf ("7- Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        switch (option){
            case 1:
                if (esparsa != NULL){
                    destroiMatrizEsparsa(esparsa);
                    printf ("Matriz apagada!");
                }
                printf ("Informe as dimensoes\n");
                printf ("Linhas e Colunas: ");
                scanf ("%d %d", &linhas, &colunas);
                esparsa = criaMatrizEsparsa(linhas, colunas, 0);
                break;
            case 2:
                destroiMatrizEsparsa(esparsa);
                printf ("Matriz Destruida.\n");
                break;
            case 3:
                printf ("Elemento a ser inserido: ");
                scanf ("%d", &elemento);
                printf ("Informe a linha e a coluna onde sera inserido o elemento: ");
                scanf ("%d %d", &linhas, &colunas);
                if (insereElemEsparsa(esparsa, elemento, linhas, colunas))
                    printf ("Elemento %d inserido na posicao (%d, %d)\n", elemento, linhas, colunas);
                else
                    printf ("Nao foi possivel inserir o elemento\n");
                break;
            case 4:
                printf ("Informe a linha e a coluna do elemento a ser removido: ");
                scanf ("%d %d", &linhas, &colunas);
                if (removeElemEsparsa(esparsa, linhas, colunas))
                    printf ("Removeu o elemento %d da posicao (%d, %d)\n", elemento, linhas, colunas);
                else
                    printf ("Nao foi possivel remover.\n");
                break;
            case 5:
                printf ("Posicao a ser consultada:\n");
                printf ("Informe a linha e a coluna: \n");
                scanf ("%d %d", &linhas, &colunas);
                if (elemento = consultaElemEsparsa(esparsa, linhas, colunas))
                    printf ("Elemento: %d\n", elemento);
                else
                    printf ("Nao foi possivel consultar nessa posicao da matriz.\n");
                break;
            case 6:
                imprimeEsparsaVetores(esparsa);
                break;
            case 7:
                printf ("Saindo.\n");
                break;
            default:
                printf ("Opcao invalida!\n");
                break;
        }
    } while(option != 7);    
    return 0;
}