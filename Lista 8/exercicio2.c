#include <stdio.h>
#include "exercicio2.h"

int main(){
    int opcao;
    Aluno elemento, *auxiliar;
    ABP* abp = NULL;

    do{
        printf("1. Criar\n");
        printf("2. Inserir\n");
        printf("3. Buscar\n");
        printf("4. Remover\n");
        printf("5. Imprimir em Ordem\n");
        printf("6. Imprimir infos do Aluno com maior nota\n");
        printf("7. Imprimir infos do Aluno com menor nota\n");
        printf("8. Destruir\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                if (abp != NULL)
                    destroiABP(abp);
                abp = criaABP();
                printf ("Criada com sucesso.");
                break;
            case 2:
                printf ("Aluno a ser inserido: \n");
                printf ("Nome (50 caracteres): ");
                setbuf(stdin, NULL);
                fgets(elemento.nome, 50, stdin);
                setbuf(stdin, NULL);
                printf ("Matricula: ");
                scanf ("%d", &elemento.matricula);
                printf ("Nota: ");
                scanf ("%lf", &elemento.nota);

                if (insereElem(abp, elemento))
                    printf ("Inseriu com sucesso");
                else
                    printf ("Falha ao inserir.");
                break;
            case 3:
                printf ("Nome para buscar (50 caracteres): ");
                setbuf(stdin, NULL);
                fgets(elemento.nome, 50, stdin);
                setbuf(stdin, NULL);

                if (pesquisa(abp, elemento))
                    printf ("Aluno encontrado.");
                else
                    printf ("Aluno nao encontrado.");
                break;
            case 4:
                printf ("Nome para remover (50 caracteres): ");
                setbuf (stdin, NULL);
                fgets(elemento.nome, 50, stdin);
                setbuf(stdin, NULL);

                if (removeElem(abp, elemento))
                    printf ("Removeu o aluno.");
                else
                    printf ("Falha ao remover o aluno.");
                break;
            case 5:
                em_ordem(*abp, 0);
                break;
            case 6:
                auxiliar = maiorNota(*abp);
                printf ("Melhor Aluno:\n");
                printf ("Nome = %s\nMatricula = %d\nNota = %.2lf", auxiliar->nome, auxiliar->matricula, auxiliar->nota);
                break;
            case 7:
                auxiliar = menorNota(*abp);
                printf ("Pior Aluno:\n");
                printf ("Nome = %s\nMatricula = %d\nNota = %.2lf", auxiliar->nome, auxiliar->matricula, auxiliar->nota);
                break;
            case 8:
                destroiABP(abp);
                break;
            case 9:
                printf ("Saindo.");
                break;
            default:
                printf ("Opcao invalida");
                break;
        }
        printf ("\n");
    } while(opcao != 9);
}