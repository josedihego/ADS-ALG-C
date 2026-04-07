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

typedef struct Loja{
    char * nome;
    Produto ** produtos;
    int quantidade;
    int proxPL;
}Loja;

Loja * criar_loja(char * nome, int quantidade){
    Loja * nova_ads = malloc(sizeof(Loja));
    nova_ads->nome = nome;
    nova_ads->quantidade = quantidade;
    nova_ads->proxPL = 0;
    nova_ads->produtos = malloc(quantidade * sizeof(Produto *));
}


void adicionar_produto(Loja * loja, Produto * p){
    loja->produtos[loja->proxPL] = p;
    loja->proxPL = loja->proxPL + 1;
}

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
    printf("Preço: %.2f\n", produto->preco);
    imprimir_dimensao(produto->dimensao);
    printf("##########################\n");
}

void imprimir_produtos_loja(Loja * loja){
 //   for(int i = 0; i < loja->quantidade; i = i +1){

   // }
   int p = 0;
   while(p < loja->proxPL){
    imprimir_produto(loja->produtos[p]);
    p = p +1;
   }
}


int main(){
    Loja * loja_menor_preco = criar_loja("Menor Preço",100);
    Produto * p = novo_produto("Patinete Elétrico Novo", "PAT-XT-82", 1200);
    p->dimensao = nova_dimensao(1.5,0.60,0.10);
   adicionar_produto(loja_menor_preco,p);
    Produto * q = novo_produto("Bola de basquete", "BOL-567",45.80);
    q->dimensao = nova_dimensao(0.45,0.45,0.45);
    //loja_menor_preco->produtos[1]= q;
    adicionar_produto(loja_menor_preco,q);
    imprimir_produtos_loja(loja_menor_preco);
}