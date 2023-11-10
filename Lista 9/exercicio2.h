#ifndef EXERCICIO2_H
#define EXERCICIO2_H
#include <stdio.h>
#include <stdlib.h>

#define MAIOR(a, b) ((a > b) ? (a) : (b))

typedef struct{
    char nome[50];
    int contratacao;
    double salario;
}Funcionario;

typedef struct NO{
    int fb, alt;
    Funcionario funcionario;
    struct NO* esq;
    struct NO* dir;
}NO;
typedef struct NO* AVL;

NO* alocarNO() {
    return (NO*)malloc(sizeof(NO));
}

void liberarNO(NO* q) {
    free(q);
}

AVL* criaAVL() {
    AVL* raiz = (AVL*)malloc(sizeof(AVL));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void destroiRec(NO* no) {
    if (no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void destroiAVL(AVL** raiz) {
    if (*raiz != NULL) {
        destroiRec(**raiz);
        free(*raiz);
        *raiz = NULL;
    }
}

int estaVazia(AVL* raiz) {
    if (raiz == NULL) return 0;
    return (*raiz == NULL);
}

int altura(NO* raiz){
    if(raiz == NULL) return 0;
    if(raiz->alt > 0)
        return raiz->alt;
    else{ 
        //printf("Calculando altura do (%d)..\n", raiz->info);
        return MAIOR(altura(raiz->esq), altura(raiz->dir)) + 1;
    }
}

int FB(NO* raiz){
    if(raiz == NULL) return 0;
    printf("Calculando FB do (%d)..\n", raiz->funcionario);
    return altura(raiz->esq) - altura(raiz->dir);
}

void avl_RotDir(NO** raiz){
   printf("Rotacao Simples a DIREITA!\n");
   NO *aux;
   aux = (*raiz)->esq;
   (*raiz)->esq = aux->dir;
   aux->dir = *raiz;
   
   //Acertando alturas e FB dos NOs afetados
    (*raiz)->alt = aux->alt = -1;
    aux->alt = altura(aux); 
    (*raiz)->alt = altura(*raiz); 
    aux->fb = FB(aux); 
    (*raiz)->fb = FB(*raiz);

   *raiz = aux;
}

void avl_RotEsq(NO** raiz){
   printf("Rotacao Simples a ESQUERDA!\n");
   NO *aux;
   aux = (*raiz)->dir;
   (*raiz)->dir = aux->esq;
   aux->esq = *raiz;
   
   //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = aux->alt = -1;
    aux->alt = altura(aux); 
    (*raiz)->alt = altura(*raiz); 
    aux->fb = FB(aux); 
    (*raiz)->fb = FB(*raiz);
   
   *raiz = aux;
}


//Funcoes de Rotacao Dupla
void avl_RotEsqDir(NO** raiz){
    printf("Rotacao Dupla ESQUERDA-DIREITA!\n");
    NO *fe; //filho esquerdo
    NO *ffd; //filho filho direito
    
    fe = (*raiz)->esq;
    ffd = fe->dir;
    
    fe->dir = ffd->esq;
    ffd->esq = fe;
    
    (*raiz)->esq = ffd->dir;
    ffd->dir = *raiz;

    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = fe->alt = ffd->alt = -1;
    fe->alt = altura(fe); 
    ffd->alt = altura(ffd);
    (*raiz)->alt = altura(*raiz); 
    fe->fb = FB(fe); 
    ffd->fb = FB(ffd);
    (*raiz)->fb = FB(*raiz);

    *raiz = ffd;
}


void avl_RotDirEsq(NO** raiz){
    printf("Rotacao Dupla DIREITA-ESQUERDA!\n");
    NO* fd; //filho direito
    NO* ffe; //filho filho esquerdo

    fd = (*raiz)->dir;
    ffe = fd->esq;
    
    fd->esq = ffe->dir;
    ffe->dir = fd;
    
    (*raiz)->dir = ffe->esq;
    ffe->esq = *raiz;

    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = fd->alt = ffe->alt = -1;
    fd->alt = altura(fd); 
    ffe->alt = altura(ffe);
    (*raiz)->alt = altura(*raiz); 
    fd->fb = FB(fd);
    ffe->fb = FB(ffe);
    (*raiz)->fb = FB(*raiz);

    *raiz = ffe;
}

void avl_RotEsqDir2(NO** raiz){
    printf("Rotacao Dupla 2 ESQUERDA-DIREITA!\n");
    avl_RotEsq(&(*raiz)->esq);
    avl_RotDir(raiz);
}

void avl_RotDirEsq2(NO** raiz){
    printf("Rotacao Dupla 2 DIREITA-ESQUERDA!\n");
    avl_RotDir(&(*raiz)->dir);
    avl_RotEsq(raiz);
}


//Funcoes Auxiliares referentes a cada filho
void avl_AuxFE(NO **raiz){
   NO* fe;
   fe = (*raiz)->esq;
   if(fe->fb == +1) /* Sinais iguais e positivo*/
     avl_RotDir(raiz);
   else /* Sinais diferentes*/
     avl_RotEsqDir(raiz);
}

void avl_AuxFD(NO **raiz){
   NO* fd;
   fd = (*raiz)->dir;
   if(fd->fb == -1) /* Sinais iguais e negativos*/
     avl_RotEsq(raiz);
   else /* Sinais diferentes*/
     avl_RotDirEsq(raiz);
}

int insereRec(NO** raiz, Funcionario elemento){
    int ok;
    if (*raiz == NULL){
        NO* novo = alocarNO();
        if (novo == NULL)
            return 0;
        novo->funcionario = elemento;
        novo->fb = 0;
        novo->alt = 1;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    } else{
        if ((*raiz)->funcionario.salario == elemento.salario){
            printf ("Elemento existente.\n");
            ok = 0;
        }
        if (elemento.salario < (*raiz)->funcionario.salario){
            ok = insereRec(&(*raiz)->esq, elemento);
            if(ok){
                switch((*raiz)->fb){
                    case -1:
                        (*raiz)->fb = 0; ok = 0; break;
                    case 0:
                        (*raiz)->fb = +1; 
                        (*raiz)->alt++; 
                        break;
                    case +1:
                        avl_AuxFE(raiz); ok = 0; break;
                }
            }
        }else if(elemento.salario > (*raiz)->funcionario.salario){
            ok = insereRec(&(*raiz)->dir, elemento);
            if(ok){
                switch((*raiz)->fb){
                    case +1:
                        (*raiz)->fb = 0; ok = 0; break;
                    case 0:
                        (*raiz)->fb = -1; (*raiz)->alt++; break;
                    case -1:
                        avl_AuxFD(raiz); ok = 0; break;
                }
            }
        }
    }
    return ok;
}

int insereElem(AVL* raiz, Funcionario elemento){
    if(raiz == NULL) 
        return 0;
    return insereRec(raiz, elemento);
}

int pesquisaRec(NO** raiz, Funcionario elemento){
    if(*raiz == NULL) return 0;
    if((*raiz)->funcionario.salario == elemento.salario) return 1;
    if(elemento.salario < (*raiz)->funcionario.salario)
        return pesquisaRec(&(*raiz)->esq, elemento);
    else 
        return pesquisaRec(&(*raiz)->dir, elemento);
}

int pesquisa(AVL* raiz, Funcionario elemento){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    return pesquisaRec(raiz, elemento);
}

int removeRec(NO** raiz, Funcionario elemento){
    if(*raiz == NULL) return 0;
    int ok;
    if((*raiz)->funcionario.salario == elemento.salario){
        NO* aux;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){   //Caso 1 - NO sem filhos
            printf("Caso 1: Liberando %d..\n", (*raiz)->funcionario);
            liberarNO(*raiz);
            *raiz = NULL;
        }else if((*raiz)->esq == NULL){ //Caso 2.1 - Possui apenas uma subarvore direita
            printf("Caso 2.1: Liberando %d..\n", (*raiz)->funcionario);
            aux = *raiz;
            *raiz = (*raiz)->dir;
            liberarNO(aux);
        }else if((*raiz)->dir == NULL){ //Caso 2.2 - Possui apenas uma subarvore esquerda
            printf("Caso 2.2: Liberando %d..\n", (*raiz)->funcionario);
            aux = *raiz;
            *raiz = (*raiz)->esq;
            liberarNO(aux);
        }else{  //Caso 3 - Possui as duas subarvores (esq e dir)
            //3.1 - Substituir pelo NO com o MAIOR valor da subarvore esquerda
            //3.2 - Substituir pelo NO com o MENOR valor da subarvore direita
            printf("Caso 3: Liberando %d..\n", (*raiz)->funcionario);
            //Estrategia 3.1:
            NO* Filho = (*raiz)->esq;
            while(Filho->dir != NULL)   //Localiza o MAIOR valor da subarvore esquerda
                Filho = Filho->dir;
            (*raiz)->funcionario = Filho->funcionario;
            Filho->funcionario = elemento;
            return removeRec(&(*raiz)->esq, elemento);
        }
        return 1;
    }else if(elemento.salario < (*raiz)->funcionario.salario){
        ok = removeRec(&(*raiz)->esq, elemento); 
        if(ok){
            switch((*raiz)->fb){
                case +1:
                case 0:
                    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
                    (*raiz)->alt = -1;
                    (*raiz)->alt = altura(*raiz); 
                    (*raiz)->fb = FB(*raiz);
                    break;
                case -1:
                    avl_AuxFD(raiz); break;
            }
        }
    }
    else{ 
        ok = removeRec(&(*raiz)->dir, elemento);
        if(ok){
            switch((*raiz)->fb){
                case -1:
                case 0:
                    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
                    (*raiz)->alt = -1;
                    (*raiz)->alt = altura(*raiz); 
                    (*raiz)->fb = FB(*raiz);
                    break;
                case +1:
                    avl_AuxFE(raiz); break;
            }
        }
    }
    return ok;
}

int removeElem(AVL* raiz, Funcionario elemento){
    if(pesquisa(raiz, elemento) == 0){
        printf("Funcionario inexistente!\n");
        return 0;
    }
    return removeRec(raiz, elemento);
}

void em_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        //printf("[%d, %d, %d] ", raiz->info, raiz->fb, nivel);
        printf("[%d, %d, %d, %d] ", raiz->funcionario, raiz->fb, nivel, raiz->alt);
        em_ordem(raiz->dir, nivel+1);
    }
}

void imprime(AVL* raiz){
    if(raiz == NULL) return;
    if(estaVazia(raiz)){
        printf("Arvore Vazia!\n");
        return;
    } 
    printf("\nEm Ordem: [INFO, FB, NIVEL, altura]\n"); 
    em_ordem(*raiz, 0);
    printf("\n");
}
//Complexidade: O(n)
Funcionario* maiorSalario(NO* raiz){
    if (raiz != NULL){
        Funcionario *dir = maiorSalario(raiz->dir);
        Funcionario *esq = maiorSalario(raiz->esq);
        Funcionario* maior;

        if (dir == NULL || (esq != NULL && esq->salario > dir->salario))
            maior = dir;
        else
            maior = esq;
        
        if (maior == NULL || raiz->funcionario.salario >= maior->salario)
            return &(raiz->funcionario);
        else
            return maior;
    }
    return NULL;
}
// Complexidade: O(n).
Funcionario* menorSalario(NO* raiz){
    if (raiz != NULL){
        Funcionario *dir = maiorSalario(raiz->dir);
        Funcionario *esq = maiorSalario(raiz->esq);
        Funcionario* maior;

        if (dir == NULL || (esq != NULL && esq->salario < dir->salario))
            maior = dir;
        else
            maior = esq;
        
        if (maior == NULL || raiz->funcionario.salario <= maior->salario)
            return &(raiz->funcionario);
        else
            return maior;
    }
    return NULL;
}
#endif