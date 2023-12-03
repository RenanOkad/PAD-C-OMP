#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define VECTOR_DIM 3

int main()
{
    int num_threads = 4;
    omp_set_num_threads(num_threads);

    double vector1[VECTOR_DIM];
    double vector2[VECTOR_DIM];

    srand(42);

    #pragma omp parallel for
    for (int i = 0; i < VECTOR_DIM; i++)
    {
        vector1[i] = (double)rand() / RAND_MAX;
        vector2[i] = (double)rand() / RAND_MAX;
    }

    double dot = 0.0;
    double mag1 = 0.0;
    double mag2 = 0.0;

    #pragma omp parallel for reduction(+ : dot, mag1, mag2)
    for (int i = 0; i < VECTOR_DIM; i++)
    {
        dot += vector1[i] * vector2[i];
        mag1 += vector1[i] * vector1[i];
        mag2 += vector2[i] * vector2[i];
    }

    mag1 = sqrt(mag1);
    mag2 = sqrt(mag2);

    double cos_theta = dot / (mag1 * mag2);
    double angle_rad = acos(cos_theta);
    double angle_deg = angle_rad * (180.0 / M_PI);

    printf("Vetor 1: (%.2f, %.2f, %.2f)\n", vector1[0], vector1[1], vector1[2]);
    printf("Vetor 2: (%.2f, %.2f, %.2f)\n", vector2[0], vector2[1], vector2[2]);
    printf("Ângulo entre os vetores: %.2f graus\n", angle_deg);

    if (angle_deg < 90.0)
    {
        printf("Tipo de ângulo: Agudo\n");
    }
    else if (angle_deg == 90.0)
    {
        printf("Tipo de ângulo: Reto\n");
    }
    else
    {
        printf("Tipo de ângulo: Obtuso\n");
    }

    return 0;
}
