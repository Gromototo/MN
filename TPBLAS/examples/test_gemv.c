#include "mnblas.h"
#include "flop.h"
#include <stdio.h>
#include <stdlib.h>

#define MATSIZE    256
#define NB_FOIS    10
#define VECSIZE    256

typedef float mfloat [MATSIZE*MATSIZE] ;
typedef double mdouble [MATSIZE*MATSIZE] ;
typedef complexe_float_t mcfloat [MATSIZE*MATSIZE] ;
typedef complexe_double_t mcdouble [MATSIZE*MATSIZE] ;

mfloat Af;
mdouble Ad;
mcfloat Acf;
mcdouble Acd;

typedef float vfloat [VECSIZE] ;
typedef double vdouble [VECSIZE] ;
typedef complexe_float_t vcfloat [VECSIZE] ;
typedef complexe_double_t vcdouble [VECSIZE] ;

vfloat Xf, Yf ;
vdouble Xd, Yd ;
vcfloat Xcf, Ycf ;
vcdouble Xcd, Ycd ;

double somme_temps = 0 ;

void matrix_init (mfloat M, float x)
{
  register unsigned int i ;

  for (i = 0; i < MATSIZE*MATSIZE; i++)
    M [i] = x ;

  return ;
}

void matrix_initd (mdouble M, double x)
{
  register unsigned int i ;

  for (i = 0; i < MATSIZE*MATSIZE; i++)
    M [i] = x ;
  return ;
}

void matrix_initcf (mcfloat M, complexe_float_t x)
{
  register unsigned int i ;

  for (i = 0; i < MATSIZE*MATSIZE; i++){
    M [i].real = x.real ;
    M[i].imaginary = x.imaginary;
  }
  return ;
}

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

void matrix_initcd (mcdouble M, complexe_double_t x)
{
  register unsigned int i ;

  for (i = 0; i < MATSIZE*MATSIZE; i++){
    M [i].real = x.real ;
    M[i].imaginary = x.imaginary;
  }
  return ;
}

void compare_float(float *X, float *Y, const int Ysize) //compare les deux vecteurs
{
    for (int i = 0; i<Ysize; i++){
        if (X[i] != Y[i]){
            printf("erreur ici : %i \n", i);
            exit(-1);
        }
    }
}
void compare_double(double *X, double *Y, const int Ysize) //compare les deux vecteurs
{
    for (int i = 0; i<Ysize; i++){
        if (X[i] != Y[i]){
            printf("erreur ici : %i \n", i);
            exit(-1);
        }
    }
}

void compare_complex_float(complexe_float_t *X, complexe_float_t *Y, const int Ysize) //compare les deux vecteurs
{
    for (int i = 0; i<Ysize; i++){
        if (X[i].real != Y[i].real || X[i].imaginary != Y[i].imaginary){
            printf("erreur ici : %i \n", i);
            printf("attendu.real/imaginary : %f + %fi \n obtenu.real/imaginary : %f +%fi", X[i].real,
            X[i].imaginary, Y[i].real, Y[i].imaginary);
            exit(-1);
        }
    }
}

void compare_complex_double(complexe_double_t *X, complexe_double_t *Y, const int Ysize) //compare les deux vecteurs
{
    for (int i = 0; i<Ysize; i++){
        if (X[i].real != Y[i].real || X[i].imaginary != Y[i].imaginary){
            printf("erreur ici : %i \n", i);
            printf("attendu.real/imaginary : %f + %fi \n obtenu.real/imaginary : %f +%fi", X[i].real,
            X[i].imaginary, Y[i].real, Y[i].imaginary);
            exit(-1);
        }
    }
}


void test00(){  //test de matrice de taille 2x3
    
    float Mat_A[6] = {1.0,2.0,4.0,5.0,7.0,8.0}; //2*3
    float Vect_X[3] = {4.0,3.0,5.0};
    float Vect_Y[2] = {3.0,5.0};
    const float alpha= 2.0;
    const float beta = 3.0;
    float compare_matrix[2] = {69.0,177.0}; //calculée à la main
    
    mncblas_sgemv(3,101,2,3, alpha,Mat_A, 0, Vect_X, 1,beta, Vect_Y, 1); //2lignes, 3colonnes

    compare_float(compare_matrix, Vect_Y,2);

    printf("\ntest00 passé\n");
    }
    

void test01(){ //test matrice 3x2

    float Mat_A[6] = {1.0,2.0,4.0,5.0,7.0,8.0}; //3*2
    float Vect_X[2] = {3.0,5.0};
    float Vect_Y[3] = {4.0,3.0,5.0};
    const float alpha= 2.0;
    const float beta = 3.0;
    float compare_matrix[3] = {38.0,83.0,137.0}; //calculée à la main
    
    mncblas_sgemv(3,101,3,2, alpha,Mat_A, 0, Vect_X, 1,beta, Vect_Y, 1); //3lignes, 2colonnes

    compare_float(compare_matrix, Vect_Y,2);

    printf("test01 passé\n");
}

void test02(){ //test de matrice de taille 2x3
    double Mat_A[6] = {1.0,2.0,4.0,5.0,7.0,8.0}; //2*3
    double Vect_X[3] = {4.0,3.0,5.0};
    double Vect_Y[2] = {3.0,5.0};
    const double alpha= 2.0;
    const double beta = 3.0;
    double compare_matrix[2] = {69.0,177.0}; //calculée à la main
    
    mncblas_dgemv(3,101,2,3, alpha,Mat_A, 0, Vect_X, 1,beta, Vect_Y, 1); //2lignes, 3colonnes

    compare_double(compare_matrix, Vect_Y,2);

    printf("test02 passé\n");
}

void test03(){ //test matrice 3x2

    double Mat_A[6] = {1.0,2.0,4.0,5.0,7.0,8.0}; //3*2
    double Vect_X[2] = {3.0,5.0};
    double Vect_Y[3] = {4.0,3.0,5.0};
    const double alpha= 2.0;
    const double beta = 3.0;
    double compare_matrix[3] = {38.0,83.0,137.0}; //calculée à la main
    
    mncblas_dgemv(3,101,3,2, alpha,Mat_A, 0, Vect_X, 1,beta, Vect_Y, 1); //3lignes, 2colonnes

    compare_double(compare_matrix, Vect_Y,2);

    printf("test03 passé\n");
}


void test04(){ //test matrice 2x3 complexe float

    complexe_float_t Mat_A[6];  //2*3
    Mat_A[0].real = 1.0;
    Mat_A[0].imaginary = 2.0;

    Mat_A[1].real = 3.0;
    Mat_A[1].imaginary = 0.0;

    Mat_A[2].real = 0.0;
    Mat_A[2].imaginary =9.0;

    Mat_A[3].real = 1.0;
    Mat_A[3].imaginary =0.0;

    Mat_A[4].real = 2.0;
    Mat_A[4].imaginary =1.0;

    Mat_A[5].real = 5.0;
    Mat_A[5].imaginary = 4.0;

    complexe_float_t Vect_X[3];
    Vect_X[0].real = 1.0;
    Vect_X[0].imaginary = 1.0;
    Vect_X[1].real = 3.0;
    Vect_X[1].imaginary = 0;
    Vect_X[2].real =0;
    Vect_X[2].imaginary = 2.0;

    complexe_float_t Vect_Y[2];
    Vect_Y[0].real = 3.0;
    Vect_Y[0].imaginary = 1.0;
    Vect_Y[1].real = 1.0;
    Vect_Y[1].imaginary = 4.0;

    complexe_float_t alpha[9];

    for (int i = 0; i<3; i++){ // alpha*I3, alpha = 1+2i
           alpha[4*i].real = 1;
           alpha[4*i].imaginary = 2;
    }

    complexe_float_t beta[4];

    for (int i = 0; i<4; i+=3){ // beta*I3, beta= 1+3i
           beta[i].real = 1;
           beta[i].imaginary = 3;
    }

    complexe_float_t compare_matrix[2] ; //calculée à la main

    compare_matrix[0].real = -16;
    compare_matrix[0].imaginary = -7;
    compare_matrix[1].real = -40;
    compare_matrix[1].imaginary = 19;
    
    mncblas_cgemv(3,101,2,3, alpha,Mat_A, 0, Vect_X, 1,beta, Vect_Y, 1); //2lignes, 3colonnes

    //printf("real: %f, imaginary : %f\n", Vect_Y[0].real, Vect_Y[0].imaginary);
   // printf("real: %f, imaginary : %f\n", Vect_Y[1].real, Vect_Y[1].imaginary);
    

    compare_complex_float(compare_matrix, Vect_Y,2);

    printf("\ntest04 passé\n");

}

void test05(){
    complexe_float_t Mat_A[6];  //3*2
    Mat_A[0].real = 1.0;
    Mat_A[0].imaginary = 2.0;

    Mat_A[1].real = 3.0;
    Mat_A[1].imaginary = 0.0;

    Mat_A[2].real = 0.0;
    Mat_A[2].imaginary =9.0;

    Mat_A[3].real = 1.0;
    Mat_A[3].imaginary =0.0;

    Mat_A[4].real = 2.0;
    Mat_A[4].imaginary =1.0;

    Mat_A[5].real = 5.0;
    Mat_A[5].imaginary = 4.0;

    complexe_float_t Vect_X[2];
    Vect_X[0].real = 3.0;
    Vect_X[0].imaginary = 1.0;
    Vect_X[1].real = 1.0;
    Vect_X[1].imaginary = 4.0;

    complexe_float_t Vect_Y[3];
    Vect_Y[0].real = 1.0;
    Vect_Y[0].imaginary = 1.0;
    Vect_Y[1].real = 3.0;
    Vect_Y[1].imaginary = 0;
    Vect_Y[2].real =2;
    Vect_Y[2].imaginary = 2.0;

    complexe_float_t alpha[9];

    for (int i = 0; i<3; i++){ // alpha*I3, alpha = 1+2i
           alpha[4*i].real = 1;
           alpha[4*i].imaginary = 2;
    }

    complexe_float_t beta[4];

    for (int i = 0; i<4; i+=3){ // beta*I3, beta= 1+3i
           beta[i].real = 1;
           beta[i].imaginary = 3;
    }

    complexe_float_t compare_matrix[3] ; //calculée à la main

    compare_matrix[0].real = -36;
    compare_matrix[0].imaginary = 31;
    compare_matrix[1].real = -67;
    compare_matrix[1].imaginary = 24;
    compare_matrix[2].real = -68;
    compare_matrix[2].imaginary = 25;
    
    mncblas_cgemv(3,101,3,2, alpha,Mat_A, 0, Vect_X, 1,beta, Vect_Y, 1); //3lignes, 2colonnes

    //printf("real: %f, imaginary : %f\n", Vect_Y[0].real, Vect_Y[0].imaginary);
   // printf("real: %f, imaginary : %f\n", Vect_Y[1].real, Vect_Y[1].imaginary);
   // printf("real: %f, imaginary : %f\n", Vect_Y[2].real, Vect_Y[2].imaginary);

    compare_complex_float(compare_matrix, Vect_Y,3);

    printf("\ntest05 passé\n");
}

void test06(){ //test matrice 2x3 complexe double

    complexe_double_t Mat_A[6];  //2*3
    Mat_A[0].real = 1.0;
    Mat_A[0].imaginary = 2.0;

    Mat_A[1].real = 3.0;
    Mat_A[1].imaginary = 0.0;

    Mat_A[2].real = 0.0;
    Mat_A[2].imaginary =9.0;

    Mat_A[3].real = 1.0;
    Mat_A[3].imaginary =0.0;

    Mat_A[4].real = 2.0;
    Mat_A[4].imaginary =1.0;

    Mat_A[5].real = 5.0;
    Mat_A[5].imaginary = 4.0;

    complexe_double_t Vect_X[3];
    Vect_X[0].real = 1.0;
    Vect_X[0].imaginary = 1.0;
    Vect_X[1].real = 3.0;
    Vect_X[1].imaginary = 0;
    Vect_X[2].real =0;
    Vect_X[2].imaginary = 2.0;

    complexe_double_t Vect_Y[2];
    Vect_Y[0].real = 3.0;
    Vect_Y[0].imaginary = 1.0;
    Vect_Y[1].real = 1.0;
    Vect_Y[1].imaginary = 4.0;

    complexe_double_t alpha[9];

    for (int i = 0; i<3; i++){ // alpha*I3, alpha = 1+2i
           alpha[4*i].real = 1;
           alpha[4*i].imaginary = 2;
    }

    complexe_double_t beta[4];

    for (int i = 0; i<4; i+=3){ // beta*I3, beta= 1+3i
           beta[i].real = 1;
           beta[i].imaginary = 3;
    }

    complexe_double_t compare_matrix[2] ; //calculée à la main

    compare_matrix[0].real = -16;
    compare_matrix[0].imaginary = -7;
    compare_matrix[1].real = -40;
    compare_matrix[1].imaginary = 19;
    
    mncblas_zgemv(3,101,2,3, alpha,Mat_A, 0, Vect_X, 1,beta, Vect_Y, 1); //2lignes, 3colonnes

    //printf("real: %f, imaginary : %f\n", Vect_Y[0].real, Vect_Y[0].imaginary);
    //printf("real: %f, imaginary : %f\n", Vect_Y[1].real, Vect_Y[1].imaginary);
    

    compare_complex_double(compare_matrix, Vect_Y,2);

    printf("\ntest06 passé\n");

}

void test07(){
    complexe_double_t Mat_A[6];  //3*2
    Mat_A[0].real = 1.0;
    Mat_A[0].imaginary = 2.0;

    Mat_A[1].real = 3.0;
    Mat_A[1].imaginary = 0.0;

    Mat_A[2].real = 0.0;
    Mat_A[2].imaginary =9.0;

    Mat_A[3].real = 1.0;
    Mat_A[3].imaginary =0.0;

    Mat_A[4].real = 2.0;
    Mat_A[4].imaginary =1.0;

    Mat_A[5].real = 5.0;
    Mat_A[5].imaginary = 4.0;

    complexe_double_t Vect_X[2];
    Vect_X[0].real = 3.0;
    Vect_X[0].imaginary = 1.0;
    Vect_X[1].real = 1.0;
    Vect_X[1].imaginary = 4.0;

    complexe_double_t Vect_Y[3];
    Vect_Y[0].real = 1.0;
    Vect_Y[0].imaginary = 1.0;
    Vect_Y[1].real = 3.0;
    Vect_Y[1].imaginary = 0;
    Vect_Y[2].real =2;
    Vect_Y[2].imaginary = 2.0;



    complexe_double_t alpha[9];

    for (int i = 0; i<3; i++){ // alpha*I3, alpha = 1+2i
           alpha[4*i].real = 1;
           alpha[4*i].imaginary = 2;
    }

    complexe_double_t beta[4];

    for (int i = 0; i<4; i+=3){ // beta*I3, beta= 1+3i
           beta[i].real = 1;
           beta[i].imaginary = 3;
    }

    complexe_double_t compare_matrix[3] ; //calculée à la main

    compare_matrix[0].real = -36;
    compare_matrix[0].imaginary = 31;
    compare_matrix[1].real = -67;
    compare_matrix[1].imaginary = 24;
    compare_matrix[2].real = -68;
    compare_matrix[2].imaginary = 25;    
    mncblas_zgemv(3,101,3,2, alpha,Mat_A, 0, Vect_X, 1,beta, Vect_Y, 1); //3lignes, 2colonnes

    printf("real: %f, imaginary : %f\n", Vect_Y[0].real, Vect_Y[0].imaginary);
    printf("real: %f, imaginary : %f\n", Vect_Y[1].real, Vect_Y[1].imaginary);
    printf("real: %f, imaginary : %f\n", Vect_Y[2].real, Vect_Y[2].imaginary);

    compare_complex_double(compare_matrix, Vect_Y,3);

    printf("\ntest07 passé\n");
}

int main(){
    

    /*test00();
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();
    printf("\nTESTS GEMV PASSED\n");*/

    struct timespec start, end ;
     int i ;
    //float measure
    
    init_nano () ;

     for (i = 0 ; i < NB_FOIS; i++)
   {
     matrix_init(Af, 2.0);
     vector_init (Xf, 1.0) ;
     vector_init (Yf, 2.0) ;
     float alpha = 2.0;
     float beta = 3.0;

     TOP_NANO (start) ;
     mncblas_sgemv (3,101,MATSIZE,MATSIZE, alpha, Af, 0, Xf, 1,beta,Yf,1) ;
     TOP_NANO (end);

     double temps = diff_nano (&start,&end);

     printf ("sgemv nano %e seconde\n", temps) ;
     if (i>=2){
      somme_temps += temps;
     }
   }
 printf("Y[0] = %f\n", Yf[0]);
 printf ("==========================================================\n") ;
 printf("moyenne des temps : %e\n\n", somme_temps/8.0);
  somme_temps=0;

//mesure double

for (i = 0 ; i < NB_FOIS; i++)
   {
     matrix_initd(Ad, 2.0);
     vector_initd (Xd, 1.0) ;
     vector_initd (Yd, 2.0) ;
     double alpha = 2.0;
     double beta = 3.0;

     TOP_NANO (start) ;
     mncblas_dgemv (3,101,MATSIZE,MATSIZE, alpha, Ad, 0, Xd, 1,beta,Yd,1) ;
     TOP_NANO (end);

     double temps = diff_nano (&start,&end);

     printf ("dgemv nano %e seconde\n", temps) ;
     if (i>=2){
      somme_temps += temps;
     }
   }
 printf("Y[0] = %f\n", Yf[0]);
 printf ("==========================================================\n") ;
 printf("moyenne des temps : %e\n\n", somme_temps/8.0);
  somme_temps=0;
    

    //mesure complexe float

for (i = 0 ; i < NB_FOIS; i++)
   {
    complexe_float_t toA = {2.0,3.0};
    complexe_float_t toX = {1.0,8.0};
    complexe_float_t toY = {-2.0,1.0};
     matrix_initcf(Acf, toA);
     vector_initcf (Xcf, toX) ;
     vector_initcf (Ycf, toY) ;
     complexe_float_t alpha[1] = {{1,2}};
     complexe_float_t beta[1] = {{3,1}};

     TOP_NANO (start) ;
     mncblas_cgemv (0,0,MATSIZE,MATSIZE, alpha, Acf, 0, Xcf, 0,beta,Ycf,0) ;
     TOP_NANO (end);

     double temps = diff_nano (&start,&end);

     printf ("cgemv nano %e seconde\n", temps) ;
     if (i>=2){
      somme_temps += temps;
     }
   }
 printf("Y[0].real = %f\n Y[0].imaginary = %f\n ", Ycf[0].real,Ycf[0].imaginary);
 printf ("==========================================================\n") ;
 printf("moyenne des temps : %e\n\n", somme_temps/8.0);
  somme_temps=0;
    
    //mesure complexe double

    for (i = 0 ; i < NB_FOIS; i++)
   {
    complexe_double_t toA = {2.0,3.0};
    complexe_double_t toX = {1.0,8.0};
    complexe_double_t toY = {-2.0,1.0};
     matrix_initcd(Acd, toA);
     vector_initcd (Xcd, toX) ;
     vector_initcd (Ycd, toY) ;
     complexe_double_t alpha[1] = {{1,2}};
     complexe_double_t beta[1] = {{3,1}};

     TOP_NANO (start) ;
     mncblas_zgemv (3,101,MATSIZE,MATSIZE, alpha, Acd, 0, Xcd, 1,beta,Ycd,1) ;
     TOP_NANO (end);

     double temps = diff_nano (&start,&end);

     printf ("zgemv nano %e seconde\n", temps) ;
     if (i>=2){
      somme_temps += temps;
     }
   }
 printf("Y[0].real = %f\n Y[0].imaginary = %f\n ", Ycd[0].real,Ycd[0].imaginary);
 printf ("==========================================================\n") ;
 printf("moyenne des temps : %e\n\n", somme_temps/8.0);
  somme_temps=0;

    return 1;
}

