#include <stdio.h>
#include <assert.h>

#include "flop.h"
#include "mnblas.h"

#define VECSIZE    65536

#define NB_FOIS    10

typedef float vfloat [VECSIZE] ;
typedef double vdouble [VECSIZE] ;
typedef complexe_float_t vcfloat [VECSIZE] ;
typedef complexe_double_t vcdouble [VECSIZE] ;

vfloat vec1, vec2 ;
vdouble vec3, vec4;
vcfloat vec5,vec6;
vcdouble vec7, vec8;

void vector_init (vfloat V, float x)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    V [i] = x ;

  return ;
}

void vector_initd (vdouble V, double x)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    V [i] = x ;
  return ;
}

void vector_initcf (vcfloat V, complexe_float_t x)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++){
    V [i].real = x.real ;
    V[i].imaginary = x.imaginary;
  }
  return ;
}

void vector_initcd (vcdouble V, complexe_double_t x)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++){
    V [i].real = x.real ;
    V[i].imaginary = x.imaginary;
  }
  return ;
}

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
  /*
  test1();
  test2();
  test4();
  test3();
  test5();
  printf("COPY TESTS PASSED\n");
  */
  struct timespec start, end ;

 int i ;
 float v1f,v2f,v3f;
 double v1d,v2d,v3d;
 complexe_float_t v1cf,v2cf,v3cf;
 complexe_double_t v1cd,v2cd,v3cd;

 init_nano () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_init (vec1, 1.0) ;
     vector_init (vec2, 2.0) ;
     v1f = vec1[0];
     v2f = vec2[0];
     TOP_NANO (start) ;
        mncblas_scopy (VECSIZE, vec1, 1, vec2, 1) ;
     TOP_NANO (end);

     v3f = vec2[0];

     printf ("scopy nano %d %e seconde\n", 2*VECSIZE, diff_nano (&start,&end)) ;
   }

 printf ("X[0] = %f ; Y[0] avant fonction = %f ; Y[0] maintenant = %f\n", v1f,v2f,v3f) ;
 printf ("==========================================================\n") ;


 for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_initd (vec3, 1.0) ;
     vector_initd (vec4, 2.0) ;
     v1d = vec3[0];
     v2d = vec4[0];
     TOP_NANO (start) ;
        mncblas_dcopy (VECSIZE, vec3, 1, vec4, 1) ;
     TOP_NANO (end);

     v3d = vec4[0];

     printf ("dcopy nano %d %e seconde\n", 2*VECSIZE, diff_nano (&start,&end)) ;
   }

 printf ("X[0] = %lf ; Y[0] avant fonction = %lf ; Y[0] maintenant = %lf\n", v1d,v2d,v3d) ;
 printf ("==========================================================\n") ;

  
  
    complexe_float_t x ={1.0,0.0};
    complexe_float_t y ={2.0,0.0};
  for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_initcf (vec5,x) ;
     vector_initcf (vec6,y) ;
     v1cf = vec5[0];
     v2cf = vec6[0];
     TOP_NANO (start) ;
        mncblas_ccopy(VECSIZE, vec5, 1, vec6, 1) ;
     TOP_NANO (end);

      v3cf = vec6[0];

     printf ("ccopy nano %d %e seconde\n", 2*VECSIZE, diff_nano (&start,&end)) ;
   }

 printf ("X[0].reel = %f ;      Y[0].reel avant fonction = %f ;     Y[0].reel maintenant = %f\n", v1cf.real,v2cf.real,v3cf.real) ;
 printf ("X[0].imaginaire = %f; Y[0].imaginaire avant fonction = %f; Y[0].imaginaire maintenant = %f\n", v1cf.imaginary,v2cf.imaginary,v3cf.imaginary) ;
 printf ("==========================================================\n") ;

   complexe_double_t x2 ={1.0,0.0};
    complexe_double_t y2 ={2.0,0.0};
  for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_initcd (vec7,x2) ;
     vector_initcd (vec8,y2) ;
     v1cd = vec7[0];
     v2cd = vec8[0];
     TOP_NANO (start);
        mncblas_zcopy(VECSIZE, vec7, 1, vec8, 1);
     TOP_NANO (end);

     printf ("zcopy nano %d %e seconde\n", 2*VECSIZE, diff_nano (&start,&end)) ;

     v3cd = vec8[0];
   }

printf ("X[0].reel = %lf ;      Y[0].reel avant fonction = %lf ;     Y[0].reel maintenant = %lf\n", v1cd.real,v2cd.real,v3cd.real) ;
printf ("X[0].imaginaire = %lf; Y[0].imaginaire avant fonction = %lf; Y[0].imaginaire maintenant = %lf\n", v1cd.imaginary,v2cd.imaginary,v3cd.imaginary) ;
printf ("==========================================================\n") ;

}