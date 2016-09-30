//
//  main.c
//  CS5239-Assignment1
//
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void allocate_mem(double*** arr, int rows, int cols);
void deallocate_mem(double*** arr, int n);
void printMatrix(double** a, int rows, int cols);
void printMatrixE(double** a, int rows, int cols);
void multMatrixp(double **A, double **B, double **C,int r1,int c1,int r2,int c2);
void init(double*** a, int rows,int cols);

int main(int argc, char* argv[])
{
    
    int ro1, co1, ro2, co2;
    double **a, **b, **c;
    
    
    
    //ro1=10;
    //co1=10000;
    //ro2=10000;
    //co2=33;
    
    ro1=atoi(argv[1]);
    co1=atoi(argv[2]);
    ro2=atoi(argv[3]);
    co2=atoi(argv[4]);
    
    
    init(&a,ro1,co1);
    init(&b,ro2,co2);
    allocate_mem(&c,ro1,co2);
    
    clock_t begin, end;
    double time_spent;
    begin = clock();
    multMatrixp(a, b, c, ro1, co1, ro2, co2);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.2lf seconds.\n", time_spent);
    
    printMatrix(a,ro1,co1);
    printMatrix(b,ro2,co2);
    printMatrixE(c,ro1,co2);
    
    
    deallocate_mem(&a,ro1);
    deallocate_mem(&b,ro2);
    deallocate_mem(&c,ro1);
    
    return 0;
}

//______________________________________________________________________________
void allocate_mem(double*** arr, int rows, int cols)
{
    int i;
    *arr = (double**)malloc(rows*sizeof(double*));
    for( i=0; i<rows; i++)
        (*arr)[i] = (double*)malloc(cols*sizeof(double));
}

//______________________________________________________________________________
void deallocate_mem(double*** arr, int rows){
    int i;
    for (i = 0; i < rows; i++)
        free((*arr)[i]);
    free(*arr);
}

//______________________________________________________________________________

void init(double*** a, int rows,int cols)
{
    int i, j;
    
    *a= (double**) malloc(rows*sizeof(double*));
    for(i=0;i<rows;i++)
        (*a)[i]=(double*)malloc(cols*sizeof(double));
    for(i=0;i<rows;i++)
        for(j=0;j<cols;j++)
            (*a)[i][j] = rand()%1000;
}


//______________________________________________________________________________
void printMatrix(double** a, int rows, int cols)
{
    int i, j;
    printf("Matrix[%d][%d]\n",rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++)
            printf("%7.1lf ",a[i][j]);
        printf("\n");
    }
    printf("\n");
}

//______________________________________________________________________________
void printMatrixE(double** a, int rows, int cols)
{
    int i, j;
    printf("Matrix[%d][%d]\n",rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++)
            printf("%9.2e ",a[i][j]);
        printf("\n");
    }
    printf("\n");
}


//______________________________________________________________________________

void multMatrixp(double **A, double **B, double **C,int ro1,int co1,int ro2,int co2)
{
    int i, j, k;
    for(i = 0; i < ro1; i++) {
        for(j = 0; j < co2; j++) {
            C[i][j] = 0;
            for(k = 0; k < co1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}