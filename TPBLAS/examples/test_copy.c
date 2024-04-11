#include <stdio.h>
#include <assert.h>

#include "flop.h"
#include "mnblas.h"

#define VECSIZE    65536

#define NB_FOIS    10

typedef float vfloat [VECSIZE] ;

void test1(){
    const int N = 5;
    const float X[5]={2.5,2.7,3.0,52.18,-18.2};
    float Y[5]={0,0,0,0,0};
    const int incX=1;
    const int incY=1;
    mncblas_scopy(N, X, incX, Y, incY);

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    int b = 1;
    for (; ((i < N) && (j < N)) ; i += incX, j += incY)
    {
      b &= Y[j]==X[i];
    }
    assert(b);

    return ;
}

void test2(){
    const int N = 5;
    const float X[10]={2.5,2.7,3.0,3.8,52.18,52.19,-18.7,-18.2,-140.99,-140.0};
    float Y[5]={0,0,0,0,0};
    const int incX=2;
    const int incY=1;
    mncblas_scopy(N, X, incX, Y, incY);

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    int b = 1;
    for (; ((i < N) && (j < N)) ; i += incX, j += incY)
    {
      b &= Y[j]==X[i];
    }
    assert(b);
}

void test3(){
    const int N = 5;
    const double X[10]={2.5,2.7,3.0,3.8,52.18,52.19,-18.7,-18.2,-140.99,-140.0};
    double Y[5]={0,0,0,0,0};
    const int incX=2;
    const int incY=1;
    mncblas_dcopy(N, X, incX, Y, incY);

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    int b = 1;
    for (; ((i < N) && (j < N)) ; i += incX, j += incY)
    {
      b &= Y[j]==X[i];
    }

    assert(b);
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
    const complexe_float_t X[5]={c1,c2,c3,c4,c5};
    complexe_float_t Y[5]={c2,c4,c1,c5,c4};
    const int incX=1;
    const int incY=1;
    mncblas_ccopy(N, X, incX, Y, incY);

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    int b1 = 1;
    int b2 = 1;
    for (; ((i < N) && (j < N)) ; i += incX, j += incY)
    {
      b1 &= Y[j].real==X[i].real;
      b2 &= Y[j].imaginary==X[i].imaginary;
    }
    assert(b1&b2);
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
    const complexe_double_t X[10]={c1,c1,c2,c2,c3,c3,c4,c4,c5,c5};
    complexe_double_t Y[5]={c2,c4,c1,c5,c4};
    const int incX=2;
    const int incY=1;
    mncblas_zcopy(N, X, incX, Y, incY);

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    for (; ((i < N) && (j < N)) ; i += incX, j += incY)
    {
      assert(Y[j].real==X[i].real);
      assert(Y[j].imaginary==X[i].imaginary);
    }
    return;
}

int main(){
  test1();
  test2();
  test4();
  test3();
  test5();


  printf("COPY TESTS PASSED\n");
}