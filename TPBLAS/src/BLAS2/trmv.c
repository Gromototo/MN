#include "../../include/mnblas.h"
#include <stdlib.h>

void mncblas_strmv(MNCBLAS_UPLO uplo, MNCBLAS_TRANSPOSE trans, MNCBLAS_DIAG diag, int n, float* A,
int lda, float* x, int incX){
    int i; //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    int k;
    if (uplo == MNCblasUpper){ // si matrice triangulaire supérieure
        k = 0;
        for (i = 0; i<n; i++){
            for (int j = k; j<n;j++){
                float obs = x[k];
                x[k] += A[j]*x[j];
                x[k] -= obs;
            }
            k++;
        }
    }
    else {
        k = 0;
        for (i = 0; i<n;i++){
            for (int j = 0; j<k+1; j++){
                if (k == n+1) {
                    break;
                }
                x[k] = A[j]*x[j];
            }
        }
    }
    
}