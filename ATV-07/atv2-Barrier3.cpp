#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        printf("Thread %d: Etapa 1\n", thread_id);

        #pragma omp barrier

        printf("Thread %d: Etapa 2\n", thread_id);
    }

    return 0;
}
