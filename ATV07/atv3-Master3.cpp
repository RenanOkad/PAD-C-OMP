#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        #pragma omp master
        {
            printf("Thread %d: Executando uma operação de depuração\n", thread_id);
        }
    }

    return 0;
}
