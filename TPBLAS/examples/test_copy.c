#include <stdio.h>

#include "mnblas.h"
#include "complexe.h"

#include "flop.h"

#define VECSIZE    65536

#define NB_FOIS    10

typedef float vfloat [VECSIZE] ;

int main(){
    int i1 = test1();
    int i2 = test2();
    int i3 = test3();
    int i4 = test4();
    int i5 = test5();
    return verif(i1,i2,i3,i4,i5);
}

int test1(){
    const int N = 5;
    const float X[5]={2.5,2.7,3.0,52.18,-18.2};
    const float Y[5]={0,0,0,0,0};
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
    return b;
}

int test2(){
    const int N = 5;
    const float X[10]={2.5,2.7,3.0,3.8,52.18,52.19,-18.7,-18.2,-140.99,-140.0};
    const float Y[5]={0,0,0,0,0};
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
    return b;
}

int test3(){
    const int N = 5;
    const double X[10]={2.5,2.7,3.0,3.8,52.18,52.19,-18.7,-18.2,-140.99,-140.0};
    const double Y[5]={0,0,0,0,0};
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
    return b;
}

int test4(){
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
    const complexe_float_t X[10]={c1,c2,c3,c4,c5};
    const complexe_float_t Y[5]={c2,c4,c1,c5,c4};
    const int incX=2;
    const int incY=1;
    mncblas_ccopy(N, X, incX, Y, incY);

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    int b1,b2 = 1;
    for (; ((i < N) && (j < N)) ; i += incX, j += incY)
    {
      b1 &= Y[j].real==X[i].real;
      b2 &= Y[j].imaginary==X[i].imaginary;
    }
    return (b1&b2);
}

int test5(){
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
    const complexe_double_t X[10]={c1,c2,c3,c4,c5};
    const complexe_double_t Y[5]={c2,c4,c1,c5,c4};
    const int incX=2;
    const int incY=1;
    mncblas_zcopy(N, X, incX, Y, incY);

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    int b1,b2 = 1;
    for (; ((i < N) && (j < N)) ; i += incX, j += incY)
    {
      b1 &= Y[j].real==X[i].real;
      b2 &= Y[j].imaginary==X[i].imaginary;
    }
    return (b1&b2);
}

int verif(int i1, int i2, int i3, int i4, int i5){
    int i = i1 & i2 & i3 & i4 & i5;
    if (i==0){
        printf("erreur dans copy\n");
        exit(-1);
    }
    else{
        printf("Copy OK\n");
        return 1;
    }
}