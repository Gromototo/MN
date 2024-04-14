#include "mnblas.h"
#include <stdio.h>

void mnblas_saxpy(const int N, const float alpha, const float *X,
                 const int incX, float *Y, const int incY)
{
    #pragma omp parallel for 
        for (int i=0; i<N;i++)
        {
            Y[i*incY] += alpha*X[i*incX];
        }
}

void mnblas_daxpy(const int N, const double alpha, const double *X,
                 const int incX, double *Y, const int incY)
{
    #pragma omp parallel for
        for (int i=0; i<N;i++)
        {
            Y[i*incY] += alpha*X[i*incX];
        }
}

void mnblas_caxpy(const int N, const complexe_float_t alpha, const complexe_float_t *X,
                 const int incX, complexe_float_t *Y, const int incY)
{
    #pragma omp parallel for
        for (int i=0; i<N;i++)
        {
            Y[i*incY] = add_complexe_float(Y[i*incY],mult_complexe_float(alpha,X[i*incX]));

        }
}
void mnblas_zaxpy(const int N, const complexe_double_t alpha, const complexe_double_t *X,
                 const int incX, complexe_double_t *Y, const int incY)
{

    #pragma omp parallel for
        for (int i=0; i<N;i++)
        {
            Y[i*incY] = add_complexe_double(Y[i*incY],mult_complexe_double(alpha,X[i*incX]));
        }
}
