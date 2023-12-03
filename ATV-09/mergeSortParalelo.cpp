#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void merge(int* array, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* leftArray = (int*)malloc(n1 * sizeof(int));
    int* rightArray = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = array[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;
    
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    free(leftArray);
    free(rightArray);
}

void mergeSort(int* array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            {
                mergeSort(array, left, middle);
            }

            #pragma omp section
            {
                mergeSort(array, middle + 1, right);
            }
        }

        merge(array, left, middle, right);
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

    for (int i = 0; i < 5; i++) {
        int numThread = numThreads[i];

        omp_set_num_threads(numThread);

        double start_time = omp_get_wtime();

        mergeSort(arr, 0, n - 1);

        double end_time = omp_get_wtime();

        double execution_time = end_time - start_time;
        printf("Threads: %d, Tempo de execução: %f segundos\n", numThread, execution_time);
    }

    free(arr);

    return 0;
}
