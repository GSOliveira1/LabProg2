#include <stdio.h>
#include "deque_sequencial_estatico.h"
// #include "deque_duplamente_encadeado.h"
/*
Esse arquivo funciona tanto para o Deque Sequencial Estático, quanto para o Deque Duplamente Encadeado.
É necessário apenas importar a biblioteca que for utilizar
    - deque_sequencial_estatico.h
    ou
    - deque_duplamente_encadeado.h
*/

int main(){
    int option, elemento;
    Deque* deque = NULL;

    do{
        printf ("1- Criar Deque.\n");
        printf ("2- Inserir item no inicio.\n");
        printf ("3- Inserir item no fim.\n");
        printf ("4- Ver o inicio do deque.\n");
        printf ("5- Ver o fim do deque.\n");
        printf ("6- Remover item do fim.\n");
        printf ("7- Remover item do inicio.\n");
        printf ("8- Imprimir deque.\n");
        printf ("9- Destruir deque.\n");
        printf ("10- Sair.\n");

        printf ("Opcao: ");
        scanf ("%d", &option);

        switch (option){
            case 1:
                if (deque != NULL){
                    destroiDeque(deque);
                    printf ("Pilha resetada!\n");
                }
                deque = criaDeque();
                break;
            case 2:
                printf ("Digite o numero que deseja adicionar no inicio do deque: \n");
                scanf ("%d", &elemento);
                if (insereInicio(deque, elemento)){
                    printf ("Adicionou (%d) no inicio!\n", elemento);
                } else{
                    printf ("Nao foi possivel adicionar!\n");
                }
                break;
            case 3:
                printf ("Digite o numero que deseja adicionar no fim do deque: \n");
                scanf ("%d", &elemento);
                if (insereFim(deque, elemento)){
                    printf ("Adicionou (%d) no fim!\n", elemento);
                } else{
                    printf ("Nao foi possivel adicionar!\n");
                }
            case 4:
                if (verInicio(deque, &elemento)){
                    printf ("Inicio do Deque = %d\n", elemento);
                } else{
                    printf ("Nao foi possivel ver o inicio.\n");
                }
                break;
            case 5:
                if (verFim(deque, &elemento)){
                    printf ("Fim do Deque = %d\n", elemento);
                } else{
                    printf ("Nao foi possivel ver o Fim.\n");
                }
                break;
            case 6:
                removeFim(deque);
                break;
            case 7:
                removeInicio(deque);
                break;
            case 8:
                imprime(deque);              
                break;
            case 9:
                if (deque != NULL)
                    destroiDeque(deque);
                break;
            case 10:
                if (deque != NULL)
                    destroiDeque(deque);
                printf ("Saindo do menu!\n");
                break;
            default:
                printf ("Opcao invalida! Tente de novo.\n");
        }
    } while (option != 10);
    return 0;  
}