#include <omp.h>
#include <stdio.h>

int main() {
    int shared_var = 0;

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        #pragma omp atomic
        shared_var += thread_id;

        printf("Thread %d incrementou shared_var para %d\n", thread_id, shared_var);
    }

    printf("Resultado final: shared_var = %d\n", shared_var);

    return 0;
}
