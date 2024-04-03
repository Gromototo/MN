#include "../../include/mnblas.h"
#include <stdlib.h>

void mncblas_strmv(MNCBLAS_UPLO uplo, MNCBLAS_TRANSPOSE trans, MNCBLAS_DIAG diag, int n, float* A,
int lda, float* x, int incX){
    int i; //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    int offset;
    int j = 0;
    float currentx[n];
    if (uplo == MNCblasUpper){ // si matrice triangulaire supérieure
        offset = 0;
        float res = 0;
        for (i = 0; i<n*n; i++){
            res += A[i+offset]*x[j];
            j++;
            if (j%n == 0){
                currentx[offset]= res;
                offset++;
                res = 0;
                j = offset;
            }
        }
        for (i = 0; i<n; i++){
            x[i] = currentx[i];
        }
    }
    else {
        int aug = n-1;
       offset = 0;
        float res = 0;
        for (i = 0; i<n*n; i++){
            res += A[i+offset]*x[j];
            j++;
            if (j%(offset+1) == 0){
                currentx[offset] = res;
                offset+=aug;
                aug--;
                res = 0;
                j = 0;
            }
        }
        
    }
    
}