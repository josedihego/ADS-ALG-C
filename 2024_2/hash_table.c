#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define A 0.618033
#define HASH_SIZE 200
#define PRIME 113

int h(char * name){
    int i =0;
    int sum = 0;
    char c;
    int l_v;
    
    while(name[i]!='\0'){
        c = name[i];
        l_v = c;
        sum = sum + l_v;
        //printf("%c = %d\n",c, c_v);
        i = i + 1;
    }
    return ((int)((sum * A))) % HASH_SIZE;

}

int main(){
    char * name = "Dom Pedro II";
    int position = h(name);
    printf("Posição de armazenamento é: %d\n", position);
}

