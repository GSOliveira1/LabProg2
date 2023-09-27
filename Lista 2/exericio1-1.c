#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int numero;
    float saldo;
    char titular[20];
} ContaBancaria;

void criarConta(ContaBancaria *c, int numero, char *titular){
    c->numero = numero;
    c->saldo = 0;
    strcpy(c->titular, titular);
}

void depositar (ContaBancaria *c, double deposito){
    if (deposito < 0){
        printf("Deposito invalido\n");
    }
    if (deposito == 0){
        return;
    }
    c->saldo += deposito;
}

void sacar (ContaBancaria *c, double saque){
    if (c->saldo < saque){
        printf("Saque invalido\n");
    } else {
        c->saldo -= saque;
    }
}

double consultarSaldo(ContaBancaria *c){
    return c->saldo;
}

void imprimirInfo(ContaBancaria *c){
    printf("Titular: %s\n", c->titular);
    printf("Numero: %d\n", c->numero);
    printf("Saldo: %.2f\n", c->saldo);
}

int main(){
    ContaBancaria c;
    criarConta(&c, 123, "Gabriel");
    depositar(&c, 100);
    imprimirInfo(&c);
    sacar(&c, 50);
    imprimirInfo(&c);

    return 0;
}