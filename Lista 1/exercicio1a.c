#include <stdio.h>
#include <stdlib.h>

int negativos(float *vet, int N)
{
    int contador = 0;
    for (int i = 0; i < N; i++)
    {
        if (vet[i] < 0)
            contador++;
    }
    return contador;
}

int main()
{
    int N;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &N);
    float *vetor;
    vetor = malloc(N * sizeof(float));

    printf("Informe os valores:");
    for (int i = 0; i < N; i++)
    {
        scanf("%f", &vetor[i]);
    }

    int resultado = negativos(vetor, N);
    printf("Quantidade de Numeros Negativos no Vetor: %d", resultado);
    return 0;
}