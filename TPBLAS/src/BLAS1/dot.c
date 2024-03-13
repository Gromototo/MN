#include "../../include/mnblas.h"
#include <stdio.h>

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

void mncblas_cdotu_sub(const int N, const void  *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
 register unsigned int i = 0 ;
 register unsigned int j = 0 ;
  
  for (i = 0 ; i < N ; i += incX)
    {
      complexe_float_t tmp = mult_complexe_float( ((complexe_float_t*)X)[i],((complexe_float_t*)Y)[j] );
      ((complexe_float_t*)dotu)->real += tmp.real;
      ((complexe_float_t*)dotu)->imaginary += tmp.imaginary;
      j+=incY ;
    }
}

void  mncblas_cdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
 register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  
  for (i = 0 ; i < N ; i += incX)
    {
      const complexe_float_t tmp = mult_complexe_float(((complexe_float_t*)X)[i],((complexe_float_t*)Y)[j]);
      complexe_float_t tmp2 = conjugate_complexe_float(tmp);
      ((complexe_float_t*)dotc)->real += tmp2.real;
      ((complexe_float_t*)dotc)->imaginary += tmp2.imaginary;
      j+=incY ;
    }
}

void mncblas_zdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
   register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  
  for (i = 0 ; i < N ; i += incX)
    {
      complexe_double_t tmp = mult_complexe_double( ((complexe_double_t*)X)[i],((complexe_double_t*)Y)[j] );
      ((complexe_double_t*)dotu)->real += tmp.real;
      ((complexe_double_t*)dotu)->imaginary += tmp.imaginary;
      j+=incY ;
    }
}
  
void mncblas_zdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  
  for (i = 0 ; i < N ; i += incX)
    {
      const complexe_double_t tmp = mult_complexe_double(((complexe_double_t*)X)[i],((complexe_double_t*)Y)[j]);
      complexe_double_t tmp2 = conjugate_complexe_double(tmp);
      ((complexe_double_t*)dotc)->real += tmp2.real;
      ((complexe_double_t*)dotc)->imaginary += tmp2.imaginary;
      j+=incY ;
    }
}




