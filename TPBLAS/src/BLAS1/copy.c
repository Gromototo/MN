#include "../../include/mnblas.h"

void mncblas_scopy(const int N, const float *X, const int incX, 
                 float *Y, const int incY)
{
  register unsigned int j = 0 ;

  #pragma omp parallel for 
    for (register unsigned int i = 0 ; i < N ; i += incX)
      {

          Y [j] = X [i] ;
          j += incY;
    
        if(j>=N){
          i=N;
        }
      }
}


void mncblas_dcopy(const int N, const double *X, const int incX, 
                 double *Y, const int incY)
{
  register unsigned int j = 0 ;
  
  #pragma omp parallel for 
    for (register unsigned int i = 0 ; i < N ; i += incX)
      {
        Y [j] = X [i] ;
        j += incY;

        if (j >= N){
          i = N;
        }
      }

}

void mncblas_ccopy(const int N, const complexe_float_t  *X, const int incX, 
                 complexe_float_t  *Y, const int incY)
{

  register unsigned int j = 0 ;

  #pragma omp parallel for 
    for (register unsigned int i = 0 ; i < N ; i += incX)
      {
          Y [j].real = X [i].real;
          Y [j].imaginary = X [i].imaginary;
          j+= incY;

          if (j >= N){
          i = N;
        }
      }
}

void mncblas_zcopy(const int N, const complexe_double_t *X, const int incX, 
                 complexe_double_t *Y, const int incY)
{

    
    register unsigned int j = 0 ;

    #pragma omp parallel for 
      for (register unsigned int i = 0 ; i < N; i += incX)
      {
          Y [j].real = X [i].real;
          Y [j].imaginary = X [i].imaginary;
          j+=incY;
          if (j >= N){
          i = N;
        }
      }
}

