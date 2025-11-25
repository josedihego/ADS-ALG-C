#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct Disciplina{
    char * nome;
    struct Aluno ** matriculados;
}Disciplina;

typedef struct Aluno{
    char * matricula;
    char * nome;
    int idade;
    Disciplina ** disciplinas;
}Aluno;


typedef struct Escola{
    Aluno ** alunos;
    int qnt_alunos;
    int prox;
}Escola;


void inserir_aluno_escola(Aluno * novo, Escola * escola){
    if(escola->prox < escola->qnt_alunos){
        escola->alunos[escola->prox] = novo;
        escola->prox = escola->prox + 1;
    }
    else{

        Aluno ** array_dobrado = malloc(2 * escola->qnt_alunos * sizeof(Aluno *));
        for(int p=0; p < escola->prox; p =p +1){
            array_dobrado[p] = escola->alunos[p];
        }
        free(escola->alunos);
        escola->alunos = array_dobrado;
        escola->qnt_alunos = escola->qnt_alunos * 2;
    }
}

bool remover_aluno_escola(Aluno * aluno, Escola * escola){
    
}