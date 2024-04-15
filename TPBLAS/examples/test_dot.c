
#include <stdio.h>
#include <assert.h>

#include "flop.h"
#include "mnblas.h"
#include <stdbool.h>

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

double somme_temps = 0 ;

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

void vector_print (vfloat V)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    printf ("%f ", V[i]) ;
  printf ("\n") ;

  return ;
}

int main (int argc, char **argv)
{
 struct timespec start, end ;
 
 float res ;
 double resd;
 complexe_float_t rescf;
 complexe_double_t rescd;
 int i ;

 init_nano () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_init (vec1, 1.0) ;
     vector_init (vec2, 2.0) ;
     res = 0.0 ;

     TOP_NANO (start) ;
        res = mncblas_sdot (VECSIZE, vec1, 1, vec2, 1) ;
     TOP_NANO (end);

     double temps = diff_nano (&start,&end);

     printf ("sdot nano %d %e seconde\n", 2*VECSIZE, temps) ;
     if (i>=2){
      somme_temps += temps;
     }
   }

 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;
 printf("moyenne des temps : %e\n\n", somme_temps/8.0);
  somme_temps=0;


 for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_initd (vec3, 1.0) ;
     vector_initd (vec4, 2.0) ;
     resd = 0.0;
     TOP_NANO (start) ;
        resd = mncblas_ddot (VECSIZE, vec3, 1, vec4, 1) ;
     TOP_NANO (end);

     double temps = diff_nano (&start,&end);

     printf ("ddot nano %d %e seconde\n", 2*VECSIZE, temps) ;
     if (i>=2){
      somme_temps += temps;
     }
   }

 printf ("resd = %f\n", resd) ;
 printf ("==========================================================\n") ;
 printf("moyenne des temps : %e\n\n", somme_temps/8.0);
  somme_temps=0;

  
  
    complexe_float_t x ={1.0,0.0};
    complexe_float_t y ={2.0,0.0};
  for (i = 0 ; i < NB_FOIS; i++)
   {
    complexe_float_t dotu[VECSIZE]; 
     vector_initcf (vec5,x) ;
     vector_initcf (vec6,y) ;
      rescf.real = 0.0;
      rescf.imaginary = 0.0; 
     TOP_NANO (start) ;
        mncblas_cdotu_sub(VECSIZE, vec5, 1, vec6, 1,dotu) ;
        rescf = dotu[0];
     TOP_NANO (end);

      double temps = diff_nano (&start,&end);

     printf ("cdotu_sub nano %d %e seconde\n", 2*VECSIZE, temps) ;
     if (i>=2){
      somme_temps += temps;
     }
   }

 printf ("rescf.reel = %f\n,rescf.imaginaire = %f\n", rescf.real, rescf.imaginary) ;
 printf ("==========================================================\n") ;
 printf("moyenne des temps : %e\n\n", somme_temps/8.0);
  somme_temps=0;

   complexe_double_t x2 ={1.0,0.0};
    complexe_double_t y2 ={2.0,0.0};
  for (i = 0 ; i < NB_FOIS; i++)
   {
    complexe_double_t dotuz[VECSIZE]; 
     vector_initcd (vec7,x2) ;
     vector_initcd (vec8,y2) ;
      rescd.real = 0.0;
      rescd.imaginary = 0.0; 
     TOP_NANO (start) ;
        mncblas_zdotu_sub(VECSIZE, vec7, 1, vec8, 1,dotuz) ;
        rescd = dotuz[0];
     TOP_NANO (end);

     double temps = diff_nano (&start,&end);

     printf ("zdotu_sub nano %d %e seconde\n", 2*VECSIZE, temps) ;
     if (i>=2){
      somme_temps += temps;
     }
   }

 printf ("rescd.reel = %f\n,rescd.imaginaire = %f\n", rescd.real, rescd.imaginary) ;
 printf ("==========================================================\n") ;
 printf("moyenne des temps : %e\n\n", somme_temps/8.0);

}