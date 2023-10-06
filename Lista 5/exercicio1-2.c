#include <stdio.h>
#include <stdlib.h>
#include "fila_simplesmente_encadeada.h"

int main(){
    int option, elemento;
    Fila* fila = NULL;

    do{
        printf ("1- Criar fila.\n");
        printf ("2- Enfileirar um item.\n");
        printf ("3- Ver o inicio da fila.\n");
        printf ("4- Desenfileirar um item.\n");
        printf ("5- Imprimir a fila.\n");
        printf ("6- Destruir a fila.\n");
        printf ("7- Sair.\n");

        printf ("Opcao: ");
        scanf ("%d", &option);

        switch (option){
            case 1:
                if (fila != NULL){
                    destroiFila(fila);
                }
                fila = criaFila();
                break;
            case 2:
                printf ("Digite o numero que deseja adicionar a fila: \n");
                scanf ("%d", &elemento);
                enfileirar(fila, elemento);
                break;
            case 3:
                if (verInicio(fila, &elemento)){
                    printf ("Inicio da Fila: %d\n", elemento);
                } else {
                    printf ("Nao foi possivel ver o inicio");
                }
                break;
            case 4:
                desenfileirar(fila);
                break;
            case 5:
                imprime(fila);
                break;
            case 6:
                destroiFila(fila);
                break;
            case 7:
                if (fila != NULL){
                    printf ("Destruindo fila primeiro!\n");
                    destroiFila(fila);
                    printf ("Saindo do menu!\n");
                    break;
                }
                printf ("Saindo do menu!\n");
                break;
            default:
                printf ("Opcao invalida! Tente de novo.\n");
        }
    } while (option != 7);
    return 0;    
}