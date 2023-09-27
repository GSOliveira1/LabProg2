#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int raizes(float A, float B, float C, float *X1, float *X2)
{
    float delta = pow(B, 2) - 4 * A * C;

    if (delta < 0)
        return 0;
    if (delta == 0)
    {
        *X1 = -B / (2 * A);
        return 1;
    }

    *X1 = (-B + sqrt(delta)) / (2 * A);
    *X2 = (-B - sqrt(delta)) / (2 * A);

    return 2;
}

int main()
{
    float a, b, c, x1, x2;
    printf("Informe os coeficientes do polinomio: ");
    scanf("%f %f %f", &a, &b, &c);

    switch (raizes(a, b, c, &x1, &x2))
    {
    case 1:
        printf("Uma raiz real\n");
        printf("X1 = %.2f\n", x1);
        break;
    case 2:
        printf("Duas raizes reais\n");
        printf("X1 = %.2f\nX2 = %.2f\n", x1, x2);
        break;
    default:
        printf("Nenhuma raiz real\n");
        break;
    }

    printf("\n");

    return 0;
}