#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[])
{
#pragma omp parallel
    {
#pragma omp single
        {
            printf("Regiao paralela ... %d\n", omp_get_num_threads());
        }
#pragma omp for
        for (int i = 0; i < 10; i++)
        {
            printf("Thread %d - i = %d \n", omp_get_thread_num(), i);
        }
    }
    return 0;
}