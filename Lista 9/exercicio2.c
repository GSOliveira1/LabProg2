#include <stdio.h>
#include "exercicio2.h"

int main(){
    int opcao;
    AVL* avl = NULL;
    Funcionario elemento, *auxiliar;

    do {
        printf("1. Criar\n");
        printf("2. Inserir\n");
        printf("3. Buscar\n");
        printf("4. Remover\n");
        printf("5. Imprimir em Ordem\n");
        printf("6. Funcionario com Maior Salario\n");
        printf("7. Funcionario com Menor Salario\n");
        printf("8. Destruir\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                if (avl != NULL)
                    destroiAVL(avl);
                avl = criaAVL();
                break;
            case 2:
                printf("Informe os Dados do Funcionario\n");
                printf("Nome (50 caracteres): ");
                setbuf(stdin, NULL);
                fgets(elemento.nome, 50, stdin);
                setbuf(stdin, NULL);
                printf("Ano de contratacao: ");
                scanf("%d", &elemento.contratacao);
                printf("Salario: ");
                scanf("%lf", &elemento.salario);

                if (insereElem(avl, elemento)){
                    printf ("Sucesso ao inserir funcionario.");
                } else {
                    printf ("Falha ao inserir funcionario");
                }
                break;
            case 3:
                printf ("Informe o salario a ser buscado: ");
                scanf ("%lf", &elemento.salario);
                if (pesquisa(avl, elemento))
                    printf ("Funcionario encontrado. Salario: %lf", elemento.salario);
                else
                    printf ("Funcionario nao encontrado.");
                break;
            case 4:
                printf ("Informe o nome do Funcionario a ser removido: ");
                fgets(elemento.nome, 50, stdin);
                setbuf (stdin, NULL);
                if (removeElem(avl, elemento))
                    printf ("Removeu com sucesso o Funcionario.");
                else
                    printf ("Falha ao remover funcionario.");
                break;
            case 5:
                imprime(avl);
                break;
            case 6:
                auxiliar = maiorSalario(*avl);
                printf ("Dados do Funcionario com Maior Salario:\n");
                printf ("Nome: %s\nAno de Contratacao: %d\nSalario: %lf", auxiliar->nome, auxiliar->contratacao, auxiliar->salario);
                break;
            case 7:
                auxiliar = menorSalario(*avl);
                printf ("Dados do Funcionario com Menor Salario:\n");
                printf ("Nome: %s\nAno de Contratacao: %d\nSalario: %lf", auxiliar->nome, auxiliar->contratacao, auxiliar->salario);                
                break;
            case 8:
                destroiAVL(&avl);
                break;
            case 9:
                if (avl != NULL){
                    destroiAVL(&avl);
                }
                printf ("Saindo.");
                break;
            default:
                printf ("Opcao invalida.");
                break;
        }
        printf("\n");        
    } while (opcao != 9);
    return 0;
}