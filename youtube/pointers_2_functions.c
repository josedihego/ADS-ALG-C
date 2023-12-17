#include <stdio.h>

// Function to calculate the sum of two numbers
int sum(int a, int b) {
    return a + b;
}

// Function to calculate the product of two numbers
int product(int a, int b) {
    return a * b;
}

// Function to calculate operation on array elements
int calculate(int arr[], int size, int (*operation)(int, int)) {
    if (size <= 0) {
        printf("Array is empty or invalid size.\n");
        return 0;
    }

    int result = arr[0];

    for (int i = 1; i < size; ++i) {
        result = operation(result, arr[i]);
    }

    return result;
}

int main() {
    int numbers[] = {2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Calculate the sum
    int sumResult = calculate(numbers, size, sum);
    printf("Sum: %d\n", sumResult);

    // Calculate the product
    int productResult = calculate(numbers, size, product);
    printf("Product: %d\n", productResult);

    return 0;
}
