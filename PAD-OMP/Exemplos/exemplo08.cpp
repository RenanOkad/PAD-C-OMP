#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    printf("\n Serial \n\n");
    omp_set_num_threads(128);
#pragma omp parallel
    {
#pragma omp sections
        {
#pragma omp section
            printf("Teste %d\n", omp_get_thread_num());
#pragma omp section
            printf("Teste %d\n", omp_get_thread_num());
        }
    }
    printf("\n Serial \n\n");
    return 0;
}