#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>

typedef struct Produto{
    char * nome;
    float preco;
}Produto;

typedef struct Funcionario{
    char * nome;
    char * CPF;
    float salario;
}Funcionario;

typedef struct Mesa{
    int numero;
    float divida_em_aberto;
}Mesa;

typedef struct Bar{
    char * nome;
    char * CNPJ;
    Produto ** produtos;
    Funcionario ** funcionarios;
    Mesa ** mesas;
    
}Bar;


int main(){
    //printf("tamanho de Produto é %ld\n",sizeof(Produto));
    Produto * pastel = malloc(sizeof(Produto));
    pastel->nome = malloc(10 * sizeof(char));
    printf("informe o nome do produto:");
    fgets(pastel->nome,10,stdin);
    pastel->preco = 14.10;
    


}