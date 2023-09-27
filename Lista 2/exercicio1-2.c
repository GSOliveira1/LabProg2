#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    int quantidade;
    float preco;
} Produto;

typedef struct{
    Produto produtos[100];
    int totalProdutos;
} CatalogoProdutos;

void criarCatalogo(CatalogoProdutos *c){
    c->totalProdutos = 0;
}

void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade){
    strcpy(c->produtos[c->totalProdutos].nome, nome);
    c->produtos[c->totalProdutos].preco = preco;
    c->produtos[c->totalProdutos].quantidade = quantidade;
    c->totalProdutos++;
}

int verificarEstoque(CatalogoProdutos *c, char *nome){
    for (int i = 0; i < c->totalProdutos; i++){
        if (strcmp(c->produtos[i].nome, nome) == 0){
            printf("Estoque de %s: %d\n", c->produtos[i].nome, c->produtos[i].quantidade);
            return c->produtos[i].quantidade;
        }
    }

    return -1;
}

void imprimirCatalogo(CatalogoProdutos *c){
    for (int i = 0; i < c->totalProdutos; i++){
        printf("%s - %.2f - %d\n", c->produtos[i].nome, c->produtos[i].preco, c->produtos[i].quantidade);
    }
}

int main(){
    CatalogoProdutos catalogo;
    criarCatalogo(&catalogo);
    
    adicionarProduto(&catalogo, "Arroz", 2.50, 10);
    adicionarProduto(&catalogo, "Feijao", 3.50, 5);
    imprimirCatalogo(&catalogo);
    verificarEstoque(&catalogo, "Arroz");
    verificarEstoque(&catalogo, "Feijao");
    
    return 0;
}