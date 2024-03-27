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
          float value = 0;
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
            double value = 0;
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
const complexe_float_t *A_ = (const complexe_float_t *)A;
    const complexe_float_t *B_ = (const complexe_float_t *)B;
    complexe_float_t *C_ = (complexe_float_t *)C;

    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            // SUM alpha * (A*B)
            complexe_float_t value;
            value.imaginary = 0;
            value.real = 0;

            for (int k = 0; k < K; k++)
            {
                complexe_float_t temp = mult_complexe_float(A_[m * lda + k], B_[n + k * ldb]);
                temp = mult_complexe_float(*(const complexe_float_t *)alpha, temp);

                value.real += temp.real;
                value.imaginary += temp.imaginary;
            }

            C_[n + m * ldc] = mult_complexe_float(*(const complexe_float_t *)beta, C_[n + m * ldc]);

            C_[n + m * ldc].real += value.real;
            C_[n + m * ldc].imaginary += value.imaginary;
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