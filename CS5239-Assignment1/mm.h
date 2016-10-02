//
//  mm.h
//  CS5239-Assignment1

#ifndef MM_H
#define MM_H

#include <stdlib.h>
#include <time.h>

float SIZE, NTHREADS;
float **A, **B, **C;

void init(float ***Aptr, float ***Bptr)
{
    float    **A; // Define a local pointer to keep rest of the code intact
    float    **B; // Define a local pointer to keep rest of the code intact
    
    int i, j;
    
    A = (float**)malloc(SIZE * sizeof(float *));
    for(i = 0; i < SIZE; i++)
        A[i] = malloc(SIZE * sizeof(float));
    
    B = (float**)malloc(SIZE * sizeof(float *));
    for(i = 0; i < SIZE; i++)
        B[i] = malloc(SIZE * sizeof(float));
    
    C = (float**)malloc(SIZE * sizeof(float *));
    for(i = 0; i < SIZE; i++)
        C[i] = malloc(SIZE * sizeof(float));
    
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

void mm(float **A, float **B, float **C)
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