#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void bubbleSortParallel(int arr[], int n) {
    int i, j;
    #pragma omp parallel for num_threads(omp_get_max_threads()) default(none) shared(arr, n) private(i, j)
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n = 500000;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n + 1;
    }

    printf("Array desordenado:\n");

    printf("\n");

    int numThreads[] = {1, 2, 4, 8, 16};

    for (int t = 0; t < 5; t++) {
        omp_set_num_threads(numThreads[t]);

        double start_time = omp_get_wtime();

        bubbleSortParallel(arr, n);

        double end_time = omp_get_wtime();

        printf("Array ordenado com %d threads:\n", numThreads[t]);
       
        printf("\n");

        double execution_time = end_time - start_time;
        printf("Tempo de execução: %f segundos\n", execution_time);
    }

    free(arr);

    return 0;
}
