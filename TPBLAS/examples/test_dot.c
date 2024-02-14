#include <stdio.h>

#include "mnblas.h"
#include "complexe.h"

#include "flop.h"

#define VECSIZE    65536

#define NB_FOIS    10

typedef float vfloat [VECSIZE] ;

vfloat vec1, vec2 ;

void vector_init (vfloat V, float x)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    V [i] = x ;

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
     
     printf ("sdot nano %d %e seconde\n", 2*VECSIZE, diff_nano (&start,&end)) ;
   }

 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;
}
