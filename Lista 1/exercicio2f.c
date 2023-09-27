/*
Torres de Hanoi: Este problema consiste de três pinos A, B, C, (origem, trabalho e destino), e de n discos de diâmetros diferentes.
O objetivo é empilhar todos os discos no pino C, obedecendo as seguintes restrições:
    a) apenas um disco pode ser movido de cada vez e
    b) em nenhum momento um disco pode ser colocado sobre outro de tamanho menor.
Para aprimorar o conhecimento, analise, execute e entenda o seguinte algoritmo recursivo para 1, 2, 3, 4 e 5 discos.
*/

#include <stdio.h>

void hanoi_recursivo(int n, char origem, char destino, char trabalho)
{
    if (n == 1)
    {
        printf("Mover disco %d de %c para %c\n", n, origem, destino);
    }

    if (n > 1)
    {
        // Mover o n-1 disco de A para B, usando o C de trabalho.
        hanoi_recursivo(n - 1, origem, trabalho, destino);
        // Mover os discos de A para C.
        printf("Mover disco %d de %c para %c\n", n, origem, destino);
        // Mover o n-1 disco de B para C, usando o a de trabalho.
        hanoi_recursivo(n - 1, trabalho, destino, origem);
    }
}

int main()
{
    int n;
    printf("Informe o numero de discos: ");
    scanf("%d", &n);
    hanoi_recursivo(n, 'A', 'C', 'B');
    printf("\n");
    return 0;
}