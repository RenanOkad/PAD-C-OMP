#include <omp.h>
#include <stdio.h>

int shared_resource = 0;

int main() {
    #pragma omp parallel
    {
        #pragma omp master
        {
            shared_resource = 42;
        }
        printf("Thread %d: shared_resource = %d\n", omp_get_thread_num(), shared_resource);
    }

    return 0;
}
