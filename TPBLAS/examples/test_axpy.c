#include <stdio.h>
#include <assert.h>

#include "flop.h"
#include "../src/BLAS1/axpy.c"

#define VECSIZE    65536

#define NB_FOIS    10

typedef float vfloat [VECSIZE] ;

void test1(){
    const int N = 5;
    float X[5]={2.5,2.7,3.0,5.1,1.2};
    float Y[5]={5,3,2,1,4};
    float alpha = 2;
    const int incX=1;
    const int incY=1;
    mnblas_saxpy(N, alpha, X, incX, Y, incY);
    assert(Y[0]==10);
    assert(Y[1]==8.4);
    assert(Y[2]==8);
    assert(Y[3]==11.2);
    assert(Y[4]==6.4);
}

void test2(){
    const int N = 5;
    double X[10]={2.5,4,2.7,12,3.0,4.1,5.1,9.2,1.2};
    double Y[5]={5,3,2,1,4};
    double alpha = -2;
    const int incX=2;
    const int incY=1;
    mnblas_daxpy(N, alpha, X, incX, Y, incY);
    assert(Y[0]==0);
    assert(Y[1]==-2.4);
    assert(Y[2]==-4);
    assert(Y[3]==-9.2);
    assert(Y[4]==1.6);
}

int main(){
  test1();
  test2();

  printf("AXPY TESTS PASSED\n");
}