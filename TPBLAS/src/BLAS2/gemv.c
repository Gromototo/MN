#include "mnblas.h"
#include <stdlib.h>
#include <stdio.h>

void mncblas_sgemv(const MNCBLAS_LAYOUT layout,
                 const MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const float alpha, const float *A, const int lda,
                 const float *X, const int incX, const float beta,
                 float *Y, const int incY)
                 {
                    int i,j;
                    #pragma omp parallel for
                    for (i = 0; i<M; i++){
                        Y[i] *= beta;
                        for (j = 0; j<N; j++){
                            Y[i] += alpha*A[i*N+j]*X[j];
                        }
                    }
                 }
                 

void mncblas_dgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const double alpha, const double *A, const int lda,
                 const double *X, const int incX, const double beta,
                 double *Y, const int incY)
                {
                int i,j;
                    #pragma omp parallel for
                    for (i = 0; i<M; i++){
                        Y[i] *= beta;
                        for (j = 0; j<N; j++){
                            Y[i] += alpha*A[i*N+j]*X[j];
                        }
                    }
                }
                 

void mncblas_cgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *X, const int incX, const void *beta,
                 void *Y, const int incY)
                 {
                  complexe_float_t* cY = (complexe_float_t*) Y;
                  complexe_float_t* cX = (complexe_float_t*) X;
                  complexe_float_t* cA = (complexe_float_t*) A;
                  complexe_float_t* calpha = (complexe_float_t*) alpha;
                  complexe_float_t* cbeta = (complexe_float_t*) beta;

                    #pragma omp parallel for
                    for (int i = 0; i<M; i++){
                        cY[i] = mult_complexe_float(cY[i], cbeta[0]);
                        for (int j = 0; j<N; j++){
                            cY[i] = add_complexe_float(cY[i],mult_complexe_float(mult_complexe_float(calpha[0],cA[i*N+j]),cX[j]));
                        }
                    }
                 }

void mncblas_zgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *X, const int incX, const void *beta,
                 void *Y, const int incY)
                 {
                  
                  complexe_double_t* cY = (complexe_double_t*) Y;
                  complexe_double_t* cX = (complexe_double_t*) X;
                  complexe_double_t* cA = (complexe_double_t*) A;
                  complexe_double_t* calpha = (complexe_double_t*) alpha;
                  complexe_double_t* cbeta = (complexe_double_t*) beta;

                    #pragma omp parallel for
                    for (int i = 0; i<M; i++){
                        cY[i] = mult_complexe_double(cY[i], cbeta[0]);
                        for (int j = 0; j<N; j++){
                            cY[i] = add_complexe_double(cY[i],mult_complexe_double(mult_complexe_double(calpha[0],cA[i*N+j]),cX[j]));
                        }
                    }
                 }  