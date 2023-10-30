#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main(int argc, char *argv[])
{

    int n = 3, p = 5, id = 0;
    const int TAM = 5;
    int v[TAM], w[TAM], k[TAM];
#pragma omp parallel private(id) shared(n, p, v, w, k)
    {
        id = omp_get_thread_num();
        v[id] = id * (n + 1);
        w[id] = id * (p + 1);
#pragma omp flush(v)
#pragma omp for
        for (int i = 0; i < omp_get_num_threads(); i++)
        {
            k[i] = v[i] + w[i];
            printf("C[%d] = %d\n", i, k[i]);
        }
    }
    return 0;
}