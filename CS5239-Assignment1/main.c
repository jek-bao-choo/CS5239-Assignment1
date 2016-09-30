#include <stdio.h>
#include <stdint.h> /* for uint64 definition */
#include <stdlib.h>
#include <time.h>
#include "mm.h"

#define BILLION 1000000000L

int localpid(void)
{
    static int a[9] = { 0 };
    return a[0];
}

int main(int argc, char* argv[])
{
    uint64_t diff;
    struct timespec clock_mono_start, clock_mono_end, clock_cpu_start, clock_cpu_end;
    int i;
    
    /* measure monotonic time */
    clock_gettime(CLOCK_MONOTONIC, & clock_mono_start); /* mark start time */
    
    sleep(1); /* do stuff */
    
    clock_gettime(CLOCK_MONOTONIC, & clock_mono_end); /* mark the end time */
    
    mono_diff = BILLION * (clock_mono_end.tv_sec - clock_mono_start.tv_sec) + clock_mono_end.tv_nsec - clock_mono_start.tv_nsec;
    
    printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) mono_diff); /* now re-do this and measure CPU time */ /* the time spent sleeping will not count (but there is a bit of overhead */
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, & clock_cpu_start); /* mark start time */
    
    sleep(1); /* do stuff */
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, & clock_cpu_end); /* mark the end time */
    
    cpu_diff = BILLION * (clock_cpu_end.tv_sec - clock_cpu_start.tv_sec) + clock_cpu_end.tv_nsec - clock_cpu_start.tv_nsec;
    
    printf("elapsed process CPU time = %llu nanoseconds\n", (long long unsigned int) cpu_diff);
    
    if(argc != 2)
    {
        printf("Usage: %s <size_of_square_matrix>\n", argv[0]);
        exit(1);
    }
    
    SIZE = atoi(argv[1]);
    init(&A, &B);
    
    clock_t begin, end;
    double time_spent;

    begin = clock();
    
    mm(A, B, C);
    
    end = clock();

 
    
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("Wall Clock Time => Elapsed time: %.2lf seconds.\n", time_spent);
    
    for(i = 0; i < SIZE; i++)
        free((void *)A[i]);
    free((void *)A);
    
    for(i = 0; i < SIZE; i++)
        free((void *)B[i]);
    free((void *)B);
    
    for(i = 0; i < SIZE; i++)
        free((void *)C[i]);
    free((void *)C);
    
    return 0;
}