#include<stdio.h>
#include<stdlib.h>

typedef struct  Produto
{
    char * codigo;
    char * nome;
    float preco;
}Produto;

typedef struct HashProduto
{
    Produto ** produtos;
    int tamanho;

}HashProduto;

int calc_chave(Produto * p ){
    int chave  = 0;
    int i = 0;
    while (p->codigo[i])
    {
        chave = chave + p->codigo[i];
        i = i +1;
    }
    return chave;
}

void init_hash(HashProduto * hash, int tamanho){
    hash->tamanho = tamanho;
    hash->produtos =  malloc(tamanho * sizeof(Produto *));
    for(int i = 0; i < tamanho; i = i +1){
       // hash->produtos[i] = NULL;
    }
}



int main(){
    Produto * p1 = malloc(sizeof(Produto));
    HashProduto * hash = malloc(sizeof(HashProduto));    
    init_hash(hash,30);
    hash->produtos[0] = p1;
    if(hash->produtos[0]==NULL) printf("%s\n","sim");
    if(hash->produtos[15]==NULL) printf("%s\n","sim");

    p1->codigo = "aAC";
    printf("%d\n", calc_chave(p1));
}