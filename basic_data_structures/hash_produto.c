#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Produto{
    char * nome;
    char * codigo;
    float preco;
} Produto;

typedef struct HashTable{
  Produto ** produtos;
  int tamanho;
}HashTable;

void init_hash(HashTable * tabela, int tamanho){
    tabela->produtos = malloc(tamanho * sizeof(Produto *));
    tabela->tamanho = tamanho;
}


int gerar_chave(Produto * produto){
    int chave = 0;
    int i = 0;
    while(produto->codigo[i]){
        chave = chave + produto->codigo[i];
        i = i+1;
    }
    return chave;
}

int hash(Produto * produto, int tamanho){
    int chave = gerar_chave(produto);
    float valor = sqrt(chave * 17)+(sqrt(5)-1);
    return (int)(valor)%tamanho;
}

int main(){
    Produto * p = malloc(sizeof(Produto));
    p->codigo = "789";
    int a;
    printf("%d\n",hash(p ,50));
    return EXIT_SUCCESS;
}