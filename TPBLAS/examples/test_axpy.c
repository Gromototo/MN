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
  /*
  test1();
  test2();
  test3();
  test4();
  printf("\nAXPY TESTS PASSED\n");
  */
  struct timespec start, end ;
 
 int i ;
 float v1f,v2f,v3f,alphaf;
 double v1d,v2d,v3d,alphad;
 complexe_float_t v1cf,v2cf,v3cf,alphacf;
 complexe_double_t v1cd,v2cd,v3cd,alphacd;

 init_nano () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_init (vec1, 1.0) ;
     vector_init (vec2, 2.0) ;
     alphaf = 3;
     v1f = vec1[0];
     v2f = vec2[0];
     TOP_NANO (start) ;
        mncblas_saxpy (VECSIZE, alphaf, vec1, 1, vec2, 1) ;
     TOP_NANO (end);

     v3f = vec2[0];

     printf ("saxpy nano %d %e seconde\n", 2*VECSIZE, diff_nano (&start,&end)) ;
   }

  printf ("Y[0] attendu = %f ; Y[0] obtenu = %f \n", v1f*alphaf+v2f,v3f) ;
  printf ("==========================================================\n") ;


 for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_initd (vec3, 1.0) ;
     vector_initd (vec4, 2.0) ;
     v1d = vec3[0];
     v2d = vec4[0];
     alphad=2;
     TOP_NANO (start) ;
        mncblas_daxpy (VECSIZE, alphad, vec3, 1, vec4, 1) ;
     TOP_NANO (end);

     v3d = vec4[0];

     printf ("daxpy nano %d %e seconde\n", 2*VECSIZE, diff_nano (&start,&end)) ;
   }

  printf ("Y[0] attendu = %lf ; Y[0] obtenu = %lf \n", v1d*alphad+v2d,v3d) ;
  printf ("==========================================================\n") ;

  
  
    complexe_float_t x ={1.0,0.0};
    complexe_float_t y ={2.0,0.0};
  for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_initcf (vec5,x) ;
     vector_initcf (vec6,y) ;
     v1cf = vec5[0];
     v2cf = vec6[0];
     alphacd = {3,5};
     TOP_NANO (start) ;
        mncblas_caxpy(VECSIZE, alphacf, vec5, 1, vec6, 1) ;
     TOP_NANO (end);

      v3cf = vec6[0];

     printf ("caxpy nano %d %e seconde\n", 2*VECSIZE, diff_nano (&start,&end)) ;
   }

  printf ("Y[0].reel attendu = %f ; Y[0].reel obtenu = %f \n", ) ;
  printf ("Y[0].imaginaire attendu = %f ; Y[0].imaginaire obtenu = %f \n", ) ;
  printf ("==========================================================\n") ;

   complexe_double_t x2 ={1.0,0.0};
    complexe_double_t y2 ={2.0,0.0};
  for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_initcd (vec7,x2) ;
     vector_initcd (vec8,y2) ;
     v1cd = vec7[0];
     v2cd = vec8[0];
     alphacd = {3,5};
     TOP_NANO (start);
        mncblas_zcopy(VECSIZE, vec7, 1, vec8, 1);
     TOP_NANO (end);

     printf ("zaxpy nano %d %e seconde\n", 2*VECSIZE, diff_nano (&start,&end)) ;

     v3cd = vec8[0];
   }

  printf ("Y[0].reel attendu = %lf ; Y[0].reel obtenu = %lf \n", );
  printf ("Y[0].imaginaire attendu = %lf ; Y[0].imaginaire obtenu = %lf \n", );
  printf ("==========================================================\n") ;
}