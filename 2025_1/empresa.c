// CRUD em uma Empresa

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct Funcionario{
    char * nome;
    char * matricula;
    char * cargo;
    bool burnout;
    float salario, vale_transporte;
}Funcionario;

typedef struct Empresa{
    char * nome, * CNPJ;// o ChatGPT nos ajudou aqui
    Funcionario * gerente;
    Funcionario ** funcionarios;
    int qnt_max_func;    
}Empresa;

Empresa * init_empresa(char *nome, char * CNPJ, int max){
    Empresa * nova = malloc(sizeof(Empresa));
    nova->nome =  nome;
    nova->CNPJ = CNPJ;
    nova->gerente = NULL;
    nova->qnt_max_func = max;
    nova->funcionarios = malloc(max * sizeof(Funcionario *));
    return nova;
}

