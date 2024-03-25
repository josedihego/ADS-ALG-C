#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LIST_SIZE 30
#define MAX_VALUE_IN_LIST 80
#define NUM_MAX_LISTS 1000

int * generare_random_list()
{
    int size_list = (rand() % MAX_LIST_SIZE) + 1;
    int *my_list = (int *)malloc((size_list + 1) * sizeof(int));
    int i;
    int random_num;
    for (i = 0; i < size_list; i = i + 1)
    {
        random_num = (rand() % MAX_VALUE_IN_LIST) + 1;
        my_list[i] = random_num;
        //printf("%d\n", random_num);
    }
    my_list[size_list] = -1;
    return my_list;
}

int calc_size(int * list)
{
    int size = 0;
    while (list[size] != -1)
    {
        size = size + 1;
    }
    return size;
}
void generate_write_file(FILE *fp)
{
    int i;
    int *my_list = generare_random_list();
    int size_of_list = calc_size(my_list);
    char text[size_of_list * 4];
    sprintf(text, "%d", my_list[0]);
    for (i = 1; i < size_of_list; i = i + 1)
    {
        sprintf(text, "%s,%d", text, my_list[i]);
    }
    sprintf(text, "%s%s", text, "\n");
    fputs(text, fp);
}

int main()
{
    FILE *fp = fopen("lists.txt", "w");
    if (fp == NULL)
        return 1;
    int i;
    srand(time(NULL));
    for (i = 0; i < NUM_MAX_LISTS; i = i + 1)
    {
        generate_write_file(fp);
    }
}
