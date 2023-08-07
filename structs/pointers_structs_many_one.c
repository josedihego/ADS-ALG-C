#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Funcionario
{
   char * nome;
   char * CPF;
   int idade;
}Funcionario;


typedef struct Empresa
{
    char * CNPJ;
    char * nome;
   // Funcionario * funcionarios2 [30];
    Funcionario ** funcionarios;
    int tam;
    int indice;
}Empresa;

void cadastrar_funcionario(Empresa * emp, Funcionario * novo){
    emp->funcionarios[emp->indice]= novo;
    emp->indice = emp->indice + 1;
}
void cadastrar_funcionario2(Empresa * emp, char * nome){
   Funcionario * novo = (Funcionario *)malloc(sizeof(Funcionario));
   novo->nome = nome;
    emp->funcionarios[emp->indice]= novo;
    emp->indice = emp->indice + 1;
}
void remover_funcionario(Empresa * emp, char * nome){
    bool achou = false;
    int i = 0;
    while (!achou && i < emp->indice)
    {
       if(strcmp(emp->funcionarios[i]->nome, nome)==0){
             achou =  true;
             free(emp->funcionarios[i]);
             emp->funcionarios[i]=NULL;
       }
       i = i +1;
    }
    if(achou){
        for(int j= i -1 ;  j < emp->indice ; j = j +1){
            emp->funcionarios[j] = emp->funcionarios[j+1];
        }
        emp->indice = emp->indice - 1;
    }
    
}

int main(){
     Empresa * padaria_azul = (Empresa * ) malloc(sizeof(Empresa));
     padaria_azul->tam = 50;
     padaria_azul->indice = 0;
     padaria_azul->funcionarios = (Funcionario **) malloc(padaria_azul->tam * sizeof(Funcionario *));
     Funcionario * zefa = (Funcionario *)malloc(sizeof(Funcionario));
     zefa->nome = "Zefa";
     Funcionario * tonho = (Funcionario *)malloc(sizeof(Funcionario));
     tonho->nome = "Tonho";
     cadastrar_funcionario(padaria_azul,zefa);
     cadastrar_funcionario(padaria_azul,tonho);
     remover_funcionario(padaria_azul, tonho->nome);
    remover_funcionario(padaria_azul, zefa->nome);

     printf("Padaria azul emprega %d funcionarios\n", padaria_azul->indice);
     for(int i = 0; i < padaria_azul->indice; i = i +1){
        char * nome = padaria_azul->funcionarios[i]->nome;
        printf("Funcionário de n° %d, nome %s trabalha na padaria azul\n", i+1,nome);
     }
    return EXIT_SUCCESS;
}
