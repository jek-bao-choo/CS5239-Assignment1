#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mm.h"

int main(int argc, char* argv[])
{
    int i;
    
    if(argc != 2)
    {
        printf("Usage: %s <size_of_square_matrix>\n", argv[0]);
        exit(1);
    }
    
    SIZE = atoi(argv[1]);
    //main function invoking init
    init(&A, &B); // Pass references to A and B
    
    clock_t begin, end;
    double time_spent;
    
    begin = clock();
    
    mm(A, B, C);
    
    end = clock();
    
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("Elapsed time: %.2lf seconds.\n", time_spent);
    
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