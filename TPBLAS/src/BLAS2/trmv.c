#include "../../include/mnblas.h"
#include <stdlib.h>

void mncblas_strmv(MNCBLAS_UPLO uplo, MNCBLAS_TRANSPOSE trans, MNCBLAS_DIAG diag, int n, float* A,
int lda, float* x, int incX){
    int offset;
    if (uplo == MNCblasUpper){ // si matrice triangulaire supérieure
        offset = 0;
        float res = 0;
        for (int j = 0; j<n*n;){
            res += A[j+offset]*x[(j+offset)%n];
            j++;
            if (j%n == 0){
                x[offset]= res;
                offset++;
                res = 0;
            }
        }
    }
    else {
        offset = 0;
        float res = 0;
        for (int j = n*n-1; j>-1;){
            res += A[j-offset]*x[(j-offset)%n];
            if (j%n == 0){
                x[n-1-offset]= res;
                offset++;
                res = 0;
            }
            j--;
        }
    }
}
    
    
