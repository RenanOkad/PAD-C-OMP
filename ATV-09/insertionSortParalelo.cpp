#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void insertionSortParalelo(int arr[], int n) {
    int i, key, j;

    #pragma omp parallel for private(i, key, j) shared(arr, n)
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
   int n = 500000;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n + 1;
    }

    const int numThreads[] = {1, 2, 4, 8, 16};

    for (int t = 0; t < 5; t++) {
        int numThread = numThreads[t];

        omp_set_num_threads(numThread);

        double start_time = omp_get_wtime();

        insertionSortParalelo(arr, n);

        double end_time = omp_get_wtime();

        printf("Array ordenado com %d threads:\n", numThread);
        double execution_time = end_time - start_time;
        printf("Tempo de execução: %f segundos\n", execution_time);
    }

    free(arr);

    return 0;
}
