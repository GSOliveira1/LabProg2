/*
Escreva uma função recursiva que faça a multiplicação de dois números inteiros positivos de forma recursiva. 
N*M = M + M + M + . . . + M (N Vezes). 
Teste a função com um programa main.
*/

#include <stdio.h>

int multiplica_recursiva (int n, int m){
    if (n == 0){
        return 0;
    }
    return m + multiplica_recursiva (n - 1, m);
}

int main(){
    int n, m;
    printf ("Primeiro Numero: ");
    scanf ("%d", &n);
    printf ("Segundo Numero: ");
    scanf ("%d", &m);

    printf ("Resultado: %d", multiplica_recursiva (n, m));
    return 0;
}