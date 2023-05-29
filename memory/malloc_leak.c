#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
  char * chunk;
  // não deixe rodar por muito tempo, ok?
  while (true)
  {
    chunk =  (char *)malloc(100000 * sizeof(char));
    printf("%s","Alocando\n");
  }
    return EXIT_SUCCESS;

}