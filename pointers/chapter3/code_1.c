#include <stdio.h>
#include <stdlib.h>

float average(int * arr, int size)
{
    int sum = 0;
    printf("arr %p\n", &arr);
    printf("size %p\n", &size);
    printf("sum %p\n", &sum);

    for (size_t i = 0; i < size; i = i + 1)
    {
        sum = sum + arr[i];
    }
    return (sum * 1.0f) / size;
}

int main()
{
    int values [3] = {5, 10, 20};
    float av =  average(values,3);
    printf("average = %.2f\n",av);
    return EXIT_SUCCESS;
}