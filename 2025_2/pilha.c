#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Pilha{
    int * S;
    int topo;
    int tamanho;
}Pilha;

void imprimir_pilha(Pilha * pilha){
    printf("\n");
    for(int i=pilha->topo; i > -1; i = i -1){
        printf("\t🧇 %d\n",pilha->S[i]);
    }
    printf("\n");
}
Pilha * criar_pilha(int tam){
    Pilha * nova = malloc(sizeof(Pilha));
    nova->S = malloc(tam * sizeof(int));
    nova->topo = -1;
    nova->tamanho = tam;
    return nova;
}

// opção 1
bool tem_espaco(Pilha * pilha){
    if(pilha->topo == pilha->tamanho -1){
        return false;
    }
    else{
        return true;
    }
}
//opção 2
bool tem_espaco_v2(Pilha * pilha){
    return !(pilha->topo == pilha->tamanho-1);
}


void empurrar(Pilha * pilha, int x){
    if(tem_espaco(pilha)){
        pilha->topo = pilha->topo +1;// pilha->topo++;
        pilha->S[pilha->topo] = x;
    }
    else{
        printf("Sem espaço na pilha 🌝\n");
    }
}

bool esta_vazia(Pilha * pilha){
    if(pilha->topo==-1) return true;
    else return false;
}

int pocar(Pilha * pilha){
    if(!esta_vazia(pilha)){
        pilha->topo = pilha->topo-1;
        return pilha->S[pilha->topo+1];
    }
    else{
        printf("Pilha vazia! 🪹");
    }
}

int main(){
    /** 
    int tamanho_pilha =  sizeof(Pilha);
    printf("🥞 tamanho de uma pilha: %d\n", tamanho_pilha);
    */
   Pilha * pilha = criar_pilha(4);
   empurrar(pilha, 8);
   empurrar(pilha, 15);
   empurrar(pilha, 9);
   empurrar(pilha, 3);
   empurrar(pilha, 77);
   imprimir_pilha(pilha);
   pocar(pilha);
   pocar(pilha);
   pocar(pilha);
   printf("Depois de pocar\n");
   imprimir_pilha(pilha);
   pocar(pilha);
   pocar(pilha);

}