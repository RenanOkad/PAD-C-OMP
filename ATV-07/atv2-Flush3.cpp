#include <omp.h>
#include <stdio.h>

int main() {
    int result = 0;

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        #pragma omp flush

        result = thread_id * 2;

        printf("Thread %d: result = %d\n", thread_id, result);
    }

    return 0;
}
