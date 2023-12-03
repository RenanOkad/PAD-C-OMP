#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        #pragma omp for ordered
        for (int i = 0; i < 4; i++) {
            int result = thread_id + i;
            #pragma omp ordered
            printf("Thread %d: Iteração %d, Resultado = %d\n", thread_id, i, result);
        }
    }

    return 0;
}
