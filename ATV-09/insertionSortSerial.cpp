#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
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
    const int size = 500000;

    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000000;
    }

    clock_t start_time = clock();

    insertionSort(arr, size);

    clock_t end_time = clock();

    printf("Tempo de execução para ordenar: %f segundos\n", (double) (end_time - start_time) / CLOCKS_PER_SEC);

    free(arr);

    return 0;
}
