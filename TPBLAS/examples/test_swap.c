#include <stdio.h>
#include <assert.h>

#include "flop.h"
#include "../src/BLAS1/swap.c"

#define VECSIZE    65536

#define NB_FOIS    10

typedef float vfloat [VECSIZE] ;

void test1(){
    const int N = 5;
    float X[5]={2.5,2.7,3.0,52.18,-18.2};
    float Y[5]={0,0,0,0,0};
    float X2[5]={2.5,2.7,3.0,52.18,-18.2};
    float Y2[5]={0,0,0,0,0};
    const int incX=1;
    const int incY=1;
    mncblas_sswap(N, X, incX, Y, incY);

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    for (; ((i < N) && (j < N)) ; i += incX, j += incY)
    {
      assert(X[i]==Y2[j]);
      assert(Y[j]==X2[i]);
    }
}

void test2(){
    const int N = 5;
    float X[10]={2.5,2.7,3.0,3.8,52.18,52.19,-18.7,-18.2,-140.99,-140.0};
    float Y[5]={0,0,0,0,0};
    float X2[10]={2.5,2.7,3.0,3.8,52.18,52.19,-18.7,-18.2,-140.99,-140.0};
    float Y2[5]={0,0,0,0,0};
    const int incX=2;
    const int incY=1;
    mncblas_sswap(N, X, incX, Y, incY);

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    for (; ((i < N) && (j < N)) ; i += incX, j += incY)
    {
      assert(X[i]==Y2[j]);
      assert(Y[j]==X2[i]);
    }
}

void test3(){
    const int N = 5;
    double X[10]={2.5,2.7,3.0,3.8,52.18,52.19,-18.7,-18.2,-140.99,-140.0};
    double Y[5]={0,0,0,0,0};
    double X2[10]={2.5,2.7,3.0,3.8,52.18,52.19,-18.7,-18.2,-140.99,-140.0};
    double Y2[5]={0,0,0,0,0};
    const int incX=2;
    const int incY=1;
    mncblas_dswap(N, X, incX, Y, incY);

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    for (; ((i < N) && (j < N)) ; i += incX, j += incY)
    {
      assert(X[i]==Y2[j]);
      assert(Y[j]==X2[i]);
    }

}

void test4(){
    const int N = 5;
    complexe_float_t c1;
    c1.real=2;
    c1.imaginary=52;
    complexe_float_t c2;
    c2.real=6;
    c2.imaginary=14;
    complexe_float_t c3;
    c3.real=12;
    c3.imaginary=2;
    complexe_float_t c4;
    c4.real=15;
    c4.imaginary=22;
    complexe_float_t c5;
    c5.real=24;
    c5.imaginary=45;
    complexe_float_t X[5]={c1,c2,c3,c4,c5};
    complexe_float_t Y[5]={c2,c4,c1,c5,c4};
    complexe_float_t X2[5]={c1,c2,c3,c4,c5};
    complexe_float_t Y2[5]={c2,c4,c1,c5,c4};
    const int incX=1;
    const int incY=1;
    mncblas_cswap(N, X, incX, Y, incY);

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    for (; ((i < N) && (j < N)) ; i += incX, j += incY)
    {
      assert(X[i].real==Y2[j].real);
      assert(X[i].imaginary==Y2[j].imaginary);
      assert(Y[j].real==X2[i].real);
      assert(Y[j].imaginary==X2[i].imaginary);
    }
}

void test5(){
    const int N = 5;
    complexe_double_t c1;
    c1.real=2;
    c1.imaginary=52;
    complexe_double_t c2;
    c2.real=6;
    c2.imaginary=14;
    complexe_double_t c3;
    c3.real=12;
    c3.imaginary=2;
    complexe_double_t c4;
    c4.real=15;
    c4.imaginary=22;
    complexe_double_t c5;
    c5.real=24;
    c5.imaginary=45;
    complexe_double_t X[10]={c1,c1,c2,c2,c3,c3,c4,c4,c5,c5};
    complexe_double_t Y[5]={c2,c4,c1,c5,c4};
    complexe_double_t X2[10]={c1,c1,c2,c2,c3,c3,c4,c4,c5,c5};
    complexe_double_t Y2[5]={c2,c4,c1,c5,c4};
    const int incX=2;
    const int incY=1;
    mncblas_zswap(N, X, incX, Y, incY);

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    for (; ((i < N) && (j < N)) ; i += incX, j += incY)
    {
      assert(X[i].real==Y2[j].real);
      assert(X[i].imaginary==Y2[j].imaginary);
      assert(Y[j].real==X2[i].real);
      assert(Y[j].imaginary==X2[i].imaginary);
    }
}

int main(){
  test1();
  test2();
  test4();
  test3();
  test5();

  printf("SWAP TESTS PASSED\n");
}