#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{
    char nome[100];
    int matricula;
    float nota;
} Aluno;

void imprimir_infos(Aluno *alunos, int tamanho){
    float maior_nota = alunos[0].nota;
    float menor_nota = alunos[0].nota;
    int indiceMaior = 0;
    int indiceMenor = 0;

    for (int i = 0; i < tamanho; i++){
        if (alunos[i].nota > maior_nota){
            maior_nota = alunos[i].nota;
            indiceMaior = i;
        }
        if (alunos[i].nota < menor_nota){
            menor_nota = alunos[i].nota;
            indiceMenor = i;
        }
    }

    printf("Aluno com Maior Nota:\n");
    printf("Nome: %s\n", alunos[indiceMaior].nome);
    printf("Matricula: %d\n", alunos[indiceMaior].matricula);
    printf("Nota: %.2f\n", maior_nota);

    printf("Aluno com Menor Nota:\n");
    printf("Nome: %s\n", alunos[indiceMenor].nome);
    printf("Matricula: %d\n", alunos[indiceMenor].matricula);
    printf("Nota: %.2f\n", menor_nota);
}

int main(){
    int numeroAlunos;
    printf("Informe o numero de alunos: ");
    scanf("%d", &numeroAlunos);

    Aluno *alunos = malloc(numeroAlunos * sizeof(Aluno));
    for (int i = 0; i < numeroAlunos; i++){
        printf("Informe o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Informe a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);

        printf("Informe a nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota);
    }

    imprimir_infos(alunos, numeroAlunos);
    return 0;
}