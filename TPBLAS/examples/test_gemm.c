#include "mnblas.h"
#include "flop.h"
#include <stdio.h>
#include <assert.h>

#define MATSIZE    256
#define NB_FOIS    10

typedef float mfloat [MATSIZE*MATSIZE] ;
typedef double mdouble [MATSIZE*MATSIZE] ;
typedef complexe_float_t mcfloat [MATSIZE*MATSIZE] ;
typedef complexe_double_t mcdouble [MATSIZE*MATSIZE] ;

mfloat Af,Bf,Cf;
mdouble Ad,Bd,Cd;
mcfloat Acf,Bcf,Ccf;
mcdouble Acd,Bcd,Ccd;


void matrix_init (mfloat M, float x)
{
  register unsigned int i ;

  for (i = 0; i < MATSIZE*MATSIZE; i++)
    M [i] = x ;

  return ;
}

void matrix_initd (mdouble M, double x)
{
  register unsigned int i ;

  for (i = 0; i < MATSIZE*MATSIZE; i++)
    M [i] = x ;
  return ;
}

void matrix_initcf (mcfloat M, complexe_float_t x)
{
  register unsigned int i ;

  for (i = 0; i < MATSIZE*MATSIZE; i++){
    M [i].real = x.real ;
    M[i].imaginary = x.imaginary;
  }
  return ;
}

void matrix_initcd (mcdouble M, complexe_double_t x)
{
  register unsigned int i ;

  for (i = 0; i < MATSIZE*MATSIZE; i++){
    M [i].real = x.real ;
    M[i].imaginary = x.imaginary;
  }
  return ;
}


void test1(){

  const float A[6] = {1, 2, 5, 3, 4, 6};
  const float B[6] = {5, 6, 7, 8, 9, 10};

  float C[4] = {9, 10, 11, 12};

  const float alpha = 2;
  const float beta = 3;

  const int M = 2;
  const int K = 3;
  const int N = 2;

  mncblas_sgemm( 0,  0,
                  0, M, N,
                 K,  alpha, A,
                 0, B, 0,
                 beta,  C, 0);


  const float R[4] = {155, 174, 227, 256};
  for (int i = 0; i < 4; i++) {
    assert(C[i] == R[i]);
    //printf("%f ", C[i]);
  }

  printf("\ntest1 passed\n");
  return;
}

void test2(){

  const double A[6] = {1, 2, 5, 3, 4, 6};
  const double B[6] = {5, 6, 7, 8, 9, 10};

  double C[4] = {9, 10, 11, 12};

  const double alpha = 2;
  const double beta = 3;

  const int M = 2;
  const int K = 3;
  const int N = 2;

  mncblas_dgemm( 0,  0,
                  0, M, N,
                 K,  alpha, A,
                 0, B, 0,
                 beta,  C, 0);


  const double R[4] = {155, 174, 227, 256};
  for (int i = 0; i < 4; i++) {
    printf("%lf %lf \n", C[i], R[i]);
    assert(C[i] == R[i]);
  }

    printf("test2 passed\n");

  return;
}




void test3(){

  const complexe_float_t A[6] = {{-3.0f, 4.0f}, {3.0f, 6.0f}, {-18.0f, 9.0f}, {1.0f, 2.0f}, {5.0f, 0.0f}, {-3.0f, 14.0f}};
  const complexe_float_t B[4] = {{3.0, 1.0}, {3.0, 1.0}, {1.0, 4.0}, {1.0, 4.0}};

  complexe_float_t C[6] = {{1,1}, {1,1}, {1,1}, {1,1},{1,1},{1,1}};

  const complexe_float_t alpha = {1.0f, 0.0f};
  const complexe_float_t beta = {1.0f, 0.0f};

  const int M = 3;
  const int K = 2;
  const int N = 2;

  mncblas_cgemm(0, 0, 0, M, N,K, &alpha,  A,
                 0, B, 0,&beta, C, 0);

  complexe_float_t R[6] = {{-33.0, 28.0}, {-33.0, 28.0}, {-69.0, 16.0}, {-69.0, 16.0},{-63,18},{-63,18}};
  for (int i = 0; i < 4; i++) {
    printf("%f %f %f %f \n",C[i].real, C[i].imaginary, R[i].real, R[i].imaginary);
    assert(C[i].real == R[i].real);
    assert(C[i].imaginary == R[i].imaginary);
  }
  printf("test3 passed\n");

  return;
}


void test4(){
    const complexe_double_t A[6] = {{-3.0f, 4.0f}, {3.0f, 6.0f}, {-18.0f, 9.0f}, {1.0f, 2.0f}, {5.0f, 0.0f}, {-3.0f, 14.0f}};
  const complexe_double_t B[4] = {{3.0, 1.0}, {3.0, 1.0}, {1.0, 4.0}, {1.0, 4.0}};

  complexe_double_t C[6] = {{1,1}, {1,1}, {1,1}, {1,1},{1,1},{1,1}};

  const complexe_double_t alpha = {1.0f, 0.0f};
  const complexe_double_t beta = {1.0f, 0.0f};

  const int M = 3;
  const int K = 2;
  const int N = 2;

  mncblas_zgemm(0, 0, 0, M, N,K, &alpha,  A,
                 0, B, 0,&beta, C, 0);

  complexe_double_t R[6] = {{-33.0, 28.0}, {-33.0, 28.0}, {-69.0, 16.0}, {-69.0, 16.0},{-63,18},{-63,18}}; //calculée à la main
  for (int i = 0; i < 4; i++) {
    printf("%f %f %f %f \n",C[i].real, C[i].imaginary, R[i].real, R[i].imaginary);
    assert(C[i].real == R[i].real);
    assert(C[i].imaginary == R[i].imaginary);
  }
  printf("test4 passed\n");

  return;
}
int main(){

 /* test1();
  test2();
  test3();
  test4();
  printf("\nGEMM TESTS PASSED\n");*/

      struct timespec start, end ;
     int i ;
    //float measure
    
    init_nano () ;

     for (i = 0 ; i < NB_FOIS; i++)
   {
     matrix_init(Af, 2.0);
     matrix_init(Bf, 2.0);
     matrix_init(Cf, 2.0);
     float alpha = 2.0;
     float beta = 3.0;

     TOP_NANO (start) ;
     mncblas_sgemm (0,0,0,MATSIZE,MATSIZE,MATSIZE, alpha, Af, 0, Bf, 0,beta,Cf,0) ;
     TOP_NANO (end);

     printf ("sgemm nano %e seconde\n", diff_nano (&start,&end)) ;
   }
 printf("Cf[0] = %f\n", Cf[0]);
 printf ("==========================================================\n") ;

//mesure double

for (i = 0 ; i < NB_FOIS; i++)
   {
     matrix_initd(Ad, 2.0);
     matrix_initd(Bd, 2.0);
     matrix_initd(Cd, 2.0);
     double alpha = 2.0;
     double beta = 3.0;

     TOP_NANO (start) ;
     mncblas_dgemm (0,0,0,MATSIZE,MATSIZE,MATSIZE, alpha, Ad, 0, Bd, 0,beta,Cd,0) ;
     TOP_NANO (end);

     printf ("dgemm nano %e seconde\n", diff_nano (&start,&end)) ;
   }
 printf("Cd[0] = %f\n", Cd[0]);
 printf ("==========================================================\n") ;
    

    //mesure complexe float

for (i = 0 ; i < NB_FOIS; i++)
   {
    complexe_float_t toA = {2.0,3.0};
    complexe_float_t toB = {1.0,8.0};
    complexe_float_t toC = {-2.0,1.0};
     matrix_initcf(Acf, toA);
     matrix_initcf(Bcf, toB);
     matrix_initcf(Ccf, toC);
     complexe_float_t alpha[1] = {{1,2}};
     complexe_float_t beta[1] = {{3,1}};

     TOP_NANO (start) ;
     mncblas_cgemm (0,0,0,MATSIZE,MATSIZE,MATSIZE, alpha, Acf, 0, Bcf, 0,beta,Ccf,0) ;
     TOP_NANO (end);

     printf ("cgemm nano %e seconde\n", diff_nano (&start,&end)) ;
   }
 printf("Ccf[0].reel = %f\n Ccf[0].imaginaire = %f\n ", Ccf[0].real, Ccf[0].imaginary);
 printf ("==========================================================\n") ;
    

    //mesure complexe double

    for (i = 0 ; i < NB_FOIS; i++)
   {
    complexe_double_t toA = {2.0,3.0};
    complexe_double_t toB = {1.0,8.0};
    complexe_double_t toC = {-2.0,1.0};
     matrix_initcd(Acd, toA);
     matrix_initcd(Bcd, toB);
     matrix_initcd(Ccd, toC);
     complexe_double_t alpha[1] = {{1,2}};
     complexe_double_t beta[1] = {{3,1}};

     TOP_NANO (start) ;
     mncblas_zgemm (0,0,0,MATSIZE,MATSIZE,MATSIZE, alpha, Acd, 0, Bcd, 0,beta,Ccd,0) ;
     TOP_NANO (end);

     printf ("zgemm nano %e seconde\n", diff_nano (&start,&end)) ;
   }
 printf("Ccd[0].reel = %f\n Ccd[0].imaginaire = %f\n ", Ccd[0].real, Ccd[0].imaginary);
 printf ("==========================================================\n") ;

  return 1;
}
