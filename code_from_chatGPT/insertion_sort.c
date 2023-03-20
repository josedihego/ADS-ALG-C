#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Array antes da ordenação:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    insertionSort(arr, n);

    printf("\nArray após a ordenação:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
