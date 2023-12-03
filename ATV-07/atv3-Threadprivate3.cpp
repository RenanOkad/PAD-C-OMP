#include <omp.h>
#include <stdio.h>

#define MATRIX_SIZE 4

int private_matrix[MATRIX_SIZE][MATRIX_SIZE] = {{0}};

#pragma omp threadprivate(private_matrix)

int main() {
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                private_matrix[i][j] = thread_id + i + j;
            }
        }

        printf("Thread %d: private_matrix[2][2] = %d\n", thread_id, private_matrix[2][2]);
    }

    return 0;
}
