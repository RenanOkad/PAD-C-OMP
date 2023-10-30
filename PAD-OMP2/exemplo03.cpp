#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main(int argc, char *argv[])
{

    int id = 0;

#pragma omp parallel private(id)
    {
        id = omp_get_thread_num();
        if (id < omp_get_num_threads() / 2)
            system("sleep");
        printf("id:%d - (antes)\n", id);
#pragma omp barrier
        printf("id:%d - (depois)\n", id);
    }
    return 0;
}