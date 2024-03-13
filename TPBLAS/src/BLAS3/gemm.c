#include "../../include/mnblas.h"
#include <stdio.h>


void mncblas_sgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const float alpha, const float *A,
                 const int lda, const float *B, const int ldb,
                 const float beta, float *C, const int ldc){


  for (int m = 0; m < M; m++) {
      for (int n = 0; n < N; n++) {
          // SUM alpha * (A+B)
          int value = 0;
          for (int k = 0; k < K; k++) {
              value += alpha * (A[m * K + k] * B[n + k * N]);
              //printf("value : %d, A[] : %d, B[] %d, m %d, n %d, k %d \n", value, m * K + k, k * N + n, m, n, k);
          }
          C[n + m * N] *= beta;
          C[n + m * N] += value;
      }
  }




    return;
  };

  void mncblas_dgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const double alpha, const double *A,
                 const int lda, const double *B, const int ldb,
                 const double beta, double *C, const int ldc)
  {

  for (int m = 0; m < M; m++) {
    for (int n = 0; n < N; n++) {
        // SUM alpha * (A+B)
        int value = 0;
        for (int k = 0; k < K; k++) {
            value += alpha * (A[m * K + k] * B[n + k * N]);
            //printf("value : %d, A[] : %d, B[] %d, m %d, n %d, k %d \n", value, m * K + k, k * N + n, m, n, k);
        }
        C[n + m * N] *= beta;
        C[n + m * N] += value;
    }
  }

}



void mncblas_cgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const void *alpha, const void *A,
                 const int lda, const void *B, const int ldb,
                 const void *beta, void *C, const int ldc)
{

  for (int m = 0; m < M; m++) {
    for (int n = 0; n < N; n++) {
        // SUM alpha * (A+B)
        complexe_float_t value;
        for (int k = 0; k < K; k++) {
            complexe_float_t temp =  mult_complexe_float(((complexe_float_t) A)[m * K + k], ((complexe_float_t)  B)[n + k * N]);
            temp = mult_complexe_float(*alpha, temp);

            value.real += temp.real;
            value.complexe += temp.complexe;


            //printf("value : %d, A[] : %d, B[] %d, m %d, n %d, k %d \n", value, m * K + k, k * N + n, m, n, k);
        }
        C[n + m * N]= mult_complexe_float(*((const complexe_float_t) beta), C[n + m * N]);

        C[n + m * N].real += value.real;
        C[n + m * N].imaginary += value.imaginary;

    }
  }    
}


void mncblas_zgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const void *alpha, const void *A,
                 const int lda, const void *B, const int ldb,
                 const void *beta, void *C, const int ldc)
{
  
}