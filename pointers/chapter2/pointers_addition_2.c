#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *nome, *cpf;
    int idade;
} funcionario;

void imprimir_fun(funcionario f)
{
    printf("nome: %s \t", f.nome);
    printf("cpf: %s \t", f.cpf);
    printf("idade: %d \t", f.idade);
}

void imprimir_list_fun(funcionario funcionarios[], int tam)
{
    for (int i = 0; i < tam; i = i + 1)
    {
        printf("%d° funcionário\n", i + 1);
        imprimir_fun(funcionarios[i]);
        printf("%s", "\n");
    }
}

int main()
{
    funcionario f1 = {"maria", "111.111.111-11", 40};
    funcionario f2;
    f2.nome = "antonio";
    f2.cpf = "222.222.222-22";
    f2.idade = 32;

    funcionario funcionarios[2];
    funcionarios[0] = f1;
    funcionarios[1] = f2;
    size_t tam = sizeof(funcionarios) / sizeof(funcionarios[0]);
    imprimir_list_fun(funcionarios, tam);

    funcionario *outros_funcionarios = malloc(2 * sizeof(funcionario));
    funcionario f3 = {"Skywalker", "222.111.111-11", 70};
    funcionario f4 = {"Ben", "333.111.111-11", 35};
    *(outros_funcionarios + 0) = f3;
    // ou outros_funcionarios[0] = f3;
    *(outros_funcionarios + 1) = f4;
    // ou outros_funcionarios[1] = f4;

    // a linha abaixo não funciona!
    // size_t tam_outros  =  sizeof(outros_funcionarios)/sizeof(outros_funcionarios[0]);
    imprimir_list_fun(outros_funcionarios, 2);

    return EXIT_SUCCESS;
}