#include <omp.h>
#include <stdio.h>

int main() {
    int sum = 0;

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int local_sum = 0;

        for (int i = 1; i <= 100; i++) {
            local_sum += i;
        }

        printf("Thread %d: local_sum = %d\n", thread_id, local_sum);

        #pragma omp barrier

        #pragma omp critical
        sum += local_sum;
        printf("Thread %d: Incrementou sum para %d\n", thread_id, sum);
    }

    printf("Resultado final: sum = %d\n", sum);

    return 0;
}
