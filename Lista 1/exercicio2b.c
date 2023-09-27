#include <stdio.h>
#include <string.h>

void imprimir_decrescente(char *vetor, int tamanho)
{
    if (tamanho > 0)
    {
        printf("%c\n", vetor[tamanho - 1]);
        imprimir_decrescente(vetor, tamanho - 1);
    }
}

int main()
{
    imprimir_decrescente("ABCDE", 7);
    return 0;
}