#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel
    {
        #pragma omp for ordered
        for (int i = 0; i < 4; i++) {
            #pragma omp ordered
            printf("Thread %d: Iteração %d\n", omp_get_thread_num(), i);
        }
    }

    return 0;
}
