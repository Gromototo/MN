#include "../../include/mnblas.h"
#include "../../include/complexe.h"
#include <stdio.h>

/*
float mncblas_sdot(const int N, const float *X, const int incX, 
                 const float *Y, const int incY)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  register float dot = 0.0 ;
  
  for (; ((i < N) && (j < N)) ; i += incX, j+=incY)
    {
      dot = dot + X [i] * Y [j] ;
    }

  return dot ;
}
*/

float mncblas_sdot(const int N, const float *X, const int incX, 
                 const float *Y, const int incY)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  float dot = 0.0 ;

  
  for (i = 0 ; i < N ; i += incX)
    {
      dot += X [i] * Y [j] ;
      j+=incY ;
    }

  return dot ;
}

double mncblas_ddot(const int N, const double *X, const int incX, 
                 const double *Y, const int incY)
{
 register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  float dot = 0.0 ;

  
  for (i = 0 ; i < N ; i += incX)
    {
      dot += X [i] * Y [j] ;
      j+=incY ;
    }

  return dot ;
  
}

complexe_float_t mncblas_cdotu_sub(const int N, const complexe_float_t  *X, const int incX,
                       const complexe_float_t *Y, const int incY, void *dotu)
{
 register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  complexe_float_t dot = {0.0,0.0} ;
  
  for (i = 0 ; i < N ; i += incX)
    {
      dot = sub_complexe_float(dot,mult_complexe_float(X[i],Y[j]));
      j+=incY ;
    }

  return dot ;
}

complexe_float_t  mncblas_cdotc_sub(const int N, const complexe_float_t *X, const int incX,
                       const complexe_float_t *Y, const int incY, void *dotc)
{
 register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  complexe_float_t dot = {0.0,0.0} ;
  
  for (i = 0 ; i < N ; i += incX)
    {
      dot = sub_complexe_float(dot,mult_complexe_float(conjugate_complexe_float(X[i]),Y[j]));
      j+=incY ;
    }

  return dot ;
}

complexe_double_t mncblas_zdotu_sub(const int N, const complexe_double_t *X, const int incX,
                       const complexe_double_t *Y, const int incY, void *dotu)
{
   register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  complexe_double_t dot = {0.0,0.0} ;
  
  for (i = 0 ; i < N ; i += incX)
    {
      dot = sub_complexe_double(dot,mult_complexe_double(X[i],Y[j]));
      j+=incY ;
    }

  return dot ;

}
  
complexe_double_t mncblas_zdotc_sub(const int N, const complexe_double_t *X, const int incX,
                       const complexe_double_t *Y, const int incY, void *dotc)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  complexe_double_t dot = {0.0,0.0} ;
  
  for (i = 0 ; i < N ; i += incX)
    {
      dot = sub_complexe_double(dot,mult_complexe_double(conjugate_complexe_double(X[i]),Y[j]));
      j+=incY ;
    }

  return dot ;
}




