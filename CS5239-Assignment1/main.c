//
//  main.c
//  CS5239-Assignment1
//
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


#define BILLION  1000000000L;

int main(int argc, char **argv) {
    
    struct timespec start, stop;
    double accum;
    
    if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
        perror( "clock gettime" );
        exit( EXIT_FAILURE );
    }
    
    int a[10][10], b[10][10], c[10][10], i, j, k;
    int sum = 0;
    
    printf("\nEnter First Matrix : \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("\nEnter Second Matrix: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    
    printf("The First Matrix is: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }
    
    printf("The Second Matrix is : \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %d ", b[i][j]);
        }
        printf("\n");
    }
    
    //Multiplication Logic
    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2; j++) {
            sum = 0;
            for (k = 0; k <= 2; k++) {
                sum = sum + a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
    
    printf("\nMultiplication Of Two Matrices : \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %d ", c[i][j]);
        }
        printf("\n");
    }
    
    if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
        perror( "clock gettime" );
        exit( EXIT_FAILURE );
    }
    
    accum = ( stop.tv_sec - start.tv_sec )
    + ( stop.tv_nsec - start.tv_nsec )
    / BILLION;
    printf( "%lf\n", accum );
    return( EXIT_SUCCESS );
    return (0);
}
