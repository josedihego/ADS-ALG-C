#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX_SIZE 100

typedef struct RadomValues{
  int * array;
  int size;
}RadomValues;

RadomValues * generate_random() {
  RadomValues * randomValues  = malloc(sizeof(RadomValues));
  int size = (rand() + 1) % MAX_SIZE;
  randomValues->size = size;
  int *random_array = malloc(size * sizeof(int));
  for (int i = 0; i < size; i = i + 1) {
    random_array[i] = rand() % 50;
  } 
  randomValues->array =  random_array;
  return randomValues;
}

void print_array(RadomValues * rv) {
 for(int i=0; i < rv->size; i =  i +1){
   printf("%d,", rv->array[i]);
 }
}

int main() {
  srand(time(NULL));
  RadomValues *array = generate_random();
  print_array(array);
  free(array);
  return EXIT_SUCCESS;
}