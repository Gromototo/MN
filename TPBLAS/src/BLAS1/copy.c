#include "../../include/mnblas.h"

void mncblas_scopy(const int N, const float *X, const int incX, 
                 float *Y, const int incY)
{
  #pragma omp parallel for 
    for (register unsigned int i=0;i<N;i++)
    {
        Y[i*incY] = X[i*incX];
    }
}


void mncblas_dcopy(const int N, const double *X, const int incX, 
                 double *Y, const int incY)
{
  #pragma omp parallel for 
    for (register unsigned int i=0;i<N;i++)
    {
        Y[i*incY] = X[i*incX];
    }

}

void mncblas_ccopy(const int N, const complexe_float_t  *X, const int incX, 
                 complexe_float_t  *Y, const int incY)
{
  #pragma omp parallel for 
  for (register unsigned int i=0;i<N;i++)
  {
    Y[i*incY] = X[i*incX];
  }
}

void mncblas_zcopy(const int N, const complexe_double_t *X, const int incX, 
                 complexe_double_t *Y, const int incY)
{
    #pragma omp parallel for 
    for (register unsigned int i=0;i<N;i++)
      {
        Y[i*incY] = X[i*incX];
      }
}

