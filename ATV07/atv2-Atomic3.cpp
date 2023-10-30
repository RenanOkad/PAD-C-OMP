#include <omp.h>
#include <stdio.h>

int main() {
    int counter = 0;

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        #pragma omp atomic
        counter++;
        printf("Thread %d incrementou o contador para %d\n", thread_id, counter);
    }

    printf("Resultado final: contador = %d\n", counter);

    return 0;
}
