#include <omp.h>
#include <stdio.h>

int main() {
    int product = 1;
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8};

    #pragma omp parallel for
    for (int i = 0; i < 8; i++) {
        #pragma omp atomic
        product *= data[i];
        printf("Thread %d multiplicou por %d, resultando em %d\n", omp_get_thread_num(), data[i], product);
    }

    printf("Resultado final: product = %d\n", product);

    return 0;
}
