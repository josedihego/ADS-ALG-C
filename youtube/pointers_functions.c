#include <stdio.h>
#include <string.h>

// Comparison function for integers
int compareInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Comparison function for strings
int compareString(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Function to find and print the largest element in an array
void printLargestElement(const void *arr, int size, size_t elementSize, int isString, int (*compareFunction)(const void *, const void *), void (*printFunction)(const void *)) {
    // Check if the array is empty
    if (size == 0) {
        printf("The array is empty.\n");
        return;
    }

    // Assume the first element is the largest
    const void *largest = arr;

    // Traverse the array to find the largest element
    for (int i = 1; i < size; ++i) {
        const void *current = (char *)arr + i * elementSize;

        if (compareFunction(current, largest) > 0) {
            largest = current;
        }
    }

    // Print the largest element using the provided print function
    printf("The largest element in the array is: ");
    printFunction(largest);
    printf("\n");
}

// Function to print an integer
void printInt(const void *ptr) {
    printf("%d", *(int *)ptr);
}

// Function to print a string
void printString(const void *ptr) {
    printf("%s", *(const char **)ptr);
}

int main() {
    // Example usage for integers
    int intArray[] = {5, 12, 3, 8, 9};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    printLargestElement(intArray, intSize, sizeof(int), 0, compareInt, printInt);

    // Example usage for strings
    const char *strArray[] = {"apple", "banana", "orange", "grape", "kiwi"};
    int strSize = sizeof(strArray) / sizeof(strArray[0]);
    printLargestElement(strArray, strSize, sizeof(char *), 1, compareString, printString);

    return 0;
}
