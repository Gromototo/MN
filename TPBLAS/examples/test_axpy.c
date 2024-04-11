#include <stdio.h>
#include <assert.h>

#include "flop.h"
#include "mnblas.h"

#define VECSIZE    65536

#define NB_FOIS    10

typedef float vfloat [VECSIZE] ;

void test1(){
    const int N = 5;
    float X[5]={2,2,3,5,1};
    float Y[5]={5,3,2,1,4};
    float alpha = 2;
    const int incX=1;
    const int incY=1;
    mnblas_saxpy(N, alpha, X, incX, Y, incY);
    assert(Y[0]==9);
    assert(Y[1]==7);
    assert(Y[2]==8);
    assert(Y[3]==11);
    assert(Y[4]==6);
}

void test2(){
    const int N = 5;
    double X[10]={2,4,2,12,3,4,5,9,1};
    double Y[5]={5,3,2,1,4};
    double alpha = -2;
    const int incX=2;
    const int incY=1;
    mnblas_daxpy(N, alpha, X, incX, Y, incY);

    for (int i=0; i<5; i++){
      printf("Y[%d] = %lf \n",i,Y[i]);
    }
    assert(Y[0]==1);
    assert(Y[1]==-1);
    assert(Y[2]==-4);
    assert(Y[3]==-9);
    assert(Y[4]==2);
}

int main(){
  test1();
  test2();

  printf("AXPY TESTS PASSED\n");
}