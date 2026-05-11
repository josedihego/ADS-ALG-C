#include <stdio.h>
#include <stdlib.h>

typedef struct Usuario{
    char * login;
    char * nome;
    int likes;
}Usuario;

typedef struct RedeSocial{
    Usuario ** usuarios;
}RedeSocial;

int main(){
    RedeSocial * redeLoL = malloc(sizeof(RedeSocial));
    redeLoL->usuarios = malloc(100 * sizeof(Usuario *));
    Usuario * u10 = redeLoL->usuarios[10];
    Usuario * u11 = u10+1;
    int qnt_likes = (*(u11)).likes;
    int qnt_likes2 = u11->likes;
}