#include <stdio.h>
#include "AVL.h"

int main(){
    int opcao;
    AVL* avl = NULL;
    int elemento;

    do {
        printf("1. Criar\n");
        printf("2. Inserir\n");
        printf("3. Buscar\n");
        printf("4. Remover\n");
        printf("5. Imprimir em Ordem\n");
        printf("6. Quantidade de Nos\n");
        printf("7. Destruir\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                if (avl != NULL)
                    destroiAVL(avl);
                avl = criaAVL();
                break;
            case 2:
                printf ("Informe o elemento: ");
                scanf ("%d", &elemento);
                if (insereElem(avl, elemento))
                    printf ("Inseriu (%d).", elemento);
                else
                    printf ("Falha ao inserir.");
                break;
            case 3:
                printf ("Informe o elemento a ser buscado: ");
                scanf ("%d", &elemento);
                if (pesquisa(avl, elemento))
                    printf ("Elemento encontrado.");
                else
                    printf ("Elemento nao encontrado.");
                break;
            case 4:
                printf ("Informe o elemento a ser removido: ");
                scanf ("%d", &elemento);
                if (removeElem(avl, elemento))
                    printf ("Removeu com sucesso.");
                else
                    printf ("Falha ao remover elemento.");
                break;
            case 5:
                em_ordem(*avl, 0);
                break;
            case 6:
                printf ("Tamanho = %d", tamanho(*avl, 0));
                break;
            case 7:
                destroiAVL(avl);
                break;
            case 8:
                printf ("Saindo.");
                break;
            default:
                printf ("Opcao invalida.");
                break;
        }
        printf("\n");        
    } while (opcao != 8);
    return 0;
}