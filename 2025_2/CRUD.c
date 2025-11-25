#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

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

Aluno * buscar_aluno_escola(Aluno * aluno, Escola * escola){
    bool achei = false;
    int p = 0;
    while(!achei && p < escola->prox){
        if(strcmp(aluno->matricula,escola->alunos[p]->matricula)==0){
            achei = true;
        }
    }
    if(achei) return escola->alunos[p];
    else return NULL;

}

int buscar_posicao_aluno_escola(Aluno * aluno, Escola * escola){
    bool achei = false;
    int p = 0;
    while(!achei && p < escola->prox){
        if(strcmp(aluno->matricula,escola->alunos[p]->matricula)==0){
            achei = true;
        }
    }
    if(achei) return p;
    else return -1;

}

bool remover_aluno_escola(Aluno * aluno, Escola * escola){
    int posicao = buscar_posicao_aluno_escola(aluno,escola);
    if(posicao != -1){
        free(escola->alunos[posicao]);
        escola->alunos[posicao] = escola->alunos[escola->prox-1];
        escola->prox = escola->prox-1;
        return true;
    }
    else{
        return false;
    }
}

bool atualizar_aluno_escola(Aluno * antigo, Aluno * novo, Escola * escola){
    if(remover_aluno_escola(antigo,escola)){
        inserir_aluno_escola(novo,escola);
    }
}


int main(){
    Escola * escola = malloc(sizeof(Escola));
    escola->qnt_alunos = 1000;
    escola->alunos = 
        malloc(escola->qnt_alunos * sizeof(Aluno *));
    escola->prox = 0;
    Aluno * julio = malloc(sizeof(Aluno));
    julio->matricula = "202.5345";
    julio->idade = 19;
    julio->nome = "Júlio";
    inserir_aluno_escola(julio,escola);

}
