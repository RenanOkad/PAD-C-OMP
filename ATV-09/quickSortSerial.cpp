#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sys/time.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSortParalelo(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSortParalelo(arr, low, pi - 1);
        quickSortParalelo(arr, pi + 1, high);
    }
}

int main()
{
    int n = 466666;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = std::rand() % n + 1;
    }

    std::cout << "Quick Sort - Array antes da ordenacao \n";
    for (int i = 0; i < n; i++)
    {
        if (i == 11)
        {
            i = n - 10;
            std::cout << "...";
        }
        std::cout << arr[i] << " ";
    }

    struct timeval start_time, end_time;
    gettimeofday(&start_time, nullptr);

    std::cout << "\nOrdenando a lista com Quick Sort...";
    quickSortParalelo(arr, 0, n - 1);

    gettimeofday(&end_time, nullptr);
    long seconds = end_time.tv_sec - start_time.tv_sec;
    long microseconds = end_time.tv_usec - start_time.tv_usec;

    if (microseconds < 0)
    {
        seconds--;
        microseconds += 1000000;
    }

    double elapsed_time = seconds + static_cast<double>(microseconds) / 1000000.0;

    std::cout << "\nQuick Sort - Array ordenado: ";
    for (int i = 0; i < n; i++)
    {
        if (i == 11)
        {
            i = n - 10;
            std::cout << "...";
        }
        std::cout << arr[i] << " ";
    }

    printf("\nTempo de execução: %.2f segundos\n", elapsed_time);

    return 0;
}
