#include <stdio.h>

/*
Desenvolva um TAD que represente um Cubo.
Inclua as funções de inicializações necessárias e as operações que retornam os tamanhos de cada lado, a sua área e o seu volume.
*/

typedef struct{
    double lado;
} Cubo;

double calcularAreaCubo(Cubo *cubo){
    return cubo->lado * cubo->lado;    
}

double calcularVolumeCubo(Cubo *cubo){
    return cubo->lado * cubo->lado * cubo->lado;
}

double tamanhoLadosCubo(Cubo *cubo){
    return cubo->lado;
}

int main(){
    Cubo cubo;
    cubo.lado = 5.0;

    printf ("Tamanho dos Lados do Cubo: %.2f\n", tamanhoLadosCubo(&cubo));
    printf ("Area do Cubo: %.2f\n", calcularAreaCubo(&cubo));
    printf ("Volume do Cubo: %.2f\n", calcularVolumeCubo(&cubo));

    return 0;
}