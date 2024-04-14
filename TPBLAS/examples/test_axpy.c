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
    printf("\ntest1 passed\n");

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
    printf("test2 passed\n");
}

void test3(){
  const int N = 5;
  complexe_float_t X[5]={{2,1},{0,3},{5,0},{3,-2},{4,0}};
  complexe_float_t Y[5]={{0,1},{1,1},{3,2},{4,0},{4,-4}};
  complexe_float_t alpha = {1,2};

  mnblas_caxpy(N, alpha, X,1, Y, 1);

  for (int i=0; i<5; i++){
      printf("Y[%i].real = %f, Y[%i].imaginary = %fi\n",i,Y[i].real,i,Y[i].imaginary);
  }

    assert(Y[0].real == 0 && Y[0].imaginary == 6);
    assert(Y[1].real == -5 && Y[1].imaginary == 4);
    assert(Y[2].real == 8 && Y[2].imaginary == 12);
    assert(Y[3].real == 11 && Y[3].imaginary == 4);
    assert(Y[4].real == 8 && Y[4].imaginary == 4);

    printf("test3 passed\n");
}

void test4(){
  const int N = 5;
  complexe_double_t X[5]={{2,1},{0,3},{5,0},{3,-2},{4,0}};
  complexe_double_t Y[5]={{0,1},{1,1},{3,2},{4,0},{4,-4}};
  complexe_double_t alpha = {1,2};

  mnblas_zaxpy(N, alpha, X,1, Y, 1);

  for (int i=0; i<5; i++){
      printf("Y[%i].real = %f, Y[%i].imaginary = %fi\n",i,Y[i].real,i,Y[i].imaginary);
  }

    assert(Y[0].real == 0 && Y[0].imaginary == 6);
    assert(Y[1].real == -5 && Y[1].imaginary == 4);
    assert(Y[2].real == 8 && Y[2].imaginary == 12);
    assert(Y[3].real == 11 && Y[3].imaginary == 4);
    assert(Y[4].real == 8 && Y[4].imaginary == 4);

    printf("test4 passed\n");
}
int main(){
  test1();
  test2();
  test3();
  test4();
  printf("\nAXPY TESTS PASSED\n");
}