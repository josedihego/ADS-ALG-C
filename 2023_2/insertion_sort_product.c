#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

// "30-08-2020" em X milisegundos
time_t text_2_time(char * text){
    struct tm tmp = {0};
    strptime(text,"%d-%m-%Y",&tmp);
    return mktime(&tmp);
}

void time_2_text(time_t * time, char * output, int size){
    struct tm * tmp = localtime(time);
    strftime(output,size, "%d-%m-%Y", tmp);
}

// X milisegundos em "30-08-2020"

typedef struct Product{
    char * name;
    float price;
    time_t due_date;
}Product;

typedef struct Supermarket{
     char * name;
    Product ** products;
}Supermarket;


int main(){
    char * date_text = "30-08-2020";
    time_t time_mili = text_2_time(date_text);
    time_mili = time_mili + (365 * 24 * 60 * 60);
    printf("antes: %s\n", date_text);
     
    char * date_text2 = malloc(11 * sizeof(char)); 
    time_2_text(&time_mili,date_text2,11);
    printf("depois: %s\n",date_text2);
    return EXIT_SUCCESS;
}