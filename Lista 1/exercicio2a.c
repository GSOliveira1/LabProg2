#include <stdio.h>
#include <stdlib.h>

void printarCrescente(int n){
    if (n <= 5){
        printf ("%d\n", n);
        printarCrescente(n+1);
    }
}

void printarDecrescente(int n){
    if (n >= 1){
        printf("%d\n", n);
        printarDecrescente(n-1);
    }
}

int main (){
    printf ("Ordem Crescente:\n");
    printarCrescente(1);
    printf ("\n");

    printf ("Ordem Decrescente:\n");
    printarDecrescente(5);
    printf ("\n");
    
    return 0;
}