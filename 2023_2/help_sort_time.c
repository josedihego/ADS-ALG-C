#include <time.h>
#include <stdio.h>
#include <stdlib.h>

time_t text_2_time(char *text)
{
    struct tm tmp = {0};
    strptime(text, "%d-%m-%Y", &tmp);
    return mktime(&tmp);
}

void time_2_text(time_t *time, char *output, int size)
{
    struct tm *tmp = localtime(time);
    strftime(output, size, "%d-%m-%Y", tmp);
}

typedef struct Product
{
    char *name;
    float price;
    time_t due_date;
} Product;

typedef struct Supermarket
{
    Product **products;
} Supermarket;

void print_product(Product *prod)
{
    printf("%s", "Product:");
    printf("\t%s", prod->name);
    printf("\t%.2f", prod->price);
    char *output = malloc(20 * sizeof(char));
    time_2_text(&prod->due_date, output, 20);
    printf("\t%s\n", output);
}

void print_products(Product **products, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        print_product(products[i]);
    }
}

void insertion_sort(Product **A, int lenght)
{
    Product *key;
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

int main()
{
    Product *p1 = malloc(sizeof(Product));
    p1->name = "Queijo";
    p1->price = 5.67;
    p1->due_date = text_2_time("25-10-2025");
    // print_product(p1);

    Product *p2 = malloc(sizeof(Product));
    p2->name = "Farinha";
    p2->price = 9.25;
    p2->due_date = text_2_time("26-10-2025");
    // print_product(p2);

    Product *p3 = malloc(sizeof(Product));
    p3->name = "Mel";
    p3->price = 8.25;
    p3->due_date = text_2_time("15-11-2030");
    // print_product(p3);

    Supermarket *sp = malloc(sizeof(Supermarket));
    sp->products = malloc(30 * sizeof(Product *));
    sp->products[0] = p3;
    sp->products[1] = p2;
    sp->products[2] = p1;

    printf("%s\n", "Antes");
    print_products(sp->products, 3);

    insertion_sort(sp->products, 3);

    printf("%s\n", "Depois");
    print_products(sp->products, 3);

    return EXIT_SUCCESS;
}
