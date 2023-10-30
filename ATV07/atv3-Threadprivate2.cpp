#include <omp.h>
#include <stdio.h>

typedef struct {
    int thread_id;
    double data;
} ThreadInfo;

ThreadInfo thread_info;

#pragma omp threadprivate(thread_info)

int main() {
    thread_info.thread_id = -1;
    thread_info.data = 3.14;

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        thread_info.thread_id = thread_id;
        thread_info.data += thread_id;
        printf("Thread %d: thread_info.data = %f\n", thread_id, thread_info.data);
    }

    return 0;
}
