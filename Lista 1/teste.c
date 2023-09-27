#include <stdio.h>

int main()
{
    int x = 3;
    int y = 4;
    float z = 1.5;
    z = z + (float)(x / y);
    printf("%f", z);
    return 0;
}