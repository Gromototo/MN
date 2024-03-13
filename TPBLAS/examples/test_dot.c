#include <stdio.h>
#include <assert.h>

#include "flop.h"
#include "../src/BLAS1/dot.c"

#define VECSIZE    65536

#define NB_FOIS    10

typedef float vfloat [VECSIZE] ;

void test1(){
    const int N = 5;
    const float X[5]={2.5,2.7,3.0,52.18,-18.2};
    float Y[5]={0,1,1,1,0};
    const int incX=1;
    const int incY=1;
    assert(mncblas_sdot(N, X, incX, Y, incY)==57.88);
}

void test2(){
    const int N = 5;
    const float X[10]={2.5,2.7,3.0,3.8,52.18,52.19,-18.7,-18.2,-140.99,-140.0};
    float Y[5]={0,1,1,1,0};
    const int incX=2;
    const int incY=1;
    assert(mncblas_sdot(N, X, incX, Y, incY)==36.48);
}

void test3(){
    const int N = 5;
    const double X[10]={2.5,2.7,3.0,3.8,52.18,52.19,-18.7,-18.2,-140.99,-140.0};
    double Y[5]={0,2.5,1,2.5,0};
    const int incX=2;
    const int incY=1;
    assert(mncblas_ddot(N, X, incX, Y, incY)==12.93);
}

void test4(){
    const int N = 2;
    void* X;
    void* Y;
    complexe_float_t c1 = {2.1, 5.2};
    complexe_float_t c2 = {2.0, 4.0};
    complexe_float_t c3 = {1.1, 3.3};
    ((complexe_float_t*)X)[0]= c1;
    ((complexe_float_t*)X)[1]= c2;
    ((complexe_float_t*)Y)[0]= c3;
    ((complexe_float_t*)Y)[1]= c1;
    int incX,incY=1;
    void* dotu;
    ((complexe_float_t*)dotu)->real=0;
    ((complexe_float_t*)dotu)->imaginary=0;
    mncblas_cdotu_sub(N, X, incX, Y, incY,dotu);
    assert(((complexe_float_t*)dotu)->real==6.51);
    assert(((complexe_float_t*)dotu)->imaginary==37.96);

}

void test5(){
  const int N = 2;
    void* X;
    void* Y;
    complexe_float_t c1 = {2.1, 5.2};
    complexe_float_t c2 = {2.0, 4.0};
    complexe_float_t c3 = {1.1, 3.3};
    ((complexe_float_t*)X)[0]= c1;
    ((complexe_float_t*)X)[1]= c2;
    ((complexe_float_t*)Y)[0]= c3;
    ((complexe_float_t*)Y)[1]= c1;
    int incX,incY=1;
    void* dotu;
    ((complexe_float_t*)dotu)->real=0;
    ((complexe_float_t*)dotu)->imaginary=0;
    mncblas_cdotu_sub(N, X, incX, Y, incY,dotu);
    assert(((complexe_float_t*)dotu)->real==6.51);
    assert(((complexe_float_t*)dotu)->imaginary==-37.96);
}

void test6(){
  const int N = 2;
    void* X;
    void* Y;
    complexe_double_t c1 = {2.1, 5.2};
    complexe_double_t c2 = {2.0, 4.0};
    complexe_double_t c3 = {1.1, 3.3};
    ((complexe_double_t*)X)[0]= c1;
    ((complexe_double_t*)X)[1]= c2;
    ((complexe_double_t*)Y)[0]= c3;
    ((complexe_double_t*)Y)[1]= c1;
    int incX,incY=1;
    void* dotu;
    ((complexe_double_t*)dotu)->real=0;
    ((complexe_double_t*)dotu)->imaginary=0;
    mncblas_cdotu_sub(N, X, incX, Y, incY,dotu);
    assert(((complexe_double_t*)dotu)->real==6.51);
    assert(((complexe_double_t*)dotu)->imaginary==37.96);
}


void test7(){
    const int N = 2;
    void* X;
    void* Y;
    complexe_double_t c1 = {2.1, 5.2};
    complexe_double_t c2 = {2.0, 4.0};
    complexe_double_t c3 = {1.1, 3.3};
    ((complexe_double_t*)X)[0]= c1;
    ((complexe_double_t*)X)[1]= c2;
    ((complexe_double_t*)Y)[0]= c3;
    ((complexe_double_t*)Y)[1]= c1;
    int incX,incY=1;
    void* dotu;
    ((complexe_float_t*)dotu)->real=0;
    ((complexe_float_t*)dotu)->imaginary=0;
    mncblas_cdotu_sub(N, X, incX, Y, incY,dotu);
    assert(((complexe_float_t*)dotu)->real==6.51);
    assert(((complexe_float_t*)dotu)->imaginary==-37.96);
}

int main(){
  test1();
  test2();
  test4();
  test3();
  test5();
  test6();
  test7();


  printf("DOT TESTS PASSED\n");
}