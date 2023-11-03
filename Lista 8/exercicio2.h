#ifndef EXERCICIO2_H
#define EXERCICIO2_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int matricula;
    double nota;
}Aluno;

typedef struct NO{
    Aluno info;
    struct NO* esq;
    struct NO* dir;
}NO;

typedef struct NO* ABP;

NO* alocarNO() {
    return (NO*)malloc(sizeof(NO));
}

void liberarNO(NO* q) {
    free(q);
}

ABP* criaABP(){
    ABP* raiz = (ABP*) malloc (sizeof(ABP));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void destroiRec(NO* no){
    if(no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void destroiABP(ABP* raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
    }
}

int estaVazia(ABP* raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}

int insereRec(NO** raiz, Aluno elem){
    if(*raiz == NULL){
        NO* novo = alocarNO();
        if(novo == NULL) return 0;
        novo->info = elem;
        novo->esq = NULL; 
        novo->dir = NULL;
        *raiz = novo;
    }else{
        int compara = strcmp((*raiz)->info.nome, elem.nome);
        if (compara == 0){
            printf ("Elemento ja existente!\n");
            return 0;
        }
        if (compara < 0)
            return insereRec(&(*raiz)->esq, elem);
        else if (compara > 0)
            return insereRec(&(*raiz)->dir, elem);
    }
    return 1;
}

int insereElem(ABP* raiz, Aluno elem){
    if (raiz == NULL)
        return 0;
    return insereRec(raiz, elem);
}

int pesquisaRec(NO** raiz, Aluno elem){
    if(*raiz == NULL) return 0;
    int compara = strcmp((*raiz)->info.nome, elem.nome);
    if(compara == 0) 
        return 1;
    else if(compara < 0)
        return pesquisaRec(&(*raiz)->esq, elem);
    else 
        return pesquisaRec(&(*raiz)->dir, elem);
}

int pesquisa(ABP* raiz, Aluno elem){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    return pesquisaRec(raiz, elem);
}

int removeRec(NO** raiz, Aluno elem){
    if(*raiz == NULL) return 0;
    int compara = strcmp((*raiz)->info.nome, elem.nome);
    if(compara == 0){
        NO* aux;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){   //Caso 1 - NO sem filhos
            printf("Caso 1: Liberando %s..\n", (*raiz)->info.nome);
            liberarNO(*raiz);
            *raiz = NULL;
        }else if((*raiz)->esq == NULL){     //Caso 2.1 - Possui apenas uma subarvore direita
            printf("Caso 2.1: Liberando %s..\n", (*raiz)->info.nome);
            aux = *raiz;
            *raiz = (*raiz)->dir;
            liberarNO(aux);
        }else if((*raiz)->dir == NULL){
            //Caso 2.2 - Possui apenas uma subarvore esquerda
            printf("Caso 2.2: Liberando %s..\n", (*raiz)->info.nome);
            aux = *raiz;
            *raiz = (*raiz)->esq;
            liberarNO(aux);
        }else{  //Caso 3 - Possui as duas subarvores (esq e dir)
            printf("Caso 3: Liberando %s..\n", (*raiz)->info.nome);
            NO* Filho = (*raiz)->esq;
            while(Filho->dir != NULL)//Localiza o MAIOR valor da subarvore esquerda
                Filho = Filho->dir;
            (*raiz)->info = Filho->info;
            Filho->info = elem;
            return removeRec(&(*raiz)->esq, elem);
        }
        return 1;
    }else if(compara < 0)
        return removeRec(&(*raiz)->esq, elem);
    else 
        return removeRec(&(*raiz)->dir, elem);
}

int removeElem(ABP* raiz, Aluno elem){
    if (pesquisa(raiz, elem) == 0){
        printf ("Elemento nao existe.\n");
        return 0;
    }
    return removeRec(raiz, elem);
}

void em_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        printf("[%s, %d] ", raiz->info.nome, nivel);
        em_ordem(raiz->dir, nivel+1);
    }
}

int tamanho(NO* raiz, int inicio){
    if (raiz == NULL)
        return 0;
    int t = 1;
    t += tamanho(raiz->esq, 0);
    t += tamanho(raiz->dir, 0);
    return t;
}

Aluno* maiorNota(NO* raiz){
    if (raiz != NULL){
        Aluno *dir = maiorNota(raiz->dir);
        Aluno *esq = maiorNota(raiz->esq);
        Aluno *maior;
        if (dir == NULL || (esq != NULL && esq->nota > dir->nota))
            maior = esq;
        else
            maior = dir;
        
        if (maior == NULL || raiz->info.nota >= maior->nota)
            return &(raiz->info);
        else
            return maior;
    }
    return NULL;
}

Aluno* menorNota(NO* raiz){
    if (raiz != NULL){
        Aluno *dir = maiorNota(raiz->dir);
        Aluno *esq = maiorNota(raiz->esq);
        Aluno *maior;
        if (dir == NULL || (esq != NULL && esq->nota < dir->nota))
            maior = esq;
        else
            maior = dir;
        
        if (maior == NULL || raiz->info.nota <= maior->nota)
            return &(raiz->info);
        else
            return maior;
    }
    return NULL;
}

#endif  //EXERCICIO2_H