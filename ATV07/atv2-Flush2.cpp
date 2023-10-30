#include <omp.h>
#include <stdio.h>

int main() {
    int shared_var = 0;

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        shared_var += thread_id;

        #pragma omp flush(shared_var)

        printf("Thread %d: shared_var = %d após a atualização\n", thread_id, shared_var);
    }

    return 0;
}
