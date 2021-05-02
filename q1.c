#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<omp.h>

struct Matrix {
    long long int arr[5000][5000];
    int m;
    int n;
} *mat[5];

typedef struct Matrix Matrix;

int printArr(long long int mat[][5000], int m, int n){
    printf("%d %d\n", m, n);
    register int i=0, j=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            printf("%lld ", mat[i][j]);
        printf("\n");
    }
}

Matrix *matmult(long long int mat1[][5000], long long int mat2[][5000], int m, int n, int o){
    Matrix *result = malloc(sizeof(Matrix));
    result->m = m;
    result->n = o;
    for(register int i=0;i<m;++i){
        for(register int j=0;j<o;++j){
            result->arr[i][j] = 0;
        }
    }
    register int i, j, k =0;
    //omp_set_num_threads(4);
    #pragma omp parallel shared(result, mat1, mat2) private(i, j, k)
    {    
    #pragma omp for schedule(static)
    for(i=0;i<m;++i){
            for(k=0;k<n;++k){
        for(j=0;j<o;++j){
                result->arr[i][j] = result->arr[i][j] + mat1[i][k]*mat2[k][j];
            }
        }
    }
    }
    return result;
}

int main(){
    clock_t start, end;
    double cpu_time_used;
    int num_matrices, t;
    t=scanf("%d", &num_matrices);
    for(register int num=0; num<num_matrices;++num){
        mat[num] = malloc(sizeof(Matrix) + 1);
        t=scanf("%d %d", &mat[num]->m, &mat[num]->n);
        for(register int i=0;i<mat[num]->m;++i){
            for(register int j=0;j<mat[num]->n;++j){
                t=scanf("%lld", &mat[num]->arr[i][j]);
            }
        }
    }
    if(num_matrices<=1)
        return 0;
    start = clock();
    Matrix *final;
    for(register int i=0;i<num_matrices-1;++i){
        final = matmult(mat[i]->arr, mat[i+1]->arr, mat[i]->m, mat[i]->n, mat[i+1]->n);
        mat[i+1] = final;
    }
    //printArr(final->arr, final->m, final->n);
    end = clock();
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    //printf("\n\n\n");
    //printf("fun() took %f seconds to execute \n", time_taken);
}
