#include "../src/BLAS2/gemv_omp.c"
#include <stdio.h>

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

    printf("real: %f, imaginary : %f\n", Vect_Y[0].real, Vect_Y[0].imaginary);
    printf("real: %f, imaginary : %f\n", Vect_Y[1].real, Vect_Y[1].imaginary);
    

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

    printf("real: %f, imaginary : %f\n", Vect_Y[0].real, Vect_Y[0].imaginary);
    printf("real: %f, imaginary : %f\n", Vect_Y[1].real, Vect_Y[1].imaginary);
    printf("real: %f, imaginary : %f\n", Vect_Y[2].real, Vect_Y[2].imaginary);

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

    printf("real: %f, imaginary : %f\n", Vect_Y[0].real, Vect_Y[0].imaginary);
    printf("real: %f, imaginary : %f\n", Vect_Y[1].real, Vect_Y[1].imaginary);
    

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

    test00();
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();


    //printf("\nTESTS GEMV PASSED\n");
    return 1;
}

