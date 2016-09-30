//
//  mm.h
//  CS5239-Assignment1

#ifndef MM_H
#define MM_H

#include <stdlib.h>
#include <time.h>

int SIZE, NTHREADS;
int **A, **B, **C;

void init(int ***Aptr, int ***Bptr)
{
    int    **A; // Define a local pointer to keep rest of the code intact
    int    **B; // Define a local pointer to keep rest of the code intact
    
    int i, j;
    
    A = (int**)malloc(SIZE * sizeof(int *));
    for(i = 0; i < SIZE; i++)
        A[i] = malloc(SIZE * sizeof(int));
    
    B = (int**)malloc(SIZE * sizeof(int *));
    for(i = 0; i < SIZE; i++)
        B[i] = malloc(SIZE * sizeof(int));
    
    C = (int**)malloc(SIZE * sizeof(int *));
    for(i = 0; i < SIZE; i++)
        C[i] = malloc(SIZE * sizeof(int));
    
    srand(time(NULL));
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            A[i][j] = rand()%100;
            B[i][j] = rand()%100;
        }
    }
    // End of function
    *Aptr = A;
    *Bptr = B;
}

void mm(int **A, int **B, int **C)
{
    int i, j, k;
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            C[i][j] = 0;   
            for(k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

#endif