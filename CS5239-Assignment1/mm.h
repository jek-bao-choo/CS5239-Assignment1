//
//  mm.h
//  CS5239-Assignment1

#ifndef MM_H
#define MM_H

#include <stdlib.h>
#include <time.h>

double SIZE, NTHREADS;
double **A, **B, **C;

void init(double ***Aptr, double ***Bptr)
{
    double    **A; // Define a local pointer to keep rest of the code intact
    double    **B; // Define a local pointer to keep rest of the code intact
    
    int i, j;
    
    A = (double**)malloc(SIZE * sizeof(int *));
    for(i = 0; i < SIZE; i++)
        A[i] = malloc(SIZE * sizeof(int));
    
    B = (double**)malloc(SIZE * sizeof(int *));
    for(i = 0; i < SIZE; i++)
        B[i] = malloc(SIZE * sizeof(int));
    
    C = (double**)malloc(SIZE * sizeof(int *));
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

void mm(double **A, double **B, double **C)
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