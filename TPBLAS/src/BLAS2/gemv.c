#include "../../include/mnblas.h"
#include <stdlib.h>

void mncblas_sgemv(const MNCBLAS_LAYOUT layout,
                 const MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const float alpha, const float *A, const int lda,
                 const float *X, const int incX, const float beta,
                 float *Y, const int incY)
                 {
                    float *newA = malloc(sizeof(float)*M*N);
                    float *new_newA = malloc(sizeof(float)*N);
                    int i;
                    for (i = 0; i<M*N; i++)
                    {
                        newA[i] = alpha*A[i];
                    }
                    int j = 0;
                    int k = 0; //indice sur lequel on travaille du tableau en sorti
                    float res = 0;
                    for(i = 0; i<N*M; i++)
                    {
                        res += newA[i]*X[j];
                        j++;
                        if (j%M == 0)
                        {
                            new_newA[k] = res;
                            k++;
                            res = 0;
                            j = 0;
                        }
                    }

                    for (int i = 0; i<M;i++)
                    {
                        Y[i] = beta * Y[i] + new_newA[i];
                    }
                 }

void mncblas_dgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const double alpha, const double *A, const int lda,
                 const double *X, const int incX, const double beta,
                 double *Y, const int incY);

void mncblas_cgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *X, const int incX, const void *beta,
                 void *Y, const int incY);

void mncblas_zgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *X, const int incX, const void *beta,
                 void *Y, const int incY);
