#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

// "30-08-2020" em X secons
time_t text_2_time(char * text){
    struct tm tmp = {0};
    strptime(text,"%d-%m-%Y",&tmp);
    return mktime(&tmp);
}

void time_2_text(time_t * time, char * output, int size){
    struct tm * tmp = localtime(time);
    strftime(output,size, "%d-%m-%Y", tmp);
}

// X secons em "30-08-2020"

typedef struct Product{
    char * name;
    float price;
    time_t due_date;
}Product;

typedef struct Supermarket{
     char * name;
    Product ** products;
}Supermarket;

void print_product(Product * product){
    char * date = malloc(11 * sizeof(char));
    time_2_text(&product->due_date, date, 11);
    printf("Nome: %s # Preco: %.2f # Data Validade:%s\n",
    product->name, product->price, date);
}

void print_all_products(Supermarket * sup, int qnt){
    for(int i = 0; i < qnt; i = i + 1){
        print_product(sup->products[i]);
    }
}

void insertion_sort(Product ** A, int lenght)
{
    Product * key;
    for (int j = 1; j < lenght; j = j + 1)
    {
        key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i]->due_date > key->due_date)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

int main(){
    Product * farinha =  malloc(sizeof(Product));
    farinha->name = "Farinha Boa Sorte";
    farinha->price = 7.00;
    farinha->due_date = text_2_time("30-12-2023");

    Product * acucar =  malloc(sizeof(Product));
    acucar->name = "Acaucar Refinado";
    acucar->price = 3.50;
    acucar->due_date = text_2_time("10-11-2025");

    Product * feijao =  malloc(sizeof(Product));
    feijao->name = "Feijao Kicaldo";
    feijao->price = 8.50;
    feijao->due_date = text_2_time("20-05-2024");

    Supermarket * super_ifba = malloc(sizeof(Supermarket));
    super_ifba->name = "Super IFBA";
    super_ifba->products = malloc(500 * sizeof(Product *));
    super_ifba->products[0] = farinha;
    super_ifba->products[1] = acucar;
    super_ifba->products[2] = feijao;

    printf("%s\n", "Antes");
    print_all_products(super_ifba, 3);
    printf("%s\n", "Depois");
    insertion_sort(super_ifba->products,3);
    print_all_products(super_ifba, 3);


}

/**
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
*/
