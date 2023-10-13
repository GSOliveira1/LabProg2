#include <stdio.h>
#include <stdlib.h>
//#include "fila_prioridades_simplesmente_encadeada.h"
#include "fila_prioridades_heap_binaria.h"

/*
Esse arquivo funciona tanto para o Deque Sequencial Estático, quanto para o Deque Duplamente Encadeado.
É necessário apenas importar a biblioteca que for utilizar
    - fila_prioridades_simplesmente_encadeada.h
    ou
    - fila_prioridades_heap_binaria.h
*/

int main(){
    int option, elemento, prioridade;
    FilaPrioridade* filaP = NULL;

    do{
        printf ("1- Criar Fila de Prioridades.\n");
        printf ("2- Inserir item pela prioridade.\n");
        printf ("3- Ver Inicio.\n");
        printf ("4- Remover um Item.\n");
        printf ("5- Imprimir Fila.\n");
        printf ("6- Mostrar Tamanho.\n");
        printf ("7- Destruir Fila.\n");
        printf ("8- Sair.\n");

        printf ("Opcao: ");
        scanf ("%d", &option);

        switch (option){
            case 1:
                if (filaP != NULL){
                    destroiFila(filaP);
                    printf ("Fila de Prioridades resetada!\n");
                }
                filaP = criaFila();
                break;
            case 2:
                printf ("Digite o numero que deseja enfileirar: \n");
                scanf ("%d", &elemento);
                printf ("Prioridade do Elemento: \n");
                scanf ("%d", &prioridade);
                if (inserirPrio(filaP, elemento, prioridade)){
                    printf ("Enfileirou (%d) \n", elemento);
                } else{
                    printf ("Nao foi possivel enfileirar!\n");
                }
                break;
            case 3:
                if (verInicio(filaP, &elemento, &prioridade)){
                    printf ("Inicio: %d (Prioridade: %d)\n", elemento, prioridade);
                } else{
                    printf ("Nao foi possivel ver o inicio.\n");
                }
                break;
            case 4:
                if (removeInicio(filaP)){
                    printf ("Desenfileirou o primeiro elemento.\n");
                } else {
                    printf ("Nao foi possivel desenfileirar.\n");
                }
                break;
            case 5:
                imprime(filaP);
                break;
            case 6:
                printf ("Tamanho: %d\n", tamanho(filaP));
                break;
            case 7:
                destroiFila(filaP);
                printf ("Fila destruida!\n");
                break;
            case 8:
                if (filaP != NULL)
                    destroiFila(filaP);
                printf ("Saindo.");              
                break;
            default:
                printf ("Opcao invalida! Tente de novo.\n");
        }
    } while (option != 8);
    return 0;  
}