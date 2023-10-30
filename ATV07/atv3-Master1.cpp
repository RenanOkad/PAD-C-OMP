#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        #pragma omp master
        {
            printf("Apenas a thread mestre (Thread 0) executa esta mensagem\n");
        }

        printf("Thread %d: Esta mensagem é impressa por todas as threads\n", thread_id);
    }

    return 0;
}
