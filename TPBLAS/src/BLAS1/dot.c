#include "../../include/mnblas.h"
#include <stdio.h>

float mncblas_sdot(const int N, const float *X, const int incX, 
                 const float *Y, const int incY)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  float dot = 0.0 ;

  #pragma omp parallel for reduction(+:dot)
    for (i = 0 ; i < N*incX ; i += incX)
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

  #pragma omp parallel for reduction(+:dot)
    for (i = 0 ; i < N*incX ; i += incX)
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
 float reel = ((complexe_float_t*)dotu)->real;
 float imaginaire = ((complexe_float_t*)dotu)->imaginary;
  
  #pragma omp parallel for reduction(+:reel) reduction(+:imaginaire)
    for (i = 0 ; i < N ; i += incX)
      {
        complexe_float_t tmp = mult_complexe_float( ((complexe_float_t*)X)[i],((complexe_float_t*)Y)[j] );
        reel -= tmp.real;
        imaginaire -= tmp.imaginary;
        j+=incY ;
      }
      ((complexe_float_t*)dotu)->real = reel;
      ((complexe_float_t*)dotu)->imaginary = imaginaire;
      
}

void  mncblas_cdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;

  float reel = ((complexe_float_t*)dotc)->real;
  float imaginaire = ((complexe_float_t*)dotc)->imaginary;

  #pragma omp parallel for reduction(+:reel) reduction(+:imaginaire)
    for (i = 0 ; i < N ; i += incX)
      {
        const complexe_float_t tmp = mult_complexe_float(((complexe_float_t*)X)[i],((complexe_float_t*)Y)[j]);
        complexe_float_t tmp2 = conjugate_complexe_float(tmp);
        reel -= tmp2.real;
        imaginaire -= tmp2.imaginary;
        j+=incY ;
      }
      ((complexe_float_t*)dotc)->real = reel;
      ((complexe_float_t*)dotc)->imaginary = imaginaire;
}

void mncblas_zdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  double reel = ((complexe_double_t*)dotu)->real;
  double imaginaire = ((complexe_double_t*)dotu)->imaginary;

  #pragma omp parallel for reduction(+:reel) reduction(+:imaginaire)
    for (i = 0 ; i < N ; i += incX)
      {
        complexe_double_t tmp = mult_complexe_double( ((complexe_double_t*)X)[i],((complexe_double_t*)Y)[j] );
        reel -= tmp.real;
        imaginaire -= tmp.imaginary;
        j+=incY ;
      }
      ((complexe_double_t*)dotu)->real = reel;
      ((complexe_double_t*)dotu)->imaginary = imaginaire;
}
  
void mncblas_zdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  
  double reel = ((complexe_double_t*)dotc)->real;
  double imaginaire = ((complexe_double_t*)dotc)->imaginary;
  
  #pragma omp parallel for reduction(+:reel) reduction(+:imaginaire)
    for (i = 0 ; i < N ; i += incX)
      {
        const complexe_double_t tmp = mult_complexe_double(((complexe_double_t*)X)[i],((complexe_double_t*)Y)[j]);
        complexe_double_t tmp2 = conjugate_complexe_double(tmp);
        reel -= tmp2.real;
        imaginaire -= tmp2.imaginary;
        j+=incY ;
      }
    ((complexe_double_t*)dotc)->real = reel;
    ((complexe_double_t*)dotc)->imaginary = imaginaire;
}




