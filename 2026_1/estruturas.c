#include <stdio.h>
#include <stdlib.h>

typedef struct  Dimensao{
    float altura;
    float profundidade;
    float largura;
}Dimensao;

typedef struct Produto{
    float preco;
    char * nome;
    char * codigo;
    Dimensao * dimensao; 
}Produto;

Produto * novo_produto(char * nome, char * codigo, float preco){
    Produto * novo = malloc(sizeof(Produto));
    novo->codigo = codigo;
    novo->nome = nome;
    novo->preco = preco;
    novo->dimensao = NULL;
    return novo;
}

Dimensao * nova_dimensao(float altura, float profundidade, float largura){
    Dimensao * nova = malloc(sizeof(Dimensao));
    nova->altura = altura;
    nova->profundidade = profundidade;
    nova->largura = largura;
    return nova;
}

void imprimir_dimensao(Dimensao * dimensao){
    printf("\t ##  Dimensões do produto ##\n");
    printf("\t %.2f m X %.2f m X %.2f\n",dimensao->altura, dimensao->profundidade, dimensao->largura);
}

void imprimir_produto(Produto * produto){
    printf("### DADOS DO PRODUTO #####\n");
    printf("Nome: %s\n", produto->nome);
    printf("Código: %s\n", produto->codigo);
    printf("Preço: %f\n", produto->preco);
    imprimir_dimensao(produto->dimensao);
    printf("##########################\n");
}


int main(){
    Produto * p = novo_produto("Patinete Elétrico Novo", "PAT-XT-82", 1200);
    p->dimensao = nova_dimensao(1.5,0.60,0.10);
    imprimir_produto(p);
}