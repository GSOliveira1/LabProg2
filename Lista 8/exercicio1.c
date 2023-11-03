#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

int main(){
    int opcao, elemento;
    ABP* abp = NULL;

    do {
        printf("1. Criar\n");
        printf("2. Inserir\n");
        printf("3. Buscar\n");
        printf("4. Remover\n");
        printf("5. Imprimir em Ordem\n");
        printf("6. Imprimir em Pre-Ordem\n");
        printf("7. Imprimir em Pos-Ordem\n");
        printf("8. Tamanho\n");
        printf("9. Destruir\n");
        printf("10. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                if (abp != NULL)
                    destroiABP(abp);
                abp = criaABP();
                break;
            case 2:
                printf ("Informe o elemento: ");
                scanf ("%d", &elemento);
                if (insereElem(abp, elemento))
                    printf ("Inseriu (%d).", elemento);
                else
                    printf ("Falha ao inserir.");
                break;
            case 3:
                printf ("Informe o elemento a ser buscado: ");
                scanf ("%d", &elemento);
                if (pesquisa(abp, elemento))
                    printf ("Elemento encontrado.");
                else
                    printf ("Elemento nao encontrado.");
                break;
            case 4:
                printf ("Informe o elemento a ser removido: ");
                scanf ("%d", &elemento);
                if (removeElem(abp, elemento))
                    printf ("Removeu com sucesso.");
                else
                    printf ("Falha ao remover elemento.");
                break;
            case 5:
                em_ordem(*abp, 0);
                break;
            case 6:
                pre_ordem(*abp, 0);
                break;
            case 7:
                pos_ordem(*abp, 0);
                break;
            case 8:
                printf ("Tamanho = %d", tamanho(*abp, 0));
                break;
            case 9:
                destroiABP(abp);
                break;
            case 10:
                printf ("Saindo.");
                break;
            default:
                printf ("Opcao invalida.");
                break;
        }
        printf("\n");        
    } while (opcao != 10);
    return 0;
}