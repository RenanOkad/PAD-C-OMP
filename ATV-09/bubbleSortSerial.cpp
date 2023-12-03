#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int n = 500000;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n + 1;
    }

    printf("Bubble Sort Serial - Array antes da ordenacao ");
    for (int i = 0; i < n; i++)
    {
        if (i == 11)
        {
            i = n - 10;
            printf("...");
        }
        printf("%d ", arr[i]);
    }

    double start_time = omp_get_wtime();

    printf("\nOrdenando a lista com BubbleSort...");
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    double end_time = omp_get_wtime();
    double elapsed_time = end_time - start_time;

    printf("\nBubble Sort Serial - Array ordenado: ");
    for (int i = 0; i < n; i++)
    {
        if (i == 11)
        {
            i = n - 10;
            printf("...");
        }
        printf("%d ", arr[i]);
    }

    printf("\nTempo de execução: %.6f segundos\n", elapsed_time);

    return 0;
}
