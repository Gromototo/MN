#include "../../include/mnblas.h"
#include "../../include/complexe.h"

void mnblas_saxpy(const int N, const float alpha, const float *X,
                 const int incX, float *Y, const int incY)
{
    int j = 0;
    float *NewX;
    for (int i=0; i<N;i+=incX)
    {
        NewX[i] = alpha*X[i];
        Y[j] = Y[j] + NewX[i];
        j+=incY;
    }

}

void mnblas_daxpy(const int N, const double alpha, const double *X,
                 const int incX, double *Y, const int incY)
{
    int j = 0;
    double *NewX;
    for (int i=0; i<N;i+=incX)
    {
        NewX[i] = alpha*X[i];
        Y[j] = Y[j] + NewX[i];
        j+=incY;
    }
}

void mnblas_caxpy(const int N, const complexe_float_t alpha, const complexe_float_t *X,
                 const int incX, complexe_float_t *Y, const int incY)
{
    int j = 0;
    complexe_float_t *NewX;
    for (int i=0; i<N;i+=incX)
    {
        NewX[i] = mult_complexe_float(alpha,X[i]);
        Y[j] = add_complexe_float(Y[j], NewX[i]);
        j+=incY;
    }
}
void mnblas_zaxpy(const int N, const complexe_double_t alpha, const complexe_double_t *X,
                 const int incX, complexe_double_t *Y, const int incY)
{
    int j = 0;
    complexe_double_t *NewX;
    for (int i=0; i<N;i+=incX)
    {
        NewX[i] = mult_complexe_double(alpha,X[i]);
        Y[j] = add_complexe_double(Y[j], NewX[i]);
        j+=incY;
    }
}
