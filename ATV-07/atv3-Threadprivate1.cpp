#include <omp.h>
#include <stdio.h>

int my_private_variable;

#pragma omp threadprivate(my_private_variable)

int main() {
    my_private_variable = 0;

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        my_private_variable = thread_id;
        printf("Thread %d: my_private_variable = %d\n", thread_id, my_private_variable);
    }

    return 0;
}
