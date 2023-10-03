#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[])
{

    float A[2048];
    float B[2048];
    float C[2048];
    {
omp_set_num_threads(128);
#pragma omp parallel for
        for (int x = 0; x < 2048; x++)
        {
            A[x] = rand() % 5000;
            B[x] = rand() % 5000;
        }
        for (int x = 0; x < 2048; x++)
        {
            C[x] = A[x] + B[x];
        }
        for (int x = 0; x < 2048; x++)
        {
            printf("C[%d] = %f\n", x, C[x]);
        }
    }
    return 0;
}