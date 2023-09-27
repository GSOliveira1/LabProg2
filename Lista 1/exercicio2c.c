/*
Escreva uma função recursiva que retorne a soma dos números de um intervalo partindo-se sempre do maior número e terminando no menor.
Teste a função com um programa main.
*/

#include <stdio.h>

int soma(int atual, int maior, int menor)
{
    if (atual < menor)
        return 0;
    return atual + soma(atual - 1, maior, menor);
}

int main()
{
    int menor, maior;
    printf("Menor numero do intervalo:");
    scanf("%d", &menor);
    printf("Maior numero do intervalo:");
    scanf("%d", &maior);
    printf("Somatorio = %d\n", soma(maior, maior, menor));

    return 0;
}