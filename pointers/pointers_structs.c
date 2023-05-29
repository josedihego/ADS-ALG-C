#include<stdio.h>
#include<stdlib.h>

typedef struct Funcionario{
    char * nome;
    char * CPF;
    int idade;
    float salario;
} Funcionario;

typedef struct Empresa{
    char * CNPJ;
    Funcionario ** funcionarios;
    //Funcionario * funcionarios [];
    int max;
    int atual;
} Empresa;

void adicionar_funcionario(Empresa * emp , Funcionario * fun){
    emp->funcionarios[emp->atual] =  fun;
    emp->atual = emp->atual + 1;
}


int main(){

    Empresa * emp = (Empresa *)malloc(sizeof(Empresa));
    emp->CNPJ =  "818";
    emp->max = 30;
    emp->atual = 0;
    emp->funcionarios =  (Funcionario **)(malloc( emp-> max * sizeof(Funcionario *)));
    Funcionario * f = malloc(sizeof(Funcionario));
    Funcionario * f2 = malloc(sizeof(Funcionario));
    f->nome = "Carlos";
    f2->nome = "Maria";
    adicionar_funcionario(emp,f);
    adicionar_funcionario(emp,f2);
    printf("%s\n",emp->funcionarios[0]->nome);
    printf("%s\n",emp->funcionarios[1]->nome);

    return EXIT_SUCCESS;

}
