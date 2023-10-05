#include <stdio.h>
#include "pilha_sequencial_estatica.h"

int main(){
    int option, elemento;
    Pilha* pilha = NULL;

    do{
        printf ("1- Criar pilha.\n");
        printf ("2- Empilhar um item.\n");
        printf ("3- Ver o topo da pilha.\n");
        printf ("4- Desempilhar um item.\n");
        printf ("5- Imprimir a pilha.\n");
        printf ("6- Destruir a pilha.\n");
        printf ("7- Sair.\n");

        printf ("Opcao: ");
        scanf ("%d", &option);

        switch (option){
            case 1:
                if (pilha != NULL){
                    destroiPilha(pilha);
                    printf ("Pilha resetada!\n");
                }
                pilha = criaPilha();
                break;
            case 2:
                printf ("Digite o numero que deseja adicionar a pilha: \n");
                scanf ("%d", &elemento);
                if (empilhar(pilha, elemento)){
                    printf ("Empilhou (%d)\n", elemento);
                } else{
                    printf ("Nao foi possivel empilhar!\n");
                }
                break;
            case 3:
                if (verTopo(pilha, &elemento)){
                    printf ("Topo da Pilha = %d\n", elemento);
                } else{
                    printf ("Nao foi possivel ver o topo.\n");
                }
                break;
            case 4:
                desempilhar(pilha);
                break;
            case 5:
                imprime(pilha);              
                break;
            case 6:
                if (pilha != NULL)
                    destroiPilha(pilha);
                break;
            case 7:
                if (pilha != NULL)
                    destroiPilha(pilha);
                printf ("Saindo do menu!\n");
                break;
            default:
                printf ("Opcao invalida! Tente de novo.\n");
        }
    } while (option != 7);
    return 0;    
}