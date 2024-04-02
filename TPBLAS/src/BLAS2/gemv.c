#include "../../include/mnblas.h"
#include <stdlib.h>

void mncblas_sgemv(const MNCBLAS_LAYOUT layout,
                 const MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const float alpha, const float *A, const int lda,
                 const float *X, const int incX, const float beta,
                 float *Y, const int incY)
                 {
                    float newA[M*N];
                    float new_newA[N];
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
                        if (j%N == 0)
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
                 double *Y, const int incY)
                 
                {
                double newA[M*N];
                double new_newA[N];
                int i;
                for (i = 0; i<M*N; i++)
                {
                    newA[i] = alpha*A[i];
                }
                int j = 0;
                int k = 0; //indice sur lequel on travaille du tableau en sorti
                double res = 0;
                for(i = 0; i<N*M; i++)
                {
                    res += newA[i]*X[j];
                    j++;
                    if (j%N == 0)
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
                 

void mncblas_cgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *X, const int incX, const void *beta,
                 void *Y, const int incY)
                 {
                    complexe_float_t newA[M*N]; //alpha*A
                    complexe_float_t new_newA[N];//alpha*A*x
                    
                    int i;
                    complexe_float_t* calpha = (complexe_float_t*) alpha; //must be In*alpha
                    complexe_float_t* cbeta = (complexe_float_t*) beta;   //same

                    complexe_float_t* cA = (complexe_float_t*) A;
                    complexe_float_t* cX = (complexe_float_t*) X;
                    complexe_float_t* cY = (complexe_float_t*) Y;


                    for (i = 0; i<M*N; i++)
                    {
                        newA[i] = mult_complexe_float(calpha[0],cA[i]);
                    }

                    int j = 0;
                    int k = 0; //indice sur lequel on travaille du tableau en sorti
                    complexe_float_t res;
                    res.real= 0;
                    res.imaginary = 0.0;
                    for(i = 0; i<N*M; i++)
                    {
                        res = add_complexe_float(res,mult_complexe_float(newA[i], cX[j])) ;
                        j++;
                        if (j%N == 0)
                        {
                            new_newA[k] = res;
                            k++;
                            res.real=0.0;
                            res.imaginary = 0.0;
                            j = 0;
                        }
                    }
 
                    for (int i = 0; i<M;i++)
                    {
                        cY[i] = add_complexe_float(new_newA[i], mult_complexe_float(cbeta[0],cY[i]));
                    }

                 }

void mncblas_zgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *X, const int incX, const void *beta,
                 void *Y, const int incY)
                 {
                    complexe_double_t newA[M*N]; //alpha*A
                    complexe_double_t new_newA[N];//alpha*A*x
                    
                    int i;
                    complexe_double_t* calpha = (complexe_double_t*) alpha; //must be In*alpha
                    complexe_double_t* cbeta = (complexe_double_t*) beta;   //same

                    complexe_double_t* cA = (complexe_double_t*) A;
                    complexe_double_t* cX = (complexe_double_t*) X;
                    complexe_double_t* cY = (complexe_double_t*) Y;


                    for (i = 0; i<M*N; i++)
                    {
                        newA[i] = mult_complexe_double(calpha[0],cA[i]);
                    }

                    int j = 0;
                    int k = 0; //indice sur lequel on travaille du tableau en sorti
                    complexe_double_t res;
                    res.real= 0;
                    res.imaginary = 0.0;
                    for(i = 0; i<N*M; i++)
                    {
                        res = add_complexe_double(res,mult_complexe_double(newA[i], cX[j])) ;
                        j++;
                        if (j%N == 0)
                        {
                            new_newA[k] = res;
                            k++;
                            res.real=0.0;
                            res.imaginary = 0.0;
                            j = 0;
                        }
                    }

                    for (int i = 0; i<M;i++)
                    {
                        cY[i] = add_complexe_double(new_newA[i], mult_complexe_double(cbeta[0],cY[i]));
                    }

                 }