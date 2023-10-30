#include <omp.h>
#include <stdio.h>

int main() {
    int soma = 0;
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8};

    #pragma omp parallel for
    for (int i = 0; i < 8; i++) {
        #pragma omp critical
        {
            soma += data[i];
            printf("Thread %d adicionou %d a soma, resultando em %d\n", omp_get_thread_num(), data[i], soma);
        }
    }

    printf("Resultado final: soma = %d\n", soma);

    return 0;
}
